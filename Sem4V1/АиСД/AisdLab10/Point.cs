using System;
using System.Collections.Generic;
using System.Linq;

namespace AisdLab10
{
    class Point
    {
        byte id;
        sbyte x;
        sbyte y;
        bool withBot;
        List<Point> neighbors;
        public Point(sbyte x, sbyte y, byte id)
        {
            this.x = x;
            this.y = y;
            this.id = id;
            this.withBot = false;
            neighbors = new List<Point>();
        }
        public sbyte getX
        {
            get
            {
                return x;
            }
        }
        public sbyte getY
        {
            get
            {
                return y;
            }
        }
        public byte getId
        {
            get
            {
                return id;
            }
        }
        public bool getWithBot
        {
            get
            {
                return withBot;
            }
        }
        public void setWithBot(bool param)
        {
            this.withBot = param;
        }
        byte distanceWith(Point point)
        {
            return (byte)Math.Sqrt(Math.Pow(point.getX - this.x, 2) + Math.Pow(point.getY - this.y, 2));
        }
        public void FindNeighbors(List<Point> points)
        {
            foreach (Point point in points)
                if (this.distanceWith(point) == 1)
                    neighbors.Add(point);
        }

        public List<List<byte>> MakeRoutes(List<byte> prevRoute)
        {
            List<Point> TEMP = new List<Point>(neighbors);
            bool restart = false, stop = false;
            while (stop==false&&TEMP.Count>0)
                foreach (Point temp in TEMP)
                {
                    foreach (byte previd in prevRoute)
                        if (temp.getId == previd)
                        {
                            TEMP.Remove(temp);
                            restart = true;
                        }
                    if (restart)
                    {
                        restart = false;
                        break;
                    }
                    if (temp.id==TEMP.Last().id)
                    {
                        stop = true;
                        break;
                    }
                }
            prevRoute.Add(this.id);
            List<List<byte>> routes = new List<List<byte>>(), nextRoute;
            routes.Add(prevRoute);
            if (TEMP.Count == 0)
                return routes;
            foreach (Point neighbor in TEMP)
            {
                nextRoute = neighbor.MakeRoutes(prevRoute);
                foreach (List<byte> route in nextRoute)
                    routes.Add(route);
            }
            return routes;
        }
    }
}
