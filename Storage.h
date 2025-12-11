#pragma once
#include <vector>
#include <string>
#include "Counter.h"

class Storage
{
private:
    std::vector<Counter> counters;
    int nextNumber;

    static Storage* instance;

    Storage(); // приватный

public:
    Storage(const Storage&) = delete;
    Storage& operator=(const Storage&) = delete;

    ~Storage();

    static Storage* getInstance();

    // доступ к данным
    const std::vector<Counter>& getCounters() const;
    Counter* getCounter(size_t index);

    // CRUD
    void addCounter(const Counter& c);
    void updateCounter(size_t index, const Counter& c);
    void removeCounter(size_t index);
    void clear();

    // сортировка
    void sortByNumber();
    void sortByName();
    void sortByUnsoldAmountDesc();

    // генерация нового номера направления
    int generateNextNumber();

    // файл
    bool loadFromFile(const std::string& path);
    bool saveToFile(const std::string& path);
};
