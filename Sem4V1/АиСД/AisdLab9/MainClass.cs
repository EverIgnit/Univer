using System;

namespace AisdLab9
{
    class MainClass
    {
        static void Main(string[] args)
        {
            const int n = 10;
            DHeap<int> heap = new DHeap<int>(3);
            Random rand = new Random();
            for (int i = 0; i < n; i++)
                heap.push(rand.Next(0, n));
            heap.drawTree();
            heap.remove(heap.Root);
            heap.drawTree();
        }
    }
}
