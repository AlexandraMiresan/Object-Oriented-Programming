//
// Created by Ale on 6/25/2025.
//
#include <QApplication>
#include <ui_PersonWindow.h>

#include "Controller/EventsController.h"
#include "Controller/PeopleController.h"
#include "GUI/personwindow.h"
#include "Repository/EventsRepository.h"
#include "Repository/PeopleRepository.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    EventsRepository eventsRepo = EventsRepository();
    PeopleRepository peopleRepo = PeopleRepository();

    EventsController eventsController = EventsController(eventsRepo);
    PeopleController peopleController = PeopleController(peopleRepo);

    for(auto& person: peopleController.getPeople()) {
        auto* window = new PersonWindow(*person, eventsController);
        eventsRepo.addObserver(window);
        window->setWindowTitle(QString::fromStdString(person->getName() +" | "+ std::to_string(person->getLocation().getLatitudeX()) + "," + std::to_string(person->getLocation().getLatitudeY()) + " , " + std::to_string(person->getLocation().getLongitudeX())+ " , " + std::to_string(person->getLocation().getLongitudeY())));
        window->show();
    }

    return app.exec();

}
