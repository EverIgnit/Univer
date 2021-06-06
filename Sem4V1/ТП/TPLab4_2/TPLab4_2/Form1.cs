using System;
using System.Drawing;
using System.Windows.Forms;

namespace TPLab4_2
{
    public partial class TPLab4_2 : Form
    {
        public TPLab4_2()
        {
            InitializeComponent();
        }

        private void TPLab4_2_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.Clear(Color.White);
            Pen pen = new Pen(Color.Black, 2);
            Font font = new Font(label1.Font.FontFamily, label1.Font.Size + 3.0F, FontStyle.Italic);
            SolidBrush brush = new SolidBrush(Color.Black);
            //Верхняя граница
            g.DrawLine(pen, 50, 50, 950, 50);
            //Верхний правый узел
            //Верхний правый сектор
            RightTop(g, pen, font, brush);
            //Правая конструкция, центр
            RightCenter(g, pen, font, brush);
            // Правый нижний узел
            RightBot(g, pen, font, brush);
            // Правые линии
            RightCarcas(g, pen, font, brush);
            //Круги
            Circles(g, pen, font, brush);
            //Прямоугольники
            Rectangles(g, pen, font, brush);
            // Треугольник
            Triangle(g, pen, font, brush);
            // "Цэшки"
            Cs(g, pen, font, brush);
            // Узлы
            Points(g);
            // Левые линии
            LeftLines(g, pen, font, brush);
            // Центр
            Center(g, pen, font, brush);
        }
        
        private void Points(Graphics g)
        {
            SolidBrush solid = new SolidBrush(Color.Black);
            PointScheme(solid, 650, 50, g);
            PointScheme(solid, 920, 90, g);
            PointScheme(solid, 260, 90, g);
            PointScheme(solid, 300, 90, g);
            PointScheme(solid, 720, 90, g);
            PointScheme(solid, 920, 50, g);
            PointScheme(solid, 140, 300, g);
            PointScheme(solid, 300, 300, g);
            PointScheme(solid, 400, 300, g);
            PointScheme(solid, 560, 300, g);
            PointScheme(solid, 820, 300, g);
            PointScheme(solid, 920, 300, g);
            PointScheme(solid, 650, 460, g);
            PointScheme(solid, 720, 460, g);
            PointScheme(solid, 820, 460, g);
        }

        private void PointScheme(SolidBrush solid, int x, int y, Graphics g)
        {
            g.FillEllipse(solid, x - 5, y - 5, 10, 10);
        }

        private void CircleScheme(string direction, int x1, int y1, Graphics g, Pen pen)
        {
            g.DrawEllipse(pen, x1, y1, 60, 60);
            switch (direction)
            {
                case "North":
                    y1 += 60;
                    g.DrawLine(pen, x1 + 5, y1 - 15 , x1 + 15, y1 - 40 );
                    g.DrawLine(pen, x1 + 5, y1 - 40 , x1 + 55, y1 - 40);
                    g.DrawLine(pen, x1 + 30, y1 - 40, x1 + 30, y1 - 60 );
                    g.DrawLine(pen, x1 + 55, y1 - 15, x1 + 45, y1 - 40 );
                    g.DrawLine(pen, x1 + 45, y1 - 30 , x1 + 45, y1 - 40 );
                    g.DrawLine(pen, x1 + 52, y1 - 33 , x1 + 45, y1 - 40);
                    break;
                case "South":
                    x1 += 60;
                    g.DrawLine(pen, x1 - 5, y1 + 15, x1 - 15, y1 + 40);
                    g.DrawLine(pen, x1 - 5, y1 + 40, x1 - 55, y1 + 40);
                    g.DrawLine(pen, x1 - 30, y1 + 40, x1 - 30, y1 + 60);
                    g.DrawLine(pen, x1 - 55, y1 + 15, x1 - 45, y1 + 40);
                    g.DrawLine(pen, x1 - 45, y1 + 30, x1 - 45, y1 + 40);
                    g.DrawLine(pen, x1 - 52, y1 + 33, x1 - 45, y1 + 40);
                    break;
                case "West":
                    x1 += 60;
                    g.DrawLine(pen, x1 - 15, y1 + 5, x1 - 40, y1 + 15);
                    g.DrawLine(pen, x1 - 40, y1 + 5, x1 - 40, y1 + 55);
                    g.DrawLine(pen, x1 - 40, y1 + 30, x1 - 60, y1 + 30);
                    g.DrawLine(pen, x1 - 15, y1 + 55, x1 - 40, y1 + 45);
                    g.DrawLine(pen, x1 - 30, y1 + 45, x1 - 40, y1 + 45);
                    g.DrawLine(pen, x1 - 33, y1 + 52, x1 - 40, y1 + 45);
                    break;
                default:
                    g.DrawLine(pen, x1 + 15, y1 + 5, x1 + 40, y1 + 15);
                    g.DrawLine(pen, x1 + 40, y1 + 5, x1 + 40, y1 + 55);
                    g.DrawLine(pen, x1 + 40, y1 + 30, x1 + 60, y1 + 30);
                    g.DrawLine(pen, x1 + 15, y1 + 55, x1 + 40, y1 + 45);
                    g.DrawLine(pen, x1 + 30, y1 + 45, x1 + 40, y1 + 45);
                    g.DrawLine(pen, x1 + 33, y1 + 52, x1 + 40, y1 + 45);
                    break;
            }
            
           
        }

