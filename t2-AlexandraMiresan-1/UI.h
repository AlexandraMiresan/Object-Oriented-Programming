//
// Created by Ale on 5/7/2025.
//

#ifndef UI_H
#define UI_H
#include "Controller.h"


class UI {
private:
    Controller controller;
public:
    UI(Controller controller) : controller(controller) {}
    void start();
    void addDepartment();
    void showDepartments();
    void showEfficientDepartments();
    void saveToFile();
    void addStartDeps();
};



#endif //UI_H
