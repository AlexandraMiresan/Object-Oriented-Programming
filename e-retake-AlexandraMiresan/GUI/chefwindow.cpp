//
// Created by Ale on 7/10/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChefWindow.h" resolved

#include "chefwindow.h"
#include "ui_ChefWindow.h"
#include <QMessageBox>

#include "viewwindow.h"

ChefWindow::ChefWindow(Recipes& recipes, Chef& chef, QWidget *parent) :
    QWidget(parent), ui(new Ui::ChefWindow), recipes(recipes), chef(chef) {
    ui->setupUi(this);
    model = new TableModel(recipes.getRecipes());
    ui->tableView->setModel(model);
    connectSignalsAndSlots();
}

void ChefWindow::connectSignalsAndSlots() {
    QObject::connect(ui->checkBox, &QCheckBox::checkStateChanged, [this](bool checked) {
        if (checked) {
            viewOnlySpecificCuisine();
        } else {
            update();
        }
    });
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &ChefWindow::addRecipe);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, this, &ChefWindow::openViewWindow);
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, &ChefWindow::filterRecipes);
    QObject::connect(ui->pushButton_4, &QPushButton::clicked, this, &ChefWindow::viewAll);
}

ChefWindow::~ChefWindow() {
    delete ui;
}

void ChefWindow::addRecipe() {
    try {
        QString nameQ = ui->lineEdit->text().trimmed();
        QString preparationTimeQ = ui->lineEdit_2->text().trimmed();
        QString ingredientsQ = ui->lineEdit_3->text().trimmed();

        std::string name, ingredients;
        int preparationTime;

        name = nameQ.toStdString();
        ingredients = ingredientsQ.toStdString();
        preparationTime = preparationTimeQ.toInt();
        std::string ingredient;
        std::vector<std::shared_ptr<std::string>> ingredientsList;

        for(auto recipe: recipes.getRecipes()) {
            if(name == recipe->getName()) {
                throw std::invalid_argument("Recipe name already exists");
            }
        }

        if(name == "") {
            throw std::invalid_argument("Invalid name");
        }

        std::stringstream ss(ingredients);

        while (std::getline(ss, ingredient, ',')) {

            ingredient.erase(0, ingredient.find_first_not_of(" \t\n\r\f\v"));
            ingredient.erase(ingredient.find_last_not_of(" \t\n\r\f\v") + 1);

            if (!ingredient.empty()) {
                ingredientsList.push_back(std::make_shared<std::string>(ingredient));
            }
        }

        std::string cuisine = chef.getCuisine();

        auto recipe = std::make_shared<Recipe>(name,cuisine , preparationTime, ingredientsList);
        recipes.addRecipe(recipe);
    }catch(...) {
        QMessageBox::critical(this, "Error", QObject::tr("Invalid name"));
    }


    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

}

void ChefWindow::viewOnlySpecificCuisine() {
    std::vector<std::shared_ptr<Recipe>> specificRecipes;
    for(auto& recipe : recipes.getRecipes()) {
        if(recipe->getCuisine() == chef.getCuisine()) {
            specificRecipes.push_back(recipe);
        }
    }

    model->resetTable(specificRecipes);
}

void ChefWindow::filterRecipes() {
    std::vector<std::shared_ptr<Recipe>> specificRecipes;
    QString ingredientsQ = ui->lineEdit_4->text().trimmed();
    std::string inputIngredients = ingredientsQ.toStdString();

    if(ui->checkBox->isChecked()) {
        for (const auto& recipe : recipes.getRecipes()) {
            if(recipe->getCuisine() == chef.getCuisine()) {
                std::string recipeIngredients = recipe->getIngredientsToStr();
                if (recipeIngredients.find(inputIngredients) != std::string::npos) {
                    specificRecipes.push_back(recipe);
                }
            }

        }
    }else {
        for (const auto& recipe : recipes.getRecipes()) {
            std::string recipeIngredients = recipe->getIngredientsToStr();
            if (recipeIngredients.find(inputIngredients) != std::string::npos) {
                specificRecipes.push_back(recipe);
            }
        }
    }



    model->resetTable(specificRecipes);

}

void ChefWindow::viewAll() {
    update();
}

void ChefWindow::openViewWindow() {
    std::vector<std::shared_ptr<Recipe>> specificRecipes;
    for(auto recipe:recipes.getRecipes()) {
        if(recipe->getCuisine() == chef.getCuisine()) {
            specificRecipes.push_back(recipe);
        }
    }
    auto window = ViewWindow(specificRecipes);
    window.setModal(true);
    window.exec();
}