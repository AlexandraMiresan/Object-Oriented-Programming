#ifndef USER_H
#define USER_H

#include "../Repository/Repository.h"
#include "../Domain/Event.h"
#include <vector>  // Include for std::vector

#include "EventList.h"

class User {
private:
    Repository* repo;  // Repository instance to interact with the events
    EventList* eventsList;  // List of events specific to the user

public:
    explicit User(Repository* r, EventList *e) : repo(r), eventsList(e) {}

    // Method to get the sorted list of events for the user
    std::vector<Event> getSortedEvents();

    void saveToFile();
    void openInApp();
    // Add an event to the user's event list
    int addEventToUserList(int id);

    // Remove an event from the user's event list
    int removeEventFromUserList(int id);

    // Get the user's list of events (return a reference to the vector)
    std::vector<Event> getUserEvents() { return this->eventsList->getEventList();}
};

#endif //USER_H
