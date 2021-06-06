package com.company;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class U_ViewStudents implements ActionListener {
    protected UserWindow window;

    U_ViewStudents(UserWindow frame) {
        this.window = frame;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        window.setViewStudents();
    }
}
