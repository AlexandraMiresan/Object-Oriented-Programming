//
// Created by Ale on 5/28/2025.
//

#ifndef UNDOREDOREMOVE_H
#define UNDOREDOREMOVE_H
#include "Repository.h"
#include "UndoRedo.h"


class UndoRedoRemove : public UndoRedo{
private:
    Repository& repo;
    Event event;
public:
    UndoRedoRemove(Repository& repo, Event& e) : repo(repo), event(e){}

    void undo() override {
        repo.addRepo(event);
    }

    void redo() override {
        repo.removeRepo(event.getId());
    }

};



#endif //UNDOREDOREMOVE_H
