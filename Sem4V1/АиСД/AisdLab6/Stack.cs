using System;
using System.Collections.Generic;

namespace AisdLab6
{
    public class Stack<T>
    {
        List<T> items;
        List<int> index;
        int top;

        public Stack()
        {
            items = new List<T>();
            index = new List<int>();
            top = 0;
        }

        public void push(T item)
        {
            items.Add(item);
            if (index.Count == 0)
                index.Add(-1);
            else
                index.Add(top);
            top = index.Count - 1;
        }

        public T pop()
        {
            if (isEmpty())
                return default(T);
            T lastItem = items[top];
            int delTop = top;
            top = index[top] == -1 ? 0 : index[top];
            items.RemoveAt(delTop);
            index.RemoveAt(delTop);
            return lastItem;
        }

        public void WriteLine()
        {
            foreach (var item in items)
                Console.Write("(" + item + ") ");
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
