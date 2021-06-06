using System;
using System.Collections.Generic;
using System.Linq;

namespace MVLab13
{
    class Program
    {
        static void Main()
        {
            double start, end, step;
            do
            {
                Console.WriteLine("Введите начало и конец интервала, затем введите шаг");
                start = Convert.ToDouble(Console.ReadLine());
                end = Convert.ToDouble(Console.ReadLine());
                step = Convert.ToDouble(Console.ReadLine());
            } while (start >= end || step >= end - start || step < 0);
            Interval interval = new Interval(start, end);

            Function f = new Function();
            f.SetStep(step);
            f.GetRootIntervals(interval);

            if (f.GetRootIntervals().Count == 0)
                Console.WriteLine("В данном интервале данное уравнение не имеет корней ");
            while (true)
            {
                f.OutRootIntervals();

                Console.WriteLine("Выберите номер действия: \n          1.......  уточнение интервалов\n          2.......  уточнение корней в этих интервалах ");
                int k = Convert.ToInt32(Console.ReadLine());
                if (k < 1 || k > 2)
                    Console.WriteLine("Такого варианта нету \n Попробуйте еще раз ");
                else if (k == 1)
                {
                    while (true)
                    {
                        if (f.GetRootIntervals().Count > 1)
                        {
                            Console.WriteLine("Выберите номер интервала котрый вы хотите уточнить ");
                            Console.WriteLine("-1  -- все интервалы ");
                            for (int i = 0; i < f.GetRootIntervals().Count; i++)
                                Console.WriteLine(i + "-й -- интервал  " + f.GetRootIntervals().ElementAt(i));
                            int v = Convert.ToInt32(Console.ReadLine());
                            double oldStep = step;
                            Console.WriteLine("Введите шаг : ");
                            step = Convert.ToDouble(Console.ReadLine());
                            if (step < oldStep && step > 0)
                            {
                                f.SetStep(step);
                                if (v == -1)
                                {
                                    List<Interval> inters = new List<Interval>();
                                    for (int i = 0; i < f.GetRootIntervals().Count; i++)
                                        inters.Add(f.GetRootIntervals().ElementAt(i));
                                    for (int i = 0; i < f.GetRootIntervals().Count; i++)
                                        f.GetRootIntervals().RemoveAt(i);
                                    for (int i = 0; i < inters.Count; i++)
                                        f.GetRootIntervals(inters.ElementAt(i));
                                    break;
                                }
                                if (v < f.GetRootIntervals().Count && v > -1)
                                {
                                    Interval interv = f.GetRootIntervals().ElementAt(v);
                                    f.GetRootIntervals().Remove(f.GetRootIntervals().ElementAt(v));
                                    f.GetRootIntervals(interv);
                                    break;
                                }
                                else
                                    Console.WriteLine(" В списке интервалов такой вариант нет\n     Попробуйте еще раз \n");
                            }
                            else
                            {
                                Console.WriteLine("Шаг должен быть больше нуля  меньше чем предыдущего шага \n   Попробуйте еще раз ");
                                step = oldStep;
                            }
                        }
                        else
                        {
                            double oldStep = step;
                            Console.WriteLine("Введите шаг : ");
                            step = Convert.ToDouble(Console.ReadLine());
                            if (step < oldStep && step > 0)
                            {
                                f.SetStep(step);
                                Interval interv = f.GetRootIntervals().ElementAt(0);
                                f.GetRootIntervals().Remove(f.GetRootIntervals().ElementAt(0));
                                f.GetRootIntervals(interv);
                                break;
                            }
                            else
                            {
                                Console.WriteLine("Шаг должен быть больше нуля  меньше чем предыдущего шага \n   Попробуйте еще раз ");
                                step = oldStep;
                            }
                        }
                    }
                }
                else if (k == 2)
                {
                    while (true)
                    {
                        if (f.GetRootIntervals().Count > 1)
                        {
                            Console.WriteLine("Выберите номер интервала в котрым вы хотите уточнить корни ");
                            Console.WriteLine("-1  -- во всех интервалах ");
                            for (int i = 0; i < f.GetRootIntervals().Count; i++)
                                Console.WriteLine(i + "-м -- интервале  " + f.GetRootIntervals().ElementAt(i));
                            int v = Convert.ToInt32(Console.ReadLine());
                            if (v == -1)
                            {
                                Console.WriteLine("\n\n");
                                for (int i = 0; i < f.GetRootIntervals().Count; i++)
                                {
                                    f.GetRootWithChordMethodOn(f.GetRootIntervals().ElementAt(i));
                                    Console.WriteLine("\n\n\n");
                                }
                                Console.WriteLine("");
                                break;
                            }
                            if (v < f.GetRootIntervals().Count && v > -1)
                                break;
                            else
                                Console.WriteLine(" В списке интервалов такой вариант нет\n     Попробуйте еще раз \n");
                        }
                        else
                        {
                            f.GetRootWithChordMethodOn(f.GetRootIntervals().ElementAt(0));
                            Console.WriteLine("\n\n\n");
                            break;
                        }
                    }
                    Console.Clear();
                }
            }
        }
    }
}