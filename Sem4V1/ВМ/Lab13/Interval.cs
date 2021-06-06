using System;

namespace MVLab13
{
    class Interval
    {
        double begin;
        double end;
        public Interval(double begin, double end)
        {
            this.begin = begin;
            this.end = end;
        }
        public double GetBegin
        {
            get
            {
                return begin;
            }
        }
        public double GetEnd
        {
            get
            {
                return end;
            }
        }
        public double GetCentre
        {
            get
            {
                return (begin + end) / 2;
            }
        }
        public double GetRadius
        {
            get
            {
                return (end - begin) / 2;
            }
        }
        public bool Сontains(double x)
        {
            return (x >= begin) && (x <= end);
        }
        override public string ToString()
        {
            return "[ " + begin + " ; " + end + " ] ";
        }
    }
}