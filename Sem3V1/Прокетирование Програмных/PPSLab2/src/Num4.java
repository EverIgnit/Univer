import javax.naming.Name;
public class Num4 {
    public static void main(String args[]) {
        // =-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
        // Initialize
        String NameOfCountry = new String(args[0]);
        int l1 = args.length - 1;
        Date dates[] = new Date[l1];
        Modify modify[] = new Modify[l1];
        int difference[], days[] = new int[l1],
                monthInAYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                monthInThisYear, i, max, imax, temp;

        for (i = 0; i < l1; i++) {
            // Error?
            if (args[i+1].length() != 10)
                return;
            // Filling the array
            dates[i] = new Date(args[i+1]);

            // =-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
            // What format to use
            switch (NameOfCountry) {
                case ("Rus"):
                    ModifyRus tempRus = new ModifyRus();
                    modify[i] = tempRus;
                    break;
                case ("Can"):
                    ModifyUS tempUS = new ModifyUS();
                    modify[i] = tempUS;
                    break;
                case ("US"):
                    ModifyCan tempCan = new ModifyCan();
                    modify[i] = tempCan;
                    break;
                default:
                    return;
            }
            // =-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
            // Modify date from string to 3 integers
            modify[i].modifyDate(dates[i]);
            // =-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
            // Days in the date for chronological order
            monthInThisYear = 0;
            for (int j = 0; j < dates[i].getMonth(); j++)
                monthInThisYear += monthInAYear[j];
            days[i] = dates[i].getDay() + monthInThisYear + (365 * dates[i].getYear()) + (dates[i].getYear() / 4) - (dates[i].getYear() / 100);
            // =-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
        }
        // =-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
        // Sort for chronological order
        for (i = 0; i < l1; i++) {
            max = days[i];
            imax = i;
            for (int j = i; j < l1; j++) {
                if (days[j] > max) {
                    max = days[j];
                    imax = j;
                }
            }
            temp = days[i];
            days[i] = days[imax];
            days[imax] = temp;
        }
        // =-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=
        // Array of differences
        int l2 = l1 - 1, min, iMin=0;
        difference = new int[l2];
        for (i = 0; i < l2; i++) {
            difference[i] = Math.abs(days[i] - days[i + 1]);
        }
        // Minimal Difference
        min=difference[0];
        for(i=1;i<l2;i++){
            if (difference[i]<min){
                min=difference[i];
                iMin=i;
            }
        }
        System.out.println("Minimal difference is " + min + " between the dates " + dates[iMin].getDateString() + " and " + dates[iMin+1].getDateString());
    }
}

class Date {
    protected String dateString;
    protected int day, month, year;

    public Date(String dateString) {
        this.dateString = dateString;
    }

    public String getDateString(){
        return dateString;
    }

    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public void setDay(int day) {
        this.day = day;
    }

}

abstract class Modify {
    abstract void modifyDate(Date date);
}

class ModifyRus extends Modify{
    public void modifyDate(Date date){
        date.setDay(Integer.parseInt(date.getDateString().substring(0,2)));
        date.setMonth(Integer.parseInt(date.getDateString().substring(3,5)));
        date.setYear(Integer.parseInt(date.getDateString().substring(6,10)));
    }
}

class ModifyUS extends Modify{
    public void modifyDate(Date date){
        date.setDay(Integer.parseInt(date.getDateString().substring(3,5)));
        date.setMonth(Integer.parseInt(date.getDateString().substring(0,2)));
        date.setYear(Integer.parseInt(date.getDateString().substring(6,10)));
    }
}

class ModifyCan extends Modify {
    public void modifyDate(Date date) {
        date.setDay(Integer.parseInt(date.getDateString().substring(8,10)));
        date.setMonth(Integer.parseInt(date.getDateString().substring(5,7)));
        date.setYear(Integer.parseInt(date.getDateString().substring(0, 4)));
    }
}