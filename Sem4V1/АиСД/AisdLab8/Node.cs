namespace AiSDlab8
{
    public class Node<T>
    {
        T value;
        Node<T> left;
        Node<T> right;
        Node<T> parent;

        public Node(T value, Node<T> parent)
        {
            this.value = value;
            this.parent = parent;
        }

        public T Value
        {
            set => this.value = value;
            get => this.value;
        }

        public Node<T> Left
        {
            set => this.left = value;
            get => this.left;
        }

        public Node<T> Right
        {
            set => this.right = value;
            get => this.right;
        }

        public Node<T> Parent
        {
            set => this.parent = value;
            get => this.parent;
        }

        public int leftChilds()
        {
            if (Left == null) return 0;
            return Left.childs();
        }

        public int rightChilds()
        {
            if (Right == null) return 0;
            return Right.childs();
        }

        private int childs()
        {
            return childCount(Left) + childCount(Right) + 1;
        }

        private int childCount(Node<T> node)
        {
            if (node == null) return 0;
            if (node.Left == null && node.Right == null)
                return 1;
            else
                return childCount(node.Left) + childCount(node.Right) + 1;
        }

        public bool removeChildNode(Node<T> node)
        {
            if (node == Right)
            {
                Right = null;
                return true;
            }
            else if (node == Left)
            {
                Left = null;
                return true;
            }
            return false;
        }

        public bool replaceChildNode(Node<T> oldNode, Node<T> newNode)
        {
            if (oldNode == Right)
            {
                Right = newNode;
                newNode.Parent = this;
                return true;
            }
            else if (oldNode == Left)
            {
                newNode.Parent = this;
                Left = newNode;
                return true;
            }
            return false;
        }
    }
}
