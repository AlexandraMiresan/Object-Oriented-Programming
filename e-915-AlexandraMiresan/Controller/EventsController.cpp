//
// Created by Ale on 6/25/2025.
//

#include "EventsController.h"
#include <cmath>

std::vector<std::shared_ptr<Event>> EventsController::getSortedEvents(Person& person) {
    std::vector<std::shared_ptr<Event>> loadedEvents;

    for(auto& event: eventsRepo.getAllEvents()) {
        double euclideanEvent = sqrt((event->getLocation().getLatitudeX() + event->getLocation().getLongitudeX()) *
            (event->getLocation().getLatitudeX() + event->getLocation().getLongitudeX()) + (event->getLocation().getLatitudeY() + event->getLocation().getLongitudeY())*
            (event->getLocation().getLatitudeY() + event->getLocation().getLongitudeY()));
        double euclideanPerson =sqrt((person.getLocation().getLatitudeX() + person.getLocation().getLongitudeX()) *
            (person.getLocation().getLatitudeX() + person.getLocation().getLongitudeX()) + (person.getLocation().getLatitudeY() + person.getLocation().getLongitudeY())*
            (person.getLocation().getLatitudeY() + person.getLocation().getLongitudeY()));
        if(abs(euclideanEvent - euclideanPerson) < 5) {
            loadedEvents.push_back(event);
        }
    }

    return loadedEvents;
}