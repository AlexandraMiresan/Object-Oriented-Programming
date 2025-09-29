//
// Created by Ale on 7/10/2025.
//

#ifndef CHEFWINDOW_H
#define CHEFWINDOW_H

#include <QWidget>
#include "../Observer/Observer.h"
#include "../Domain/Chef.h"
#include "../Service/Recipes.h"
#include "../TableModel/TableModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChefWindow; }
QT_END_NAMESPACE

class ChefWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit ChefWindow(Recipes& recipes, Chef& chef, QWidget *parent = nullptr);
    ~ChefWindow() override;
    void update() override {
        model->resetTable(recipes.getRecipes());
    }
    void viewOnlySpecificCuisine();
    void connectSignalsAndSlots();
    void addRecipe();
    void filterRecipes();
    void openViewWindow();
    void viewAll();

private:
    Ui::ChefWindow *ui;
    Recipes& recipes;
    Chef& chef;
    TableModel* model;
};


#endif //CHEFWINDOW_H
