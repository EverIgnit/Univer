package com.company;

public class Client {
    public static void main(final String[] args) {
        try {
            int K = Integer.parseInt(args[0]), n = Integer.parseInt(args[1]);
            int[][] A = new int[n][n], B = new int[n][n];
            var rand = new java.util.Random();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    A[i][j] = rand.nextInt(10);
                    B[i][j] = rand.nextInt(10);
                }
            printMatrix(A,"A.txt" );
            printMatrix(B,"B.txt" );

            var data = new MyData(K, A, B);
            calcSingle(data);
            final var serverSocket = new java.net.Socket("localhost", 30000);
            new java.io.ObjectOutputStream(serverSocket.getOutputStream()).writeObject(data);
        } catch (Exception exception) {
            System.out.printf("Exception: %s", exception);
        }
    }

    private static void calcSingle(MyData data) {
        int[][] A = data.getA(), B = data.getB();
        var n = A.length;
        var C = new int[n][n];

        var st = System.currentTimeMillis();
        for (var i = 0; i < n; i++)
            for (var j = 0; j < n; j++)
                for (var t = 0; t < n; t++)
                    C[i][j] += A[i][t] * B[t][j];
        System.out.println("Single time: " + (System.currentTimeMillis() - st));
        printMatrix(C, "Single.txt");
    }

    public static void printMatrix(int[][] matrix, String fileName) {
        try {
            var printWriter = new java.io.PrintWriter(new java.io.FileWriter(fileName));
            for (var i = 0; i < matrix.length; printWriter.println(), i++)
                for (var j = 0; j < matrix.length; j++)
                    printWriter.print(matrix[i][j] + " ");
            printWriter.close();
        } catch (java.io.IOException e) {
            System.out.println("IO exception: " + e);
        }
    }
}
