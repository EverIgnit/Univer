import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculateButtonHandler implements ActionListener {
    private JTextField edits, labels, x, y, w, h;
    private JComboBox layout;

    public CalculateButtonHandler(JTextField f1, JTextField f2, JTextField f3, JTextField f4, JTextField f5, JTextField f6, JComboBox b1) {
        edits = f1;
        labels = f2;
        x = f3;
        y = f4;
        w = f5;
        h = f6;
        layout = b1;
    }

    public void actionPerformed(ActionEvent e) {
        try {
            int     edits = Integer.parseInt(this.edits.getText()),
                    labels = Integer.parseInt(this.labels.getText()),
                    x = Integer.parseInt(this.x.getText()),
                    y = Integer.parseInt(this.y.getText()),
                    w = Integer.parseInt(this.w.getText()),
                    h = Integer.parseInt(this.h.getText());

            if ((edits >= 0) && (labels >= 0) && (x >= 0) && (y >= 0) && (w >= 0) && (h >= 0)) {
                JFrame jf = new JFrame();
                jf.setBounds(x, y, w, h);
                jf.setVisible(true);
                JPanel p = new JPanel();
                jf.add(p);
                switch (layout.getSelectedIndex()) {
                    case 0:
                        p.setLayout(new BorderLayout());
                        break;
                    case 1:
                        p.setLayout(new BoxLayout(p, BoxLayout.X_AXIS));
                        break;
                    case 2:
                        p.setLayout(new FlowLayout());
                        break;
                    default:
                        p.setLayout(new GridLayout(2, Math.max(edits, labels)));
                        break;
                }
                for (int i = 0; i < labels; i++)
                    p.add(new TextField("New Field " + (i + 1)));
                for (int i = 0; i < edits; i++) {
                    JButton mButton = new JButton("New Button " + (i + 1));
                    p.add(mButton, BorderLayout.WEST);
                }
            } else
                JOptionPane.showMessageDialog(null, "Invalid value");
        } catch (NumberFormatException exception) {
            JOptionPane.showMessageDialog(null, "Invalid value");
        }
    }
}