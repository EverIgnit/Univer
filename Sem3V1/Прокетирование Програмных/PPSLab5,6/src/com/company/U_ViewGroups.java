package com.company;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class U_ViewGroups implements ActionListener {
    protected UserWindow window;

    U_ViewGroups(UserWindow window){
        this.window=window;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        window.setViewGroups();
    }
}
