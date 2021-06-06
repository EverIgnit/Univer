using System;
using System.Collections.Generic;
class Program
{
    static void Main(string[] args)
    {
        const int n = 1000000;
        double ctime = 0;
        HashTable<double> hashTable = new HashTable<double>(n);
        Random rand = new Random();
        DateTime startTime = DateTime.Now;
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            hashTable.add(i, rand.Next(0, 100));
            if (i == 100)
            {
                ctime = DateTime.Now.Subtract(startTime).TotalMilliseconds;
                Console.WriteLine("add first 100: " + ctime);
            }
            if (i == n - 100)
                startTime = DateTime.Now;
        }
        double time = DateTime.Now.Subtract(startTime).TotalMilliseconds;
        Console.WriteLine("add last 100: " + time);
        startTime = DateTime.Now;
        hashTable.get(rand.Next(0, n));
        time = DateTime.Now.Subtract(startTime).TotalMilliseconds;
        Console.WriteLine("search: " + time);
    }
}
public class Node<T>
{
    public int key;
    public T value;
    public Node(int key, T value)
    {
        this.key = key;
        this.value = value;
    }
}
public class HashTable<T>
{
    List<Node<T>>[] table;
    public int Size
    {
        get
        {
            return table.Length;
        }
    }
    public HashTable(int size)
    {
        table = new List<Node<T>>[size];
    }
    private int hash(int key)
    {
        return (int)((Int64)Math.Pow(key, 2) >> 11) % Size;
    }
    private void addToHashTable(List<Node<T>>[] table, Node<T> node)
    {
        int hashKey = hash(node.key);
        if (table[hashKey] == null)
            table[hashKey] = new List<Node<T>>(new Node<T>[] { node });
        else
            table[hashKey].Add(node);
    }
    public void add(int key, T value)
    {
        addToHashTable(table, new Node<T>(key, value));
    }
    public T get(int key)
    {
        foreach (var node in table[hash(key)])
            if (node.key == key)
                return node.value;
        return default(T);
    }
    public void resize(int size)
    {
        List<Node<T>>[] newTable = new List<Node<T>>[size];
        foreach (var listNode in table)
            if (listNode != null)
                foreach (var node in listNode)
                    addToHashTable(newTable, node);
        table = newTable;
    }
}