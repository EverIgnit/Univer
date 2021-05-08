package src;

public class MatrixMultiplier implements Multiplier {
    static int[] A, B, C;
    static int n;

    @Override
    public void multiply(int Start, int End) {
        for (int i = Start; i < End; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    C[i * n + j] += A[i * n + k] * B[k * n + j];
    }

    public static void getResult(String pathname) throws java.io.IOException {
        try {
            var outputFile = new java.io.File(pathname);
            if (outputFile.exists() && !outputFile.delete()) throw new java.io.IOException("failed to delete file");
        } catch (java.io.IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        var outputWriter = new java.io.FileWriter(pathname);
        for (var i = 0; i < n; outputWriter.write("\n"), i++)
            for (var j = 0; j < n; j++)
                outputWriter.write(String.format("%-9d", C[i * n + j]));
        outputWriter.close();
    }
}