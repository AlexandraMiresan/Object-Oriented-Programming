//
// Created by Ale on 5/16/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUIDesigner.h" resolved

#include "guidesigner.h"
#include "ui_GUIDesigner.h"
#include "Domain/Event.h"
#include "Service/Administrator.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

GUIDesigner::GUIDesigner(Administrator &admin, User &user, QWidget *parent): admin(admin), user(user),
                                                                             QWidget(parent), ui(new Ui::GUIDesigner) {
    loadEvents();
    ui->setupUi(this);
    populateTable();
    connectSignalsAndSlots();
    //populateUser();
    openLinkButton();
    participateEvents();

}

GUIDesigner::~GUIDesigner() {
    delete ui;
}

QString formatDate(std::chrono::year_month_day &ymd) {
    std::ostringstream oss;
    oss << static_cast<int>(ymd.year()) << "-"
            << std::setw(2) << std::setfill('0') << static_cast<unsigned>(unsigned(ymd.month())) << "-"
            << std::setw(2) << std::setfill('0') << static_cast<unsigned>(ymd.day());
    return QString::fromStdString(oss.str());
}

void GUIDesigner::populateTable() {
    if (ui->tableWidget->rowCount() > 0) {
        ui->tableWidget->clear();
    }

    std::vector<Event> events = this->admin.getAllEventsAdmin();

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(static_cast<int>(events.size()));
    ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << "Title" << "Description" << "Date" << "Time" << "Number of people attending" << "Link");


    for (int row = 0; row < events.size(); row++) {
        Event &e = events[row];

        //ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(e.getId())));
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(e.getTitle())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(e.getDescription())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(formatDate(e.getDate())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(e.getTime(), 'f', 2)));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(e.getNumberOfPeople())));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(e.getLink())));
    }

    ui->tableWidget->resizeColumnsToContents();
}

std::chrono::year_month_day toYMD(QString &dateStr) {
    QStringList parts = dateStr.split("-");
    int year = parts[2].toInt();
    unsigned month = parts[1].toInt();
    unsigned day = parts[0].toInt();
    return std::chrono::year{year} / std::chrono::month{month} / std::chrono::day{day};
}

void GUIDesigner::addButtonHandler() {
    QString title = ui->lineTitle->text().trimmed();
    QString description = ui->lineDescription->text().trimmed();
    QString date = ui->lineDate->text().trimmed();
    QString time = ui->lineTime->text().trimmed();
    QString people = ui->linePeople->text().trimmed();
    QString link = ui->lineLink->text().trimmed();

    std::chrono::year_month_day ymd = toYMD(date);

    admin.addEventAdmin(title.toStdString(), description.toStdString(), ymd, time.toDouble(), people.toInt(),
                        link.toStdString());

    this->populateTable();
    // int row = ui->tableWidget->rowCount();
    // ui->tableWidget->setItem(row, 0, new QTableWidgetItem(title));
    // ui->tableWidget->setItem(row, 1, new QTableWidgetItem(description));
    // ui->tableWidget->setItem(row, 2, new QTableWidgetItem(date));
    // ui->tableWidget->setItem(row, 3, new QTableWidgetItem(time));
    // ui->tableWidget->setItem(row, 4, new QTableWidgetItem(people));
    // ui->tableWidget->setItem(row, 5, new QTableWidgetItem(link));

    ui->lineTitle->clear();
    ui->lineDescription->clear();
    ui->lineDate->clear();
    ui->lineTime->clear();
    ui->linePeople->clear();
    ui->lineLink->clear();
    loadEvents();
}

void GUIDesigner::connectSignalsAndSlots() {
    QObject::connect(ui->addButton, &QPushButton::clicked, this, &GUIDesigner::addButtonHandler);
    QObject::connect(ui->deleteButton, &QPushButton::clicked, this, &GUIDesigner::deleteButtonHandler);
    QObject::connect(ui->updateButton, &QPushButton::clicked, this, &GUIDesigner::updateButtonHandler);
    QObject::connect(ui->nextButton, &QPushButton::clicked, this, [this]() {
        currentIndex++;
        if (currentIndex >= allEvents.size())
            currentIndex = 0;
        showEvents(currentIndex);
    });
    QObject::connect(ui->openLinkButton, &QPushButton::clicked, this, &GUIDesigner::openLinkButton);
    QObject::connect(ui->removeButton, &QPushButton::clicked, this, &GUIDesigner::removeEventUser);
    QObject::connect(ui->saveButton, &QPushButton::clicked, this, &GUIDesigner::saveFile);
    QObject::connect(ui->openApp, &QPushButton::clicked, this, &GUIDesigner::openInApp);
}

void GUIDesigner::deleteButtonHandler() {
    QString id = ui->lineDelete->text().trimmed();

    if (id.isEmpty()) {
        QMessageBox::critical(this, "Error", "ID must not be empty!");
    }

    admin.removeEventAdmin(id.toInt());

    this->populateTable();

    ui->lineDelete->clear();
    loadEvents();
}

