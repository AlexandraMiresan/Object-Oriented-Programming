//
// Created by Ale on 5/8/2025.
//

#ifndef EVENTLIST_H
#define EVENTLIST_H
#include <vector>

#include "Event.h"


class EventList {
protected:
    std::vector<Event> events;
    int index;
    std::string type;

public:
    EventList();
    EventList(std::vector<Event> e, int index);
    ~EventList();

    std::string getType(){return this->type;}
    int getSize(){return this->events.size();}

    virtual void addEventList(Event &e);
    virtual void removeEventList(Event &e);

    Event getCurrentEvent();
    void next();
    bool isEmpty();
    void openLink();

    int findEventList(Event &e);
    std::vector<Event> getEventList(){return this->events;}

    virtual void writeToFile()=0;
    virtual void openInApp()=0;

};

class EventListRepoException: public std::exception {
private:
    std::string message;
    public:
    explicit EventListRepoException(std::string message);
    const char *what() const  noexcept override;
};


#endif //EVENTLIST_H
