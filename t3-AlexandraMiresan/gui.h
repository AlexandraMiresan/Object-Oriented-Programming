//
// Created by Ale on 5/28/2025.
//

#ifndef GUI_H
#define GUI_H

#include <QWidget>

#include "Controller.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(Controller& controller,QWidget *parent = nullptr);
    ~GUI() override;

private:
    Ui::GUI *ui;
    Controller& controller;

    void connectButtons();
    void populateList();
    void filterByPrecipitation();
    void displayByDescriptionAndHour();
};


#endif //GUI_H
