package com.company;

import java.util.ArrayList;


public class GroupContainer {
    private static ArrayList<Group> list = new ArrayList<>();

    static void addGroup(Group group) {
        list.add(group);


    }

    static void removeGroup(int pos) {
        list.remove(pos);
    }

    static Group getGroup(int pos) {
        return list.get(pos);
    }

    static ArrayList<Group> getList() {
        return list;
    }

    static void setList(ArrayList<Group> newList) {
        list = newList;
    }


}
