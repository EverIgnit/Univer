using System;
using System.Collections.Generic;

namespace AisdLab6
{
    public class Queue<T>
    {
        List<T> items;
        List<StructIndex> index;
        int back;
        int top;
        public Queue()
        {
            items = new List<T>();
            index = new List<StructIndex>();
            back = 0;
            top = -1;
        }
        public void push(T item)
        {
            items.Add(item);
            if (index.Count > 0)
            {
                index[top] = new StructIndex(items.Count - 1, index[top].prev);
            }
            index.Add(new StructIndex(-1, top));
            top = index.Count - 1;
        }
        public T shift()
        {
            if (isEmpty()) return default(T);
            T firstItem = items[back];
            int delBack = back;
            back = index[back].prev == -1 ? 0 : index[back].prev;
            if (index.Count > 1)
            {
                index[index[back].next] = new StructIndex(index[index[back].next].next, -1);
            }
            items.RemoveAt(delBack);
            index.RemoveAt(delBack);
            for (int i = 0; i < index.Count; i++)
            {
                index[i] = new StructIndex(index[i].next != -1 ? index[i].next - 1 : -1, index[i].prev != -1 ? index[i].prev - 1 : -1);
            }
            top -= 1;
            return firstItem;
        }
        public void WriteLine()
        {
            foreach (var item in items)
            {
                Console.Write("(" + item + ") ");
            }
            Console.WriteLine();
        }
        public bool isEmpty()
        {
            if (items.Count == 0)
                return true;
            return false;
        }
    }
}
