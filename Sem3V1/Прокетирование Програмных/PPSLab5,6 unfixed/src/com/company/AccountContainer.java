package com.company;

import java.util.ArrayList;

public class AccountContainer {
    private static ArrayList<Account> accounts = new ArrayList<>();

    //Methods
    static void addAccount(String type, String login, String password) {
        accounts.add(new Account(type, login, password));
    }

    static void removeAccount(int index) {
        accounts.remove(index);
    }

    static String getAccountType(int index) {
        return accounts.get(index).getType();
    }

    static int findAccount(Account account) {
        for (Account listAccount : accounts) {
            if (listAccount.checkLogin(account.getLogin()) && listAccount.checkPassword(account.getPassword()))
                return getPos(listAccount);
        }
        return -1;
    }

    static int getPos(Account account){
        return accounts.indexOf(account);
    }

    static int getListSize(){
        return accounts.size();
    }

    public static String getLogin(int i) {
        return accounts.get(i).getLogin();
    }

    public static String getRights(int i) {
        return accounts.get(i).getType();
    }

    public static String getPassword(int i) {
        return accounts.get(i).getPassword();
    }

    public static void setAccounts(ArrayList<Account> list){
        accounts=list;
    }

    public static ArrayList<Account> getAccounts(){
        return accounts;
    }

    public static Account getAccount(int index) {
        return accounts.get(index);
    }
}
