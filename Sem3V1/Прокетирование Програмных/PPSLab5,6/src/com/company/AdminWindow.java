package com.company;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.io.IOException;

public class AdminWindow extends UserWindow {
    private DefaultTableModel adminModel = new DefaultTableModel();
    private JTable adminTable = new JTable(adminModel);
    private JScrollPane adminScrollPane;
    private JButton viewUsers = new JButton("View User");
    private JButton addUser = new JButton("Add User");
    private JButton changeUser = new JButton("Change User");
    private JButton removeUser = new JButton("Remove User");
    private JPanel adminTools = new JPanel(new FlowLayout());
    private JComboBox<String> rights = new JComboBox<>(new String[]{"Administrator", "Manager", "User"});
    private JButton confirmAdd = new JButton("Confirm addition");
    private JButton confirmChange = new JButton("Confirm Change");
    private JButton confirmRemove = new JButton("Confirm Removal");


    AdminWindow(String Login) {
        super(Login);

        setupAdminTable();

        viewUsers.addActionListener(new Adm_ViewUsers(this));

        addUser.addActionListener(new Adm_Listener(this, 0));

        confirmAdd.addActionListener(new Adm_Listener(this, 1));


        changeUser.addActionListener(new Adm_Listener(this, 2));

        confirmChange.addActionListener(new Adm_Listener(this, 3));


        removeUser.addActionListener(new Adm_Listener(this, 4));

        confirmRemove.addActionListener(new Adm_Listener(this, 5));

        viewStudents.addActionListener(new Adm_ViewStudents(this));
        viewGroups.addActionListener(new Adm_ViewGroups(this));

        add(adminTools, BorderLayout.NORTH);
        validate();
    }


    protected void setupAdminTable() {
        adminModel.addColumn("Username");
        adminModel.addColumn("Password");
        adminModel.addColumn("Rights/User Type");

        adminTable.setDragEnabled(false);
        adminTable.getTableHeader().setReorderingAllowed(false);
        adminTable.setAutoCreateRowSorter(true);
        adminTable.getColumnModel().getColumn(2).setCellEditor(new DefaultCellEditor(rights));


        adminScrollPane = new JScrollPane(adminTable);

        addUser.setEnabled(false);
        changeUser.setEnabled(false);
        removeUser.setEnabled(false);

        adminTools.add(addUser);
        adminTools.add(viewUsers);
        adminTools.add(changeUser);
        adminTools.add(removeUser);

        adminTools.add(confirmAdd);
        adminTools.add(confirmChange);
        adminTools.add(confirmRemove);

        confirmAdd.setVisible(false);
        confirmChange.setVisible(false);
        confirmRemove.setVisible(false);


    }

    protected void clearAdminTable() {
        int rowCount = adminModel.getRowCount();
//          Remove rows one by one from the end of the table
        for (int i = rowCount - 1; i >= 0; i--) {
            adminModel.removeRow(i);
        }
    }

    protected void fillAdminTable() {
        for (int i = 0; i < AccountContainer.getListSize(); i++) {
            adminModel.addRow(new Object[]{AccountContainer.getLogin(i), AccountContainer.getPassword(i), AccountContainer.getRights(i)});
        }
    }

    protected void updateAdminTable() {
        clearAdminTable();
        fillAdminTable();
    }

    protected void disableAdminUi() {
        viewUsers.setEnabled(false);
        addUser.setEnabled(false);
        changeUser.setEnabled(false);
        removeUser.setEnabled(false);
        disableBasicUi();

        adminTable.setEnabled(true);

    }

    protected void enableAdminUi() {
        viewUsers.setEnabled(false);
        addUser.setEnabled(true);
        changeUser.setEnabled(true);
        removeUser.setEnabled(true);
        enableBasicUi();

        adminTable.setEnabled(false);
    }

    //func section
    protected void viewUsers() {
        enableAdminUi();

        remove(scrollPaneGroups);
        remove(scrollPaneStudents);
        add(adminScrollPane, BorderLayout.CENTER);

        updateAdminTable();

        adminTable.setVisible(true);
        validate();
    }

    protected void addUser() {
        disableAdminUi();

        confirmAdd.setVisible(true);
        adminModel.addRow(new Object[]{});

    }

    protected void confirmAdd() {
        enableAdminUi();
        viewGroups.setEnabled(false);

        confirmAdd.setVisible(false);
        try {
            String name = (String) adminTable.getValueAt(adminTable.getRowCount() - 1, 0);
            String password = (String) adminTable.getValueAt(adminTable.getRowCount() - 1, 1);
            String type = (String) rights.getSelectedItem();

            assert type != null;
            if (name.isEmpty() || password.isEmpty() || type.isEmpty())
                throw new NullPointerException();

            AccountContainer.addAccount(type, name, password);
            Serializer.updateAccounts();
        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null, "Incorrect user type, retry.");
            adminModel.removeRow(adminTable.getRowCount() - 1);
        }
    }

    protected void changeUser() {
        disableAdminUi();
        confirmChange.setVisible(true);
    }

    protected void confirmChange() {
        enableAdminUi();
        viewGroups.setEnabled(false);

        confirmChange.setVisible(false);
        try {
            int pos = adminTable.getSelectedRow();
            if (pos < 0)
                throw new IOException("No row selected, retry");

            String name = (String) adminTable.getValueAt(adminTable.getSelectedRow(), 0);
            String password = (String) adminTable.getValueAt(adminTable.getSelectedRow(), 1);
            String type = (String) rights.getSelectedItem();

            assert type != null;
            if (name.isEmpty() || password.isEmpty() || type.isEmpty())
                throw new NullPointerException("Incorrect user type, retry.");

            AccountContainer.removeAccount(adminTable.getSelectedRow());
            adminModel.removeRow(adminTable.getSelectedRow());
            adminModel.addRow(new Object[]{type, name, password});

            AccountContainer.addAccount(type, name, password);
            Serializer.updateAccounts();
            updateAdminTable();

        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null, e.getMessage());
            adminModel.removeRow(adminTable.getRowCount() - 1);
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, e.getMessage());
        }
    }

    protected void removeUser() {
        disableAdminUi();
        adminTable.setRowSelectionAllowed(true);
        confirmRemove.setVisible(true);
    }

    protected void confirmRemove() {
        enableAdminUi();
        confirmRemove.setVisible(false);
        adminTable.setRowSelectionAllowed(false);
        try {
            if (adminTable.getSelectedRow() == -1)
                throw new NullPointerException("No row selected, retry.");

            if (adminTable.getSelectedRowCount() > 1)
                throw new NullPointerException("More than 1 row selected, retry.");

            AccountContainer.removeAccount(adminTable.getSelectedRow());
            adminModel.removeRow(adminTable.getSelectedRow());
            Serializer.updateAccounts();
            updateAdminTable();
        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null, e.getMessage());
        }
    }

    @Override
    protected void setViewStudents() {
        super.setViewStudents();
        remove(adminScrollPane);
        logOut.setEnabled(true);
        viewUsers.setEnabled(true);
        addUser.setEnabled(false);
        changeUser.setEnabled(false);
        removeUser.setEnabled(false);
    }

    @Override
    protected void setViewGroups() {
        super.setViewGroups();
        remove(adminScrollPane);
        viewUsers.setEnabled(true);
        addUser.setEnabled(false);
        changeUser.setEnabled(false);
        removeUser.setEnabled(false);
        logOut.setEnabled(true);
    }

    @Override
    protected String getRights() {
        return "Administrator";
    }

}