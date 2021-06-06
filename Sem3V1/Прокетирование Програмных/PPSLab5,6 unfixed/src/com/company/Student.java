package com.company;

import javax.swing.*;
import java.io.Serializable;

public class Student implements Serializable {
    private Group group;
    private String surname, name, patronymic, date, budget, sex;
    private int examsFailed;

    Student(Group group, String surname, String name, String patronymic, String date, String budget, String sex, int examsFailed) {
        setGroup(group);
        setSurname(surname);
        setName(name);
        setPatronymic(patronymic);
        setDate(date);
        setExamsFailed(examsFailed);
        setBudget(budget);
        setSex(sex);
    }

    public Group getGroup() {
        return group;
    }

    public String getSurname() {
        return surname;
    }

    public String getName() {
        return name;
    }

    public String getPatronymic() {
        return patronymic;
    }

    public String getDate() {
        return date;
    }

    public String getBudget() {
        return budget;
    }

    public String getSex() {
        return sex;
    }

    public int getExamsFailed() {
        return examsFailed;
    }

    public void setGroup(Group group) {
        this.group = group;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPatronymic(String patronymic) {
        this.patronymic = patronymic;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setSex(String sex) {
        sex = sex;
    }

    public void setBudget(String budget) {
        budget = budget;
    }

    public void setExamsFailed(int examsFailed) {
        if (examsFailed > 2 || examsFailed < 0) {
            JOptionPane.showMessageDialog(null,
                    "Invalid Amount of exams failed!" +
                            "Set Default 2!");
            this.examsFailed = 2;
        } else
            this.examsFailed = examsFailed;
    }

}