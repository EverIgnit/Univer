import java.io.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class Serialization {
    private static String filePath = "File.bin";
    private static Scanner sc = new Scanner(System.in);
    private static List<PhoneCall> callList;

    public static void main(String args[]) {
        try {
            InputStream in = new FileInputStream(filePath);
            ObjectInputStream inp = new ObjectInputStream(in);
            callList = (List<PhoneCall>) inp.readObject();
            inp.close();
        } catch (IOException | ClassNotFoundException e) {
            callList = new ArrayList<>();
        }
        try {
            menu();
            OutputStream out = new FileOutputStream(filePath);
            ObjectOutputStream outP = new ObjectOutputStream(out);
            outP.writeObject(callList);
            outP.close();
        } catch (IOException e) {
            System.out.println("Unable to save the file");
        }
    }

    public static void menu() throws IOException {
        while (true) {
            System.out.println("Choose the option (only from 1 to 6):");
            System.out.println("1-View | 2-Add | 3-Edit | 4-Delete | 5) CallsSinceTheDate | 6) Exit");
            byte option = sc.nextByte();
            switch(option){
                case 1:
                    for(PhoneCall phc : callList)
                        System.out.println(phc.toString());;
                    break;
                case 2:
                    callList.add(new PhoneCall().Input());
                    System.out.println("The call was added successfully");
                    break;
                case 3:
                    System.out.println("Enter the index of the call to edit");
                    byte ind=sc.nextByte();
                    callList.get(ind).Input();
                    System.out.println("The call was edited successfully");
                    break;
                case 4:
                    byte index=sc.nextByte();
                    callList.remove(callList.get(index));
                    System.out.println("The call was deleted successfully");
                    break;
                case 5:
                    System.out.println("Enter day, month, year, hours and minutes one by one");
                    Date dateFrom=new Date();
                    dateFrom.setYear(sc.nextInt());
                    dateFrom.setMonth(sc.nextInt());
                    dateFrom.setDate(sc.nextInt());
                    dateFrom.setHours(sc.nextInt());
                    dateFrom.setMonth(sc.nextInt());
                    System.out.println("Enter day, month, year, hours and minutes one by one");
                    Date dateTo=new Date();
                    dateTo.setYear(sc.nextInt());
                    dateTo.setMonth(sc.nextInt());
                    dateTo.setDate(sc.nextInt());
                    dateTo.setHours(sc.nextInt());
                    dateTo.setMonth(sc.nextInt());
                    for(PhoneCall phcall : callList){
                        if(dateFrom.compareTo(phcall.date)>0&&dateTo.compareTo(phcall.date)<0){
                            System.out.println(phcall.toString());
                        }
                    }
                    break;
                case 6:
                    System.out.println("Shutting down the program...");
                    return;
            }
        }
    }
}
class PhoneCall implements Serializable{
    private String numberIncome;
    private String numberOutcome;
    public Date date;
    private String callLength;

    public /*static*/ PhoneCall Input(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the income number");
        this.numberIncome=sc.nextLine();
        System.out.println("Enter the outcome number");
        this.numberOutcome=sc.nextLine();
        System.out.println("Enter the date of the call:");
        System.out.println("Enter day, month, year, hours and minutes one by one");
//        Calendar c = Calendar.newInstance();
//        c.set(sc.nextByte(), sc.nextByte() - 1, sc.nextByte());
//        date = c.getTime();
        date=new Date();
        date.setYear(sc.nextInt());
        date.setMonth(sc.nextInt());
        date.setDate(sc.nextInt());
        date.setHours(sc.nextInt());
        date.setMonth(sc.nextInt());
        System.out.println("Enter the length of the call");
        this.callLength=sc.nextLine();
        return this;
    }
    public String toString() {
        return numberOutcome + " " + numberIncome + " " + date.toString() + " " + callLength;
    }
}
