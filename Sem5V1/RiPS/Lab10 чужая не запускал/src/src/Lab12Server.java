package src;

public class Lab12Server extends MatrixMultiplier {
    public static void main(String[] args) throws Exception {
        int n, K;
        var scanner = new java.util.Scanner(System.in);
        System.out.println("Square matrix multiplication:\nSquare matrix size:");
        n = Integer.parseInt(scanner.nextLine());
        System.out.print("Threads used:");
        K = Integer.parseInt(scanner.nextLine());
        int size = n * n;
        int[] A = new int[size], B = new int[size], C = new int[size];

        var random = new java.util.Random();
        for (var i = 0; i < size; i++) {
            A[i] = random.nextInt(1000);
            B[i] = random.nextInt(1000);
            C[i] = 0;
        }
        MatrixMultiplier.A = A; MatrixMultiplier.B = B; MatrixMultiplier.C = C; MatrixMultiplier.n = n;
        int[] Start = new int[K], End = new int[K];

        java.rmi.registry.LocateRegistry.getRegistry().rebind("Multiplier", (Multiplier) java.rmi.server.UnicastRemoteObject.exportObject(new MatrixMultiplier(), 0));
        System.err.println("Server ready");

        int q = n / K, r = n % K;
        Start[0] = 0;
        for (var i = 0; i < K; i++) {
            End[i] = Start[i] + q + (i < r ? 1 : 0);
            if (i < K - 1)
                Start[i + 1] = End[i];
        }

        Runtime.getRuntime().exec(("java src/Lab12Client 0 " + n)).waitFor();
        System.out.println("Single thread done");
        MatrixMultiplier.getResult("./single.txt");
        for (var i = 0; i < size; i++)
            MatrixMultiplier.C[i] = 0;

        var ClientProcesses = new Process[K];
        for (var i = 0; i < K; i++)
            ClientProcesses[i] = Runtime.getRuntime().exec(("java src/Lab12Client " + Start[i] + " " + End[i]));
        for (var process : ClientProcesses)
            process.waitFor();
        MatrixMultiplier.getResult("./mult.txt");
        System.out.println("Multithreading Done");
        System.exit(0);
    }
}