//
// Created by Ale on 5/16/2025.
//

#ifndef GUIDESIGNER_H
#define GUIDESIGNER_H

#include <qabstractitemmodel.h>
#include <QWidget>

#include "UserModel.h"
#include "Service/User.h"


class Administrator;
QT_BEGIN_NAMESPACE
namespace Ui { class GUIDesigner; }
QT_END_NAMESPACE

class GUIDesigner : public QWidget {
Q_OBJECT

public:
    explicit GUIDesigner(Administrator& admin, User& user, QWidget *parent = nullptr);
    ~GUIDesigner() override;

private:
    Ui::GUIDesigner *ui;
    UserModel* model;
    Administrator& admin;
    User& user;
    std::vector<Event> allEvents;
    int currentIndex;

    void populateTable();
    void addButtonHandler();
    void connectSignalsAndSlots();
    void deleteButtonHandler();
    void updateButtonHandler();
    void cycleThroughEvents();

    //void populateUser();
    void showEvents(int index);
    void loadEvents();
    void participateEvents();
    void openLinkButton();

    void removeEventUser(const QModelIndex &index);
    void saveFile();
    void openInApp();

    void undo();
    void redo();
    QString formatDate(std::chrono::year_month_day &ymd);
};


#endif //GUIDESIGNER_H
