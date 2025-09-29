//
// Created by Ale on 7/10/2025.
//

#ifndef CHEFSREPO_H
#define CHEFSREPO_H
#include <memory>
#include <vector>
#include "../Domain/Chef.h"


class ChefsRepo {
private:
    std::vector<std::shared_ptr<Chef>> chefs;
public:
    ChefsRepo() {
        this->chefs = readFromFile();
    }
    std::vector<std::shared_ptr<Chef>>& getChefs(){return this->chefs;}
    ~ChefsRepo()=default;
private:
    std::vector<std::shared_ptr<Chef>> readFromFile();
};



#endif //CHEFSREPO_H
