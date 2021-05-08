package src;

public interface Multiplier extends java.rmi.Remote {
    void multiply(int Start, int End) throws java.rmi.RemoteException;
}