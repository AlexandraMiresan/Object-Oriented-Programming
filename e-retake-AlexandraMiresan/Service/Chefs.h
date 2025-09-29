//
// Created by Ale on 7/10/2025.
//

#ifndef CHEFS_H
#define CHEFS_H

#include "../Repository/ChefsRepo.h"

class Chefs {
private:
    ChefsRepo& chefs;
public:
    Chefs(ChefsRepo& chefsRepo) : chefs(chefsRepo) {}
    std::vector<std::shared_ptr<Chef>>& getChefs(){return this->chefs.getChefs();}
    ~Chefs()=default;
};



#endif //CHEFS_H
