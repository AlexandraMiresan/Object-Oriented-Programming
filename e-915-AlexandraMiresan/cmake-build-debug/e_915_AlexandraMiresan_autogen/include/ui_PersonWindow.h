/********************************************************************************
** Form generated from reading UI file 'personwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONWINDOW_H
#define UI_PERSONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonWindow
{
public:
    QTableView *tableView;
    QCheckBox *box;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *PersonWindow)
    {
        if (PersonWindow->objectName().isEmpty())
            PersonWindow->setObjectName("PersonWindow");
        PersonWindow->resize(863, 610);
        tableView = new QTableView(PersonWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 30, 611, 551));
        box = new QCheckBox(PersonWindow);
        box->setObjectName("box");
        box->setGeometry(QRect(650, 40, 78, 20));
        lineEdit = new QLineEdit(PersonWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(700, 100, 113, 21));
        label = new QLabel(PersonWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(640, 100, 49, 16));
        lineEdit_2 = new QLineEdit(PersonWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(700, 130, 113, 21));
        label_2 = new QLabel(PersonWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(640, 130, 49, 16));
        lineEdit_3 = new QLineEdit(PersonWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(700, 160, 113, 21));
        label_3 = new QLabel(PersonWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(640, 160, 49, 16));
        lineEdit_4 = new QLineEdit(PersonWindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(700, 190, 113, 21));
        label_4 = new QLabel(PersonWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(640, 190, 49, 16));
        lineEdit_5 = new QLineEdit(PersonWindow);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(700, 220, 113, 21));
        label_5 = new QLabel(PersonWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(640, 220, 49, 16));
        lineEdit_6 = new QLineEdit(PersonWindow);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(700, 250, 113, 21));
        label_6 = new QLabel(PersonWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(640, 250, 49, 16));
        lineEdit_7 = new QLineEdit(PersonWindow);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(700, 280, 113, 21));
        label_7 = new QLabel(PersonWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(640, 280, 49, 16));
        pushButton = new QPushButton(PersonWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(690, 330, 75, 24));
        pushButton_2 = new QPushButton(PersonWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(660, 420, 181, 121));

        retranslateUi(PersonWindow);

        QMetaObject::connectSlotsByName(PersonWindow);
    } // setupUi

    void retranslateUi(QWidget *PersonWindow)
    {
        PersonWindow->setWindowTitle(QCoreApplication::translate("PersonWindow", "PersonWindow", nullptr));
        box->setText(QCoreApplication::translate("PersonWindow", "CheckBox", nullptr));
        label->setText(QCoreApplication::translate("PersonWindow", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("PersonWindow", "Description", nullptr));
        label_3->setText(QCoreApplication::translate("PersonWindow", "latitudeX", nullptr));
        label_4->setText(QCoreApplication::translate("PersonWindow", "latitudeY", nullptr));
        label_5->setText(QCoreApplication::translate("PersonWindow", "longitudeX", nullptr));
        label_6->setText(QCoreApplication::translate("PersonWindow", "longitudeY", nullptr));
        lineEdit_7->setText(QString());
        label_7->setText(QCoreApplication::translate("PersonWindow", "date", nullptr));
        pushButton->setText(QCoreApplication::translate("PersonWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PersonWindow", "GOING", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonWindow: public Ui_PersonWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONWINDOW_H
