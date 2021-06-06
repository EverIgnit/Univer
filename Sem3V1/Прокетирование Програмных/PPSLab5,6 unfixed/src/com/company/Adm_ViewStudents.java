package com.company;

import java.awt.event.ActionEvent;

public class Adm_ViewStudents extends U_ViewStudents {


    Adm_ViewStudents(UserWindow frame) {
        super(frame);
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        window.setViewStudents();
    }
}