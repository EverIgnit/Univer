package com.company;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class ManagerWindow extends UserWindow {

    private JButton addStudent = new JButton("Add Student");
    private JButton changeStudent = new JButton("Change Student");
    private JButton removeStudent = new JButton("Remove Student");
    private JButton addGroup = new JButton("Add Group");
    private JButton changeGroup = new JButton("Change Group");
    private JButton removeGroup = new JButton("Remove Group");

    private JPanel managerTools = new JPanel(new FlowLayout());

    private JButton confirmAddStudent = new JButton("Confirm Add");
    private JButton confirmChangeStudent = new JButton("Confirm Change");
    private JButton confirmRemoveStudent = new JButton("Confirm Remove");

    private JButton confirmAddGroup = new JButton("Confirm Add");
    private JButton confirmChangeGroup = new JButton("Confirm Change");
    private JButton confirmRemoveGroup = new JButton("Confirm Remove");

    @Override
    protected String getRights() {
        return "Manager";
    }

    ManagerWindow(String Login) {
        super(Login);

        setupManagerTools();


        addGroup.addActionListener(new ManagerListener(this, 0));

        confirmAddGroup.addActionListener(new ManagerListener(this, 1));


        changeGroup.addActionListener(new ManagerListener(this, 2));

        confirmChangeGroup.addActionListener(new ManagerListener(this, 3));


        removeGroup.addActionListener(new ManagerListener(this, 4));

        confirmRemoveGroup.addActionListener(new ManagerListener(this, 5));



        addStudent.addActionListener(new ManagerListener(this, 6));

        confirmAddStudent.addActionListener(new ManagerListener(this, 7));


        changeStudent.addActionListener(new ManagerListener(this, 8));

        confirmChangeStudent.addActionListener(new ManagerListener(this, 9));


        removeStudent.addActionListener(new ManagerListener(this, 10));

        confirmRemoveStudent.addActionListener(new ManagerListener(this, 11));


        this.viewStudents.addActionListener(new ManagerListener(this, 12));

        this.viewGroups.addActionListener(new ManagerListener(this, 13));

    }

    //Al section start
    protected void addGroup(){
        disableGroupUi();
        this.disableBasicUi();

        confirmAddGroup.setVisible(true);
        groups.add(new Group("Name", "Speciality", "бюджет", 0, 0));
        groupModel.addRow(new Object[]{});
        setupGroupTable();
        setupGroupTable();
    }

    protected void setConfirmAddGroup(){
        this.enableBasicUi();
        enableGroupUi();
        viewGroups.setEnabled(false);

        confirmAddGroup.setVisible(false);
        try {
            int pos = groupTable.getRowCount() - 1;
            String name = (String) groupTable.getValueAt(pos, 0);
            String speciality = (String) groupTable.getValueAt(pos, 1);
            String form = (String) groupTable.getValueAt(pos, 2);
            int amountOfStudents = (Integer) groupTable.getValueAt(pos, 3);
            int course = (Integer) groupTable.getValueAt(pos, 4);

            Group group = new Group(name, speciality, form, amountOfStudents, course);
            GroupContainer.removeGroup(pos);
            GroupContainer.addGroup(group);
            Serializer.updateGroupFile();
            initialGroup();

        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null, "Input error:" + e.getMessage() + ". Retry.");
            groupModel.removeRow(groupTable.getRowCount() - 1);
            groups.remove(groups.size() - 1);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error:" + e.getMessage() + ". Retry.");
        }
    }

    protected void setChangeGroup(){
        disableGroupUi();
        this.disableBasicUi();

        setupGroupTable();

        confirmChangeGroup.setVisible(true);
    }

    protected void setConfirmChangeGroup(){
        this.enableBasicUi();
        enableGroupUi();
        viewGroups.setEnabled(false);

        confirmChangeGroup.setVisible(false);
        try {
            int pos = groupTable.getRowCount() - 1;
            String name = (String) groupTable.getValueAt(pos, 0);
            String speciality = (String) groupTable.getValueAt(pos, 1);
            String form = (String) groupTable.getValueAt(pos, 2);
            int amountOfStudents = (Integer) groupTable.getValueAt(pos, 3);
            int course = (Integer) groupTable.getValueAt(pos, 4);

            ArrayList<Student> tTicket = GroupContainer.getGroup(pos).getStudentList();
            Group group = new Group(name, speciality, form, amountOfStudents, course);
            group.setStudentList(tTicket);

            GroupContainer.removeGroup(pos);
            GroupContainer.addGroup(group);
            Serializer.updateGroupFile();
            updateGroupTable();
        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null, "Input error:" + e.getMessage() + ". Retry.");
            groupModel.removeRow(groupTable.getRowCount() - 1);
            groups.remove(groups.size() - 1);
        } finally {
            initialGroup();
        }
    }

    protected void setRemoveGroup(){
        disableGroupUi();
        groupTable.setEnabled(true);
        this.disableBasicUi();
        confirmRemoveGroup.setVisible(true);
    }

    protected void setConfirmRemoveGroup(){
        this.enableBasicUi();
        enableGroupUi();
        viewGroups.setEnabled(false);

        confirmRemoveGroup.setVisible(false);
        try {
            GroupContainer.removeGroup(groupTable.getSelectedRow());
            groupModel.removeRow(groupTable.getSelectedRow());
            Serializer.updateGroupFile();
        } catch (IndexOutOfBoundsException e) {
            JOptionPane.showMessageDialog(null, "Array index out of bounds, retry");
        }
    }

    protected void setAddStudent(){
        disableStudentUi();
        this.disableBasicUi();

        confirmAddStudent.setVisible(true);
        students.add(new Student(selectedGroup, "Surname", "Name", "Patronymic", "dd.MM.yyyy", "дневная", "M", 0));
        studentModel.addRow(new Object[]{});
        confirmAddStudent.setVisible(true);
        setupStudentTable();
    }

    protected void setConfirmAddStudent(){
        this.enableBasicUi();
        enableStudentUi();
        viewStudents.setEnabled(false);

        confirmAddStudent.setVisible(false);
        try {
            int pos = studentTable.getRowCount() - 1;
            String surname=(String)studentTable.getValueAt(pos, 1);
            String name=(String)studentTable.getValueAt(pos,
                    2);
            String patronymic=(String)studentTable.getValueAt(pos, 3);
            String date=(String)studentTable.getValueAt(pos, 4);
            String budget= (String)studentTable.getValueAt(pos, 5);
            String sex=(String)studentTable.getValueAt(pos, 6);
            int examsFailed=(Integer)studentTable.getValueAt(pos, 7);


            Student student = new Student(selectedGroup, surname, name, patronymic, date, budget, sex , examsFailed);
            students.remove(pos);
            students.add(student);
            Serializer.updateGroupFile();
            updateStudentTable();
            initialStudents(selectedGroup);
        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null, "Error:" + e.getMessage());
        }
    }

    protected void setChangeStudent(){
        disableStudentUi();
        this.disableBasicUi();

        setupStudentTable();

        confirmChangeStudent.setVisible(true);
    }

    protected void setConfirmChangeStudent(){
        this.enableBasicUi();
        enableStudentUi();
        viewStudents.setEnabled(false);

        confirmChangeStudent.setVisible(false);
        try {
            int pos = studentTable.getRowCount() - 1;
            String surname=(String)studentTable.getValueAt(pos, 0);
            String name=(String)studentTable.getValueAt(pos, 1);
            String patronymic=(String)studentTable.getValueAt(pos, 2);
            String date=(String)studentTable.getValueAt(pos, 3);
            String budget= (String)studentTable.getValueAt(pos, 4);
            String sex=(String)studentTable.getValueAt(pos, 5);
            int examsFailed=(Integer)studentTable.getValueAt(pos, 6);

            Student student = new Student(selectedGroup, surname, name, patronymic, date, budget, sex , examsFailed);
            students.remove(pos);
            students.add(student);

            Serializer.updateGroupFile();
            updateStudentTable();
        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null, "Error:" + e.getMessage());
            studentModel.removeRow(studentTable.getRowCount()-1);
            students.remove(students.size()-1);
        }
        finally {
            initialStudents(selectedGroup);
        }
    }

    protected void setRemoveStudent(){
        disableStudentUi();
        studentTable.setEnabled(true);
        this.disableBasicUi();
        confirmRemoveStudent.setVisible(true);
    }

    protected void setConfirmRemoveStudent(){
        this.enableBasicUi();
        enableStudentUi();
        viewStudents.setEnabled(false);

        confirmRemoveStudent.setVisible(false);
        try {
            students.remove(studentTable.getSelectedRow());
            studentModel.removeRow(studentTable.getSelectedRow());
            Serializer.updateGroupFile();
        } catch (IndexOutOfBoundsException e) {
            JOptionPane.showMessageDialog(null, "Array index out of bounds, retry");
        }
    }

    protected void viewGroups(){
        enableGroupUi();
        disableGroupUi();
    }

    protected void viewStudents(){
        enableStudentUi();
        disableGroupUi();
    }
    //Al section end

    //Ui
    private void setupManagerTools() {

        managerTools.add(addGroup);
        managerTools.add(changeGroup);
        managerTools.add(removeGroup);

        confirmAddGroup.setVisible(false);
        confirmChangeGroup.setVisible(false);
        confirmRemoveGroup.setVisible(false);

        managerTools.add(confirmAddGroup);
        managerTools.add(confirmChangeGroup);
        managerTools.add(confirmRemoveGroup);


        disableStudentUi();

        managerTools.add(addStudent);
        managerTools.add(changeStudent);
        managerTools.add(removeStudent);

        confirmAddStudent.setVisible(false);
        confirmChangeStudent.setVisible(false);
        confirmRemoveStudent.setVisible(false);

        managerTools.add(confirmAddStudent);
        managerTools.add(confirmChangeStudent);
        managerTools.add(confirmRemoveStudent);

        add(managerTools, BorderLayout.NORTH);

    }

    private void setupGroupTable() {
        groups = GroupContainer.getList();
        groupModel = new GroupTableEditModel(groups);
        groupTable = new JTable(groupModel);

        groupTable.setDragEnabled(false);
        groupTable.getTableHeader().setReorderingAllowed(false);
        groupTable.setAutoCreateRowSorter(true);

        remove(scrollPaneGroups);
        scrollPaneGroups = new JScrollPane(groupTable);
        showGroupTable();
    }

    private void disableGroupUi() {
        addGroup.setEnabled(false);
        changeGroup.setEnabled(false);
        removeGroup.setEnabled(false);
    }

    private void enableGroupUi() {
        addGroup.setEnabled(true);
        changeGroup.setEnabled(true);
        removeGroup.setEnabled(true);
    }

    private void disableStudentUi() {
        addStudent.setEnabled(false);
        changeStudent.setEnabled(false);
        removeStudent.setEnabled(false);
    }

    private void enableStudentUi() {
        addStudent.setEnabled(true);
        changeStudent.setEnabled(true);
        removeStudent.setEnabled(true);
    }

    private void updateGroupTable() {
        int rowCount = groupTable.getRowCount();
        for (int i = rowCount - 1; i >= 0; i--) {
            groupModel.removeRow(i);
        }
        for (int i = 0; i < GroupContainer.getList().size(); i++) {
            groupModel.addRow(new Object[]{});
        }
    }

    private void updateStudentTable() {
        int rowCount = studentTable.getRowCount();
        for (int i = rowCount - 1; i >= 0; i--) {
            studentModel.removeRow(i);
        }
        for (int i = 0; i < selectedGroup.getStudentList().size(); i++) {
            studentModel.addRow(new Object[]{});
        }
    }
    //Ui end
}
