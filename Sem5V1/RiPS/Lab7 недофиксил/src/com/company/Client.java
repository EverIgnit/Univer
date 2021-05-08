package com.company;

public class Client {

    public static void main(String[] args) {
        try {
            var data = new MyData(Integer.parseInt(args[0]),Double.parseDouble(args[1]),Double.parseDouble(args[2]),Double.parseDouble(args[3]),Double.parseDouble(args[4]),Integer.parseInt(args[5]),Integer.parseInt(args[6]),Integer.parseInt(args[7]));
            var startMillis = System.nanoTime();

            System.out.println("Single: " + calcMono(data) + "\nSingle time: " + (System.nanoTime() - startMillis));

            var serverSocket = new java.net.Socket("localhost", 30000);
            new java.io.ObjectOutputStream(serverSocket.getOutputStream()).writeObject(data);
            Thread.sleep(2000);
            serverSocket.close();
        } catch (Exception e) {
            System.out.printf("Exception: %s%n",e);
        }
    }

    private static double calcMono(MyData data) {
        double result = 0,hx = (data.getB() - data.getA()) / data.getN(), hy = (data.getD() - data.getC()) / data.getC(),x = data.getA() + hx / 2;
        for (var i = 0; i < data.getN(); x += hx, i++) {
            double y = data.getC() + hy / 2;
            for (var j = 0; j < data.getM(); y += hy, j++)
                result += data.calc(x, y);
        }
        return result* hx * hy;
    }
}
