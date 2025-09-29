//
// Created by Ale on 4/3/2025.
//

#ifndef UI_H
#define UI_H
#include "../Service/Administrator.h"
#include "../Service/User.h"


class UI {
private:
    Administrator admin;
    User user;
public:
    UI(Administrator admin, User user) : admin(admin), user(user) {}
    void start();
private:
    void adminAddEvent();
    void userAddEvent();
    void adminRemoveEvent();
    void userRemoveEvent();
    void adminUpdateEvent();
    void userGetEventsToAttend();
    void adminGetEvents();
};



#endif //UI_H
