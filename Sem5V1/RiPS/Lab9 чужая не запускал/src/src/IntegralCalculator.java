package src;

public class IntegralCalculator implements Calculator {
    private static double result = 0;

    public static double getResult() {
        return result;
    }

    @Override
    public double integral(double a, double c, int lower, int upper, int m, int function, double h1, double h2) {
        double accumulator = 0;
        for (int i = lower; i < upper; i++) {
            double x = a + h1 * (i + 0.5);

            for (int j = 0; j < m; j++) {
                double y = c + h2 * (j + 0.5);
                double val = Math.exp(x) * Math.sin(y) * h1 * h2;
                switch (function){
                    case 4:
                        val = Math.exp(Math.cos(x * x + y)) * h1 * h2;
                        break;
                    case 2:
                        val = Math.sin(x + 2 * y) * h1 * h2;
                        break;
                    case 3:
                        val = Math.cos(x * Math.exp(y)) * h1 * h2;
                        break;
                }
                accumulator += val;
            }
        }
        result += accumulator;
        return accumulator;
    }
}