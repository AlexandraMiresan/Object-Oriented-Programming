//
// Created by Ale on 5/28/2025.
//

#ifndef USERMODEL_H
#define USERMODEL_H
#include <QAbstractTableModel>
#include "User.h"



class UserModel : public QAbstractTableModel {
private:
    User& user;
public:
    UserModel(User& user);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void addEvent(int id);
    void removeEvent(int row);
    int getEventIdAtRow(int row) const;
};



#endif //USERMODEL_H
