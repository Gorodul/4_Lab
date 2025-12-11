#include "Counter.h"
#include <algorithm>

Counter::Counter()
    : number(0),
    name_station(""),
    count_place(0),
    sell_ticket(0),
    ticket_price(100.0)
{
}

Counter::Counter(int number,
    const std::string& name,
    int count_place,
    int sell_ticket,
    double ticket_price)
    : number(number),
    name_station(name),
    count_place(count_place),
    sell_ticket(sell_ticket),
    ticket_price(ticket_price)
{
}

int Counter::getNumber() const
{
    return number;
}

const std::string& Counter::getStationName() const
{
    return name_station;
}

int Counter::getCountPlace() const
{
    return count_place;
}

int Counter::getSellTicket() const
{
    return sell_ticket;
}

double Counter::getTicketPrice() const
{
    return ticket_price;
}

int Counter::getUnsoldCount() const
{
    int unsold = count_place - sell_ticket;
    return unsold < 0 ? 0 : unsold;
}

double Counter::getUnsoldAmount() const
{
    return static_cast<double>(getUnsoldCount()) * ticket_price;
}

void Counter::setNumber(int n)
{
    number = n;
}

void Counter::setStationName(const std::string& name)
{
    name_station = name;
}

void Counter::setCountPlace(int c)
{
    count_place = c;
}

void Counter::setSellTicket(int s)
{
    sell_ticket = s;
}

void Counter::setTicketPrice(double p)
{
    ticket_price = p;
}
