import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main extends JFrame {
    boolean start = false;
    JTextField tf0, tf1, tfA, tfB, tfC, tfD;

    public Main() {
        super("PPSLab4.4");
        super.setSize(400, 300);
        super.setDefaultCloseOperation(EXIT_ON_CLOSE);
        super.setLayout(new FlowLayout());

        final JPanel jpSecond = new GPanel();
        jpSecond.setLayout(new FlowLayout());

        JLabel label0 = new JLabel("Between :");
        jpSecond.add(label0);

        tf0 = new JTextField("-10");
        jpSecond.add(tf0);


        JLabel label1 = new JLabel("and  :");
        jpSecond.add(label1);

        tf1 = new JTextField("10");
        jpSecond.add(tf1);


        JLabel labelA = new JLabel("a :");
        jpSecond.add(labelA);

        tfA = new JTextField("1");
        jpSecond.add(tfA);

        JLabel labelB = new JLabel("b :");
        jpSecond.add(labelB);

        tfB = new JTextField("1");
        jpSecond.add(tfB);

        JLabel labelC = new JLabel("c :");
        jpSecond.add(labelC);

        tfC = new JTextField("1");
        jpSecond.add(tfC);

        JLabel labelD = new JLabel("d :");
        jpSecond.add(labelD);

        tfD = new JTextField("1");
        jpSecond.add(tfD);

        JButton jb0 = new JButton("Draw");
        jb0.addActionListener(new ActionListener() {
                                  public void actionPerformed(ActionEvent e) {
                                      start = true;
                                      jpSecond.repaint();
                                  }
                              }
        );
        jpSecond.add(jb0);
        add(jpSecond);
    }

    public static void main(String[] args) {
        Main g1 = new Main();
        g1.setVisible(true);
    }

    class GPanel extends JPanel {
        public GPanel() {
            super.setPreferredSize(new Dimension(600, 600));
        }

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (start) {
                g.setColor(Color.GRAY);

                g.drawLine(130, 100, 320 , 100  );
                g.drawLine(200, 30, 200  , 190  );
                g.drawLine(320, 100, 315 , 95  );
                g.drawLine(320, 100, 315 , 105 );
                g.drawLine(200, 30, 195  , 35  );
                g.drawLine(200, 30, 205 , 35 );


                int begIndex = Integer.parseInt(tf0.getText()),
                endIndex = Integer.parseInt(tf1.getText()),
                a = Integer.parseInt(tfA.getText()),
                b = Integer.parseInt(tfB.getText()),
                c = Integer.parseInt(tfC.getText()),
                d = Integer.parseInt(tfD.getText());

                Polygon p = new Polygon();

                for (int x = begIndex; x <= endIndex; x++) {
                    p.addPoint(x + 200, 100 - (int) (a * Math.sin(b * x) + c *Math.cos(d * x)));
                }

                g.setColor(Color.RED);
                g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
            }
        }

    }

}