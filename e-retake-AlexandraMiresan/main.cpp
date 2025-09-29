//
// Created by Ale on 7/10/2025.
//
#include <iostream>

#include "GUI/chefwindow.h"
#include <QApplication>

#include "Repository/ChefsRepo.h"
#include "Repository/RecipesRepo.h"
#include "Service/Chefs.h"
#include "Service/Recipes.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ChefsRepo cRepo = ChefsRepo();
    RecipesRepo rRepo = RecipesRepo();

    auto chefs = Chefs(cRepo);
    auto recipes = Recipes(rRepo);

    for(auto& chef : chefs.getChefs()) {
        auto* window = new ChefWindow(recipes, *chef);
        rRepo.addObserver(window);
        window->setWindowTitle(QString::fromStdString(chef->getName()));
        window->show();
    }

    return app.exec();
}
