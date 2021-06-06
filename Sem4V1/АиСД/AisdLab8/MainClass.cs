namespace AiSDlab8
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree<int> tree = new BinaryTree<int>();
            int[] values = { 16, 13, 12, 7, 6, 1, 18, 11, 4 };
            tree.push(values);
            tree.drawTree();
            Node<int> node = tree.searchMiddle();
            tree.remove(node);
            tree.drawTree();
            tree.directBypass();
        }
    }
}
