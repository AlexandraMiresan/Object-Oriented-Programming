//
// Created by Ale on 6/25/2025.
//

#ifndef EVENTSCONTROLLER_H
#define EVENTSCONTROLLER_H
#include "../Repository/EventsRepository.h"
#include "../Domain/Person.h"

class EventsController {
private:
    EventsRepository& eventsRepo;
    std::vector<Person> attendants;
public:
    EventsController(EventsRepository& eventsRepo): eventsRepo(eventsRepo) {this->attendants = {};}
    ~EventsController()=default;
    std::vector<std::shared_ptr<Event>> getEvents() {
        return eventsRepo.getAllEvents();
    }
    std::vector<std::shared_ptr<Event>> getSortedEvents(Person& person);
    void addEvent(std::shared_ptr<Event> event) {
        eventsRepo.addEvent(event);

    }
    void addAttendant(Person& person) {
        attendants.push_back(person);
    }
    std::vector<Person> getAttendants() {return this->attendants;}
};



#endif //EVENTSCONTROLLER_H
