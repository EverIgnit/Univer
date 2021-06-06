import java.util.Random;
import java.util.Scanner;

public class Menu {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        byte option = 1;
        Logic logic = new Logic();
        boolean IsExecutedForTheFirstTime = true;
        while (true) {
            System.out.println("Choose the option:\n 1. Fill the array randomly\n" +
                    " 2. Enter the array\n 3. Display the array\n 4. Sum till the positive sin\n" +
                    " 5. Delete all the even elements\n 6. To Exit");
            option = sc.nextByte();
            if (IsExecutedForTheFirstTime) {
                if (option > 2 && option != 6) {
                    System.out.println("ERROR! Fill the array first!");
                    continue;
                } else {
                    IsExecutedForTheFirstTime = false;
                }
            }
            switch (option) {
                case 1:
                    logic.FillArray();
                    break;
                case 2:
                    logic.EnterTheArray();
                    break;
                case 3:
                    logic.DisplayTheArray();
                    break;
                case 4:
                    logic.Sum();
                    break;
                case 5:
                    logic.Delete();
                    break;
                case 6:
                    System.out.println("The program has been finished");
                    return;
                default:
                    System.out.println("ERROR! Enter a number from 1 to 6!");
                    break;
            }
        }
    }
}

class Logic {
    double[] arr;
    byte n;

    public void FillArray() {
        if (arr != null) arr = null;
        Random rand = new Random();
        Scanner sc1 = new Scanner(System.in);
        System.out.println("Enter the amount of elements");
        n = sc1.nextByte();
        if (n < 1){ System.out.println("ERROR! Incorrect value!"); return;}
        arr = new double[n];
        for (byte i = 0; i < n; i++) {
            arr[i] = 100 * rand.nextDouble()-50;
        }
    }

    public void EnterTheArray() {
        if (arr != null) arr = null;
        Scanner sc2 = new Scanner(System.in);
        System.out.println("Enter the number of elements, then initialize them");
        n = sc2.nextByte();
        if (n < 1){ System.out.println("ERROR! Incorrect value!"); return;}
        arr = new double[n];
        for (byte i = 0; i < n; i++) {
            arr[i] = sc2.nextDouble();
        }
    }

    public void DisplayTheArray() {
        for (byte i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public void Sum() {
        double sum = 0;
        for (byte i = 0; i < n; i++) {
            if (Math.sin(Math.toRadians(arr[i])) > 0) {
                break;
            }
            sum += arr[i];
        }
        System.out.println("Sum = " + sum);
    }

    public void Delete() {
        for (byte i = 0; i < n; i++) {
            if (((int)arr[i]) % 2 == 0) {
                for(byte j=i;j<n-1;j++){
                    arr[j]=arr[j+1];
                }
                n--;
            }
        }
    }
}