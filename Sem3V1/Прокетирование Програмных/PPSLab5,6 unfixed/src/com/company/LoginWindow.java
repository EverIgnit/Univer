package com.company;
import javax.swing.*;
import java.awt.*;

class LoginWindow extends JFrame {

    LoginWindow() {
        super("Login");

        JTextField login = new JTextField(20);
        JPasswordField password = new JPasswordField(20);
        JPanel panel = new JPanel();
        JButton Log_In = new JButton("Log in");
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        setBounds(dim.width / 2 - 150, dim.height / 2 - 70, 300, 140);
        setResizable(false);
        setLayout(new BorderLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        panel.add(new JLabel("Login:"));
        panel.add(login);
        panel.add(new JLabel("Password:"));
        panel.add(password);
        panel.add(Log_In);
        add(panel);
        Log_In.addActionListener(new Login(login, password));
        pack();
        validate();
        setVisible(true);

    }
}