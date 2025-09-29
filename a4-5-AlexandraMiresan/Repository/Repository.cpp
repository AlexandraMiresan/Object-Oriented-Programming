//
// Created by Ale on 4/3/2025.
//

#include "Repository.h"


int Repository::addRepo(Event &event) {
    Event aux;
    double checkTime = event.getTime() - static_cast<int>(event.getTime());
    if(event.getTime() > 24.00 || event.getTime() < 1.00 || checkTime > 59 || checkTime < 0) {
        throw std::invalid_argument("Repository::addRepo: Invalid time");
    }
    for (int i = 0; i < this->events.get_size(); i++) {
        aux = this->events.get_elem(i);
        if (aux.getTitle() == event.getTitle() && aux.getDate() == event.getDate() && aux.getTime() == event.
            getTime()) {
            throw std::invalid_argument("Event already exists");
        }
    }
    this->events.add(event);
    return 0;
}

int Repository::deleteRepo(int id) {
    Event aux;
    for (int i = 0; i < this->events.get_size(); i++) {
        aux = this->events.get_elem(i);
        if (aux.getId() == id) {
            this->events.remove(i);
            return 0;
        }
    }
    throw std::invalid_argument("Event does not exist");
}

int Repository::updateRepo(int id, Event &event) {
    Event aux;
    for (int i = 0; i < this->events.get_size(); i++) {
        aux = this->events.get_elem(i);
        if(aux.getId() == id) {
            this->events.set_elem(i, event);
            return 0;
        }
    }

    throw std::invalid_argument("Event does not exist");

}

