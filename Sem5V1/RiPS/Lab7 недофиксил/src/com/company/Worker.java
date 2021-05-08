package com.company;

public class Worker {
    public static void main(String[] args) {
        try {
            var port = Integer.parseInt(args[0]);

            System.out.println("Worker is started on port: " + port);
            while(true)
                new Thread(new WorkerThread(new java.net.ServerSocket(port).accept())).start();
        } catch (Exception exception) {
            System.out.printf("Exception: %s%n",exception);
        }
    }
}
