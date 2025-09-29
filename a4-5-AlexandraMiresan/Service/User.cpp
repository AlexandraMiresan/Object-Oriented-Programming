//
// Created by Ale on 4/3/2025.
//

#include "User.h"

int User::addEventToUserList(int id) {
    int repoSize = this->repo->getRepository().get_size();

    for (int i = 0; i < repoSize; ++i) {
        Event event = this->repo->getRepository().get_elem(i);

        if (event.getId() == id) {
            // Check if the event already exists in user's list
            for (int j = 0; j < this->userEvents.get_size(); ++j) {
                if (this->userEvents.get_elem(j).getId() == id) {
                    throw std::invalid_argument("Event already exists");
                }
            }

            // Add to user's list
            this->userEvents.add(event);

            // Increase number of people
            int numberOfPeople = event.getNumberOfPeople() + 1;
            event.setNumberOfPeople(numberOfPeople);

            return 0;
        }
    }

    throw std::invalid_argument("Event does not exist");
}


int User::removeEventFromUserList(int id) {
    for (int i = 0; i < this->userEvents.get_size(); i++) {
        if (this->userEvents.get_elem(i).getId() == id) {
            this->userEvents.remove(i);
            return 0;
        }
    }

    throw std::invalid_argument("Event does not exist");
}

DynamicVector<Event>& User::getSortedEvents() {
    for(int i = 0; i < this->repo->getRepository().get_size() - 1; i++) {
        for(int j = i + 1; j < this->repo->getRepository().get_size(); j++) {
            if(this->repo->getRepository().get_elem(i).getDate() == this->repo->getRepository().get_elem(j).getDate()) {
                if(this->repo->getRepository().get_elem(i).getTime() > this->repo->getRepository().get_elem(j).getTime()) {
                    Event aux = this->repo->getRepository().get_elem(i);
                    this->repo->getRepository().set_elem(i, this->repo->getRepository().get_elem(j));
                    this->repo->getRepository().set_elem(j, aux);
                }
            }
            if(this->repo->getRepository().get_elem(i).getDate() > this->repo->getRepository().get_elem(j).getDate()) {
                Event aux = this->repo->getRepository().get_elem(i);
                this->repo->getRepository().set_elem(i, this->repo->getRepository().get_elem(j));
                this->repo->getRepository().set_elem(j, aux);
            }
        }
    }

    return this->repo->getRepository();
}
