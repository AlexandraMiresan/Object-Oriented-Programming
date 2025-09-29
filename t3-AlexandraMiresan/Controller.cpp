//
// Created by Ale on 5/28/2025.
//

#include "Controller.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

Controller::Controller(std::string filename) : filename(filename) {
    this->timeIntervals = loadFromFile();
}

std::vector<std::shared_ptr<TimeInterval>> Controller::loadFromFile() {
    std::vector<std::shared_ptr<TimeInterval>> loadedTimeIntervals;

    std::ifstream fin {filename};

    if(!fin.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return {};
    }

    std::string line;
    while(std::getline(fin, line)) {
        std::stringstream ss(line);

        std::string startHourStr, endHourStr, temperatureStr, precipitationStr, description;

        std::getline(ss, startHourStr, ',');
        std::getline(ss, endHourStr, ',');
        std::getline(ss, temperatureStr, ',');
        std::getline(ss, precipitationStr,',');
        std::getline(ss, description);

        try {
            int startHour = std::stoi(startHourStr);
            int endHour = std::stoi(endHourStr);
            int temperature = std::stoi(temperatureStr);
            int precipitation = std::stoi(precipitationStr);

            auto timeInt = std::make_shared<TimeInterval>(startHour, endHour, temperature, precipitation, description);

            loadedTimeIntervals.push_back(timeInt);

        }catch(...) {
            std::cerr << "Error while reading from file " << filename << std::endl;
        }
    }

    fin.close();
    return loadedTimeIntervals;
}

std::vector<std::shared_ptr<TimeInterval>> Controller::getTimeIntervals() {
    std::sort(timeIntervals.begin(), timeIntervals.end(), [](const std::shared_ptr<TimeInterval>& ti1, const std::shared_ptr<TimeInterval>& ti2) {
        return ti1->getStartHour() < ti2->getStartHour();
    });
    return timeIntervals;
}