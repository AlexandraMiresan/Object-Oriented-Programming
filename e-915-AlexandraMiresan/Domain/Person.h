//
// Created by Ale on 6/25/2025.
//

#ifndef PERSON_H
#define PERSON_H
#include <string>

#include "Location.h"


class Person {
private:
    std::string name;
    Location location;
    bool isOrganiser;
public:
    Person(std::string& name, Location location, bool isOrganiser):name(name),location(location), isOrganiser(isOrganiser) {}
    std::string getName(){return this->name;}
    Location getLocation(){return this->location;}
    bool getIsOrganiser(){return this->isOrganiser;}
    ~Person()=default;
};



#endif //PERSON_H
