using System;
using System.Collections.Generic;

namespace AisdLab10
{
    class Program
    {
        static void ShowRobotsRoutes(List<Point> points)
        {
            List<List<byte>> routes = new List<List<byte>>();
            List<byte> prevRoute;
            foreach (Point point in points)
            {
                if (point.getWithBot == false)
                    continue;
                Console.WriteLine("=-=-=-=-=-=-=-=-=");
                point.FindNeighbors(points);
                prevRoute = new List<byte>();
                routes = point.MakeRoutes(prevRoute);
                foreach (List<byte> route in routes)
                {
                    foreach (byte id in route)
                        Console.Write(id + " ");
                    Console.WriteLine();
                }
            }
        }
        static List<Point> InputPoints(List<Point> points, int am)
        {
            Point tempPoint;
            sbyte x, y;

            for (byte i = 0; i < am; i++)
            {
                Console.Write(i + ":\nx -> ");
                x = Convert.ToSByte(Console.ReadLine());
                Console.Write("y -> ");
                y = Convert.ToSByte(Console.ReadLine());
                tempPoint = new Point(x, y, i);
                points.Add(tempPoint);
            }
            return points;
        }
        static bool IsPossible(List<Point> points)
        {
            foreach (Point point in points)
                if (point.getWithBot == true)
                    foreach (Point point1 in points)
                        if (point1.getWithBot == true && point1.getId == point.getId)
                            return true;
            return false;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Enter point's amount:");
            byte am = Convert.ToByte(Console.ReadLine()), number = 0, rAm=0;
            List<Point> points = new List<Point>();
            points = InputPoints(points, am);
            
            Console.WriteLine("=-=-=-=-=-=-=-=-=");
            do
            {
                Console.Write("Enter robot's amount:\n-> ");
                rAm = Convert.ToByte(Console.ReadLine());
            } while (rAm < 2 || rAm > am);
            Console.WriteLine("=-=-=-=-=-=-=-=-=");

            for (byte i = 0; i < rAm; i++)
            {
                Console.Write("Enter stating points' numbers\n-> ");
                number = Convert.ToByte(Console.ReadLine());
                foreach (Point point in points)
                    if (number == point.getId)
                        point.setWithBot(true);
            }

            if (IsPossible(points) != true)
            {
                Console.WriteLine("Robots are out of each other's reach");
                return;
            }

            ShowRobotsRoutes(points);
            Console.WriteLine("=-=-=-=-=-=-=-=-=");
            Console.WriteLine("These are possible rbots routes");
        }
    }
 
}
