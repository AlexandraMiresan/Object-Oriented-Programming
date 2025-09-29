//
// Created by Ale on 7/10/2025.
//

#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

#include "Observer.h"


class Subject {
private:
    std::vector<Observer*> _observers;
public:
    void addObserver(Observer* observer) {
        _observers.push_back(observer);
    }
    void notify() {
        for (auto observer : _observers) {
            observer->update();
        }
    }
};



#endif //SUBJECT_H
