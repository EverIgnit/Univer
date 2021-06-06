import javax.swing.*;

public class FormConstructor extends JFrame {
    public FormConstructor() {
        super("PPSLab4.2");
        setBounds(100, 50, 375, 290);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel Label1 = new JLabel("Button amount:");
        Label1.setBounds(10, 10, 350, 30);
        add(Label1);

        JTextField TextEdit1 = new JTextField();
        TextEdit1.setBounds(250, 10, 100, 30);
        add(TextEdit1);

        JLabel Label2 = new JLabel("Field amount:");
        Label2.setBounds(10, 50, 350, 30);
        add(Label2);

        JTextField TextEdit2 = new JTextField();
        TextEdit2.setBounds(250, 50, 100, 30);
        add(TextEdit2);

        JLabel Label3 = new JLabel("Position:");
        Label3.setBounds(10, 90, 80, 30);
        add(Label3);

        JTextField TextEdit3 = new JTextField();
        TextEdit3.setBounds(140, 90, 100, 30);
        add(TextEdit3);

        JTextField TextEdit4 = new JTextField();
        TextEdit4.setBounds(250, 90, 100, 30);
        add(TextEdit4);

        JLabel Label4 = new JLabel("Size:");
        Label4.setBounds(10, 130, 80, 30);
        add(Label4);

        JTextField TextEdit5 = new JTextField();
        TextEdit5.setBounds(140, 130, 100, 30);
        add(TextEdit5);

        JTextField TextEdit6 = new JTextField();
        TextEdit6.setBounds(250, 130, 100, 30);
        add(TextEdit6);

        JLabel Label5 = new JLabel("Layout:");
        Label5.setBounds(10, 170, 100, 30);
        add(Label5);

        String[] data = {"BorderLayout", "BoxLayout", "FlowLayout", "GridLayout",};
        JComboBox list = new JComboBox(data);
        list.setBounds(140, 170, 210, 30);
        add(list);

        JButton calculateButton = new JButton("Create");
        calculateButton.setBounds(10, 210, 340, 30);
        calculateButton.addActionListener(new CalculateButtonHandler(TextEdit1, TextEdit2, TextEdit3, TextEdit4, TextEdit5, TextEdit6, list));
        add(calculateButton);

        setVisible(true);
    }
}