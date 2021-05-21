using System;
using Var1;
using System.Linq;
using System.Collections.Generic;
using System.Collections;
class Program
{
    // Fields to display info about
    public AirPort shumilino = new();
    public List<AirPort> moscowAirPorts = new();
    // Program starting point
    static void Main() => new Program().MainFunc();
    // Main program
    void MainFunc()
    {
        // Creating objects to display
        PlaneRace planeRace = new() { Arrival = DateTime.Now, Departure = DateTime.Now, Sits = new Random().Next(50, 200) };
        Ticket ticket = new() { Price = new Random().Next(100, 1000) };
        planeRace.Tickets.Add(ticket);
        shumilino.TicketWindow.Tickets.Add(ticket);
        shumilino.PlaneRacesTimeTable.Add(planeRace);
        moscowAirPorts.Add(shumilino);
        moscowAirPorts.Add(shumilino);
        // Hadnling the input
        Console.WriteLine("Select a variable by its number:");
        typeof(Program).GetFields().ToList().ForEach(Console.WriteLine);
        var choise = typeof(Program).GetFields()[int.Parse(Console.ReadLine())];
        Console.WriteLine($"{choise.Name}{InfoOf(choise.GetValue(this))}");
    }
    // Method return the info of the specified object and it's parts
    static string InfoOf(object obj)
    {
        var type = obj.GetType();
        var res = $" - a{("eyuioa".ToUpper().Contains(type.Name.First()) ? 'n' : string.Empty)} {type.Name}";
        if (typeof(IEnumerable).IsAssignableFrom(type))
        {
            res += " which consists of";
            var list = (IEnumerable)obj;
            var count = 0;
            foreach (var el in list)
            {
                res += $"\n{count}{InfoOf(el)}";
                count++;
            }
        }
        else if (type.IsClass)
        {
            res += " which has";
            var props = type.GetProperties();
            foreach (var prop in props)
                res += $"\n{prop.Name}{InfoOf(prop.GetValue(obj))}";
        }
        else
            res += " and it equals to " + obj;
        return res.Replace("\n", "\n ");
    }
}
// Change the classes of this namespace to change your variant
namespace Var1
{
    class AirPort
    {
        public TimeTable PlaneRacesTimeTable { get; } = new();
        public TicketWindow TicketWindow { get; } = new();
    }
    class TimeTable : List<PlaneRace> { }
    class PlaneRace
    {
        public int Sits { get; init; }
        public DateTime Arrival { get; set; }
        public DateTime Departure { get; set; }
        public List<Ticket> Tickets { get; } = new();
    }
    class TicketWindow
    {
        public List<Ticket> Tickets { get; } = new();
        public bool IsAvaliable(int num) => Tickets.ElementAtOrDefault(num)?.Avaliable ?? false;
        public void BuyTicket(int num) { if (IsAvaliable(num)) Tickets.RemoveAt(num); }
    }
    class Ticket
    {
        public virtual int Price { get; set; }
        public bool Avaliable { get; set; } = true;
    }
    class LuxTicket : Ticket
    {
        public override int Price { get => base.Price * 2; set => base.Price = value; }
    }

}
