package com.company;

public class WorkerThread implements Runnable {
    private final java.net.Socket socket;

    WorkerThread(java.net.Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            var objectInputStream = new java.io.ObjectInputStream(socket.getInputStream());
            new java.io.ObjectOutputStream(socket.getOutputStream()).writeObject(calc((int)objectInputStream.readObject(), (MyData) objectInputStream.readObject()));
            socket.close();
        } catch (Exception exception) {
            System.out.printf("Exception: %s%n",exception);
        }
    }

    private int[][] calc(int index, MyData data) {
        int[][] A = data.getA(), B = data.getB();
        var n = A.length;
        var C = new int[n][n];
        for (int x = (n * n) / data.getK(), y = (n * n) % data.getK(), rectCount = x, startRect = index * (index < y? ++rectCount: y + x), i = startRect / n, j = startRect % n, counter = 0;counter < rectCount;counter++) {
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
            if (++j == n) {
                j = 0;
                i++;
            }
        }
        return C;
    }
}