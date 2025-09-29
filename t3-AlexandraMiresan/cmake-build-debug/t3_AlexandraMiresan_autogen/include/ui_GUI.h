/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QPushButton *filterButton;
    QLineEdit *precipitationLine;
    QLineEdit *starthourLine;
    QPushButton *showButton;
    QLineEdit *descriptionLine;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName("GUI");
        GUI->resize(667, 617);
        GUI->setStyleSheet(QString::fromUtf8("background-color:lightblue;"));
        listWidget = new QListWidget(GUI);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 20, 371, 271));
        listWidget->setStyleSheet(QString::fromUtf8("background-color:white; color:black"));
        listWidget_2 = new QListWidget(GUI);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(30, 310, 371, 261));
        listWidget_2->setStyleSheet(QString::fromUtf8("background-color:white; color:black"));
        filterButton = new QPushButton(GUI);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(420, 60, 221, 24));
        filterButton->setStyleSheet(QString::fromUtf8("background-color:black"));
        precipitationLine = new QLineEdit(GUI);
        precipitationLine->setObjectName("precipitationLine");
        precipitationLine->setGeometry(QRect(420, 30, 221, 21));
        precipitationLine->setStyleSheet(QString::fromUtf8("background-color:white; color:black"));
        starthourLine = new QLineEdit(GUI);
        starthourLine->setObjectName("starthourLine");
        starthourLine->setGeometry(QRect(410, 350, 221, 21));
        starthourLine->setStyleSheet(QString::fromUtf8("background-color:white;color:black"));
        showButton = new QPushButton(GUI);
        showButton->setObjectName("showButton");
        showButton->setGeometry(QRect(410, 380, 221, 24));
        showButton->setStyleSheet(QString::fromUtf8("background-color:black"));
        descriptionLine = new QLineEdit(GUI);
        descriptionLine->setObjectName("descriptionLine");
        descriptionLine->setGeometry(QRect(410, 320, 221, 21));
        descriptionLine->setStyleSheet(QString::fromUtf8("background-color:white;color:black"));
        label = new QLabel(GUI);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 420, 49, 16));
        label_2 = new QLabel(GUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(420, 10, 221, 16));
        label_2->setStyleSheet(QString::fromUtf8("color:black"));
        label_3 = new QLabel(GUI);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 300, 211, 16));
        label_3->setStyleSheet(QString::fromUtf8("color:balck;"));
        pushButton = new QPushButton(GUI);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(430, 110, 201, 24));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:black"));

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        filterButton->setText(QCoreApplication::translate("GUI", "Filter", nullptr));
        showButton->setText(QCoreApplication::translate("GUI", "Show Intervals and Total Time", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("GUI", "Please enter the precipitation probability:", nullptr));
        label_3->setText(QCoreApplication::translate("GUI", "Please enter description and start hour:", nullptr));
        pushButton->setText(QCoreApplication::translate("GUI", "Show all data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
