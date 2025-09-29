//
// Created by Ale on 7/10/2025.
//

#include "ChefsRepo.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::shared_ptr<Chef> > ChefsRepo::readFromFile() {
    std::vector<std::shared_ptr<Chef>> loadedChefs;
    std::ifstream fin { "../chefs.txt"};

    if(!fin.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return {};
    }

    std::string line;
    while(std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string name, cuisine;

        std::getline(ss, name, ',');
        std::getline(ss, cuisine);

        auto chef = std::make_shared<Chef>(name, cuisine);

        loadedChefs.push_back(chef);
    }

    fin.close();
    return loadedChefs;
}
