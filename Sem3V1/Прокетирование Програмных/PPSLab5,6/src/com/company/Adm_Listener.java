package com.company;

import java.awt.event.ActionEvent;

public class Adm_Listener extends Adm_ViewUsers {
    private final int action;

    Adm_Listener(AdminWindow adm, int action) {
        super(adm);
        this.action = action;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        //add user
        switch (action) {
            case 0:
                instance.addUser();
                break;
            case 1:
                instance.confirmAdd();
                break;
            case 2:
                instance.changeUser();
                break;
            case 3:
                instance.confirmChange();
                break;
            case 4:
                instance.removeUser();
                break;
            case 5:
                instance.confirmRemove();
                break;
        }
    }

}