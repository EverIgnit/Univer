import java.util.Scanner;
public class Num1 {
    public static void main(String args[]) {
        int n = args.length-1;
        Array S = new Array(args, n);
        String str;
        str = args[n];
        S.OutP();
        System.out.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        int arr[] = S.AmountOfSubstr(str);
        S.Sort(arr);
        S.OutP();
        System.out.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        arr=S.FirstPosOfSubstr(str);
        S.Sort(arr);
        S.OutP();
    }
}
class Array {
    private String s[];
    private int n;

        Array(String args[], int n) {
        this.n = n;
        s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = args[i];
        }
    }

    public void OutP() {
        for (int i = 0; i < n; i++) {
            System.out.println(s[i]);
        }
    }

    public int[] AmountOfSubstr(String str) {
        int arr[] = new int[n];
        int l = str.length(), count, ind, leng;
        for (int i = 0; i < n; i++) {
            count = 0;
            ind = s[i].indexOf(str, count);
            leng = s[i].length();
            for (int j = 0; j < leng && ind >= 0; j = ind + l) {
                count++;
                ind = s[i].indexOf(str, count);
            }
            arr[i] = count;
        }
        return arr;
    }

    public int[] FirstPosOfSubstr(String str) {
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = s[i].indexOf(str);
        }
        return arr;
    }

    public void Sort(int[] arr) {
        int max, imax, temparr;
        String tempstr;
        for (int i = 0; i < n; i++) {
            max = arr[i];
            imax = i;
            for (int j = i; j < n; j++) {
                if (arr[j] > max) {
                    max = arr[j];
                    imax = j;
                }
            }
            temparr = arr[i];
            arr[i] = arr[imax];
            arr[imax] = temparr;
            tempstr = s[i];
            s[i] = s[imax];
            s[imax] = tempstr;
        }
    }
}