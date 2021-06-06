package com.company;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public abstract class AbstractUser extends JFrame {
    protected String Login;
    protected DefaultTableModel groupModel;
    protected DefaultTableModel studentModel;

    protected abstract void setLogin(String Login);

    protected abstract String getRights();

}