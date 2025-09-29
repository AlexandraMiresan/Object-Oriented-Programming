//
// Created by Ale on 6/25/2025.
//

#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QWidget>
#include "../Controller/EventsController.h"
#include "../TableModel/TableModel.h"
#include "../Domain/Person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PersonWindow; }
QT_END_NAMESPACE

class PersonWindow : public QWidget, public Observer {
Q_OBJECT

public:
    explicit PersonWindow(Person& person, EventsController& events, QWidget *parent = nullptr);
    ~PersonWindow() override;
    void connectSignalsAndSlots();
    void attendEvent();
    void addNewEvents();
    void goToEvent();
    void update() override;
    void showDescription();

Event &getEventAtIndex();

private:
    Ui::PersonWindow *ui;
    EventsController& events;
    Person& person;
    TableModel* model;
    std::vector<Event> goingEvents;
};


#endif //PERSONWINDOW_H
