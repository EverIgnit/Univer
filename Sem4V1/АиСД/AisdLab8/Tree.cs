using System;
using System.Collections.Generic;

namespace AiSDlab8
{
    public abstract class Tree<T> where T : IComparable
    {
        protected Node<T> root;
        public abstract void push(T value);
        public abstract bool remove(Node<T> value);
        protected abstract Node<T> search(Node<T> node, T value);

        public Node<T> search(T value)
        {
            return search(root, value);
        }

        public int getHeight()
        {
            return getHeight(root);
        }

        public int getDepth()
        {
            return getDepth(root);
        }

        public void directBypass()
        {
            Console.WriteLine();
            directBypass(root);
        }

        public int getLevel(Node<T> node)
        {
            return getHeight() - getDepth(node);
        }

        public void reverseRound()
        {
            Console.WriteLine();
            reverseRound(root);
        }

        public void symmetricalBypass()
        {
            Console.WriteLine();
            symmetricalBypass(root);
        }

        protected List<int> Larray;
        public void drawTree()
        {
            Larray = new List<int>();
            drawTree(root);
        }
        protected abstract void drawTree(Node<T> node);

        protected abstract int getHeight(Node<T> node);
        protected abstract int getDepth(Node<T> node);

        protected abstract void directBypass(Node<T> node);
        protected abstract void reverseRound(Node<T> node);
        protected abstract void symmetricalBypass(Node<T> node);
    }
}
