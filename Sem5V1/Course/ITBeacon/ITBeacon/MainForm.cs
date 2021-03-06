using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;
using System.Collections.Generic;
using System.Linq;

namespace ITBeacon
{
    public partial class MainForm : Form
    {
        public SqlConnection connection;
        static bool needUpdating = false;
        static readonly HashSet<(int, int)> indexesToChange = new();
        public MainForm() => InitializeComponent();
        void DBCreation_Button_Click(object sender, EventArgs e)
        {
            try
            {
                using System.IO.StreamReader sr = new("file.txt");
                SqlCommand sqlCommand = new()
                {
                    Connection = connection
                };
                var commands = sr.ReadToEnd().Split(new string[] { "\nGO", "\ngo", "\nGo" },
                    StringSplitOptions.None);
                for (int i = 0; i < commands.Length; i++)
                {
                    sqlCommand.CommandText = commands[i];
                    sqlCommand.ExecuteNonQuery();
                }
                MessageBox.Show("Таблицы успешно созданы");
                DBCreation_Button.Enabled = false;
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        void SendRequest_Button_Click(object sender, EventArgs e)  => new SendCmdForm(this).Show();
        void RemoveEl_Button_Click(object sender, EventArgs e)
        {
            if (Metadata_DGV.SelectedCells.Count < 1)
                return;
            var cmdText = $"DELETE FROM {Tables_LB.SelectedItem} WHERE id IN (";
            for (int i = 0; i < Metadata_DGV.SelectedCells.Count; i++)
                cmdText += $"\'{Metadata_DGV.Rows[Metadata_DGV.SelectedCells[i].RowIndex].Cells[0].Value}\', ";
            cmdText = cmdText.Remove(cmdText.Length - 2, 2) + ')';
            try
            {
                MessageBox.Show($"Удалено {new SqlCommand(cmdText, connection).ExecuteNonQuery()} строк");
                Reload_metadata_DVG();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        public void FillTableList()
        {
            Tables_LB.Items.Clear();
            DataTable dataTable = new();
            new SqlDataAdapter("SELECT * FROM sys.objects WHERE type in (N'U')", connection).Fill(dataTable);
            var ind = dataTable.Columns.IndexOf("name");
            foreach (var row in dataTable.Rows)
                Tables_LB.Items.Add((row as DataRow)?.ItemArray[ind].ToString());
            if (Tables_LB.Items.Count == 0)
                DBCreation_Button.Enabled = true;
            
        }
        void Tables_LB_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (Tables_LB.SelectedItem != null) 
                Reload_metadata_DVG();
        }
        void Reload_metadata_DVG()
        {
            try
            {
                DataTable dataTable = new();
                new SqlDataAdapter($"SELECT * FROM {Tables_LB.SelectedItem}", connection).Fill(dataTable);
                Metadata_DGV.DataSource = dataTable;
            }
            catch(Exception e)
            {
                MessageBox.Show($"{e.GetType()}: {e.Message} - {(e as SqlException)?.ErrorCode}");
            }
        }
        void SubmitChanges_Button_Click(object sender, EventArgs e)
        {
            static bool StrDType(object val) => !typeof(int).Equals(val.GetType());
            if (!needUpdating)
                return;
            try
            {
                // Get Columns Names
                var cmdText = $"select COLUMN_NAME from INFORMATION_SCHEMA.columns where TABLE_NAME = \'{Tables_LB.SelectedItem}\'";
                DataTable dataTable = new();
                new SqlDataAdapter(cmdText, connection).Fill(dataTable);
                // Generate the query
                var rowsToChange = indexesToChange.GroupBy(cords => cords.Item1);
                foreach(var row in rowsToChange)
                {
                    cmdText = $"UPDATE {Tables_LB.SelectedItem} SET";
                    foreach (var pair in row) {
                        var val = Metadata_DGV.Rows[pair.Item1].Cells[pair.Item2].Value;
                        cmdText += $" {dataTable.Rows[pair.Item2].ItemArray[0]} = {(StrDType(val)? $"\'{val}\'" : $"{val}")},";
                    }
                    cmdText = cmdText.Remove(cmdText.Length-1,1) + $" WHERE id = {Metadata_DGV.Rows[row.Key].Cells[0].Value}";
                    // Send the query
                    try
                    {
                        new SqlCommand(cmdText, connection).ExecuteNonQuery();
                        Reload();
                    }
                    catch (SqlException ex)
                    {
                        if (ex.ErrorCode == -2146232060)
                        {
                            InsertValuesCmd(row.Key, dataTable, ref cmdText);
                            try
                            {
                                new SqlCommand(cmdText, connection).ExecuteNonQuery();
                                Reload();
                            }
                            catch(Exception exept)
                            {
                                MessageBox.Show(exept.Message);
                            }
                        }
                        else 
                            MessageBox.Show(ex.Message);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message);
                    }
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            void Reload()
            {
                 // Reload
                indexesToChange.Clear();
                needUpdating = false;
                SubmitChanges_Button.Enabled = false;
                Reload_metadata_DVG();
            }
        }
        void InsertValuesCmd(int rowInd, DataTable dataTable, ref string cmdtext)
        {
            cmdtext = $"INSERT INTO {Tables_LB.SelectedItem} (";
            for (int i = 0; i < dataTable.Rows.Count; i++)
                if (dataTable.Rows[i].ItemArray[0].ToString() != "id")
                    cmdtext += dataTable.Rows[i].ItemArray[0].ToString() + ", ";
            cmdtext = cmdtext.Remove(cmdtext.Length-2,2) + ") VALUES (";
            for (int i = 0; i < dataTable.Rows.Count; i++)
                if (dataTable.Rows[i].ItemArray[0].ToString() != "id") 
                cmdtext += string.Format("\'{0}\', ", Metadata_DGV.Rows[rowInd].Cells[i]?.Value);
            cmdtext = cmdtext.Remove(cmdtext.Length - 2, 2) + ")";
        }
        void Metadata_DGV_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {
            indexesToChange.Add((e.RowIndex, e.ColumnIndex));
            needUpdating = true;
            SubmitChanges_Button.Enabled = true;
        }
        void ChangeConnection_Button_Click(object sender, EventArgs e)
        {
            new ConnectionForm(this).Show();
            Hide();
        }
        void MainPage_Close(object sender, FormClosedEventArgs e)
        {
            connection?.Close();
            Application.Exit();
        }
    }
}
