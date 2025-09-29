//
// Created by Ale on 5/28/2025.
//

#ifndef UNDOREDO_H
#define UNDOREDO_H



class UndoRedo {
public:
    virtual void undo()=0;
    virtual void redo()=0;
    virtual ~UndoRedo()=default;
};



#endif //UNDOREDO_H
