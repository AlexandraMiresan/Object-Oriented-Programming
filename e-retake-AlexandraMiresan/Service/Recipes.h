//
// Created by Ale on 7/10/2025.
//

#ifndef RECIPES_H
#define RECIPES_H
#include "../Repository/RecipesRepo.h"


class Recipes {
private:
    RecipesRepo& recipes;
public:
    Recipes(RecipesRepo& recipesRepo) : recipes(recipesRepo) {}
    ~Recipes()=default;

    std::vector<std::shared_ptr<Recipe>> &getRecipes() {
        return recipes.getRecipes();
    }
    void addRecipe(std::shared_ptr<Recipe>& recipe) {
        recipes.addRecipe(recipe);
    }

};



#endif //RECIPES_H
