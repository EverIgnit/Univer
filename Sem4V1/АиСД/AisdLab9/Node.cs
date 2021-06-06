using System;
using System.Collections.Generic;

namespace AisdLab9
{
    public class Node<T> where T : IComparable
    {
        protected T value;
        protected Node<T> parent;
        protected List<Node<T>> childs;

        public Node(T value, Node<T> parent)
        {
            this.value = value;
            this.parent = parent;
            childs = new List<Node<T>>();
        }

        public T Value
        {
            set => this.value = value;
            get => this.value;
        }

        public List<Node<T>> Childs
        {
            get => this.childs;
            set => this.childs = value;
        }

        public Node<T> Parent
        {
            set => this.parent = value;
            get => this.parent;
        }
    }
}