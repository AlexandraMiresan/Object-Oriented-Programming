//
// Created by Ale on 5/28/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QMessageBox>


GUI::GUI(Controller& controller,QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI), controller(controller) {
    ui->setupUi(this);
    populateList();
    connectButtons();
}

GUI::~GUI() {
    delete ui;
}

void GUI::populateList() {
    ui->listWidget->clear();
    for(auto& ti : controller.getTimeIntervals()) {
        QListWidgetItem *item = new QListWidgetItem("Start h:" + QString::number(ti->getStartHour()) + "-" + "End hour:" + QString::number(ti->getEndHour()) + "-" + QString::number(ti->getTemperature()) + "-" + QString::number(ti->getPrecipitationProbability()) + "-" + QString::fromStdString(ti->getDescription()));
        ui->listWidget->addItem(item);
    }
}

void GUI::filterByPrecipitation() {
    ui->listWidget->clear();
    QString precipitationStr = ui->precipitationLine->text().trimmed();
    int precipitation = precipitationStr.toInt();
    for(auto& ti : controller.getTimeIntervals()) {
        if(ti->getPrecipitationProbability() < precipitation) {
            ui->listWidget->addItem("Start h:" + QString::number(ti->getStartHour()) + "-" + "End hour:" + QString::number(ti->getEndHour()));
        }
    }
    ui->precipitationLine->clear();
}

void GUI::connectButtons() {
    QObject::connect(ui->filterButton, &QPushButton::clicked, this, &GUI::filterByPrecipitation);
    QObject::connect(ui->showButton, &QPushButton::clicked, this, &GUI::displayByDescriptionAndHour);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &GUI::populateList);
}

void GUI::displayByDescriptionAndHour() {
    ui->label->clear();
    QString descriptionStr = ui->descriptionLine->text().trimmed();
    QString startTimeStr = ui->starthourLine->text().trimmed();
    int startTime = startTimeStr.toInt();
    std::string description = descriptionStr.toStdString();
    int sum = 0;
    ui->listWidget_2->clear();

    for(auto& ti : controller.getTimeIntervals()) {
        if(ti->getStartHour() >= startTime || ti->getEndHour() > startTime) {
            if(ti->getDescription() == description) {
                ui->listWidget_2->addItem("Start h:" + QString::number(ti->getStartHour()) + "-" +"End h:"+ QString::number(ti->getEndHour()));
                sum += ti->getEndHour() - startTime;
            }
        }
    }


    ui->descriptionLine->clear();
    ui->starthourLine->clear();

    if(sum == 0) {
        QMessageBox::critical(this, "Error", "No such intervals!");
    }else {
        ui->label->setText(QString::number(sum));
    }
}



