import java.util.Scanner;
public class PPSLab2 {
    public static void main(String args[]) {
        int max = 1000000;
        double corner = 0;
        short[][] color = new short[max][3]; // создание массива цветов отрезков (3-RGB)
        double[][][] coord = new double[max][2][2]; //2-начало и конец, 2-координаты х и у
        double shag = 10;
        while (shag <= 0 || shag >= 2 * Math.PI) {
            System.out.println("Enter a step (0<step<2pi) The value of 0,001 is recommended: ");
            Scanner in = new Scanner(System.in);
            shag = in.nextDouble();
            // in.nextLine();
        }
        int kol = (int) ((2 * Math.PI) / shag);  // кол-во отрезков
        // вычисление координат
        for (int i = 0; i < kol; i++) {
            //Первая функция
            double first = (2 - Math.abs(Math.cos((Math.PI + 10 * corner) / 4))) / 2;
            double firstX = first * Math.cos(corner);
            double firstY = first * Math.sin(corner);
            //Вторая функция
            double second = (Math.tan((Math.PI * (2 + Math.sin(5 * corner))) / 8) / 5);
            double secondX = second * Math.cos(corner);
            double secondY = second * Math.sin(corner);
            // добавляем в массив полученные координаты
            coord[i][0][0] = firstX; // i - iый отрезок, 0-начало отрезка , 0-координата х
            coord[i][0][1] = firstY;
            coord[i][1][0] = secondX;
            coord[i][1][1] = secondY;
            corner += shag;
        }
        // вычисление цветов
        color[0][0] = 0;
        color[0][1] = 0;
        color[0][2] = 0;
        short a0 = 255;
        short a1 = 1;
        short a2 = 1;
        // вычисляем цвета для каждого отрезка
        for (int i = 1; i < kol; i++) {
            if ((color[i - 1][0] + a0 > 255) || (color[i - 1][0] + a0 < 0)) {
                a0 *= -1;
            }
            if ((color[i - 1][1] + a1 > 255) || (color[i - 1][1] + a1 < 0)) {
                a1 *= -1;
            }
            if ((color[i - 1][2] + a2 > 255) || (color[i - 1][2] + a2 < 0)) {
                a2 *= -1;
            }
            color[i][0] = (short) (color[i - 1][0] + a0); // красный цвет iго отрезка будет равен красному цвету i-1го отрезка + изменение
            color[i][1] = (short) (color[i - 1][1] + a1);
            color[i][2] = (short) (color[i - 1][2] + a2);
        }
        //Здесь вызывается метод для рисования графика
        by.vsu.mf.ai.ssd.painting.Painter.paint(1500, 800, coord, color);
    }
}