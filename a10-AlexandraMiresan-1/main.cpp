//
// Created by Ale on 4/15/2025.
//


#include <QApplication>
#include <QInputDialog>

#include "Administrator.h"
#include "CSVEventList.h"
#include "guidesigner.h"
#include "HTMLEventList.h"
#include "Repository.h"
#include "User.h"
#include "UserModel.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QStringList options;
    options << "CSV" << "HTML";
    bool ok;
    QString choice = QInputDialog::getItem(nullptr, "Select Export Format",
                                           "Choose the type of EventList to use:",
                                           options, 0, false, &ok);

    if (!ok || choice.isEmpty()) {
        return 0;
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
    //std::unique_ptr<UserModel> model = std::make_unique<UserModel>(userRepo);
    GUIDesigner window{admin, userRepo};
    window.setWindowTitle("Event App");
    window.show();

        return app.exec();
}


