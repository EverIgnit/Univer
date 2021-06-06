import javax.swing.*;
import java.awt.*;

class Form extends JFrame {
    public Form() {
        super("PPSLab 4.1");
        setBounds(200, 150, 300, 200);
        setLayout(new GridLayout(4, 1));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel resultLabel = new JLabel("New date is:");
        resultLabel.setBounds(10, 180, 500, 30);
        add(resultLabel);

        JTextField resultTextField = new JTextField();
        resultTextField.setEnabled(false);
        add(resultTextField);

        JLabel firstOperandLabel = new JLabel("Date (dd.mm.yyyy):");
        add(firstOperandLabel);

        JTextField firstOperandTextField = new JTextField();
        add(firstOperandTextField);

        JLabel secondOperandLabel = new JLabel("Number:");
        add(secondOperandLabel);

        JTextField secondOperandTextField = new JTextField();
        add(secondOperandTextField);

        JButton calculateButton = new JButton("Calculate");
        calculateButton.addActionListener(new Calculate(firstOperandTextField, secondOperandTextField, resultTextField));
        add(calculateButton);
        validate();
        setVisible(true);
    }
}