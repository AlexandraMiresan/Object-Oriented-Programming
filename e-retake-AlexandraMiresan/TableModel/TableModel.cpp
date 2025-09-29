//
// Created by Ale on 7/10/2025.
//

#include "TableModel.h"

int TableModel::rowCount(const QModelIndex & parent)const {
    return recipes.size();
}

int TableModel::columnCount(const QModelIndex & parent) const {
    return 4;
}

QVariant TableModel::data(const QModelIndex & index, int role) const {
    int row = index.row();
    int column = index.column();

    if(role == Qt::DisplayRole) {
        auto recipe = recipes[row];
        switch(column) {
            case 0:
                return QString::fromStdString(recipe->getName());
            case 1:
                return QString::fromStdString(recipe->getCuisine());
            case 2:
                return QString::number(recipe->getPreparationTime());
            case 3:
                return QString::fromStdString(recipe->getIngredientsToStr());
            default:
                break;
        }
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch(section) {
            case 0:
                return QString("Name");
            case 1:
                return QString("Cuisine");
            case 2:
                return QString("Preparation time");
            case 3:
                return QString("Ingredients");
        }
    }

    return QVariant();
}

void TableModel::resetTable(std::vector<std::shared_ptr<Recipe>>& newRecipes) {
    beginResetModel();
    recipes = newRecipes;
    endResetModel();
}