package com.company;

public class MyData implements java.io.Serializable {
    private final int[][] A, B;
    private final int K;

    public MyData(int K, int[][] A, int[][] B) {
        this.K = K;
        this.A = A;
        this.B = B;
    }

    public int[][] getA() {
        return A;
    }
    public int[][] getB() {
        return B;
    }
    public int getK() {
        return K;
    }
}
