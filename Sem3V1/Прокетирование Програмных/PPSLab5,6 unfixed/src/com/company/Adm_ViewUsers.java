package com.company;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Adm_ViewUsers implements ActionListener {
    AdminWindow instance;

    Adm_ViewUsers(AdminWindow adm){
        instance = adm;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        instance.viewUsers();
    }
}
