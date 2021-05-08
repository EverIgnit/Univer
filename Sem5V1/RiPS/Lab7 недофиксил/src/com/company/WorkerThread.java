package com.company;

public class WorkerThread implements Runnable {
    private final java.net.Socket socket;

    WorkerThread(java.net.Socket socket) {this.socket = socket;}

    @Override
    public void run() {
        try {
            var objectInputStream = new java.io.ObjectInputStream(socket.getInputStream());
            new java.io.ObjectOutputStream(socket.getOutputStream()).writeObject(calc((int) objectInputStream.readObject(), (MyData) objectInputStream.readObject()));
            socket.close();
        } catch (Exception exception) {
            System.out.printf("Exception: %s%n",exception);
        }
    }

    private double calc(int index, MyData data) {

        double result = 0d, hx = (data.getB() - data.getA()) / data.getN(), hy = (data.getD() - data.getC()) / data.getM();

        int rectCount = data.getN() / data.getK(), ost = data.getN() % data.getK(), startRect = rectCount * index;
        if (index < ost) startRect+=index;
        startRect += Math.min(index, ost);

        double x = data.getA() + hx / 2 + startRect * hx;

        for (int i = startRect, length = startRect + rectCount; i < length; x += hx, i++) {
            double y = data.getC() + hy / 2;
            for (int j = 0; j < data.getM(); y += hy, j++)
                result += data.calc(x, y);
        }
        return result * hx * hy;
    }
}