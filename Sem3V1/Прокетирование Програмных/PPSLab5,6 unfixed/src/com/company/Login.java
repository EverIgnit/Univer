package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Login implements ActionListener {
    private JTextField loginField;
    private JPasswordField passField;

    Login(JTextField loginField, JPasswordField passField){
        this.loginField = loginField;
        this.passField = passField;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        try {
            String name = loginField.getText();
            String pass = String.valueOf(passField.getPassword());

            if (name.isEmpty() || pass.isEmpty()) {
                throw new NullPointerException("Empty lines, check input");
            }

            loginField.setText("");
            passField.setText("");

            Account user = new Account(name, pass);
            String type;
            int pos = AccountContainer.findAccount(user);
            if (pos != -1)
                type = AccountContainer.getAccountType(pos);
            else throw new NullPointerException("No account found, retry or contact the \"Admin\" entity");

            Account account = AccountContainer.getAccount(pos);

            if (!account.getPassword().equals(pass) && !account.getLogin().equals(name)) {
                JOptionPane.showMessageDialog(null,"Invalid login/password");
                return;
            }
            if (type.equals("User")) {
                new UserWindow(name);
                return;
            }
            if(type.equals("Administrator")){
                new AdminWindow(name);
                return;
            }
            if(type.equals("Manager")){
                new ManagerWindow(name);
            }


        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null, "Error: " + e.getMessage());
        }
    }

}
