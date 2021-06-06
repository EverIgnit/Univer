package com.company;

import javax.swing.table.DefaultTableModel;
import java.util.List;

public class StudentTableViewModel extends DefaultTableModel {
    protected List<Student> studentList;

    StudentTableViewModel(List<Student> list) {
        studentList = list;
        addColumn("Group");
        addColumn("Surname");
        addColumn("Name");
        addColumn("Patronymic");
        addColumn("Sex");
        addColumn("BirthDate");
        addColumn("Form");
        addColumn("ExamsFailed");
        setRowCount(list.size());
    }

    @Override
    public Object getValueAt(int row, int col) {
        switch (col) {
            case 0:
                return studentList.get(row).getGroup();
            case 1:
                return studentList.get(row).getSurname();
            case 2:
                return studentList.get(row).getName();
            case 3:
                return studentList.get(row).getPatronymic();
            case 4:
                return studentList.get(row).getSex();
            case 5:
                return studentList.get(row).getDate();
            case 6:
                return studentList.get(row).getBudget();
            default:
                return studentList.get(row).getExamsFailed();
        }
    }

    @Override
    public void setValueAt(Object value, int row, int col) {
        switch (col) {
            case 1:
                studentList.get(row).setSurname((String) value);
                break;
            case 2:
                studentList.get(row).setName((String) value);
                break;
            case 3:
                studentList.get(row).setPatronymic((String) value);
                break;
            case 4:
                studentList.get(row).setSex((String) value);
                break;
            case 5:
                studentList.get(row).setDate((String) value);
                break;
            case 6:
                studentList.get(row).setBudget((String) value);
                break;
            default:
                studentList.get(row).setExamsFailed((Integer) value);
                break;
        }
    }

    @Override
    public Class<?>getColumnClass(int i) {
        if (i == 0) return Group.class;

        if (i == 7) return Integer.class;
        return String.class;
    }

    @Override
    public boolean isCellEditable(int row, int col){
        return false;
    }
}
