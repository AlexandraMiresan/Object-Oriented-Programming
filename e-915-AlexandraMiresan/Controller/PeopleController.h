//
// Created by Ale on 6/25/2025.
//

#ifndef PEOPLECONTROLLER_H
#define PEOPLECONTROLLER_H

#include <memory>
#include <vector>

#include "../Repository/PeopleRepository.h"
#include "../Domain/Person.h"

class PeopleController {
private:
  PeopleRepository& peopleRepo;
public:
  PeopleController(PeopleRepository& peopleRepo):peopleRepo(peopleRepo){}
  ~PeopleController()=default;
  std::vector<std::shared_ptr<Person>> getPeople() {
    return peopleRepo.getAllPeople();
  }
};



#endif //PEOPLECONTROLLER_H
