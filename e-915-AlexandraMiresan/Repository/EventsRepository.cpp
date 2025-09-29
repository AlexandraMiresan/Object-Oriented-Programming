//
// Created by Ale on 6/25/2025.
//

#include "EventsRepository.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::shared_ptr<Event> > EventsRepository::readFromFile() {
    std::vector<std::shared_ptr<Event> > loadedEvents;
    std::ifstream fin{"../events.txt"};

    if(!fin.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return {};
    }

    std::string line;
    while(std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string organiser, name, description, latitudeXStr, latitudeYStr, longitudeXStr, longitudeYStr, date;

        std::getline(ss, organiser, ',');
        std::getline(ss, name, ',');
        std::getline(ss, description, ',');
        std::getline(ss, latitudeXStr, ',');
        std::getline(ss, latitudeYStr, ',');
        std::getline(ss, longitudeXStr, ',');
        std::getline(ss, longitudeYStr, ',');
        std::getline(ss, date);

        int latitudeX = std::stoi(latitudeXStr);
        int latitudeY = std::stoi(latitudeYStr);
        int longitudeX = std::stoi(longitudeXStr);
        int longitudeY = std::stoi(longitudeYStr);

        auto location = Location(latitudeX,latitudeY, longitudeX,longitudeY);
        auto event = std::make_shared<Event>(organiser, name, description, location, date);
        loadedEvents.push_back(event);

    }

    fin.close();
    return loadedEvents;

}


void EventsRepository::writeToFile() {
    std::ofstream fout{"../events.txt"};
    if(!fout.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    for(auto event : events) {
        fout << event->getOrganiser() << ","
        << event->getName() << ","
        << event->getDescription() << ","
        << event->getLocation().getLatitudeX() << ","
        << event->getLocation().getLatitudeY() << ","
        << event->getLocation().getLongitudeX() << ","
        << event->getLocation().getLongitudeY() << ","
        <<event->getDate() << std::endl;
    }

    fout.close();
}