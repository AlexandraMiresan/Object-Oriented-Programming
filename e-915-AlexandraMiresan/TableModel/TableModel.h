//
// Created by Ale on 6/25/2025.
//

#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "../Domain/Event.h"
#include <vector>
#include <memory>
#include "../Domain/Person.h"

class TableModel: public QAbstractTableModel{
private:
    std::vector<std::shared_ptr<Event>> events;
    Person& person;
public:
    TableModel(std::vector<std::shared_ptr<Event>> events, Person& person):events(events), person(person){}
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void setTableData(std::vector<std::shared_ptr<Event>> events);
    Event& getEvent(int row);
};



#endif //TABLEMODEL_H
