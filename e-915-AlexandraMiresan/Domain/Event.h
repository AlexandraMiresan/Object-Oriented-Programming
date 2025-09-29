//
// Created by Ale on 6/25/2025.
//

#ifndef EVENT_H
#define EVENT_H
#include <string>

#include "Location.h"


class Event {
private:
    std::string organiser;
    std::string name;
    std::string description;
    Location location;
    std::string date;
public:
    Event(std::string& organiser, std::string& name, std::string& description, Location location, std::string& date) : location(location){
        this->organiser = organiser;
        this->name = name;
        this->description = description;
        this->location = location;
        this->date = date;
    }
    std::string getOrganiser() {return this->organiser;}
    std::string getName() {return this->name;}
    std::string getDescription() {return this->description;}
    Location getLocation() {return this->location;}
    std::string getDate() {return this->date;}
    ~Event()=default;
};



#endif //EVENT_H
