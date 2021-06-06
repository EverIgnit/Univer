using System;
using System.Threading;

namespace AisdLab6
{
    class MainClass
    {
        static void Main()
        {
            // GAME SETTINGS:
            const byte rAmount = 10;
            const byte ingrAppearSpeed = 8;
            // Initialisation:
            const string align = "\t\t";
            var rand = new Random();
            Stack<string> ingr1 = new Stack<string>();
            Stack<string> ingr2 = new Stack<string>();
            Stack<string> ingr3 = new Stack<string>();
            Deque<string> salads = new Deque<string>();
            Deque<string> shop = new Deque<string>();
            Queue<string> robots = new Queue<string>();
            Queue<string> robInProc = new Queue<string>();
            Queue<string> returnRobots = new Queue<string>();
            for (byte i = 0; i < rAmount; i++)
                robots.push("R");

            // ProgramCycle:
            while (true)
            {
                Console.Write(align + "Sorting Center:\n(R)");
                salads.Write();
                Console.WriteLine("(R) ");
                if (salads.Count > 0)
                    shop.push(salads.pop());
                if (salads.Count > 0)
                    shop.push(salads.shift());

                while (!robInProc.isEmpty())
                {
                    returnRobots.push(robInProc.shift());
                    salads.push("S");
                }

                while (true)
                {
                    if (ingr1.isEmpty() || ingr2.isEmpty() || ingr3.isEmpty() || robots.isEmpty())
                        break;
                    robInProc.push(robots.shift());
                    Console.Write("(R) ");
                    ingr1.pop();
                    ingr2.pop();
                    ingr3.pop();
                }
                Console.WriteLine("\n"+ align + "Storage:");
                Console.WriteLine("Ingredient1: ");
                ingr1.WriteLine();
                Console.WriteLine("Ingredient2: ");
                ingr2.WriteLine();
                Console.WriteLine("Ingredient3: ");
                ingr3.WriteLine();

                for (int i = 0; i < ingrAppearSpeed; i++)
                    switch (rand.Next(0, 3))
                    {
                        case 0:
                            ingr1.push("I1");
                            break;
                        case 1:
                            ingr2.push("I2");
                            break;
                        default:
                            ingr3.push("I3");
                            break;
                    }
                Console.WriteLine("\n" + align + "FreeRobots:");
                robots.WriteLine();

                while(!returnRobots.isEmpty())
                    robots.push(returnRobots.shift());

                Console.WriteLine(align + "Shop:");
                shop.Write();

                Thread.Sleep(500);
                Console.Clear();
            }
        }
    }
}