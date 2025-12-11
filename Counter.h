#pragma once
#include <string>

class Counter
{
public:
    Counter();
    Counter(int number,
        const std::string& name,
        int count_place,
        int sell_ticket,
        double ticket_price);

    // геттеры
    int getNumber() const;
    const std::string& getStationName() const;
    int getCountPlace() const;
    int getSellTicket() const;
    double getTicketPrice() const;
    int getUnsoldCount() const;
    double getUnsoldAmount() const;

    // сеттеры
    void setNumber(int n);
    void setStationName(const std::string& name);
    void setCountPlace(int c);
    void setSellTicket(int s);
    void setTicketPrice(double p);

private:
    int         number;
    std::string name_station;
    int         count_place;
    int         sell_ticket;
    double      ticket_price;
};
