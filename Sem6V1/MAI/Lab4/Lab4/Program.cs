using System;
using System.Linq;
using System.Collections.Generic;
var query = Console.ReadLine();
enum InfoType { Is, Has, Equals }
interface IInfoDisplayer 
{
    public string Info(string query)
    {
        var pars = query.Split(' ');
        if (pars.Contains("contains")) {
            var props = GetType().GetProperties();
            foreach (var prop in props)
                if (pars.Contains(prop.Name))
                    return "Yes";
        }
    }
}
class Aeroport : IInfoDisplayer
{
    public TimeTable PlaneRaces { get; } = new();
    public TicketWindow TicketWindow { get; } = new();

    public string Info(string query)
    {
        var pars = query.Split(' ');
        if (pars.Contains("is")) return "No";
        if (pars.Contains(""))
    }
}
class TimeTable : List<PlaneRace>{}
class PlaneRace : IInfoDisplayer
{
    public int Sits { get; init; }
    public DateTime Arrival { get; private set; }
    public DateTime Departure { get; private set; }
    public List<Ticket> Tickets { get; } = new();

    public string Info(string query)
    {
        throw new NotImplementedException();
    }
}
class TicketWindow : IInfoDisplayer
{
    private List<Ticket> Tickets { get; } = new();
    public bool IsAvaliable(int num) => Tickets.ElementAtOrDefault(num)?.Avaliable ?? false;
    public void BuyTicket(int num) { if (IsAvaliable(num)) Tickets.RemoveAt(num); }

    public string Info(string query)
    {
        throw new NotImplementedException();
    }
}
class Ticket : IInfoDisplayer
{
    public virtual int Price { get; protected set; }
    public bool Avaliable { get; set; }

    public string Info(string query)
    {
        throw new NotImplementedException();
    }
}
class LuxTicket : Ticket
{
    public override int Price { get => base.Price * 2; protected set => base.Price = value; }
}
