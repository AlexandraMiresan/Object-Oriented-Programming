//
// Created by Ale on 6/25/2025.
//

#include "PeopleRepository.h"

#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::shared_ptr<Person>> PeopleRepository::readFromFile() {
    std::vector<std::shared_ptr<Person>> loadedPeople;

    std::ifstream fin{"../people.txt"};

    if (!fin.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return {};
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string name, latitudeXStr, longitudeXStr, isOrganiserStr, latitudeYStr,longitudeYStr;

        std::getline(ss, name, ',');
        std::getline(ss, latitudeXStr, ',');
        std::getline(ss, latitudeYStr, ',');
        std::getline(ss, longitudeXStr, ',');
        std::getline(ss, longitudeYStr, ',');
        std::getline(ss, isOrganiserStr);

        int latitudeX = std::stoi(latitudeXStr);
        int latitudeY = std::stoi(latitudeYStr);
        int longitudeX = std::stoi(longitudeXStr);
        int longitudeY = std::stoi(longitudeYStr);

        bool isOrganiser;
        if (isOrganiserStr == "true") {
            isOrganiser = true;
        }else {
            isOrganiser = false;
        }

        auto location = Location(latitudeX,latitudeX,longitudeX,longitudeY);
        auto person = std::make_shared<Person>(name,location,isOrganiser);
        loadedPeople.push_back(person);
    }

    fin.close();
    return loadedPeople;

}


void PeopleRepository::writeToFile() {
    std::ofstream fout{"../people.txt"};
    if (!fout.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    for(auto p: people) {
        fout << p->getName() << ","
        << p->getLocation().getLatitudeX() << ","
        << p->getLocation().getLatitudeY() << ","
        << p->getLocation().getLongitudeX() << ",";
        fout << p->getLocation().getLongitudeY() << ",";
        if(p->getIsOrganiser() == true) {
            fout << "true" << std::endl;
        }else {
            fout << "false" << std::endl;
        }
    }

    fout.close();
}