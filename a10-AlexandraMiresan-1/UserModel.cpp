//
// Created by Ale on 5/28/2025.
//

#include "UserModel.h"
#include <QModelIndex>

UserModel::UserModel(User& user) : user(user){}

int UserModel::rowCount(const QModelIndex &parent) const{
    return user.getSize();
}

int UserModel::columnCount(const QModelIndex &parent) const {
    return 6;
}

QString formatDate(std::chrono::year_month_day &ymd) {
    std::ostringstream oss;
    oss << static_cast<int>(ymd.year()) << "-"
            << std::setw(2) << std::setfill('0') << static_cast<unsigned>(unsigned(ymd.month())) << "-"
            << std::setw(2) << std::setfill('0') << static_cast<unsigned>(ymd.day());
    return QString::fromStdString(oss.str());
}

QVariant UserModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();

    if(role == Qt::DisplayRole) {
        Event& e = this->user.getUserEvents()[row];

        switch (col) {
            case 0:
                return QString::fromStdString(e.getTitle());
            case 1:
                return QString::fromStdString(e.getDescription());
            case 2:
                return formatDate(e.getDate());
            case 3:
                return QString::number(e.getTime(), 'f', 2);
            case 4:
                return QString::number(e.getNumberOfPeople());
            case 5:
                return QString::fromStdString(e.getLink());
            default:
                break;
        }
    }

    return QVariant();
}

QVariant UserModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return "Title";
            case 1:
                return "Description";
            case 2:
                return "Date";
            case 3:
                return "Time";
            case 4:
                return "NumberOfPeople";
            case 5:
                return "Link";
            default:
                break;
        }
    }

    return QVariant();
}

void UserModel::addEvent(int id) {
    int newRow = user.getSize();
    beginInsertRows(QModelIndex(), newRow, newRow);
    user.addEventToUserList(id);
    endInsertRows();
}

void UserModel::removeEvent(int id) {
    auto events = user.getUserEvents();

    // Find the event index in your container by id
    int rowToRemove = -1;
    for(int i = 0; i < events.size(); ++i) {
        if(events[i].getId() == id) {
            rowToRemove = i;
            break;
        }
    }
    if(rowToRemove == -1) {
        // Event not found
        return;
    }

    beginRemoveRows(QModelIndex(), rowToRemove, rowToRemove);

    // Remove the event from the container
    user.removeEventFromUserList(rowToRemove + 1);

    endRemoveRows();
}

int UserModel::getEventIdAtRow(int row) const {
    auto events = user.getUserEvents();
    // assuming your events are stored in a vector<Event> called events
    if (row < 0 || row >= events.size())
        return -1;  // invalid

    return events[row].getId();
}