void GUIDesigner::updateButtonHandler() {
    QString id = ui->lineIdU->text().trimmed();
    QString title = ui->lineTitleU->text().trimmed();
    QString description = ui->lineDescriptionU->text().trimmed();
    QString date = ui->lineDateU->text().trimmed();
    QString time = ui->lineTimeU->text().trimmed();
    QString people = ui->linePeopleU->text().trimmed();
    QString link = ui->lineLinkU->text().trimmed();

    //std::chrono::year_month_day ymd = toYMD(date);

    if (id.isEmpty()) {
        QMessageBox::critical(this, "Error", "ID must not be empty!");
    }
    if (!title.isEmpty()) {
        admin.updateTitleAdmin(id.toInt(), title.toStdString());
    }
    if (!description.isEmpty()) {
        admin.updateDescriptionAdmin(id.toInt(), description.toStdString());
    }
    if (!date.isEmpty()) {
        std::chrono::year_month_day ymd = toYMD(date);
        admin.updateDateAdmin(id.toInt(), ymd);
    }
    if (!time.isEmpty()) {
        admin.updateTimeAdmin(id.toInt(), time.toDouble());
    }
    if (!people.isEmpty()) {
        admin.updateNumberOfPeopleAdmin(id.toInt(), people.toInt());
    }
    if (!link.isEmpty()) {
        admin.updateLinkAdmin(id.toInt(), link.toStdString());
    }

    this->populateTable();

    ui->lineTitleU->clear();
    ui->lineDescriptionU->clear();
    ui->lineDateU->clear();
    ui->lineTimeU->clear();
    ui->linePeopleU->clear();
    ui->lineLinkU->clear();
    ui->lineIdU->clear();
    loadEvents();
}

void GUIDesigner::populateUser() {
    if (ui->userEvents->rowCount() > 0) {
        ui->userEvents->clear();
    }

    auto userEvents = this->user.getUserEvents();

    ui->userEvents->setColumnCount(7);
    ui->userEvents->setRowCount(static_cast<int>(userEvents.size()));
    ui->userEvents->setHorizontalHeaderLabels(
        QStringList() << "ID" << "Title" << "Description" << "Date" << "Time" << "Number of people attending" <<
        "Link");


    for (int row = 0; row < userEvents.size(); row++) {
        Event &e = userEvents[row];

        ui->userEvents->setItem(row, 0, new QTableWidgetItem(QString::number(e.getId())));
        ui->userEvents->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(e.getTitle())));
        ui->userEvents->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(e.getDescription())));
        ui->userEvents->setItem(row, 3, new QTableWidgetItem(formatDate(e.getDate())));
        ui->userEvents->setItem(row, 4, new QTableWidgetItem(QString::number(e.getTime(), 'f', 2)));
        ui->userEvents->setItem(row, 5, new QTableWidgetItem(QString::number(e.getNumberOfPeople())));
        ui->userEvents->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(e.getLink())));
    }

    ui->userEvents->resizeColumnsToContents();
}

void GUIDesigner::showEvents(int index) {
    if (index >= 0 && index < allEvents.size()) {
        Event &e = allEvents[index];

        ui->displayList->clear();

        ui->displayList->addItem(QString::fromStdString(e.getTitle()));
        ui->displayList->addItem(QString::fromStdString(e.getDescription()));
        ui->displayList->addItem(formatDate(e.getDate()));
        ui->displayList->addItem(QString::number(e.getTime(), 'f', 2));
        ui->displayList->addItem(QString::number(e.getNumberOfPeople()));

    }
    participateEvents();
}

void GUIDesigner::loadEvents() {
    allEvents = admin.getAllEventsAdmin();  // or your existing function
    currentIndex = -1;
}

void GUIDesigner::participateEvents() {
    try {
        if(ui->checkBox->isChecked()) {
            user.addEventToUserList(currentIndex);
        }
        populateUser();
        ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
    }catch(...) {
        QMessageBox::critical(this, "Error", "Event already added!");
    }

}

void GUIDesigner::openLinkButton() {
    if (currentIndex >= 0 && currentIndex < allEvents.size()) {
        QString link = QString::fromStdString(allEvents[currentIndex].getLink());

        if (QUrl(link).isValid()) {
            QDesktopServices::openUrl(QUrl(link));
        } else {
            qDebug() << "Invalid link:" << link;
        }
    } else {
        return;
    }
}

void GUIDesigner::removeEventUser() {
    try {
        this->user.removeEventFromUserList(currentIndex + 1);
        populateUser();
    }catch(...) {
        QMessageBox::critical(this, "Error", "Event not added!");
    }
}

void GUIDesigner::saveFile() {
    this->user.saveToFile();
}

void GUIDesigner::openInApp() {
    this->user.openInApp();
}

