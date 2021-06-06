package com.company;

import javax.swing.*;
import java.io.*;
import java.util.ArrayList;

public class Serializer {

    static void deserializeGroups() {
        try {
            InputStream is = new FileInputStream("C:\\Users\\Admin\\Downloads\\PPSLab5,6\\Files\\Serialized\\Groups.bin");
            ObjectInputStream ois = new ObjectInputStream(is);
            GroupContainer.setList((ArrayList<Group>) ois.readObject());
            is.close();
            ois.close();
        } catch (java.io.FileNotFoundException e) {
            System.out.println("File not found, working with no initial data");
            GroupContainer.setList(new ArrayList<>());
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("No " + e);
            GroupContainer.setList(new ArrayList<>());
        }
    }

    static void updateGroupFile() {
        try {
            String fName = "C:\\Users\\Admin\\Downloads\\PPSLab5,6\\Files\\Serialized\\Groups.bin";
            OutputStream os = new FileOutputStream(fName);
            ObjectOutputStream oos = new ObjectOutputStream(os);
            oos.writeObject(GroupContainer.getList());
            oos.close();
            os.close();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Unable to save groups to file" + e);
        }
    }

    static void updateAccounts() {
        try {
            String fName = "C:\\Users\\Admin\\Downloads\\PPSLab5,6\\Files\\Serialized\\Accounts.bin";
            OutputStream os = new FileOutputStream(fName);
            ObjectOutputStream oos = new ObjectOutputStream(os);
            oos.writeObject(AccountContainer.getAccounts());
            oos.close();
            os.close();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Unable to save accounts to file" + e);
        }
    }

    static void deserializeAccounts() {
        try {
            InputStream is = new FileInputStream("C:\\Users\\Admin\\Downloads\\PPSLab5,6\\Files\\Serialized\\Accounts.bin");
            ObjectInputStream ois = new ObjectInputStream(is);
            AccountContainer.setAccounts((ArrayList<Account>) ois.readObject());
            is.close();
            ois.close();
        } catch (java.io.FileNotFoundException e) {
            System.out.println("Account file not found, continue with no initial data...");
            ArrayList<Account> accounts = new ArrayList<>();
            Account account = new Account("Administrator", "Admin", "Admin");
            accounts.add(account);
            AccountContainer.setAccounts(accounts);
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("No " + e);
            AccountContainer.setAccounts(new ArrayList<>());
        }
    }

}