        private void Rectangles(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawRectangle(pen, 130, 160, 20, 50);
            g.DrawString("R1", font, brush, 155, 160);
            g.DrawRectangle(pen, 290, 110, 20, 50);
            g.DrawString("R2", font, brush, 315, 120);
            g.DrawRectangle(pen, 550, 160, 20, 50);
            g.DrawString("R3", font, brush, 520, 170);
            g.DrawRectangle(pen, 290, 200, 20, 50);
            g.DrawString("R4", font, brush, 315, 215);
            g.DrawRectangle(pen, 390, 130 + 90, 20, 50);
            g.DrawString("R5", font, brush, 355, 215);
            g.DrawRectangle(pen, 840, 280, 50, 20);
            g.DrawString("R6", font, brush, 850, 260);
            g.DrawRectangle(pen, 70, 450, 50, 20);
            g.DrawString("R7", font, brush, 80, 430);
            g.DrawRectangle(pen, 580, 450, 50, 20);
            g.DrawString("R8", font, brush, 590, 430);
        }

        private void Circles(Graphics g, Pen pen, Font font, Brush brush)
        {
            CircleScheme("South", 790, 75, g, pen);
            g.DrawString("VT1", font, brush, 840, 60);
            CircleScheme("East", 35, 270, g, pen);
            g.DrawString("VT2", font, brush, 90, 260);
            CircleScheme("West", 605, 270, g, pen);
            g.DrawString("VT3", font, brush, 580, 270);
            CircleScheme("East", 125, 370, g, pen);
            g.DrawString("VT4", font, brush, 180, 360);
            CircleScheme("West", 515, 370, g, pen);
            g.DrawString("VT5", font, brush, 490, 360);
        }

        private void LeftLines(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawLine(pen, 50, 50, 50, 275);
            g.DrawLine(pen, 50, 325, 50, 460);
            g.DrawLine(pen, 70, 460, 50, 460);
            g.DrawLine(pen, 120, 460, 140, 460);
            g.DrawLine(pen, 140, 425, 140, 460);
            g.DrawLine(pen, 140, 210, 140, 375);
            g.DrawLine(pen, 140, 90, 140, 160);
            g.DrawLine(pen, 85, 300, 300, 300);
            g.DrawLine(pen, 300, 250, 300, 300);
            g.DrawLine(pen, 300, 200, 300, 160);
            g.DrawLine(pen, 300, 90, 300, 110);
        }

        private void Center(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawLine(pen, 400, 300, 605, 300);
            g.DrawLine(pen, 400, 300, 400, 250);
            g.DrawLine(pen, 400, 200, 400, 90);
            g.DrawLine(pen, 185, 400, 300, 400);
            g.DrawLine(pen, 400, 400, 515, 400);
            g.DrawLine(pen, 300, 300, 400, 400);
            g.DrawLine(pen, 400, 300, 300, 400);
            g.DrawLine(pen, 550, 430, 550, 460);
            g.DrawLine(pen, 560, 90, 560, 160);
            g.DrawLine(pen, 560, 210, 560, 375);
        }

