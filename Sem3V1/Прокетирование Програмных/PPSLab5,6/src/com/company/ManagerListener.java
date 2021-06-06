package com.company;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ManagerListener implements ActionListener {
    private ManagerWindow instance;
    private int action;

    ManagerListener(ManagerWindow instance, int action) {
        this.instance = instance;
        this.action = action;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        if (action == 0)
            instance.addGroup();
        else if (action == 1)
            instance.setConfirmAddGroup();
        else if (action == 2)
            instance.setChangeGroup();
        else if (action == 3)
            instance.setConfirmChangeGroup();
        else if (action == 4)
            instance.setRemoveGroup();
        else if (action == 5)
            instance.setConfirmRemoveGroup();
        else if (action == 6)
            instance.setAddStudent();
        else if (action == 7)
            instance.setConfirmAddStudent();
        else if (action == 8)
            instance.setChangeStudent();
        else if (action == 9)
            instance.setConfirmChangeStudent();
        else if (action == 10)
            instance.setRemoveStudent();
        else if (action == 11)
            instance.setConfirmRemoveStudent();
        else if (action == 12)
            instance.viewStudents();
        else if (action == 13)
            instance.viewGroups();
    }
}
