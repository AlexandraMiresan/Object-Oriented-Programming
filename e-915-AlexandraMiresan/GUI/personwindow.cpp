//
// Created by Ale on 6/25/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PersonWindow.h" resolved

#include "personwindow.h"
#include "ui_PersonWindow.h"
#include <QCheckBox>
#include <QMessageBox>
#include <QPushButton>

PersonWindow::PersonWindow(Person &person, EventsController &events, QWidget *parent) : QWidget(parent),
    ui(new Ui::PersonWindow), person(person), events(events) {
    ui->setupUi(this);
    goingEvents = {};
    model = new TableModel(events.getEvents(), person);
    ui->tableView->setModel(model);
    connectSignalsAndSlots();
}

PersonWindow::~PersonWindow() {
    delete ui;
}

void PersonWindow::connectSignalsAndSlots() {
    QObject::connect(ui->box, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {
            model->setTableData(events.getSortedEvents(person));
        } else {
            model->setTableData(events.getEvents());
        }
    });
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &PersonWindow::addNewEvents);
    QObject::connect(ui->tableView, &QTableView::doubleClicked, this, &PersonWindow::showDescription);
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, &PersonWindow::goToEvent);
}



void PersonWindow::addNewEvents() {
    QString nameQ = ui->lineEdit->text().trimmed();
    QString descriptionQ = ui->lineEdit_2->text().trimmed();
    QString longitudeXq = ui->lineEdit_3->text().trimmed();
    QString longitudeYq = ui->lineEdit_4->text().trimmed();
    QString latitudeXq = ui->lineEdit_5->text().trimmed();
    QString latitudeYq = ui->lineEdit_6->text().trimmed();
    QString dateQ = ui->lineEdit_7->text().trimmed();

    try {
        std::string name = nameQ.toStdString();
        std::string description = descriptionQ.toStdString();
        int latitudeX = latitudeXq.toInt();
        int latitudeY = latitudeYq.toInt();
        int longitudeX = longitudeXq.toInt();
        int longitudeY = longitudeYq.toInt();
        std::string date = dateQ.toStdString();

        if (person.getIsOrganiser() == false) {
            throw std::invalid_argument("Person is not an organiser!");
        }

        for (auto event: events.getEvents()) {
            if (event->getName() == name || (event->getLocation().getLatitudeX() == latitudeX && event->getLocation().
                                             getLatitudeY() == latitudeY && event->getLocation().getLongitudeX() ==
                                             longitudeX && event->getLocation().getLongitudeY() == longitudeY)) {
                throw std::invalid_argument("Event already exists!");
            }
        }


        auto loc = Location(latitudeX, latitudeY, longitudeX, longitudeY);
        std::string organiser = person.getName();

        auto event = std::make_shared<Event>(organiser, name, description, loc, date);
        events.addEvent(event);
    } catch (...) {
        QMessageBox::critical(this, "Error", QString("Error while adding new events!"));
    }
}

void PersonWindow::update() {
    model->setTableData(events.getEvents());
}

void PersonWindow::showDescription() {
    Event &event = getEventAtIndex();
    if (event.getOrganiser() == person.getName()) {
        int cnt = 0;
        for(auto person: events.getAttendants()) {
            if(person.getName() == event.getOrganiser()) {
                cnt++;
            }

        }
        QMessageBox::about(this, "Description and atendees", QString::fromStdString(event.getDescription()) +","+ QString::number(cnt));

    } else {
        QMessageBox::about(this, "Description", QString::fromStdString(event.getDescription()));
    }
}

Event &PersonWindow::getEventAtIndex() {
    QModelIndex ind = ui->tableView->currentIndex();
    int row = ind.row();

    auto *model = dynamic_cast<TableModel *>(ui->tableView->model());
    Event &event = model->getEvent(row);

    return event;
}

void PersonWindow::goToEvent() {
    try {
        Event &event = getEventAtIndex();
        if (event.getOrganiser() == person.getName()) {
            throw std::invalid_argument("Cant go to event that you are organising!");
        }
        for (auto ev: goingEvents) {
            if (event.getName() == ev.getName()) {
                throw std::invalid_argument("Event already exists!");
            }
        }

        goingEvents.push_back(event);
        events.addAttendant(person);
        update();
    } catch (...) {
        QMessageBox::critical(this, "Error", QString("Already going to event!"));
    }
}
