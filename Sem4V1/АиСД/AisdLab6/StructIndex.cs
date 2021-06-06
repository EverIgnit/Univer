namespace AisdLab6
{
    public struct StructIndex
    {
        public int next;
        public int prev;
        public StructIndex(int next, int prev)
        {
            this.next = next;
            this.prev = prev;
        }
    }
}
