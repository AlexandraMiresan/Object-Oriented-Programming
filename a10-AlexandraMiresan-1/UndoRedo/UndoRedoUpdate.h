//
// Created by Ale on 5/28/2025.
//

#ifndef UNDOREDOUPDATE_H
#define UNDOREDOUPDATE_H
#include "Event.h"
#include "Repository.h"
#include "UndoRedo.h"


class UndoRedoUpdate :public UndoRedo{
private:
    Repository& repo;
    Event newEvent;
    Event oldEvent;
public:
    UndoRedoUpdate(Repository& repo, Event newEvent, Event oldEvent):repo(repo), newEvent(newEvent), oldEvent(oldEvent){}

    void undo() override {
        repo.updateRepo(oldEvent.getId(), oldEvent);
    }
    void redo() override {
        repo.updateRepo(newEvent.getId(), newEvent);
    }
};



#endif //UNDOREDOUPDATE_H
