#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <stack>

#include "../Repository/EventList.h"
#include "../Repository/Repository.h"
#include "../Domain/Event.h"

#include "../UndoRedo/UndoRedo.h"

class Administrator {
private:
    Repository* repo;
    EventList *eventList;
    std::stack<UndoRedo*> undoStack;
    std::stack<UndoRedo*> redoStack;

public:
    explicit Administrator(Repository* r) : repo(r) {}

    // Add event
    void addEventAdmin(std::string title, std::string description, std::chrono::year_month_day date,
                       double time, int numberOfPeople, std::string link);

    // Remove event
    void removeEventAdmin(int id);

    void saveToFile() {
        this->repo->saveToFile();
    }

    // Update individual fields of event
    void updateTitleAdmin(int id, std::string title);
    void updateDescriptionAdmin(int id, std::string description);
    void updateDateAdmin(int id, std::chrono::year_month_day date);
    void updateTimeAdmin(int id, double time);
    void updateNumberOfPeopleAdmin(int id, int numberOfPeople);
    void updateLinkAdmin(int id, std::string link);

    // Update entire event
    void updateEventAdmin(int id, std::string title, std::string description,
                         std::chrono::year_month_day date, double time,
                         int numberOfPeople, std::string link);

    // Get all events in the repository
    std::vector<Event>& getAllEventsAdmin(){ return this->repo->getRepo(); }

    void undo();
    void redo();
    ~Administrator() {
        delete this->repo;
        while(!undoStack.empty()) {delete undoStack.top(); undoStack.pop();}
        while(!redoStack.empty()) {delete redoStack.top(); redoStack.pop();}
    }
};

#endif // ADMINISTRATOR_H
