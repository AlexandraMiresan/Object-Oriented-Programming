//
// Created by Ale on 7/10/2025.
//

#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <memory>
#include <vector>
#include "../Domain/Recipe.h"
#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel {
private:
    std::vector<std::shared_ptr<Recipe>> recipes;
public:
    TableModel(std::vector<std::shared_ptr<Recipe>> recipes) : recipes(recipes) {}
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void resetTable(std::vector<std::shared_ptr<Recipe>>& newRecipes);
};



#endif //TABLEMODEL_H
