import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;

class Calculate implements ActionListener {
    private JTextField f1, f2, f3;

    public Calculate(JTextField f1, JTextField f2, JTextField f3) {
        this.f1 = f1;
        this.f2 = f2;
        this.f3 = f3;
    }

    public void actionPerformed(ActionEvent event) {
        try {
            String data = f1.getText();
            int number = Integer.parseInt(f2.getText());

            String[] parseData = data.split("\\.");
            if (parseData.length == 3) {
                int day = Integer.parseInt(parseData[0]), month = Integer.parseInt(parseData[1]), year = Integer.parseInt(parseData[2]);
                int monthInAYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                if (month > 0 && month < 13 && year > 1970) {
                    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                        monthInAYear[1] = 29;
                    if (day > 0 && day <= monthInAYear[month - 1]) {
                        SimpleDateFormat dateFormat = new SimpleDateFormat("dd.MM.yyyy");
                        Calendar cal = Calendar.getInstance();
                        try {
                            cal.setTime(dateFormat.parse(data));
                        } catch (ParseException e) {
                            e.printStackTrace();
                            JOptionPane.showMessageDialog(null, "Invalid value. Please, try again");
                            return;
                        }
                        int days = cal.get(Calendar.DAY_OF_MONTH);
                        cal.set(Calendar.DAY_OF_MONTH, days + number);

                        String relation;

                        if (number > 0)
                            relation = "Future";
                        else if (number < 0)
                            relation = "Past";
                        else
                            relation = "Equal";
                        f3.setText(relation);
                        JOptionPane.showMessageDialog(null,
                                "New Date is: "
                                        + cal.get(Calendar.DAY_OF_MONTH) + "."
                                        + (cal.get(Calendar.MONTH) + 1) + "."
                                        + cal.get(Calendar.YEAR) + " ");
                        return;
                    }
                }
            }
            JOptionPane.showMessageDialog(null, "Invalid value. Please, try again");
        } catch (NumberFormatException exception) {
            JOptionPane.showMessageDialog(null, "Invalid value");
        }
    }
}