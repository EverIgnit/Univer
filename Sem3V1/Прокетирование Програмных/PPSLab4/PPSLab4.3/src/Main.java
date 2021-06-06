import java.awt.*;
import javax.swing.JFrame;

public class Main extends Canvas {

    public void paint(Graphics g) {
        super.paint(g);
        g.setColor(Color.cyan);
        g.fillOval(150, 150, 500, 500);
        g.setColor(Color.red);
        int[] arr1 = {230, 230, 395, 395}, arr2 = {230, 395, 395, 230},
                arr3={230,230,395,395},arr4={570,405,405,570},
                arr5={570,570,405,405},arr6={230,395,395,230},
                arr7 = {570, 570, 405, 405}, arr8 = {570, 405, 405, 570};
        g.fillPolygon(arr1, arr2, 4);
        g.setColor(Color.green);
        g.fillPolygon(arr3, arr4, 4);
        g.setColor(Color.blue);
        g.fillPolygon(arr5, arr6, 4);
        g.setColor(Color.yellow);
        g.fillPolygon(arr7, arr8, 4);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.getContentPane().add(new Main());
        frame.setSize(800, 800);
        frame.setVisible(true);
    }
}

/*
        g.setColor(Color.RED);
        g.fillOval(100, 100, 500, 500);
        g.setColor(Color.ORANGE);
        g.fillOval(450,100,500,500);
        g.setColor(Color.RED);
        int[] arrayY1 = {190, 190, 220, 220};
        int[] arrayX1 = {500, 540, 560, 480};
        g.fillPolygon(arrayX1, arrayY1, 4);
        int[] arrayY2 = {250, 250, 280, 280};
        int[] arrayX2 = {470, 560, 580, 455};
        g.fillPolygon(arrayX2, arrayY2, 4);
        int[] arrayY3 = {300, 300, 430, 430};
        int[] arrayX3 = {450, 585, 585, 445};
        g.fillPolygon(arrayX3, arrayY3, 4);
        int[] arrayY5 = {450, 450, 480, 480};
        int[] arrayX5 = {470, 580, 560, 455};
        g.fillPolygon(arrayX5, arrayY5, 4);
        int[] arrayY4 = {500, 500, 528, 528};
        int[] arrayX4 = {500, 550, 525, 480};
        g.fillPolygon(arrayX4, arrayY4, 4);
        g.setColor(Color.BLUE);
        Font font = new Font("Tahoma", Font.BOLD|Font.ITALIC, 135);
        g.setFont(font);
        g.drawString("MasterCard", 130, 425);
        g.setColor(Color.WHITE);
        g.drawString("MasterCard", 135, 420);
        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(2));
        g.drawOval(915, 410, 13, 13);
        Font font2 = new Font("Tahoma", Font.ITALIC, 10);
        g.setFont(font2);
        g.drawString("R", 920, 420);
        g.setColor(Color.ORANGE);
        g.drawOval(920, 470, 13, 13);
        g.drawString("R", 925, 480);
         */