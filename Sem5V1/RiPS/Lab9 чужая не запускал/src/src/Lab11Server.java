package src;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

public class Lab11Server extends IntegralCalculator{
    private static Process runProcess(String command) throws Exception {
        return Runtime.getRuntime().exec(command);
    }

    public static void main(String[] args) {
        try {

            LocateRegistry.getRegistry().rebind("Calculator",  UnicastRemoteObject.exportObject(new IntegralCalculator(), 0));
            System.err.println("Server ready");
            double a, b, c, d;
            int n, m, K, function;
            var scanner = new Scanner(System.in);
			
            System.out.print("K, a, b, c, d, n, m");
            K = Integer.parseInt(scanner.nextLine());
            if (K<0) {K=7;a=1;b=2;c=3;d=4;n=5;m=6;}
            else {a = Double.parseDouble(scanner.nextLine());b = Double.parseDouble(scanner.nextLine());c = Double.parseDouble(scanner.nextLine());d = Double.parseDouble(scanner.nextLine());n = Integer.parseInt(scanner.nextLine());m = Integer.parseInt(scanner.nextLine());}

            System.out.print("Function # (1-4):");
            function = Integer.parseInt(scanner.nextLine());

            int Qx = n / K, // остаток x, доля на thread
                    Rx = n % K;

            double h1 = (b - a) / n;
            double h2 = (d - c) / m;



            String params;

            Process[] ClientProcesses = new Process[K];
            int lower = 0;
            for (int i = 0; i < K; i++) {
                int upper = lower + Qx + (i < Rx ? 1 : 0);
				
                params = a + " " + c + " " + lower + " " + upper + " " + m + " " + function + " " + h1 + " " + h2;

                ClientProcesses[i] = runProcess("java src/Lab11Client " + params);

                lower = upper;
            }

            for (var process : ClientProcesses) {
                process.waitFor();
            }

            System.out.println("Result: " + IntegralCalculator.getResult());
            System.out.print("Press enter to leave.");
            scanner.nextLine();
            System.exit(0);
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}