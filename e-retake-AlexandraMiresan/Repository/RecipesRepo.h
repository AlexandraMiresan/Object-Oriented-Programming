//
// Created by Ale on 7/10/2025.
//

#ifndef RECIPESREPO_H
#define RECIPESREPO_H
#include <memory>
#include <vector>
#include "../Domain/Recipe.h"
#include "../Observer/Subject.h"

class RecipesRepo : public Subject {
private:
    std::vector<std::shared_ptr<Recipe>> recipes;
public:
    RecipesRepo() {
        this->recipes = readFromFile();
    }
    std::vector<std::shared_ptr<Recipe>>& getRecipes();
    void addRecipe(std::shared_ptr<Recipe>& recipe) {
        recipes.push_back(recipe);
        notify();
        writeToFile();
    }
    ~RecipesRepo()=default;
private:
    std::vector<std::shared_ptr<Recipe>> readFromFile();
    void writeToFile();

};



#endif //RECIPESREPO_H
