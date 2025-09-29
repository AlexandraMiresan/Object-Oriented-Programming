#ifndef USER_H
#define USER_H

#include "../Repository/Repository.h"
#include "../Domain/Event.h"
#include <vector>  // Include for std::vector

#include "../Repository/EventList.h"

class User {
private:
    Repository* repo;  // Repository instance to interact with the events
    EventList* eventsList;  // List of events specific to the user
    int size;

public:
    explicit User(Repository* r, EventList *e) : repo(r), eventsList(e) {
        this->size = 0;
    }

    // Method to get the sorted list of events for the user
    std::vector<Event> getSortedEvents();

    void saveToFile();
    void openInApp();
    // Add an event to the user's event list
    int addEventToUserList(int id);

    int getSize(){return this->size;}

    // Remove an event from the user's event list
    int removeEventFromUserList(int id);

    // Get the user's list of events (return a reference to the vector)
    std::vector<Event> getUserEvents() { return this->eventsList->getEventList();}

    int getUserEvent(Event e);
};

#endif //USER_H
