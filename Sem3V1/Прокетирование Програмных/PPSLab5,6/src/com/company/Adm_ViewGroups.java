package com.company;

import java.awt.event.ActionEvent;

public class Adm_ViewGroups extends U_ViewGroups {

    Adm_ViewGroups(UserWindow window) {
        super(window);
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        window.setViewGroups();
    }
}
