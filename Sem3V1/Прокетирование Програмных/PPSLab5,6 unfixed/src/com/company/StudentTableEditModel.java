package com.company;

import java.util.List;

public class StudentTableEditModel extends StudentTableViewModel{
    StudentTableEditModel(List<Student> list){
        super(list);
    }
    @Override
    public boolean isCellEditable(int row, int col){
        return col!=0;
    }

}