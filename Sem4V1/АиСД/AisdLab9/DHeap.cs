using System;
using System.Linq;

namespace AisdLab9
{
    public class DHeap<T> : Heap<T> where T : IComparable
    {
        private int d;
        private Node<T> lastNode;

        public DHeap(int d)
        {
            this.d = d;
        }

        public override void push(T value)
        {
            if (Root == null)
            {
                Root = new Node<T>(value, null);
            }
            else
            {
                Node<T> insertNode = getInsertPos(Root);
                Node<T> newNode = new Node<T>(value, insertNode);
                insertNode.Childs.Add(newNode);
                lastNode = newNode;
                while (newNode.Parent != null && newNode.Parent.Value.CompareTo(newNode.Value) == 1)
                {
                    swapValue(newNode, newNode.Parent);
                    newNode = newNode.Parent;
                }

            }
        }

        private Node<T> getInsertPos(Node<T> node)
        {
            if (node.Childs.Count < d)
            {
                return node;
            }
            Node<T> minNode = node.Childs[0];
            foreach (Node<T> snode in node.Childs)
            {
                if (snode.Childs.Count < d)
                {
                    minNode = snode;
                    break;
                }
            }
            return getInsertPos(minNode);
        }

        protected void swapValue(Node<T> first, Node<T> second)
        {
            T temp = first.Value;
            first.Value = second.Value;
            second.Value = temp;
        }

        public override void remove(Node<T> node)
        {
            if (node.Childs.Count == 0)
            {
                node.Value = lastNode.Value;
                lastNode.Parent.Childs.Remove(lastNode);
                lastNode = lastNode.Parent.Childs.Last();
                return;
            }
            else
            {
                Node<T> minNode = node.Childs[0];
                foreach (Node<T> snode in node.Childs)
                {
                    if (minNode.Value.CompareTo(snode.Value) == 1)
                    {
                        minNode = snode;
                    }
                }
                swapValue(minNode, node);
                remove(minNode);
            }
        }

        protected override int getDepth(Node<T> node)
        {
            int height = 0;
            Node<T> currentPos = node;
            while (currentPos.Parent != null)
            {
                height += 1;
                currentPos = currentPos.Parent;
            }
            return height;
        }

        private void drawLine(int height)
        {
            for (int i = 0; i < height; i++)
            {
                if (Larray.IndexOf(i) >= 0)
                {
                    Console.Write(" |");
                    i++;
                }
                Console.Write(" ");
            }
        }

        protected override Node<T> popLast(Node<T> node)
        {
            return null;
        }

        protected override void drawTree(Node<T> node)
        {
            Console.WriteLine((node.Parent == null ? "└" : "") + node.Value);
            if (node.Childs.Count == 0) return;
            Larray.Add(getDepth(node) * 2);

            for (int i = 0; i < d; i++)
            {
                if (i + 1 == d)
                {
                    Larray.Remove(getDepth(node) * 2);
                }
                drawLine(getDepth(node) * 2);
                if (node.Parent != null && node.Parent.Childs.IndexOf(node) == d - 1) Console.Write(" ");
                Console.Write(i + 1 != d ? " ├─" : " └─");
                Console.Write("[" + i + "]:");
                if (node.Childs.Count > i)
                {
                    drawTree(node.Childs[i]);
                }
                else
                {
                    Console.WriteLine("-");
                }
            }
            Larray.Remove(getDepth(node) * 2);
        }

    }
}