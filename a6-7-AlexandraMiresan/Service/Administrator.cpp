#include "Administrator.h"

// Add event
void Administrator::addEventAdmin(std::string title, std::string description,
                                  std::chrono::year_month_day date, double time,
                                  int numberOfPeople, std::string link) {
    Event event = Event(title, description, date, time, numberOfPeople, link);
    return this->repo->addRepo(event); // Assuming addEvent is properly defined in the repository
}

// Remove event
int Administrator::removeEventAdmin(int id) {
    return this->repo->removeRepo(id); // Assuming removeEvent is properly defined in the repository
}

// Update event title
int Administrator::updateTitleAdmin(int id, std::string title) {
    auto& events = this->repo->getRepo();  // Access the vector reference

    for (Event event : events) {  // Using reference to modify the event directly
        if (event.getId() == id) {
            event.setTitle(title);
            return this->repo->updateRepo(id, event); // Assuming updateEvent updates the event in the repository
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event description
int Administrator::updateDescriptionAdmin(int id, std::string description) {
    auto& events = this->repo->getRepo();

    for (auto event : events) {
        if (event.getId() == id) {
            event.setDescription(description);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event date
int Administrator::updateDateAdmin(int id, std::chrono::year_month_day date) {
    auto& events = this->repo->getRepo();

    for (auto event : events) {
        if (event.getId() == id) {
            event.setDate(date);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event time
int Administrator::updateTimeAdmin(int id, double time) {
    auto& events = this->repo->getRepo();

    for (auto event : events) {
        if (event.getId() == id) {
            event.setTime(time);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event number of people
int Administrator::updateNumberOfPeopleAdmin(int id, int numberOfPeople) {
    auto& events = this->repo->getRepo();

    for (auto event : events) {
        if (event.getId() == id) {
            event.setNumberOfPeople(numberOfPeople);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event link
int Administrator::updateLinkAdmin(int id, std::string link) {
    auto& events = this->repo->getRepo();

    for (auto event : events) {
        if (event.getId() == id) {
            event.setLink(link);
            return this->repo->updateRepo(id, event);
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update entire event
int Administrator::updateEventAdmin(int id, std::string title, std::string description,
                                    std::chrono::year_month_day date, double time,
                                    int numberOfPeople, std::string link) {
    auto& events = this->repo->getRepo();

    for (auto event : events) {
        if (event.getId() == id) {
            // Apply all the updates
            event.setTitle(title);
            event.setDescription(description);
            event.setDate(date);
            event.setTime(time);
            event.setNumberOfPeople(numberOfPeople);
            event.setLink(link);

            return this->repo->updateRepo(id, event);  // Assuming updateEvent method updates the event
        }
    }

    throw std::invalid_argument("Invalid id");
}
