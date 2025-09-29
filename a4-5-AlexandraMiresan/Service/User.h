//
// Created by Ale on 4/3/2025.
//

#ifndef USER_H
#define USER_H
#include "../Repository/Repository.h"


class User {
private:
    Repository *repo;
    DynamicVector<Event> userEvents;
public:
    explicit User(Repository *r) : repo(r) {}
    DynamicVector<Event> &getSortedEvents();
    int addEventToUserList(int id);
    int removeEventFromUserList(int id);
    DynamicVector<Event> &getUserEvents(){return this->userEvents;};
};



#endif //USER_H
