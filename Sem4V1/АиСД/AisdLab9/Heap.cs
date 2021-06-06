using System;
using System.Collections.Generic;

namespace AisdLab9
{
    public abstract class Heap<T> where T : IComparable
    {
        protected Node<T> root;

        public Node<T> Root
        {
            get => this.root;
            set => this.root = value;
        }

        public abstract void push(T value);
        public abstract void remove(Node<T> node);
        protected abstract Node<T> popLast(Node<T> node);

        public int getDepth()
        {
            return getDepth(root);
        }

        public Node<T> popLast()
        {
            return popLast(root);
        }

        protected List<int> Larray;
        public void drawTree()
        {
            Larray = new List<int>();
            drawTree(root);
        }
        protected abstract int getDepth(Node<T> node);
        protected abstract void drawTree(Node<T> node);
    }
}