package com.company;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class UserWindow extends AbstractUser {
    protected JPanel buttons = new JPanel();

    protected JTable studentTable;
    protected JTable groupTable;

    protected ArrayList<Group> groups;
    protected ArrayList<Student> students = new ArrayList<>();

    protected JScrollPane scrollPaneStudents = new JScrollPane(),
            scrollPaneGroups = new JScrollPane();

    protected JButton viewStudents,
            viewGroups,
            logOut = new JButton("Log Out");

    protected Group selectedGroup;

    UserWindow(String Login) {
        setLogin(Login);
        setTitle(Login + " <-> " + getRights());
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(50, 50, 1300, 700);

        initialGroup();
        showGroupTable();

        viewGroups = new JButton("View Groups");
        viewGroups.setEnabled(false);

        viewStudents = new JButton("View Students");


        buttons.add(viewGroups);
        buttons.add(viewStudents);


        buttons.add(logOut);
        logOut.addActionListener(actionEvent -> dispose());


        add(buttons, BorderLayout.SOUTH);


        viewGroups.addActionListener(new U_ViewGroups(this));

        viewStudents.addActionListener(new U_ViewStudents(this));


        validate();
        setVisible(true);

    }

    protected void setViewGroups() {
        viewStudents.setEnabled(true);
        viewGroups.setEnabled(false);
        remove(scrollPaneStudents);
        showGroupTable();
        validate();
    }

    protected void setViewStudents() {
        try {
            int pos = groupTable.getSelectedRow();
            if (pos == -1)
                throw new NullPointerException("No Group selected, select a group");
            else if (groupTable.getSelectedRowCount() > 1)
                throw new NullPointerException("Multiple groups selected, select one");

            remove(scrollPaneGroups);

            selectedGroup = GroupContainer.getGroup(pos);
            initialStudents(selectedGroup);

            viewGroups.setEnabled(true);
            viewStudents.setEnabled(false);
            validate();
        } catch (NullPointerException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Error " + e.getMessage());
        }
    }

    protected void initialGroup() {
        groups = GroupContainer.getList();
        groupModel = new GroupTableViewModel(groups);
        groupTable = new JTable(groupModel);

        groupTable.setDragEnabled(false);
        groupTable.getTableHeader().setReorderingAllowed(false);

        groupTable.setAutoCreateRowSorter(true);
        remove(scrollPaneGroups);
        scrollPaneGroups = new JScrollPane(groupTable);
        showGroupTable();
    }

    protected void showGroupTable() {
        add(scrollPaneGroups, BorderLayout.CENTER);
    }

    protected void initialStudents(Group innit) {
        students = innit.getStudentList();
        studentModel = new StudentTableViewModel(students);
        studentTable = new JTable(studentModel);

        studentTable.setDragEnabled(false);
        studentTable.getTableHeader().setReorderingAllowed(false);
        studentTable.setAutoCreateRowSorter(true);

        remove(scrollPaneStudents);
        scrollPaneStudents = new JScrollPane(studentTable);
        showStudentTable();
    }

    protected void showStudentTable() {
        add(scrollPaneStudents, BorderLayout.CENTER);
    }

    protected void setupStudentTable() {
        students = selectedGroup.getStudentList();

        studentModel = new StudentTableEditModel(students);
        studentTable.setModel(studentModel);

        studentTable.setDragEnabled(false);
        studentTable.getTableHeader().setReorderingAllowed(false);
        studentTable.setAutoCreateRowSorter(true);

        remove(scrollPaneStudents);
        scrollPaneStudents = new JScrollPane(studentTable);
        showStudentTable();
    }

    protected void disableBasicUi() {
        viewGroups.setEnabled(false);
        viewStudents.setEnabled(false);
        logOut.setEnabled(false);
    }

    protected void enableBasicUi() {
        viewGroups.setEnabled(true);
        viewStudents.setEnabled(true);
        logOut.setEnabled(true);
    }

    @Override
    protected void setLogin(String Login) {
        this.Login = Login;
    }

    @Override
    protected String getRights() {
        return "Authorised User";
    }

}