import by.vsu.mf.ai.ssd.strings.Job;
import by.vsu.mf.ai.ssd.strings.Manager;
import java.util.Scanner;

 public class Num3 {
    public static void main(String args[]){
        ChangeString A=new ChangeString();
        Manager.createWindow(A);
    }
}

class ChangeString implements Job {
    public static final String SUBSTR_1 = "/*";
    public static final String SUBSTR_2 = "*/";
     public void perform(StringBuilder s){
         int ind1 = 0, ind2;
         while((ind1 = s.indexOf(SUBSTR_1, ind1)) != -1) {
             ind2 = s.indexOf(SUBSTR_2, ind1 + SUBSTR_1.length());
             s.delete(ind1, ind2 + 2);
         }
     }
}