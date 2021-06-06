package com.company;

import java.io.Serializable;

public class Account implements Serializable {
    private String type;
    private String login;
    private String password;

    Account(String type, String login, String password) {
        this.type = type;
        this.login = login;
        this.password = password;
    }

    Account(String login, String password){
        this.login=login;
        this.password=password;
    }

    boolean checkPassword(String password) {
        return this.password.equals(password);
    }

    boolean checkLogin(String login) {
        return this.login.equals(login);
    }

    String getType() {
        return type;
    }

    String getLogin(){
        return login;
    }

    String getPassword(){
        return password;
    }
}
