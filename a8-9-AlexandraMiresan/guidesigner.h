//
// Created by Ale on 5/16/2025.
//

#ifndef GUIDESIGNER_H
#define GUIDESIGNER_H

#include <QWidget>

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
    Administrator& admin;
    User& user;
    std::vector<Event> allEvents;
    int currentIndex = 0;

    void populateTable();
    void addButtonHandler();
    void connectSignalsAndSlots();
    void deleteButtonHandler();
    void updateButtonHandler();

    void populateUser();
    void showEvents(int index);
    void loadEvents();
    void participateEvents();
    void openLinkButton();

    void removeEventUser();
    void saveFile();
    void openInApp();
};


#endif //GUIDESIGNER_H
