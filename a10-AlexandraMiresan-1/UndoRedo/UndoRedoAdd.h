//
// Created by Ale on 5/28/2025.
//

#ifndef UNDOREDOADD_H
#define UNDOREDOADD_H
#include "Repository.h"
#include "UndoRedo.h"


class UndoRedoAdd : public UndoRedo{
private:
    Repository& repo;
    Event event;
public:
    UndoRedoAdd(Repository& repo, Event& e) : repo(repo), event(e) {}
    void undo() override {
        repo.removeRepo(event.getId());
    }

    void redo() override {
        repo.addRepo(event);
    }
};



#endif //UNDOREDOADD_H
