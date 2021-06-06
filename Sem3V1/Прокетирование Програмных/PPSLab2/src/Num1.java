import java.util.Arrays;
import java.util.Comparator;

public class Num1 {
    public static void main(String args[]) {
        int n = args.length - 1;
        String[] S = new String[n];
        for (int i = 0; i < n; i++) {
            S[i]=args[i];
            System.out.println(S[i]);
        }
        String sub = args[n];
        System.out.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        Arrays.sort(S, new StringComparatorByAmount(sub));
        for (int i = 0; i < n; i++) {
            System.out.println(S[i]);
        }
        System.out.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        Arrays.sort(S, new StringComparatorByPos(sub));
        for (int i = 0; i < n; i++) {
            System.out.println(S[i]);
        }
    }
}

class StringComparatorByAmount implements Comparator<String> {
    private String sub;

    StringComparatorByAmount(String sub) {
        this.sub = sub;
    }

    public int compare(String s1, String s2) {
        return count(s1) - count(s2);
    }
    private int count(String s) {
        int ind = 0, count = 0;
        while ((ind = s.indexOf(sub, ind)) >= 0) {
            count++;
            ind++;
        }
        return count;
    }
}

class StringComparatorByPos implements Comparator<String> {
    private String sub;

    StringComparatorByPos(String sub) {
        this.sub = sub;
    }

    public int compare(String s1, String s2) {
        Integer A = (s1.indexOf(sub));
        return A.compareTo(s2.indexOf(sub));
//        return s1.indexOf(sub)-s2.indexOf(sub);
    }
}