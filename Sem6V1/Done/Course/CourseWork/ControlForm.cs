using System;
using System.Linq;
using System.Windows.Forms;
using System.Data;
using System.Collections.Generic;
using System.Data.SqlClient;

namespace CourseWork
{
    public partial class ControlForm : Form
    {
        public ControlForm() => InitializeComponent();
        private void BtnSelectTable1_Click(object sender, EventArgs e) => Logic.SelectTable(cmbTable1, Logic.DataSet1, ofdOpenTableFile1);
        private void BtnSelectTable2_Click(object sender, EventArgs e) => Logic.SelectTable(cmbTable2, Logic.DataSet2, ofdOpenTableFile2);
        private void CmbTables_SelectedIndexChanged(object sender, EventArgs e) => dgvResTable.DataSource = Logic.GridViewOptions[cmbTables.SelectedItem.ToString()];
        private void CmbTable1_SelectedIndexChanged(object sender, EventArgs e) => ManageControls();
        private void CmbTable2_SelectedIndexChanged(object sender, EventArgs e) => ManageControls();
        private void BtnJoinTables_Click(object sender, EventArgs e)
        {
            ManageControls();
            Logic.Result = JoinTables(Logic.SelectedTable(cmbTable1.SelectedItem.ToString(), Logic.DataSet1), Logic.SelectedTable(cmbTable2.SelectedItem.ToString(), Logic.DataSet2));
            Logic.GridViewOptions.Add("Result", Logic.Result);
            CmbTables_Refresh();
        }
        /// <summary>
        /// Joins two provided tables depending on what option was selected on the form
        /// </summary>
        /// <param name="table1">Table to join to</param>
        /// <param name="table2">Table to be joined</param>
        /// <returns>DataTable,  the result of joining 2 tables</returns>
        private DataTable JoinTables(DataTable table1, DataTable table2)
            => flpRadioJoins.Controls
                .Cast<Control>()
                .FirstOrDefault(control => control is RadioButton rb && rb.Checked)
            .Text switch
            {
                "Auto Inner Join" => new TableJoiner(table1, table2).InnerJoin(),
                _ => new TableJoiner(table1, table2).FullJoin()
            };
        /// <summary>
        /// Changes controls parameters according to their availability from defined by the provided data
        /// </summary>
        private void ManageControls()
        {
            if (cmbTable1.SelectedItem is null || cmbTable2.SelectedItem is null)
                return;
            btnJoinTables.Enabled = true;
            var sharedColNames = new TableJoiner(Logic.SelectedTable(cmbTable1.SelectedItem.ToString(), Logic.DataSet1), Logic.SelectedTable(cmbTable2.SelectedItem.ToString(), Logic.DataSet2)).SharedColNames;
            flpRadioJoins.Controls
                .Cast<Control>()
                .FirstOrDefault(ctrl => ctrl.Text is "Auto Inner Join")
                .Enabled =
                sharedColNames.Key is not null &&
                sharedColNames.Value is not null;
            Logic.GridViewOptions.Clear();
            Logic.GridViewOptions.Add("1st Table", Logic.SelectedTable(cmbTable1.SelectedItem.ToString(), Logic.DataSet1));
            Logic.GridViewOptions.Add("2st Table", Logic.SelectedTable(cmbTable2.SelectedItem.ToString(), Logic.DataSet2));
            CmbTables_Refresh();
        }
        /// <summary>
        /// Refreshes the combobox which defines a table to be displayed in data grid view
        /// </summary>
        private void CmbTables_Refresh()
        {
            cmbTables.Items.Clear();
            foreach (var pair in Logic.GridViewOptions)
                cmbTables.Items.Add(pair.Key);
            cmbTables.SelectedIndex = cmbTables.Items.Count - 1;
        }
        private void BtnConnect_Click(object sender, EventArgs e)
        {
            Logic.SqlConnection.ConnectionString = tbConnection.Text;
            btnSaveDS.Enabled = true;
            // btnGenerateData.Enabled = true;
        }
        private void BtnSaveDS_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() != DialogResult.OK)
                return;
            try
            {
                Logic.GetSQLDataSet().WriteXml(saveFileDialog1.FileName);
            }
            catch(Exception ex)
            {
                MessageBox.Show($"Smth went wrong here: {ex}");
            }
        }
        private void TbConnection_TextChanged(object sender, EventArgs e) => btnConnect.Enabled = tbConnection.Text.Contains("Data Sourse") && tbConnection.Text.Contains("Initial Catalog");
        private void BtnGenerateData_Click(object sender, EventArgs e) => Logic.GenerateData();
    }
    /// <summary>
    /// Class for handling all the table-joining operations
    /// </summary>
    class TableJoiner
    {
        readonly DataTable _table1;
        readonly DataTable _table2;
        /// <summary>
        /// Contains the names of two columns found in both tables which match the "ON" sql-operation
        /// </summary>
        public KeyValuePair<string, string> SharedColNames { get; init; }
        public TableJoiner(DataTable table1, DataTable table2)
        {
            _table1 = table1;
            _table2 = table2;
            SharedColNames = new (DataTable, DataTable)[] { (_table1, _table2), (_table2, _table1) }.Select(pair =>
                new KeyValuePair<string, string>(
                    _table1.Columns
                    .Cast<DataColumn>()
                    .Select(column => column.ColumnName)
                    .FirstOrDefault(colName => {
                        colName = colName.ToLower();
                        return
                        (
                            colName.Contains("id") ||
                            colName.Contains("no") ||
                            colName.Contains("num")
                        )
                        && colName.Contains(_table2.TableName.ToLower());
                    }
                    ),
                    _table2.Columns
                    .Cast<DataColumn>()
                    .Select(column => column.ColumnName)
                    .FirstOrDefault(colName =>
                    {
                        colName = colName.ToLower();
                        return
                            colName is "id" or "num" or "no" ||
                            colName.Contains(_table2.TableName.ToLower()) &&
                            colName.Contains("id") ||
                            colName.Contains("no") ||
                            colName.Contains("num");
                    }
                    )
                )
            )
            .FirstOrDefault(pair => pair.Key is not null && pair.Value is not null);
        }
        /// <summary>
        /// Joins two provided tables keeping all the data form both of them
        /// </summary>
        /// <returns>DataTable consisting of both table header rows and their data</returns>
        public DataTable FullJoin()
        {
            DataTable res = new();
            new DataTable[] { _table1, _table2 }
            .ToList()
            .ForEach(table =>
            {
                int prevNCols = res.Columns.Count;
                for (int i = 0; i < table.Columns.Count; i++)
                    try
                    {
                        res.Columns.Add(table.Columns[i].ColumnName);
                    }
                    catch (DuplicateNameException)
                    {
                        res.Columns.Add(table.Columns[i].ColumnName + "2");
                    }
                while (res.Rows.Count < table.Rows.Count)
                    res.Rows.Add();
                for (int i = 0; i < table.Columns.Count; i++)
                    for (int j = 0; j < table.Rows.Count; j++)
                        res.Rows[j][prevNCols + i] = table.Rows[j].ItemArray[i];
            });
            return res;
        }
        /// <summary>
        /// The analogue of sql's "ON" operation with the automatic search of the ON-columns
        /// </summary>
        /// <returns>DataTable consisting of joined on some table data</returns>
        public DataTable InnerJoin()
        {
            var sharedColNames = SharedColNames;
            if (sharedColNames is {Value: null, Key: null })
            {
                MessageBox.Show("No shared column Found!");
                return null;
            }
            var rowPairs = from row1 in _table1.AsEnumerable()
                           from row2 in _table2.AsEnumerable()
                           where row1.Field<string>(sharedColNames.Key) == row2.Field<string>(sharedColNames.Value)
                           select new KeyValuePair<DataRow, DataRow>(row1, row2);
            DataTable res = new();
            foreach (DataColumn column in _table1.Columns)
                res.Columns.Add(column.ColumnName);
            foreach (DataColumn column in _table2.Columns)
                if (column.ColumnName != sharedColNames.Value)
                    try
                    {
                        res.Columns.Add(column.ColumnName);
                    }
                    catch (DuplicateNameException)
                    {
                        res.Columns.Add(column.ColumnName + "2");
                    }
            while (res.Rows.Count <= rowPairs.Count())
                res.Rows.Add();
            for (int i = 0; i < rowPairs.Count(); i++)
            {
                var row1Length = rowPairs.ElementAt(i).Key.ItemArray.Length;
                for (int j = 0; j < row1Length; j++)
                    res.Rows[i][j] = rowPairs.ElementAt(i).Key[j];
                for (int j = 0; j < rowPairs.ElementAt(i).Value.ItemArray.Length-1; j++)
                    res.Rows[i][j + row1Length] = rowPairs.ElementAt(i).Value[j];
            }
            return res;
        }
    }
    /// <summary>
    /// Contains information about provided datasets, connection and hangles their interactions
    /// </summary>
    static class Logic
    {
        /// <summary>
        /// Connection to the DataBase with the required data
        /// </summary>
        public static SqlConnection SqlConnection { get; } = new();
        /// <summary>
        /// Dataset for the selection of the first table to join
        /// </summary>
        public static DataSet DataSet1 { get; } = new();
        /// <summary>
        /// Dataset for the selection of the second table to join
        /// </summary>
        public static DataSet DataSet2 { get; } = new();
        /// <summary>
        /// DataTable which contains the result of joining two provided tables
        /// </summary>
        public static DataTable Result { get; set; } = null;
        /// <summary>
        /// Cotains pairs of data table to view and its name
        /// </summary>
        public static Dictionary<string, DataTable> GridViewOptions { get; } = new();
        public static void SelectTable(ComboBox comboBox, DataSet dataSet, OpenFileDialog openFileDialog)
        {
            if (openFileDialog.ShowDialog() is not DialogResult.OK)
            {
                MessageBox.Show("Choose a file to pick a table to join!");
                return;
            }
            dataSet.ReadXml(openFileDialog.FileName);
            foreach (DataTable table in dataSet.Tables)
                comboBox.Items.Add(table.TableName);
            if (comboBox.Items.Count is not 0)
                comboBox.SelectedIndex = 0;
        }
        /// <summary>
        /// Searches the data table in dataset
        /// </summary>
        /// <param name="selectedTableName">The name of the data table to find</param>
        /// <param name="dataSet">Dataset to search selected data table in</param>
        /// <returns>DataTable which name matches the provided name in the dataset</returns>
        /// <exception cref="DataException">Thrown when there is no datatable with the given name in dataset</exception>
        public static DataTable SelectedTable(string selectedTableName, DataSet dataSet)
        {
            foreach (DataTable dataTable in dataSet.Tables)
                if (dataTable.TableName == selectedTableName)
                    return dataTable;
            throw new DataException("No table from the specified dataset found in the combobox");
        }
        public static DataSet GetSQLDataSet()
        {
            DataSet dataSet = new();
            new SqlDataAdapter("SELECT TABLE_NAME FROM INFORMATION_SCHEMA.Tables", SqlConnection).Fill(dataSet);
            DataSet resDS = new();
            for (int i = 0; i < dataSet.Tables[0].Rows.Count; i++)
                new SqlDataAdapter($"SELECT * FROM {dataSet.Tables[0].Rows[i][0]}", SqlConnection).Fill(resDS, dataSet.Tables[0].Rows[i][0].ToString());
            return resDS;
        }
        public static void GenerateData() { }
    }
}