        private void RightTop(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawLine(pen, 950, 50, 940, 30);
            g.DrawLine(pen, 950, 50, 940, 70);
            g.DrawLine(pen, 970, 50, 960, 30);
            g.DrawLine(pen, 970, 50, 960, 70);
            g.DrawLine(pen, 970, 50, 990, 50);
            g.DrawString("XP1", font, brush, 910, 50 - 40);
            g.DrawString("XS1", font, brush, 910 + 40, 50 - 40);
            g.DrawLine(pen, 990, 135, 990, 50);
            g.DrawLine(pen, 970, 135, 990, 170);
            g.DrawLine(pen, 990, 255, 990, 170);
            g.DrawString("SA1", font, brush, 970 - 20, 135 - 20);

        }

        private void RightCenter(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawLine(pen, 975, 255, 1005, 255);
            g.DrawLine(pen, 980, 260, 1000, 260);
            g.DrawLine(pen, 975, 255 + 45, 1005, 255 + 45);
            g.DrawLine(pen, 980, 260 + 45, 1000, 260 + 45);
            g.DrawString("+", font, brush, 970, 235);
            g.DrawString("-", font, brush, 970, 230 + 70);
            g.DrawString("G1", font, brush, 950, 260);
            g.DrawLine(pen, 990, 305, 990, 460);

        }

        private void RightBot(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawLine(pen, 950, 50 + 410, 940, 30 + 410);
            g.DrawLine(pen, 950, 50 + 410, 940, 70 + 410);
            g.DrawLine(pen, 970, 50 + 410, 960, 30 + 410);
            g.DrawLine(pen, 970, 50 + 410, 960, 70 + 410);
            g.DrawLine(pen, 970, 50 + 410, 990, 50 + 410);
            g.DrawLine(pen, 550,460, 580, 460);
            g.DrawString("XP1", font, brush, 910, 50 + 410 + 20);
            g.DrawString("XS1", font, brush, 910 + 40, 50 + 410 + 20);
        }

        private void Triangle(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawLine(pen, 805, 415, 835, 415);
            g.DrawLine(pen, 805, 415, 805, 405);
            g.DrawLine(pen, 820, 415, 805, 390);
            g.DrawLine(pen, 820, 415, 835, 390);
            g.DrawLine(pen, 805, 390, 835, 390);
            g.DrawString("VD1", font, brush, 830, 370);
        }

        private void Cs(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawLine(pen, 240, 280, 240, 320);
            g.DrawLine(pen, 250, 280, 250, 320);
            g.DrawString("C1", font, brush, 230, 255);
            g.DrawLine(pen, 450, 280, 450, 320);
            g.DrawLine(pen, 460, 280, 460, 320);
            g.DrawString("C2", font, brush, 450, 255);
            g.DrawLine(pen, 700, 210, 740, 210);
            g.DrawLine(pen, 700, 220, 740, 220);
            g.DrawString("C3", font, brush, 740, 195);
            g.DrawString("+", font, brush, 700, 220);
        }

        private void RightCarcas(Graphics g, Pen pen, Font font, Brush brush)
        {
            g.DrawLine(pen, 950, 460, 630, 460);
            g.DrawLine(pen, 920, 50, 920, 460);
            g.DrawLine(pen, 820, 135, 820, 460);
            g.DrawLine(pen, 720, 220, 720, 460);
            g.DrawLine(pen, 720, 90, 720, 210);
            g.DrawLine(pen, 650, 325, 650, 460);
            g.DrawLine(pen, 650, 275, 650, 50);
            g.DrawLine(pen, 140, 90, 795, 90);
            g.DrawLine(pen, 845, 90, 920, 90);
            g.DrawLine(pen, 890, 290, 920, 290);
            g.DrawLine(pen, 820, 290, 840, 290);
        }
    }
}
