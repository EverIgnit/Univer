package com.company;

public class ServerThread implements Runnable {

    private final java.net.Socket socket;

    public ServerThread(java.net.Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            com.company.Client.printMatrix(calc((MyData) new java.io.ObjectInputStream(socket.getInputStream()).readObject()),"multi.txt" );
        } catch (Exception exception) {
            System.out.printf("Exception1: %s%n",exception);
        }
    }

    private int[][] calc(MyData data) {
        var startTimeMillis = System.currentTimeMillis();
        var workersCount = data.getK();
        var n = data.getA().length;
        var results = new int[workersCount][n][n];
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

        var result = new int[n][n];
        for (var t = 0; t < workersCount; t++) {
            try {
                threads[t].join();
                for (var i = 0; i < n; i++)
                    for (var j = 0; j < n; j++)
                        result[i][j] += results[t][i][j];
            } catch (Exception exception) {
                System.out.println("Exception3: " + exception);
            }
        }
        System.out.println("multi time: " + (System.currentTimeMillis() - startTimeMillis));
        return result;
    }

    private int[][] calcWorker(int index, MyData data) throws Exception {
        var workerSocket = new java.net.Socket("localhost", 30001 + index);
        var objectOutputStream = new java.io.ObjectOutputStream(workerSocket.getOutputStream());
        objectOutputStream.writeObject(index);
        objectOutputStream.writeObject(data);
        var result = (int[][]) new java.io.ObjectInputStream(workerSocket.getInputStream()).readObject();
        workerSocket.close();
        return result;
    }

}
