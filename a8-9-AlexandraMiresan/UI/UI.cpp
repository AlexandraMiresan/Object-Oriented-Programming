#include "UI.h"
#include <iostream>
#include <unordered_map>


void print_menu() {
    std::cout << ">> Admin" << std::endl;
    std::cout << ">> User" << std::endl;
    std::cout << ">> Exit" << std::endl;
}

void print_user_menu() {
    std::cout << ">> View events in a specific month and add to InterestedIn list. <add>" << std::endl;
    std::cout << ">> Delete event from the InterestedIn list. <delete>" << std::endl;
    std::cout << ">> Show all events from InterestedIn list. <view>" << std::endl;
    std::cout << ">> Save events to specified file. <save>" << std::endl;
    std::cout << ">> Open in app. <open>" << std::endl;
    std::cout << ">> Exit" << std::endl;
}

void print_admin_menu() {
    std::cout << ">> Add event. <add>" << std::endl;
    std::cout << ">> Delete event. <delete>" << std::endl;
    std::cout << ">> Update event. <update>" << std::endl;
    std::cout << ">> Show all events. <view>" << std::endl;
    std::cout << ">> Exit" << std::endl;
}

std::chrono::month month_from_string(const std::string &month_str) {
    static const std::unordered_map<std::string, std::chrono::month> month_map = {
        {"January", std::chrono::January}, {"February", std::chrono::February},
        {"March", std::chrono::March}, {"April", std::chrono::April},
        {"May", std::chrono::May}, {"June", std::chrono::June},
        {"July", std::chrono::July}, {"August", std::chrono::August},
        {"September", std::chrono::September}, {"October", std::chrono::October},
        {"November", std::chrono::November}, {"December", std::chrono::December}
    };

    auto it = month_map.find(month_str);
    if (it != month_map.end()) {
        return it->second;
    }
    throw std::invalid_argument("Invalid month string: " + month_str);
}

