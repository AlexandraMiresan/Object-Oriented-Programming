//
// Created by Ale on 5/12/2025.
//

#ifndef GUI_H
#define GUI_H
#include <QWidget>
#include <QListWidget>
#include <QPushButton>

#include "../Service/Administrator.h"
#include <QTableWidget>

class GUI : public QWidget{
private:
    Administrator &administrator;

    QListWidget* allEvents;
    QLineEdit* lineName;
    QLineEdit* lineDescription;
    QLineEdit* lineDate;
    QLineEdit* lineTime;
    QLineEdit* lineLink;

    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;

    QTabWidget *tabWidget;

    QTableWidget *tableWidget;
    //QPushButton* copyButton;
    QListWidget* events;

    // QPushButton* openLink;
    // QPushButton* nextEvent;

public:
    GUI(Administrator &admin);
    void initGUI();
    void populateList();
    // void connectSignalsAndSlots();
    //
    // void addButtonHandler();



};



#endif //GUI_H
