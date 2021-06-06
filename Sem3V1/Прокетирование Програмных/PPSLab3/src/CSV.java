import java.io.*;

public class CSV {
    public static void main(String args[]) {
        BufferedReader buffReader = null;
        try {
            String Line;
            byte n = 0, m=0;
            Reader reader = new FileReader("file.csv");
            buffReader = new BufferedReader(reader);
            while ((Line = buffReader.readLine()) != null) {
                n++;
            }
            String S[] = new String[n];
            byte k=0;
            while ((Line = buffReader.readLine()) != null) {
                S[k] = buffReader.readLine();
                k++;
            }
            for(byte i=0;i<S[0].length();i++) {
                if (S[0].charAt(i) == ';') {
                    m++;
                }
            }
            String[] arrstr[]=new String[n][m];
            int arr[][]=new int[n][m];
            for(byte i=0;i<n;i++) {
                for (byte j = 0; j < m; j++) {
                    arrstr[i]=S[i].split(";");
                    arr[i][j]=Integer.parseInt(arrstr[i][j]);
                }
            }
            //=-=-=-=-=-=-=-=-=-=-=
            int max=arr[0][0], iMaxI=0,iMaxJ=0;
            for(byte i=0;i<n;i++){
                for(byte j=0;j<m;j++){
                    if(arr[i][j]>=max){
                        max=arr[i][j];
                        iMaxI=i;
                        iMaxJ=j;
                    }
                }
            }
            int min=arr[0][0], iMinI=0, iMinJ=0;
            for(byte i=0;i<iMaxI;i++){
                for(byte j=0;j<iMaxJ;j++){
                    if(arr[i][j]<min){
                        max=arr[i][j];
                        iMinI=i;
                        iMinJ=j;
                    }
                }
            }
            System.out.println("Max = " + max + " with index [" + iMaxI + "][" + iMaxJ + "], Min = " + min + " with index [" + iMinI + "][" + iMinJ + "].");

        } catch (FileNotFoundException e) {
            System.out.println("ERROR! File Not Found!");
        } catch (IOException e) {
            System.out.println("ERROR! Input-Output exception");
        } finally {
            try { buffReader.close(); } catch (Exception e) {}
        }
    }
}
