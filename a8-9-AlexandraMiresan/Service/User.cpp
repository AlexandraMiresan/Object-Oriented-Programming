#include "User.h"
#include <algorithm>

// Add event to the user's event list
int User::addEventToUserList(int id) {
    // Retrieve the event from the repository by ID
    std::vector<Event> allEvents = repo->getRepo();  // Get all events from the repo

    for (auto& event : allEvents) {  // Use non-const reference to allow modification
        if (event.getId() == id) {
            // Check if the event already exists in the user's list
            if(this->eventsList->findEventList(event) != -1) {
                throw std::invalid_argument("Event already exists");
            }

            event.setNumberOfPeople(event.getNumberOfPeople() + 1);

            eventsList->addEventList(event);

            return 0;  // Success
        }
    }

    throw std::invalid_argument("Event does not exist");
}

void User::saveToFile() {
    this->eventsList->writeToFile();
}

void User::openInApp() {
    this->eventsList->openInApp();
}


int User::removeEventFromUserList(int id) {
    if(id < 0 || id > this->eventsList->getSize()) {
        throw std::invalid_argument("Event does not exist");
    }
    for(auto &event : repo->getRepo()) {
        if (event.getId() == id) {
            if (this->eventsList->findEventList(event) != -1) {
                this->eventsList->removeEventList(event);
                return 0;
            }
        }
    }

    throw std::invalid_argument("Event does not exist in user's list");
}

std::vector<Event> User::getSortedEvents() {
    std::vector<Event> sortedEvents = this->repo->getRepo();  // Make a copy to sort

    std::sort(sortedEvents.begin(), sortedEvents.end(), [](Event& a, Event& b) {
        if (a.getDate() == b.getDate()) {
            return a.getTime() < b.getTime();  // Sort by time if same date
        }
        return a.getDate() < b.getDate();  // Otherwise, sort by date
    });

    return sortedEvents;
}

