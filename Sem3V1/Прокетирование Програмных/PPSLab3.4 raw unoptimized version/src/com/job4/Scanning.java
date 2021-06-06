package com.job4;

import java.io.*;

public class Scanning
{
    public String getInputString()
    {
        String input = null;
        try
        {
            BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
            input = is.readLine();
            if(input.length() == 0)
                return null;
        }
        catch(IOException e)
        {
            System.out.println(e);
        }
        return input;
    }
}
