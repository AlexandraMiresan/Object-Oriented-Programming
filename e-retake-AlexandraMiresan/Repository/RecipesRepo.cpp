//
// Created by Ale on 7/10/2025.
//

#include "RecipesRepo.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::shared_ptr<Recipe>> RecipesRepo::readFromFile() {
    std::vector<std::shared_ptr<Recipe>> loadedRecipes;

    std::ifstream fin{"../recipes.txt"};

    if (!fin.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return {};
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string name, cuisine, preparationTimeStr;

        std::getline(ss, name, ',');
        std::getline(ss, cuisine, ',');
        std::getline(ss, preparationTimeStr, ',');
        std::string ingredient;
        std::vector<std::shared_ptr<std::string>> ingredients;
        while(std::getline(ss, ingredient, '|')) {
            auto ing = std::make_shared<std::string>(ingredient);
            ingredients.push_back(ing);
        }

        int preparationTime = std::stoi(preparationTimeStr);

        auto recip = std::make_shared<Recipe>(name, cuisine, preparationTime, ingredients);
        loadedRecipes.push_back(recip);
    }

    fin.close();
    return loadedRecipes;
}

std::vector<std::shared_ptr<Recipe>>& RecipesRepo::getRecipes() {
    std::sort(recipes.begin(), recipes.end(), [](std::shared_ptr<Recipe> a, std::shared_ptr<Recipe> b) {
        return a->getCuisine() < b->getCuisine();
    });

    return recipes;
}

void RecipesRepo::writeToFile() {
    std::ofstream fout{"../recipes.txt"};
    if (!fout.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    for (auto recipe : recipes) {
        fout << recipe->getName() << ",";
        fout << recipe->getCuisine() << ",";
        fout << recipe->getPreparationTime() << ",";
        fout << recipe->getIngredientsToStr();
        fout << std::endl;
    }

    fout.close();
}