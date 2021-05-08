package com.company;

public class Server {

    public static void main(String[] args) {
        try {
            var serverSocket = new  java.net.ServerSocket(30000);

            System.out.println("Server has started...");
            while(true)
                new Thread(new ServerThread(serverSocket.accept())).start();
            //System.out.println("Server has stopped");
        } catch (Exception exception) {
            System.out.printf("Exception: %s%n", exception);
        }
    }
}
