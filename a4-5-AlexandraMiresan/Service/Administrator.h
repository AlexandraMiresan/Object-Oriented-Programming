#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "../Repository/Repository.h"
#include "../Domain/Event.h"

class Administrator {
private:
    Repository* repo;

public:
    explicit Administrator(Repository* r) : repo(r) {}

    // Add event
    int addEventAdmin(std::string title, std::string description, std::chrono::year_month_day date,
                      double time, int numberOfPeople, std::string link);

    // Remove event
    int removeEventAdmin(int id);

    // Update individual fields of event
    int updateTitleAdmin(int id, std::string title);
    int updateDescriptionAdmin(int id, std::string description);
    int updateDateAdmin(int id, std::chrono::year_month_day date);
    int updateTimeAdmin(int id, double time);
    int updateNumberOfPeopleAdmin(int id, int numberOfPeople);
    int updateLinkAdmin(int id, std::string link);

    // Update entire event
    int updateEventAdmin(int id, std::string title, std::string description,
                         std::chrono::year_month_day date, double time,
                         int numberOfPeople, std::string link);

    // Get all events in the repository
    DynamicVector<Event> getAllEventsAdmin() const { return this->repo->getRepository(); }
};

#endif // ADMINISTRATOR_H
