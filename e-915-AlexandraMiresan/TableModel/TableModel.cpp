//
// Created by Ale on 6/25/2025.
//

#include "TableModel.h"

#include <qbrush.h>

int TableModel::rowCount(const QModelIndex &parent) const {
    return events.size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}


QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if(role == Qt::DisplayRole) {
        Event& event = *events[row];
        switch(column) {
            case 0:
                return QString::fromStdString(event.getOrganiser());
            case 1:
                return QString::fromStdString(event.getName());
            case 2:
                return QString::fromStdString(std::to_string(event.getLocation().getLatitudeX()) +","+ std::to_string(event.getLocation().getLatitudeY()));
            case 3:
                QString::fromStdString(std::to_string(event.getLocation().getLongitudeX()) +","+ std::to_string(event.getLocation().getLongitudeY()));
            case 4:
                return QString::fromStdString(event.getDate());
            default:
                break;
        }
    }

    if(role == Qt::BackgroundRole) {
        Event& event = *events[row];
        if(person.getName() == event.getOrganiser()) {
            return QBrush(Qt::darkGreen);
        }
    }

    return QVariant();
}


QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch(section) {
            case 0:
                return "Organiser";
            case 1:
                return "Name";
            case 2:
                return "Latitude";
            case 3:
                return "Longitude";
            case 4:
                return "Date";
            default:
                break;
        }
    }

    return QVariant();
}


void TableModel::setTableData(std::vector<std::shared_ptr<Event>> newEvents) {
    beginResetModel();
    events = newEvents;
    endResetModel();
}

Event& TableModel::getEvent(int row) {
    return *events[row];
}