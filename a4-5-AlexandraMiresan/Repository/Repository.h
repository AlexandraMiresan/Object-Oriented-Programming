//
// Created by Ale on 4/3/2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "../DynamicVector/DynamicVector.h"
#include "../Domain/Event.h"


class Event;

class Repository {
private:
    DynamicVector<Event> events;
public:
    int addRepo(Event &event);
    int deleteRepo(int id);
    int updateRepo(int id, Event &event);
    DynamicVector<Event> &getRepository(){return this->events;};
};



#endif //REPOSITORY_H
