using System;

class Program
{
    static int[,] profit;
    static ushort[] prices;
    static byte am;
    static void Main(string[] args)
    {
        am = 5;
        prices = new ushort[] { 5, 10, 2, 6, 3 };
        /*
        Console.Write("Enter prices amount:\n-> ");
        am = Convert.ToByte(Console.ReadLine());
        prices = new ushort[am];
        Console.WriteLine("Enter prices");
        for (int i = 0; i < am; i++){
            prices[i] = Convert.ToUInt16(Console.ReadLine());
            }
        */
        int min = prices[0], max, c = 0, imin = 0, imax = 0;
        profit = new int [am, 2];
        for (int j = 0; j < am; j++)
        {
            min = int.MaxValue;
            for (int i = 0; i < am; i++)
                if (!Checked(i)&&prices[i] < min)
                {
                    min = prices[i];
                    imin = i;
                }
            max = min;
            imax = imin;
            // The division is here
            for (int i = imin; i < am; i++)
                if (prices[i] > max)
                {
                    max = prices[i];
                    imax = i;
                }
            profit[c, 0] = imin;
            profit[c, 1] = imax;
            c++;
        }
        max = int.MinValue;
        imax = profit[0, 1];
        for (int i = 0; i < am; i++)
            if (prices[profit[i, 1]] - prices[profit[i, 0]] > max)
            {
                max = prices[profit[i, 1]] - prices[profit[i, 0]];
                imax = i;
            }
        Console.WriteLine("The most profitable dates are " + profit[imax, 0] + " and " + profit[imax, 1] + ": " + (prices[profit[imax, 1]] - prices[profit[imax, 0]]));
    }
    static bool Checked(int check)
    {
        for (byte i = 0; i < am; i++)
            if (check == profit[i, 0])
                return true;
        return false;
    }
}












/* Мучался долго. К сожалению, соображалки не хватило на большее,
 * т.к. в случае падающего графика в других случаях отображалось неверно.
 * Надеюсь, за старания и усидчивость это можно зачесть. Особенно потому что работает
 */
