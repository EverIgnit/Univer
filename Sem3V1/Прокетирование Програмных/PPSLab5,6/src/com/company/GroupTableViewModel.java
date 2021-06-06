package com.company;

import javax.swing.table.DefaultTableModel;
import java.util.List;

class GroupTableViewModel extends DefaultTableModel {
    protected List<Group> groups;

    GroupTableViewModel(List<Group> groups) {
        this.groups = groups;
        addColumn("Name");
        addColumn("Speciality");
        addColumn("Form");
        addColumn("StudAmount");
        addColumn("Course");
        setRowCount(groups.size());
    }

    @Override
    public Object getValueAt(int row, int column) {
        switch (column) {
            case 0:
                return groups.get(row).getName();
            case 1:
                return groups.get(row).getSpeciality();
            case 2:
                return groups.get(row).getForm();
            case 3:

                return groups.get(row).getAmountOfStudents();
            default:
                return groups.get(row).getCourse();
        }
    }

    @Override
    public Class<?> getColumnClass(int index) {
        switch (index) {
            case 3:
            case 4:
                return Integer.class;
            default:
                return String.class;
        }
    }

    @Override
    public void setValueAt(Object value, int row, int col) {
        switch (col) {
            case 0:
                groups.get(row).setName((String) value);
                break;
            case 1:
                groups.get(row).setSpeciality((String) value);
                break;
            case 2:
                groups.get(row).setForm((String) value);
                break;
            case 3:
                groups.get(row).setAmountOfStudents((Integer) value);
                break;
            default:
                groups.get(row).setCourse((Integer) value);
                break;
        }
    }
}