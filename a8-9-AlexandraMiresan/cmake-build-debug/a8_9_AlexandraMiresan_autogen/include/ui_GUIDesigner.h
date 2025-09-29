/********************************************************************************
** Form generated from reading UI file 'guidesigner.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDESIGNER_H
#define UI_GUIDESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIDesigner
{
public:
    QGridLayout *gridLayout;
    QTabWidget *TabWidget;
    QWidget *Admin;
    QTableWidget *tableWidget;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QLineEdit *lineTitle;
    QLineEdit *lineDescription;
    QLineEdit *lineDate;
    QLineEdit *lineTime;
    QLineEdit *linePeople;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineLink;
    QLabel *label_6;
    QLineEdit *lineDelete;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineTimeU;
    QLineEdit *lineDateU;
    QLineEdit *lineLinkU;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineIdU;
    QLineEdit *lineDescriptionU;
    QLineEdit *lineTitleU;
    QLabel *label_13;
    QLineEdit *linePeopleU;
    QLabel *label_14;
    QFrame *line;
    QFrame *line_2;
    QWidget *User;
    QTableWidget *userEvents;
    QListWidget *displayList;
    QPushButton *nextButton;
    QCheckBox *checkBox;
    QPushButton *openLinkButton;
    QPushButton *removeButton;
    QPushButton *openApp;
    QPushButton *saveButton;

    void setupUi(QWidget *GUIDesigner)
    {
        if (GUIDesigner->objectName().isEmpty())
            GUIDesigner->setObjectName("GUIDesigner");
        GUIDesigner->resize(1170, 684);
        gridLayout = new QGridLayout(GUIDesigner);
        gridLayout->setObjectName("gridLayout");
        TabWidget = new QTabWidget(GUIDesigner);
        TabWidget->setObjectName("TabWidget");
        TabWidget->setStyleSheet(QString::fromUtf8("background-color: lightpink;\n"
"color: black;;"));
        Admin = new QWidget();
        Admin->setObjectName("Admin");
        Admin->setStyleSheet(QString::fromUtf8("\n"
"font: 9pt \"Segoe UI\";"));
        tableWidget = new QTableWidget(Admin);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 10, 771, 601));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: white;"));
        addButton = new QPushButton(Admin);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(1010, 20, 80, 18));
        addButton->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        addButton->setToolTipDuration(-1);
        addButton->setStyleSheet(QString::fromUtf8("color:black; background-color:white"));
        deleteButton = new QPushButton(Admin);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(1020, 220, 80, 18));
        deleteButton->setStyleSheet(QString::fromUtf8("color:black; background-color:white"));
        updateButton = new QPushButton(Admin);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(1020, 270, 80, 21));
        updateButton->setStyleSheet(QString::fromUtf8("color:black; background-color:white"));
        lineTitle = new QLineEdit(Admin);
        lineTitle->setObjectName("lineTitle");
        lineTitle->setGeometry(QRect(902, 20, 101, 20));
        lineTitle->setStyleSheet(QString::fromUtf8("background-color:white"));
        lineDescription = new QLineEdit(Admin);
        lineDescription->setObjectName("lineDescription");
        lineDescription->setGeometry(QRect(902, 50, 101, 20));
        lineDescription->setStyleSheet(QString::fromUtf8("background-color:white"));
        lineDate = new QLineEdit(Admin);
        lineDate->setObjectName("lineDate");
        lineDate->setGeometry(QRect(902, 80, 101, 20));
        lineDate->setStyleSheet(QString::fromUtf8("background-color:white"));
        lineTime = new QLineEdit(Admin);
        lineTime->setObjectName("lineTime");
        lineTime->setGeometry(QRect(902, 110, 101, 20));
        lineTime->setStyleSheet(QString::fromUtf8("background-color:white"));
        linePeople = new QLineEdit(Admin);
        linePeople->setObjectName("linePeople");
        linePeople->setGeometry(QRect(960, 140, 41, 20));
        linePeople->setStyleSheet(QString::fromUtf8("background-color:white"));
        label = new QLabel(Admin);
        label->setObjectName("label");
        label->setGeometry(QRect(800, 20, 51, 20));
        label->setStyleSheet(QString::fromUtf8("color: black;"));
        label_2 = new QLabel(Admin);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(800, 50, 71, 20));
        label_2->setStyleSheet(QString::fromUtf8("color:black"));
        label_3 = new QLabel(Admin);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(800, 80, 51, 20));
        label_3->setStyleSheet(QString::fromUtf8("color:black"));
        label_4 = new QLabel(Admin);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(800, 110, 51, 20));
        label_4->setStyleSheet(QString::fromUtf8("color:black"));
        label_5 = new QLabel(Admin);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(796, 140, 161, 20));
        label_5->setStyleSheet(QString::fromUtf8("color:black"));
        lineLink = new QLineEdit(Admin);
        lineLink->setObjectName("lineLink");
        lineLink->setGeometry(QRect(890, 170, 113, 20));
        lineLink->setStyleSheet(QString::fromUtf8("background-color:white"));
        label_6 = new QLabel(Admin);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(800, 170, 37, 12));
        label_6->setStyleSheet(QString::fromUtf8("color:black"));
        lineDelete = new QLineEdit(Admin);
        lineDelete->setObjectName("lineDelete");
        lineDelete->setGeometry(QRect(890, 220, 113, 21));
        lineDelete->setStyleSheet(QString::fromUtf8("background-color:white"));
        label_7 = new QLabel(Admin);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(800, 220, 81, 21));
        label_7->setStyleSheet(QString::fromUtf8("color:black"));
        label_8 = new QLabel(Admin);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(796, 380, 161, 20));
        label_8->setStyleSheet(QString::fromUtf8("color:black"));
        label_9 = new QLabel(Admin);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(800, 260, 51, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: black;"));
        lineTimeU = new QLineEdit(Admin);
        lineTimeU->setObjectName("lineTimeU");
        lineTimeU->setGeometry(QRect(902, 350, 101, 20));
        lineTimeU->setStyleSheet(QString::fromUtf8("background-color:white"));
        lineDateU = new QLineEdit(Admin);
        lineDateU->setObjectName("lineDateU");
        lineDateU->setGeometry(QRect(902, 320, 101, 20));
        lineDateU->setStyleSheet(QString::fromUtf8("background-color:white"));
        lineLinkU = new QLineEdit(Admin);
        lineLinkU->setObjectName("lineLinkU");
        lineLinkU->setGeometry(QRect(890, 410, 113, 20));
        lineLinkU->setStyleSheet(QString::fromUtf8("background-color:white"));
        label_10 = new QLabel(Admin);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(800, 320, 51, 20));
        label_10->setStyleSheet(QString::fromUtf8("color:black"));
        label_11 = new QLabel(Admin);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(800, 350, 51, 20));
        label_11->setStyleSheet(QString::fromUtf8("color:black"));
        label_12 = new QLabel(Admin);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(800, 410, 37, 12));
        label_12->setStyleSheet(QString::fromUtf8("color:black"));
        lineIdU = new QLineEdit(Admin);
        lineIdU->setObjectName("lineIdU");
        lineIdU->setGeometry(QRect(890, 460, 113, 21));
        lineIdU->setStyleSheet(QString::fromUtf8("background-color:white"));
        lineDescriptionU = new QLineEdit(Admin);
        lineDescriptionU->setObjectName("lineDescriptionU");
        lineDescriptionU->setGeometry(QRect(902, 290, 101, 20));
        lineDescriptionU->setStyleSheet(QString::fromUtf8("background-color:white"));
        lineTitleU = new QLineEdit(Admin);
        lineTitleU->setObjectName("lineTitleU");
        lineTitleU->setGeometry(QRect(902, 260, 101, 20));
        lineTitleU->setStyleSheet(QString::fromUtf8("background-color:white"));
        label_13 = new QLabel(Admin);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(800, 460, 81, 21));
        label_13->setStyleSheet(QString::fromUtf8("color:black"));
        linePeopleU = new QLineEdit(Admin);
        linePeopleU->setObjectName("linePeopleU");
        linePeopleU->setGeometry(QRect(960, 380, 41, 20));
        linePeopleU->setStyleSheet(QString::fromUtf8("background-color:white"));
        label_14 = new QLabel(Admin);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(800, 290, 71, 20));
        label_14->setStyleSheet(QString::fromUtf8("color:black"));
        line = new QFrame(Admin);
        line->setObjectName("line");
        line->setGeometry(QRect(780, 240, 331, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(Admin);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(780, 200, 331, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::InputKeyboard));
        TabWidget->addTab(Admin, icon, QString());
        User = new QWidget();
        User->setObjectName("User");
        userEvents = new QTableWidget(User);
        userEvents->setObjectName("userEvents");
        userEvents->setGeometry(QRect(30, 140, 741, 481));
        userEvents->setStyleSheet(QString::fromUtf8("background-color:white"));
        displayList = new QListWidget(User);
        displayList->setObjectName("displayList");
        displayList->setGeometry(QRect(40, 20, 341, 101));
        displayList->setStyleSheet(QString::fromUtf8("background-color:white"));
        nextButton = new QPushButton(User);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(390, 20, 80, 18));
        nextButton->setStyleSheet(QString::fromUtf8("background-color: white;"));
        checkBox = new QCheckBox(User);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(390, 40, 91, 31));
        openLinkButton = new QPushButton(User);
        openLinkButton->setObjectName("openLinkButton");
        openLinkButton->setGeometry(QRect(390, 70, 75, 24));
        openLinkButton->setStyleSheet(QString::fromUtf8("background-color:white;"));
        removeButton = new QPushButton(User);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(390, 100, 75, 24));
        removeButton->setStyleSheet(QString::fromUtf8("background-color:white;"));
        openApp = new QPushButton(User);
        openApp->setObjectName("openApp");
        openApp->setGeometry(QRect(690, 100, 75, 24));
        openApp->setStyleSheet(QString::fromUtf8("background-color:white"));
        saveButton = new QPushButton(User);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(600, 100, 75, 24));
        saveButton->setStyleSheet(QString::fromUtf8("background-color:white"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::AudioCard));
        TabWidget->addTab(User, icon1, QString());

        gridLayout->addWidget(TabWidget, 0, 0, 1, 1);


        retranslateUi(GUIDesigner);

        TabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GUIDesigner);
    } // setupUi

    void retranslateUi(QWidget *GUIDesigner)
    {
        GUIDesigner->setWindowTitle(QCoreApplication::translate("GUIDesigner", "GUIDesigner", nullptr));
#if QT_CONFIG(accessibility)
        Admin->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        addButton->setText(QCoreApplication::translate("GUIDesigner", "Add event", nullptr));
        deleteButton->setText(QCoreApplication::translate("GUIDesigner", "Delete event", nullptr));
        updateButton->setText(QCoreApplication::translate("GUIDesigner", "Update event", nullptr));
        label->setText(QCoreApplication::translate("GUIDesigner", "Title", nullptr));
        label_2->setText(QCoreApplication::translate("GUIDesigner", "Description", nullptr));
        label_3->setText(QCoreApplication::translate("GUIDesigner", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("GUIDesigner", "Time", nullptr));
        label_5->setText(QCoreApplication::translate("GUIDesigner", "Number of people attending", nullptr));
        label_6->setText(QCoreApplication::translate("GUIDesigner", "Link", nullptr));
        label_7->setText(QCoreApplication::translate("GUIDesigner", "ID to delete:", nullptr));
        label_8->setText(QCoreApplication::translate("GUIDesigner", "Number of people attending", nullptr));
        label_9->setText(QCoreApplication::translate("GUIDesigner", "Title", nullptr));
        label_10->setText(QCoreApplication::translate("GUIDesigner", "Date", nullptr));
        label_11->setText(QCoreApplication::translate("GUIDesigner", "Time", nullptr));
        label_12->setText(QCoreApplication::translate("GUIDesigner", "Link", nullptr));
        label_13->setText(QCoreApplication::translate("GUIDesigner", "ID to update:", nullptr));
        label_14->setText(QCoreApplication::translate("GUIDesigner", "Description", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Admin), QCoreApplication::translate("GUIDesigner", "Admin", nullptr));
        nextButton->setText(QCoreApplication::translate("GUIDesigner", "Next", nullptr));
        checkBox->setText(QCoreApplication::translate("GUIDesigner", "Participate", nullptr));
        openLinkButton->setText(QCoreApplication::translate("GUIDesigner", "Open Link", nullptr));
        removeButton->setText(QCoreApplication::translate("GUIDesigner", "Remove", nullptr));
        openApp->setText(QCoreApplication::translate("GUIDesigner", "Open in App", nullptr));
        saveButton->setText(QCoreApplication::translate("GUIDesigner", "Save", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(User), QCoreApplication::translate("GUIDesigner", "User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIDesigner: public Ui_GUIDesigner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDESIGNER_H
