package com.job4;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Reader
{
    private File file;
    protected BufferedReader reader;
    private  String line;
    private boolean error;
    public Reader(String name)
    {
        file = new File(name);
        try
        {
            reader = new BufferedReader(new FileReader(file));
        }
        catch (IOException e)
        {
            error = true;
        }
    }
    public final String read()
    {
        try
        {
            line = reader.readLine();
        } catch (IOException e)
        {
            error = true;
        }
        return line;
    }
    public final boolean isValid()
    {
        return !error;
    }
}
