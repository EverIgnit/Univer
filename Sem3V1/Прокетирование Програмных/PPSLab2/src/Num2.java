import java.util.Scanner;
public class Num2 {
    public static final String SUBSTR_1 = "/*";
    public static final String SUBSTR_2 = "*/";
    public static void main(String args[]) {
        System.out.printf("Enter the string with '%s', '%s' symbols\n", SUBSTR_1, SUBSTR_2);
        Scanner sc = new Scanner(System.in);
        StringBuilder s = new StringBuilder(sc.nextLine());
        int ind1 = 0, ind2;
        while((ind1 = s.indexOf(SUBSTR_1, ind1)) != -1) {
            ind2 = s.indexOf(SUBSTR_2, ind1 + SUBSTR_1.length());
            s.delete(ind1, ind2 + 2);
        }
        System.out.println(s);
    }
}