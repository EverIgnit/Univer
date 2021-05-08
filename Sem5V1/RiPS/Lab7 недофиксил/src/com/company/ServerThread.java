package com.company;

public class ServerThread implements Runnable {
    private final java.net.Socket socket;

    public ServerThread(java.net.Socket socket) {this.socket = socket;}

    @Override
    public void run() {
        try {
            System.out.println("Mult: " + calc((MyData)new java.io.ObjectInputStream(socket.getInputStream()).readObject()));
        } catch (Exception exception) {
            System.out.printf("Exception1: %s%n",exception);
        }
    }

    private double calc(MyData data) {
        var startTimeMillis = System.nanoTime();

        var workersCount = data.getK();
        var results = new double[workersCount];
        var threads = new Thread[workersCount];
        java.util.stream.IntStream.range(0, workersCount).forEach(i -> {
            threads[i] = new Thread(() -> {
                try {
                    results[i] = calcWorker(i, data);
                } catch (Exception exception) {
                    System.out.println("Exception2: " + exception);
                }
            });

            threads[i].start();
        });

        var result = 0.;
        for (var i = 0; i < workersCount; i++) {
            try {
                threads[i].join();
                result += results[i];
            } catch (Exception exception) {
                System.out.println("Exception3: " + exception);
            }
        }

        System.out.println("Mult time: " + (System.nanoTime() - startTimeMillis));
        return result;
    }

    private double calcWorker(int index, MyData data) throws Exception {
        var workerSocket = new java.net.Socket("localhost", 30001 + index);
        var objectOutputStream = new java.io.ObjectOutputStream(workerSocket.getOutputStream());
        objectOutputStream.writeObject(index);
        objectOutputStream.writeObject(data);
        workerSocket.close();
        return (double) new java.io.ObjectInputStream(workerSocket.getInputStream()).readObject();
    }

}
