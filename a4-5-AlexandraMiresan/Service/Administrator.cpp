//
// Created by Ale on 4/3/2025.
//

#include "Administrator.h"

int Administrator::addEventAdmin(std::string title, std::string description, std::chrono::year_month_day date,
                                 double time, int numberOfPeople, std::string link) {
    Event event = Event(title, description, date, time, numberOfPeople, link);
    return this->repo->addRepo(event);
}

int Administrator::removeEventAdmin(int id) {
    return this->repo->deleteRepo(id);
}

int Administrator::updateEventAdmin(int id, std::string title, std::string description,
                                    std::chrono::year_month_day date, double time, int numberOfPeople,
                                    std::string link) {
    int repoSize = this->repo->getRepository().get_size();

    for (int i = 0; i < repoSize; ++i) {
        Event event = this->repo->getRepository().get_elem(i);

        if (event.getId() == id) {
            if (event.getTitle() != title) {
                event.setTitle(title);
            }
            if (event.getDescription() != description) {
                event.setDescription(description);
            }
            if (event.getDate() != date) {
                event.setDate(date);
            }
            if (event.getTime() != time) {
                double checkTime = time - static_cast<int>(time);
                if (time > 24.0 || time < 1.0 || checkTime >= 1.0 || checkTime < 0) {
                    throw std::invalid_argument("Invalid time");
                }
                event.setTime(time);
            }
            if (event.getNumberOfPeople() != numberOfPeople) {
                event.setNumberOfPeople(numberOfPeople);
            }
            if (event.getLink() != link) {
                event.setLink(link);
            }

            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}


int Administrator::updateTitleAdmin(int id, std::string title) {
    int repoSize = this->repo->getRepository().get_size();

    for (int i = 0; i < repoSize; ++i) {
        Event event = this->repo->getRepository().get_elem(i);  // Use reference

        if (event.getId() == id) {
            event.setTitle(title);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

int Administrator::updateDescriptionAdmin(int id, std::string description) {
    int repoSize = this->repo->getRepository().get_size();

    for (int i = 0; i < repoSize; ++i) {
        Event event = this->repo->getRepository().get_elem(i);  // Reference to real object

        if (event.getId() == id) {
            event.setDescription(description);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

int Administrator::updateDateAdmin(int id, std::chrono::year_month_day date) {
    int repoSize = this->repo->getRepository().get_size();

    for (int i = 0; i < repoSize; ++i) {
        Event event = this->repo->getRepository().get_elem(i);

        if (event.getId() == id) {
            event.setDate(date);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

int Administrator::updateTimeAdmin(int id, double time) {
    int repoSize = this->repo->getRepository().get_size();

    for (int i = 0; i < repoSize; ++i) {
        Event event = this->repo->getRepository().get_elem(i);

        if (event.getId() == id) {
            event.setTime(time);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}


int Administrator::updateNumberOfPeopleAdmin(int id, int numberOfPeople) {
    int repoSize = this->repo->getRepository().get_size();

    for (int i = 0; i < repoSize; ++i) {
        Event event = this->repo->getRepository().get_elem(i);

        if (event.getId() == id) {
            event.setNumberOfPeople(numberOfPeople);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

int Administrator::updateLinkAdmin(int id, std::string link) {
    int repoSize = this->repo->getRepository().get_size();

    for (int i = 0; i < repoSize; ++i) {
        Event event = this->repo->getRepository().get_elem(i);

        if (event.getId() == id) {
            event.setLink(link);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}
