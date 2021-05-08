package src;

public class Lab11Client {

    public static void main(String[] args) {
        try {
            ((Calculator) java.rmi.registry.LocateRegistry.getRegistry(null).lookup("Calculator")).integral( Double.parseDouble(args[0]), Double.parseDouble(args[1]), Integer.parseInt(args[2]), Integer.parseInt(args[3]), Integer.parseInt(args[4]), Integer.parseInt(args[5]), Double.parseDouble(args[6]), Double.parseDouble(args[7]));
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
