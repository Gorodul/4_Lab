#include "Storage.h"
#include <fstream>
#include <algorithm>

Storage* Storage::instance = nullptr;

Storage::Storage()
    : nextNumber(1)
{
}

Storage::~Storage()
{
    instance = nullptr;
}

Storage* Storage::getInstance()
{
    if (instance == nullptr)
        instance = new Storage();
    return instance;
}

const std::vector<Counter>& Storage::getCounters() const
{
    return counters;
}

Counter* Storage::getCounter(size_t index)
{
    if (index >= counters.size())
        return nullptr;
    return &counters[index];
}

void Storage::addCounter(const Counter& c)
{
    counters.push_back(c);
    if (c.getNumber() >= nextNumber)
        nextNumber = c.getNumber() + 1;
}

void Storage::updateCounter(size_t index, const Counter& c)
{
    if (index < counters.size())
        counters[index] = c;
}

void Storage::removeCounter(size_t index)
{
    if (index < counters.size())
        counters.erase(counters.begin() + index);
}

void Storage::clear()
{
    counters.clear();
    nextNumber = 1;
}

void Storage::sortByNumber()
{
    std::sort(counters.begin(), counters.end(),
        [](const Counter& a, const Counter& b)
        {
            return a.getNumber() < b.getNumber();
        });
}

void Storage::sortByName()
{
    std::sort(counters.begin(), counters.end(),
        [](const Counter& a, const Counter& b)
        {
            return a.getStationName() < b.getStationName();
        });
}

void Storage::sortByUnsoldAmountDesc()
{
    std::sort(counters.begin(), counters.end(),
        [](const Counter& a, const Counter& b)
        {
            return a.getUnsoldAmount() > b.getUnsoldAmount();
        });
}

int Storage::generateNextNumber()
{
    return nextNumber++;
}

// формат строки: number;name;price;count_place;sell_ticket
bool Storage::loadFromFile(const std::string& path)
{
    std::ifstream in(path);
    if (!in.is_open()) return false;

    counters.clear();
    nextNumber = 1;

    std::string line;
    while (std::getline(in, line))
    {
        if (line.empty()) continue;

        size_t p1 = line.find(';');
        size_t p2 = line.find(';', p1 + 1);
        size_t p3 = line.find(';', p2 + 1);
        size_t p4 = line.find(';', p3 + 1);

        if (p1 == std::string::npos ||
            p2 == std::string::npos ||
            p3 == std::string::npos ||
            p4 == std::string::npos)
            continue;

        int number = std::stoi(line.substr(0, p1));
        std::string name = line.substr(p1 + 1, p2 - p1 - 1);
        double price = std::stod(line.substr(p2 + 1, p3 - p2 - 1));
        int count_place = std::stoi(line.substr(p3 + 1, p4 - p3 - 1));
        int sell_ticket = std::stoi(line.substr(p4 + 1));

        Counter c(number, name, count_place, sell_ticket, price);
        addCounter(c);
    }

    return true;
}

bool Storage::saveToFile(const std::string& path)
{
    std::ofstream out(path);
    if (!out.is_open()) return false;

    for (const auto& c : counters)
    {
        out << c.getNumber() << ';'
            << c.getStationName() << ';'
            << c.getTicketPrice() << ';'
            << c.getCountPlace() << ';'
            << c.getSellTicket() << '\n';
    }

    return true;
}
