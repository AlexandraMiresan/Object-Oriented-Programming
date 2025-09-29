/********************************************************************************
** Form generated from reading UI file 'chefwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHEFWINDOW_H
#define UI_CHEFWINDOW_H

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

class Ui_ChefWindow
{
public:
    QTableView *tableView;
    QCheckBox *checkBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *ChefWindow)
    {
        if (ChefWindow->objectName().isEmpty())
            ChefWindow->setObjectName("ChefWindow");
        ChefWindow->resize(700, 479);
        tableView = new QTableView(ChefWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 20, 421, 431));
        checkBox = new QCheckBox(ChefWindow);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(460, 20, 171, 20));
        label = new QLabel(ChefWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(460, 70, 49, 16));
        lineEdit = new QLineEdit(ChefWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(560, 70, 113, 21));
        lineEdit_2 = new QLineEdit(ChefWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(560, 100, 113, 21));
        label_2 = new QLabel(ChefWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 100, 101, 16));
        lineEdit_3 = new QLineEdit(ChefWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(530, 130, 161, 51));
        label_3 = new QLabel(ChefWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(460, 130, 61, 16));
        lineEdit_4 = new QLineEdit(ChefWindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(460, 240, 211, 51));
        label_4 = new QLabel(ChefWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(460, 220, 131, 16));
        pushButton = new QPushButton(ChefWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(590, 190, 75, 24));
        pushButton_2 = new QPushButton(ChefWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(520, 300, 75, 24));
        pushButton_3 = new QPushButton(ChefWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(460, 420, 75, 24));
        pushButton_4 = new QPushButton(ChefWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(460, 380, 75, 24));

        retranslateUi(ChefWindow);

        QMetaObject::connectSlotsByName(ChefWindow);
    } // setupUi

    void retranslateUi(QWidget *ChefWindow)
    {
        ChefWindow->setWindowTitle(QCoreApplication::translate("ChefWindow", "ChefWindow", nullptr));
        checkBox->setText(QCoreApplication::translate("ChefWindow", "view only matching cuisine", nullptr));
        label->setText(QCoreApplication::translate("ChefWindow", "Recipe", nullptr));
        label_2->setText(QCoreApplication::translate("ChefWindow", "Preparation Time", nullptr));
        label_3->setText(QCoreApplication::translate("ChefWindow", "Ingredients", nullptr));
        label_4->setText(QCoreApplication::translate("ChefWindow", "Search by ingredients", nullptr));
        pushButton->setText(QCoreApplication::translate("ChefWindow", "add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChefWindow", "filter", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ChefWindow", "view", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ChefWindow", "show all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChefWindow: public Ui_ChefWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEFWINDOW_H
