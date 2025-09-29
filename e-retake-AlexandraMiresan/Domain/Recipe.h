//
// Created by Ale on 7/10/2025.
//

#ifndef RECIPE_H
#define RECIPE_H
#include <memory>
#include <vector>


class Recipe {
private:
    std::string name;
    std::string cuisine;
    int preparationTime;
    std::vector<std::shared_ptr<std::string>> ingredients;
public:
    Recipe(std::string& name, std::string& cuisine, int preparationTime, std::vector<std::shared_ptr<std::string>>& ingredients) :
        name(name), cuisine(cuisine), preparationTime(preparationTime), ingredients(ingredients){}
    std::string getName() {return this->name;}
    std::string getCuisine() {return this->cuisine;}
    int getPreparationTime() {return this->preparationTime;}
    std::vector<std::shared_ptr<std::string>> getIngredients() {return this->ingredients;}
    std::string getIngredientsToStr() {
        std::string ingredientsStr;
        for(auto& ingredient : this->ingredients) {
            ingredientsStr += *ingredient + "|";
        }

        return ingredientsStr;
    }
    ~Recipe()=default;
};



#endif //RECIPE_H
