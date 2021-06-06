using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace AisdLab6
{
    public class Deque<T>
    {
        List<T> items;
        List<StructIndex> index;
        int back;
        int top;
        public int Count
        {
            get
            {
                return items.Count;
            }
        }
        public Deque()
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

        public T pop()
        {
            if (isEmpty()) return default(T);
            T lastItem = items[top];
            int delTop = top;
            if (index.Count > 1)
            {
                index[index[top].prev] = new StructIndex(-1, index[index[top].prev].prev);
            }
            top = index[top].prev;
            items.RemoveAt(delTop);
            index.RemoveAt(delTop);
            return lastItem;
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

        public void Write()
        {
            foreach (var item in items)
            {
                Console.Write("(" + item + ") ");
            }
        }

        public bool isEmpty()
        {
            if (items.Count == 0)
                return true;
            return false;
        }
    }
}
