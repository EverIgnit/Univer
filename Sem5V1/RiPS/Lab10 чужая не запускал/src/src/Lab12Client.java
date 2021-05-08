package src;

public class Lab12Client {
    public static void main(String[] args) {
        try {
            ((Multiplier) java.rmi.registry.LocateRegistry.getRegistry(null).lookup("Multiplier")).multiply(Integer.parseInt(args[0]),Integer.parseInt(args[1]));
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}