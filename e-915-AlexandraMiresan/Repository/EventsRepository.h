//
// Created by Ale on 6/25/2025.
//

#ifndef EVENTSREPOSITORY_H
#define EVENTSREPOSITORY_H

#include <vector>
#include <memory>
#include "../Domain/Event.h"
#include "../Observer/Subject.h"
class EventsRepository : public Subject {
private:
    std::vector<std::shared_ptr<Event>> events;
public:
    EventsRepository() {
        this->events = readFromFile();
    }
    ~EventsRepository()=default;
    std::vector<std::shared_ptr<Event>> getAllEvents(){return this->events;}
    void addEvent(std::shared_ptr<Event> event) {
        this->events.push_back(event);
        notify();
        writeToFile();
    }
private:
    std::vector<std::shared_ptr<Event>> readFromFile();
    void writeToFile();
};



#endif //EVENTSREPOSITORY_H
