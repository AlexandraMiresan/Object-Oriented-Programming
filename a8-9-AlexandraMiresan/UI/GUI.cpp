//
// Created by Ale on 5/12/2025.
//

#include "GUI.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>

GUI::GUI(Administrator &admin) : administrator(admin) {
    this->initGUI();
    this->populateList();
    //this->connectSignalsAndSlots();
}

void GUI::initGUI() {
    QVBoxLayout* adminLayout = new QVBoxLayout{};
    QLabel* allEventsLable = new QLabel("All events");
    adminLayout->addWidget(allEventsLable);

    QHBoxLayout* mainWindow = new QHBoxLayout{this};
    mainWindow->addLayout(adminLayout);

    allEvents = new QListWidget{};
    adminLayout->addWidget(allEvents);

    QFormLayout* eventsDetails = new QFormLayout{};
    lineName = new QLineEdit{};
    lineDescription = new QLineEdit{};
    lineLink = new QLineEdit{};
    lineDate = new QLineEdit{};
    lineTime = new QLineEdit{};

    eventsDetails->addRow("Title", lineName);
    eventsDetails->addRow("Description", lineDescription);
    eventsDetails->addRow("Date", lineDate);
    eventsDetails->addRow("Time", lineTime);
    eventsDetails->addRow("Link", lineLink);

    adminLayout->addLayout(eventsDetails);

    QGridLayout* adminButtonsLayout = new QGridLayout{};

    addButton = new QPushButton("Add");
    deleteButton = new QPushButton("Delete");
    editButton = new QPushButton("Edit");

    adminButtonsLayout->addWidget(addButton, 0, 0);
    adminButtonsLayout->addWidget(deleteButton, 0, 1);
    adminButtonsLayout->addWidget(editButton, 0, 2);

    adminLayout->addLayout(adminButtonsLayout);
    populateList();

    //copyButton = new QPushButton("Copy");
    //mainWindow->addWidget(copyButton);

}

void GUI::populateList() {
    if(allEvents->count() > 0) {
        allEvents->clear();
    }

    std::vector<Event> events = this->administrator.getAllEventsAdmin();

    for(Event &e : events) {
        allEvents->addItem(QString::fromStdString(e.getTitle() +" "+ e.getDescription() +" "+ e.getLink()));
    }
}