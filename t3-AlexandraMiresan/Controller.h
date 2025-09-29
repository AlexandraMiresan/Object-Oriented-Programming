//
// Created by Ale on 5/28/2025.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>
#include <vector>

#include "TimeInterval.h"


class Controller {
private:
    std::vector<std::shared_ptr<TimeInterval>> timeIntervals;
    std::string filename;
public:
    Controller(std::string filename);
    ~Controller()=default;
    std::vector<std::shared_ptr<TimeInterval>> getTimeIntervals();
private:
    std::vector<std::shared_ptr<TimeInterval>> loadFromFile();
};



#endif //CONTROLLER_H
