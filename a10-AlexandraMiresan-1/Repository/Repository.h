#pragma once
#include "../Domain/Event.h"
#include <vector>
#include <string>

class Repository {
protected:
    std::string filename;
    std::vector<Event> events;


public:
    Repository(std::string& file) : filename(file) {
        events = loadFromFile();
    }
    ~Repository() {}
    void addRepo(Event& e);
    std::string formatDate(std::chrono::year_month_day &date);
    std::chrono::year_month_day parseDate(std::string& date);
    bool removeRepo(int id);
    bool updateRepo(int id, Event& event);
    std::vector<Event>& getRepo() {return this->events;};
    void saveToFile();
    std::vector<Event> loadFromFile();
    Event getEvent(int id);
};

