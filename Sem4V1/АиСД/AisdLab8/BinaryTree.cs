using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace AiSDlab8
{
    class BinaryTree<T>: Tree<T> where T: IComparable
    {
        public BinaryTree() {}
        public override void push(T value)
        {
            if (root == null)
            {
                root = new Node<T>(value, null);
                return;
            }
            Node<T> insertPos = getInsertPostion(root, value);
            if (insertPos.Value.CompareTo(value) < 0)
            {
                insertPos.Right = new Node<T>(value, insertPos);
            } else
            {
                insertPos.Left = new Node<T>(value, insertPos);
            }
        }
        public void push(T[] values)
        {
            if (values.Length!=0)
            root = new Node<T>(values[0], null);
            foreach (T i in values)
                {
                Node<T> insertPos = getInsertPostion(root, i);
                if (insertPos.Value.CompareTo(i) < 0)
                {
                    insertPos.Right = new Node<T>(i, insertPos);
                }
                else
                {
                    insertPos.Left = new Node<T>(i, insertPos);
                }
            }
        }

        private Node<T> getInsertPostion(Node<T> node, T value)
        {
            if (node.Value.CompareTo(value) < 0)
            {
                return node.Right != null ? getInsertPostion(node.Right, value) : node;
            } else if (node.Left != null)
            {
                return getInsertPostion(node.Left, value);
            } else
            {
                return node;
            }
        }

        public override bool remove(Node<T> delNode)
        {
            if (delNode.Left == null && delNode.Right == null)
            {
                delNode.Parent.removeChildNode(delNode);
            } else if (!(delNode.Left != null && delNode.Right != null))
            {
                delNode.Parent.replaceChildNode(delNode, delNode.Left != null ? delNode.Left : delNode.Right);
            } else
            {
                Node<T> replaceNode = rightLastFind(delNode);
                replaceNode.Left = delNode.Left;
                replaceNode.Right = delNode.Right;
                replaceNode.Parent.removeChildNode(replaceNode);
                replaceNode.Parent = delNode.Parent;
                if (delNode.Parent != null)
                {
                    delNode.Parent.replaceChildNode(delNode, replaceNode);
                } else
                {
                    root = replaceNode;
                    root.Left = delNode.Left;
                    root.Right = delNode.Right;
                }
            }
            return true;
        }

        protected Node<T> leftLastFind(Node<T> node)
        {
            if (node.Left == null && node.Right == null)
            {
                return node;
            } else
            {
                return leftLastFind(node.Left != null ? node.Left : node.Right);
            }
        }

        protected Node<T> rightLastFind(Node<T> node)
        {
            if (node.Left == null && node.Right == null)
            {
                return node;
            }
            else
            {
                return rightLastFind(node.Right != null ? node.Right : node.Left);
            }
        }

        public Node<T> searchMiddle()
        {
            List<Node<T>> nodes = new List<Node<T>>();
            searchNodesDifferentHereditary(root, nodes);
            return nodes[(int)(nodes.Count / 2)];
        }

        private void searchNodesDifferentHereditary(Node<T> node, List<Node<T>> nodes)
        {
            if (node != null)
            {
                if (node.leftChilds() != node.rightChilds())
                {
                    nodes.Add(node);
                }
                searchNodesDifferentHereditary(node.Left, nodes);
                searchNodesDifferentHereditary(node.Right, nodes);
            }
            return;
        }

        protected override Node<T> search(Node<T> node, T value)
        {
            if (node == null)
            {
                return null;
            }
            switch (node.Value.CompareTo(value))
            {
                case 0:
                    return node;
                case 1:
                    return search(node.Left, value);
                default:
                    return search(node.Right, value);
            }
        }

        private void drawLine(int height)
        {
            for (int i = 0; i < height; i++)
            {
                if (Larray.IndexOf(i) >= 0)
                {
                    Console.Write("|");
                    i++;
                }
                Console.Write(' ');
            }
        }

        protected override void drawTree(Node<T> node)
        {
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.WriteLine((node.Parent == null ? "└─" : "") + node.Value);
            if (node.Left == null && node.Right == null) return;
            Larray.Add(getHeight(node) * 2);

            drawLine(getHeight(node) * 2);

            Console.Write("├─");
            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.Write("L:");
            if (node.Left != null)
            {
                drawTree(node.Left);
            } else
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("-");
            }

            Larray.Remove(getHeight(node) * 2);
            Console.ForegroundColor = ConsoleColor.Gray;
            drawLine(getHeight(node) * 2);

            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write("└─");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.Write("R:");
            if (node.Right != null)
            {
                drawTree(node.Right);
            } else
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("-");
            }
            Console.ForegroundColor = ConsoleColor.Gray;
        }

        protected override int getHeight(Node<T> node)
        {
            if (node.Left != null && node.Right != null)
            {
                return Math.Max(getDepth(node.Left), getDepth(node.Right));
            }
            else if (node.Left != null)
            {
                return getDepth(node.Left);
            }
            else if (node.Right != null)
            {
                return getDepth(node.Right);
            }
            else
            {
                return 1;
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

        protected override void directBypass(Node<T> node)
        {
            if (node == null)
            {
                return;
            }
            Console.Write(node.Value + " ");
            directBypass(node.Left);
            directBypass(node.Right);
        }

        protected override void reverseRound(Node<T> node)
        {
            if (node.Left != null)
            {
                reverseRound(node.Left);
            }
            if (node.Right != null)
            {
                reverseRound(node.Right);
            }
            Console.Write(node.Value + " ");
        }

        protected override void symmetricalBypass(Node<T> node)
        {
            if (node.Left != null)
            {
                symmetricalBypass(node.Left);
            }
            Console.Write(node.Value + " ");
            if (node.Right != null)
            {
                symmetricalBypass(node.Right);
            }
        }
    }
}
