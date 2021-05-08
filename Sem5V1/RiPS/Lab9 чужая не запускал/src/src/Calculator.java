package src;

public interface Calculator extends java.rmi.Remote {
    double integral(double a, double c, int lower, int upper, int m, int function, double h1, double h2) throws java.rmi.RemoteException;
}