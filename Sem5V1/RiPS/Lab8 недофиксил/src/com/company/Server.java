package com.company;

public class Server {
    public static void main(String[] args) {
        try {
            System.out.println("Server started");
            while (true)
                new Thread(new ServerThread(new java.net.ServerSocket(30000).accept())).start();
        } catch (Exception exception) {
            System.out.printf("Exception: %s", exception);
        }
    }
}
