package com.company;

public class MyData implements java.io.Serializable {
    final double a, b, c, d;
    final int K, n, m, funcNumber;

    public MyData(int K,double a,double b,double c,double d,int n,int m,int funcNumber) {
        this.K = K;
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.n = n;
        this.m = m;
        this.funcNumber = funcNumber;
    }

    public int getK() {
        return K;
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }

    public double getD() {
        return d;
    }

    public int getN() {
        return n;
    }

    public int getM() {
        return m;
    }

    public double calc(double x, double y) {
        switch (funcNumber) {
            case 2:
                return Math.sin(x + 2 * y);
            case 3:
                return Math.cos(x * Math.exp(y));
            case 4:
                return Math.exp(Math.cos(x * x + y));
            default:
                return Math.exp(x) * Math.sin(y);
        }
    }
}