void UI::start() {
    while (true) {
        print_menu();
        std::string cmd;
        std::getline(std::cin, cmd);

        if (cmd == "admin") {
            handle_admin();
        } else if (cmd == "user") {
            handle_user();
        } else if (cmd == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}

void UI::handle_admin() {
    while (true) {
        print_admin_menu();
        std::string adminCmd;
        std::getline(std::cin, adminCmd);

        if (adminCmd == "add") {
            adminAddEvent();
        } else if (adminCmd == "delete") {
            adminRemoveEvent();
        } else if (adminCmd == "update") {
            adminUpdateEvent();
        } else if (adminCmd == "view") {
            adminGetEvents();
        } else if (adminCmd == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}

void UI::adminGetEvents() {
    auto &events = this->admin.getAllEventsAdmin();
    for (auto &e: events) {
        std::cout << e.to_string() << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void UI::handle_user() {
    while (true) {
        print_user_menu();
        std::string userCmd;
        std::getline(std::cin, userCmd);

        if (userCmd == "add") {
            userAddEvent();
        } else if (userCmd == "delete") {
            userRemoveEvent();
        } else if (userCmd == "view") {
            userGetEventsToAttend();
        } else if (userCmd == "save") {
            userSaveEventsList();
        }else if (userCmd == "open") {
            userOpenEventsList();
        } else if (userCmd == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}

void UI::userOpenEventsList() {
    this->user.openInApp();
}


void UI::userSaveEventsList() {
    this->user.saveToFile();
}


void UI::adminAddEvent() {
    try {
        std::string title, description, link;
        int year, month, day, numberOfPeople;
        double time;

        std::cout << "Enter event title: ";
        std::getline(std::cin, title);
        std::cout << "Enter event description: ";
        std::getline(std::cin, description);
        std::cout << "Enter event date (YYYY MM DD): ";
        std::cin >> year >> month >> day;

        std::string buffer;
        std::getline(std::cin, buffer);


        if (month < 1 || month > 12 || day < 1 || day > 31) {
            throw std::invalid_argument("Invalid date format");
        }

        std::chrono::year_month_day date = {
            std::chrono::year{year}, std::chrono::month{static_cast<unsigned>(month)},
            std::chrono::day{static_cast<unsigned>(day)}
        };

        std::cout << "Enter event time: ";
        std::cin >> time;
        std::cout << "Enter number of people attending: ";
        std::cin >> numberOfPeople;


        std::getline(std::cin, buffer);

        std::cout << "Enter event link: ";
        std::getline(std::cin, link);

        this->admin.addEventAdmin(title, description, date, time, numberOfPeople, link);

        std::cout << "Successfully added event!" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what();
    }
}

void UI::adminRemoveEvent() {
    try {
        int id;
        std::cout << "Enter event ID to delete: ";
        std::cin >> id;

        std::string buffer;
        std::getline(std::cin, buffer);

        if (this->admin.removeEventAdmin(id) == 0) {
            std::cout << "Successfully deleted event!" << std::endl;
        }
    } catch (...) {
        std::cout << "Invalid input." << std::endl;
    }
}

void UI::adminUpdateEvent() {
    try {
        int id;
        std::string title, description, link, field;
        int year, month, day, numberOfPeople;
        double time;

        std::cout << "Enter event ID to update: ";
        std::cin >> id;

        std::string buffer;
        std::getline(std::cin, buffer);

        std::cout << "Which field would you like to update? (title/description/date/time/people/link/all): ";
        std::getline(std::cin, field);

        if (field == "title") {
            std::cout << "Enter new title: ";
            std::getline(std::cin, title);
            if (this->admin.updateTitleAdmin(id, title) == 0) {
                std::cout << "Successfully updated title!" << std::endl;
            }
        } else if (field == "description") {
            std::cout << "Enter new description: ";
            std::getline(std::cin, description);
            if (this->admin.updateDescriptionAdmin(id, description) == 0) {
                std::cout << "Successfully updated description!" << std::endl;
            }
        } else if (field == "date") {
            std::cout << "Enter new date (YYYY MM DD): ";
            std::cin >> year >> month >> day;
            std::chrono::year_month_day date = {
                std::chrono::year{year}, std::chrono::month{static_cast<unsigned>(month)},
                std::chrono::day{static_cast<unsigned>(day)}
            };
            if (this->admin.updateDateAdmin(id, date) == 0) {
                std::cout << "Successfully updated date!" << std::endl;
            }
        } else if (field == "time") {
            std::cout << "Enter new time: ";
            std::cin >> time;
            if (this->admin.updateTimeAdmin(id, time) == 0) {
                std::cout << "Successfully updated time!" << std::endl;
            }
        } else if (field == "numberOfPeople") {
            std::cout << "Enter number of people attending: ";
            std::cin >> numberOfPeople;
            if (this->admin.updateNumberOfPeopleAdmin(id, numberOfPeople) == 0) {
                std::cout << "Successfully updated number of people!" << std::endl;
            }
        } else if (field == "link") {
            std::cout << "Enter new link: ";
            std::cin >> link;
            if (this->admin.updateLinkAdmin(id, link) == 0) {
                std::cout << "Successfully updated link!" << std::endl;
            }
        } else if (field == "all") {
            // Handle update of all fields together (similar to individual updates)
            std::cout << "Enter new event details..." << std::endl;
            adminAddEvent(); // Reuse the method to gather all inputs
        }
    } catch (...) {
        std::cout << "Invalid input." << std::endl;
    }
}

void UI::userAddEvent() {
    try {
        std::string month;
        std::cout << "Enter the month for which you want to see the events: " << std::endl;
        std::getline(std::cin, month);

        bool cont = true;
        while (cont) {
            if (month == "") {
                std::vector<Event> events = this->admin.getAllEventsAdmin();
                for (auto &event: events) {
                    event.openLink();
                    std::cout << event.to_string() << std::endl;
                    std::cout << std::endl;
                    std::cout << "Do you want to attend this event? (y/n)" << std::endl;

                    std::string attend;
                    std::getline(std::cin, attend);


                    if (attend == "y") {
                        if (this->user.addEventToUserList(event.getId()) == 0) {
                            std::cout << "Successfully added event!" << std::endl;
                        }
                    } else {
                        std::cout << "Too bad you won't attend this event! :(" << std::endl;
                    }

                    std::string getNextEvent;
                    std::getline(std::cin, getNextEvent);

                    if (getNextEvent == "next") {
                        continue;
                    } else if (getNextEvent == "exit") {
                        cont = false;
                        break;
                    } else {
                        std::cout << "Invalid input." << std::endl;
                    }
                }
            } else {
                auto events = this->user.getSortedEvents();


                for (auto &event: events) {
                    std::chrono::year_month_day ymd = event.getDate();
                    std::chrono::month m = ymd.month();

                    if (m == month_from_string(month)) {
                        event.openLink();
                        std::cout << event.to_string() << std::endl;
                        std::cout << std::endl;
                        std::cout << "Do you want to attend this event? (y/n)" << std::endl;

                        std::string attend;
                        std::getline(std::cin, attend);

                        if (attend == "y") {
                            if (this->user.addEventToUserList(event.getId()) == 0) {
                                std::cout << "Successfully added event!" << std::endl;
                            }
                        } else {
                            std::cout << "Too bad you won't attend this event! :(" << std::endl;
                        }

                        std::string getNextEvent;
                        std::getline(std::cin, getNextEvent);

                        if (getNextEvent == "next") {
                            continue;
                        } else if (getNextEvent == "exit") {
                            cont = false;
                            break;
                        } else {
                            std::cout << "Invalid input." << std::endl;
                        }
                    }
                }
            }
        }
    } catch (...) {
        std::cerr << "There was an error." << std::endl;
    }
}

void UI::userRemoveEvent() {
    try {
        int id;
        std::cout << "Enter event ID to delete from InterestedIn list: ";
        std::cin >> id;

        std::string buffer;
        std::getline(std::cin, buffer);

        if (this->user.removeEventFromUserList(id) == 0) {
            std::cout << "Successfully deleted event!" << std::endl;
        }
    } catch (...) {
        std::cout << "Invalid input." << std::endl;
    }
}

void UI::userGetEventsToAttend() {
    auto events = this->user.getUserEvents();
    for (auto &event: events) {
        std::cout << event.to_string() << std::endl;
    }
    std::cout << std::endl;
}
