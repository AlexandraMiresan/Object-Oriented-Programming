//
// Created by Ale on 6/25/2025.
//

#ifndef PEOPLEREPOSITORY_H
#define PEOPLEREPOSITORY_H

#include <memory>
#include <vector>

#include "../Domain/Person.h"

class PeopleRepository {
private:
    std::vector<std::shared_ptr<Person>> people;
public:
    PeopleRepository() {
        people = readFromFile();
    }
    ~PeopleRepository()=default;
    std::vector<std::shared_ptr<Person>> getAllPeople(){return this->people;}
private:
    std::vector<std::shared_ptr<Person>> readFromFile();
    void writeToFile();
};



#endif //PEOPLEREPOSITORY_H
