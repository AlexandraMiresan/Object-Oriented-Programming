#pragma once

#include "../Service/Administrator.h"
#include "../Service/User.h"


class UI {
private:
    Administrator& admin;
    User& user;

    // Admin menu functions
    void handle_admin();
    void adminAddEvent();
    void adminRemoveEvent();
    void adminUpdateEvent();
    void adminGetEvents();

    // User menu functions
    void handle_user();
    void userAddEvent();
    void userRemoveEvent();
    void userGetEventsToAttend();

    void userSaveEventsList();
    void userOpenEventsList();

public:
    UI(Administrator& adminService, User& userService)
        : admin(adminService), user(userService) {}

    void start(); // Main loop for UI
};

