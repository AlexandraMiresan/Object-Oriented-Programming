//
// Created by Ale on 7/10/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ViewWindow.h" resolved

#include "viewwindow.h"
#include "ui_ViewWindow.h"


ViewWindow::ViewWindow(std::vector<std::shared_ptr<Recipe>> recipes, QWidget *parent) :
    QDialog(parent), ui(new Ui::ViewWindow), recipes(recipes) {
    ui->setupUi(this);
    update();
}

ViewWindow::~ViewWindow() {
    delete ui;
}


void ViewWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    for(auto recipe : recipes) {
        if(recipe->getPreparationTime() > 100) {
            painter.setBrush(Qt::red);
            painter.setPen(Qt::black);
            QRect rect(rand()%150, rand() % 150, recipe->getPreparationTime()*2, recipe->getPreparationTime()*2);
            painter.drawRect(rect);
            painter.drawText(rect, Qt::AlignCenter, QString::fromStdString(recipe->getName()));
        }else {
            painter.setBrush(Qt::darkGreen);
            painter.setPen(Qt::black);
            QRect rect(rand()%150, rand() % 150, recipe->getPreparationTime()*2, recipe->getPreparationTime()*2);
            painter.drawRect(rect);
            painter.drawText(rect, Qt::AlignCenter, QString::fromStdString(recipe->getName()));
        }
    }
}
