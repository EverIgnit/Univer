package com.company;

import javax.swing.*;
import java.io.Serializable;
import java.util.ArrayList;

public class Group implements Comparable<Group>, Serializable {
    private String name, speciality, form;
    private Integer amountOfStudents, course;
    private ArrayList<Student> studentList;

    @Override
    public String toString() {
        return Integer.toString(amountOfStudents);
    }

    @Override
    public int compareTo(Group group) {
        return (this.toString().compareTo(group.toString()));
    }

    Group(String name, String speciality, String form, int amountOfStudents, int course) {
        setName(name);
        setSpeciality(speciality);
        setForm(form);
        setAmountOfStudents(amountOfStudents);
        setStudentList(new ArrayList<>());
        setCourse(course);
    }

    public ArrayList<Student> getStudentList() {
        return studentList;
    }

    public int getAmountOfStudents() {
        return amountOfStudents;
    }

    public int getCourse() {
        return course;
    }

    public String getName() {
        return name;
    }

    public String getSpeciality() {
        return speciality;
    }

    public String getForm() {
        return form;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAmountOfStudents(int amountOfStudents) {
        if (amountOfStudents < 0 || amountOfStudents > 20) {
            if (amountOfStudents > 30 && !form.equals("бюджет")) {
                this.amountOfStudents = amountOfStudents;
                return;
            }
            JOptionPane.showMessageDialog(null,
                    "Invalid amount of students" +
                            "Set Default 20!");
            this.amountOfStudents = 20;
        } else
            this.amountOfStudents = amountOfStudents;
    }

    public void setCourse(int course) {
        if (course < 0 || course > 6) {
            JOptionPane.showMessageDialog(null,
                    "Invalid course value" +
                            "Set Default 1!");
            this.course = 1;
        } else
            this.course = course;
    }

    public void setSpeciality(String speciality) {
        this.speciality = speciality;
    }

    public void setStudentList(ArrayList<Student> studentList) {
        this.studentList = studentList;
    }

    public void setForm(String form) {
        if (!form.equals("бюджет") && !form.equals("вне бюджет")) {
            JOptionPane.showMessageDialog(null,
                    "Invalid form" +
                            "Set Default бюджет!");
            this.form = "бюджет";
        } else
            this.form = form;
    }

}