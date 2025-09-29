//
// Created by Ale on 4/15/2025.
//

#include <iostream>


#include "Repository/CSVEventList.h"
#include "Repository/EventList.h"
#include "Repository/HTMLEventList.h"
#include "Repository/Repository.h"
#include "Service/Administrator.h"
#include "Service/User.h"
#include "UI/UI.h"

#include <QApplication>


#include <QApplication>
#include <QPushButton>

#include "UI/GUI.h"
//
// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);
//
//     std::string filename = "../admin.txt";
//     Repository *repo = new Repository(filename);
//     Administrator admin(repo);
//     GUI gui{admin};
//     gui.show();
//
//     return app.exec();
// }
#include <QApplication>
#include "guidesigner.h"
//
// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);
//     std::string filename = "../admin.txt";
//     Repository *repo = new Repository(filename);
//     Administrator admin(repo);
//     EventList *user = new CSVEventList();
//     User userRepo(repo, user);
//     GUIDesigner window{admin, userRepo};
//     window.show(); // Show the main widget
//
//     return app.exec(); // Start the Qt event loop
// }


#include <QApplication>
#include <QInputDialog>
#include "GUIDesigner.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Prompt the user to choose EventList type
    QStringList options;
    options << "CSV" << "HTML";
    bool ok;
    QString choice = QInputDialog::getItem(nullptr, "Select Export Format",
                                           "Choose the type of EventList to use:",
                                           options, 0, false, &ok);

    if (!ok || choice.isEmpty()) {
        return 0; // User cancelled
    }

    std::string filename = "../admin.txt";
    Repository *repo = new Repository(filename);
    Administrator admin(repo);

    EventList *userList = nullptr;
    if (choice == "CSV") {
        userList = new CSVEventList();
    } else if (choice == "HTML") {
        userList = new HTMLEventList();
    }

    User userRepo(repo, userList);
    GUIDesigner window{admin, userRepo};
    window.show(); // Show the main widget

    return app.exec(); // Start the Qt event loop
}


