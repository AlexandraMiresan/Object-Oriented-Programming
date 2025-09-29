#include "Administrator.h"
#include "../UndoRedo/UndoRedoAdd.h"
#include "../UndoRedo/UndoRedoRemove.h"
#include "../UndoRedo/UndoRedoUpdate.h"
// Add event
void Administrator::addEventAdmin(std::string title, std::string description,
                                  std::chrono::year_month_day date, double time,
                                  int numberOfPeople, std::string link) {
    Event event = Event(title, description, date, time, numberOfPeople, link);
    this->repo->addRepo(event);
    undoStack.push(new UndoRedoAdd(*repo, event));
    while(!redoStack.empty()) { delete redoStack.top(); redoStack.pop();}
}

// Remove event
void Administrator::removeEventAdmin(int id) {
    Event e = repo->getEvent(id);
    this->repo->removeRepo(id);
    undoStack.push(new UndoRedoRemove(*repo, e));
    while(!redoStack.empty()) { delete redoStack.top(); redoStack.pop();}
}

// Update event title
void Administrator::updateTitleAdmin(int id, std::string title) {
    auto& events = this->repo->getRepo();  // Access the vector reference
    Event oldE = repo->getEvent(id);
    for (Event event : events) {  // Using reference to modify the event directly
        if (event.getId() == id) {
            event.setTitle(title);
            this->repo->updateRepo(id, event); // Assuming updateEvent updates the event in the repository
            undoStack.push(new UndoRedoUpdate(*repo, oldE, event));
            while(!redoStack.empty()){ delete redoStack.top(); redoStack.pop();}
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event description
void Administrator::updateDescriptionAdmin(int id, std::string description) {
    auto& events = this->repo->getRepo();
    Event oldE = repo->getEvent(id);
    for (auto event : events) {
        if (event.getId() == id) {
            event.setDescription(description);
            this->repo->updateRepo(id, event);
            undoStack.push(new UndoRedoUpdate(*repo, oldE, event));
            while(!redoStack.empty()) { delete redoStack.top(); redoStack.pop();}
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event date
void Administrator::updateDateAdmin(int id, std::chrono::year_month_day date) {
    auto& events = this->repo->getRepo();
    Event oldE = repo->getEvent(id);
    for (auto event : events) {
        if (event.getId() == id) {
            event.setDate(date);
            this->repo->updateRepo(id, event);
            undoStack.push(new UndoRedoUpdate(*repo, oldE, event));
            while(!redoStack.empty()) {delete redoStack.top(); redoStack.pop();}
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event time
void Administrator::updateTimeAdmin(int id, double time) {
    auto& events = this->repo->getRepo();
    Event oldE = repo->getEvent(id);
    for (auto event : events) {
        if (event.getId() == id) {
            event.setTime(time);
            this->repo->updateRepo(id, event);
            undoStack.push(new UndoRedoUpdate(*repo, oldE, event));
            while(!redoStack.empty()) { delete redoStack.top(); redoStack.pop();}
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event number of people
void Administrator::updateNumberOfPeopleAdmin(int id, int numberOfPeople) {
    auto& events = this->repo->getRepo();
    Event oldE = repo->getEvent(id);
    for (auto event : events) {
        if (event.getId() == id) {
            event.setNumberOfPeople(numberOfPeople);
            this->repo->updateRepo(id, event);
            undoStack.push(new UndoRedoUpdate(*repo, oldE, event));
            while(!redoStack.empty()) { delete redoStack.top(); redoStack.pop();}
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update event link
void Administrator::updateLinkAdmin(int id, std::string link) {
    auto& events = this->repo->getRepo();
    Event oldE = repo->getEvent(id);
    for (auto event : events) {
        if (event.getId() == id) {
            event.setLink(link);
            this->repo->updateRepo(id, event);
            undoStack.push(new UndoRedoUpdate(*repo, oldE, event));
            while(!redoStack.empty()){ delete redoStack.top(); redoStack.pop();}
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

// Update entire event
void Administrator::updateEventAdmin(int id, std::string title, std::string description,
                                    std::chrono::year_month_day date, double time,
                                    int numberOfPeople, std::string link) {
    auto& events = this->repo->getRepo();
    Event oldE = repo->getEvent(id);
    for (auto event : events) {
        if (event.getId() == id) {
            // Apply all the updates
            event.setTitle(title);
            event.setDescription(description);
            event.setDate(date);
            event.setTime(time);
            event.setNumberOfPeople(numberOfPeople);
            event.setLink(link);

            this->repo->updateRepo(id, event);
            undoStack.push(new UndoRedoUpdate(*repo, oldE, event));
            while(!redoStack.empty()) { delete redoStack.top(); redoStack.pop();}
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

void Administrator::undo() {
    if(undoStack.empty()) return;
    UndoRedo* ur = undoStack.top(); undoStack.pop();
    ur->undo();
    redoStack.push(ur);
}

void Administrator::redo() {
    if(redoStack.empty()) return;
    UndoRedo* ur = redoStack.top(); redoStack.pop();
    ur->redo();
    undoStack.push(ur);
}
