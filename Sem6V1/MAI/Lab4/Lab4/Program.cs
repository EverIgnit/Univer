using System;
using System.Linq;
using System.Collections.Generic;
using System.Collections;
class Program
{
    public AirPort shumilino = new();
    public List<AirPort> moscowAirPorts = new();
    static void Main() => new Program().F();
    void F()
    {
        PlaneRace planeRace = new() { Arrival = DateTime.Now, Departure = DateTime.Now, Sits = new Random().Next(50, 200) };
        Ticket ticket = new() { Price = new Random().Next(100, 1000) };
        planeRace.Tickets.Add(ticket);
        shumilino.TicketWindow.Tickets.Add(ticket);
        shumilino.PlaneRacesTimeTable.Add(planeRace);
        moscowAirPorts.Add(shumilino);
        moscowAirPorts.Add(shumilino);
        Console.WriteLine("Select a variable by its number:");
        typeof(Program).GetFields().ToList().ForEach(Console.WriteLine);
        var choise = typeof(Program).GetFields()[int.Parse(Console.ReadLine())];
        Console.WriteLine($"{choise.Name}{InfoDisplayer.InfoBy(choise.GetValue(this))}");
    }
}
static class InfoDisplayer
{
    public static string InfoBy(object obj)
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
                res += $"\n{count}{InfoBy(el)}";
                count++;
            }
        }
        else if (type.IsClass)
        {
            res += " which has";
            var props = type.GetProperties();
            foreach (var prop in props)
                res += $"\n{prop.Name}{InfoBy(prop.GetValue(obj))}";
        }
        else
            res += " and it equals to " + obj;
        return res.Replace("\n", "\n ");
    }
}
class AirPort 
{
    public TimeTable PlaneRacesTimeTable { get; } = new();
    public TicketWindow TicketWindow { get; } = new();
}
class TimeTable : List<PlaneRace>{}
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
