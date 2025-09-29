//
// Created by Ale on 4/3/2025.
//

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
    } else {
        throw std::invalid_argument("Invalid month string: " + month_str);
    }
}

void UI::start() {
    while (true) {
        print_menu(); // Always print the main menu
        std::string cmd;
        std::getline(std::cin, cmd);

        if (cmd == "Admin") {
            while (true) {
                // Keep showing the admin menu until "exit"
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
                    break; // Exit the admin loop and return to the main menu
                } else {
                    std::cout << "Invalid command. Please try again." << std::endl;
                }
            }
            continue; // After exiting the admin loop, go back to the main menu
        } else if (cmd == "User") {
            while (true) {
                // Keep showing the user menu until "exit"
                print_user_menu();
                std::string userCmd;
                std::getline(std::cin, userCmd);

                if (userCmd == "add") {
                    userAddEvent();
                } else if (userCmd == "delete") {
                    userRemoveEvent();
                } else if (userCmd == "view") {
                    userGetEventsToAttend();
                } else if (userCmd == "exit") {
                    break; // Exit the user loop and return to the main menu
                } else {
                    std::cout << "Invalid command. Please try again." << std::endl;
                }
            }
            continue; // After exiting the user loop, go back to the main menu
        } else if (cmd == "Exit") {
            break; // Exit the program
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}


void UI::adminAddEvent() {
    try {
        std::string title, description, link;
        int year, month, day;
        double time;
        int numberOfPeople;

        std::cout << "Enter event title: " << std::endl;
        std::getline(std::cin, title);
        std::cout << "Enter event description: " << std::endl;
        std::getline(std::cin, description);
        std::cout << "Enter date of event (YYYY MM DD): " << std::endl;
        std::cin >> year;
        std::cin >> month;
        std::cin >> day;

        std::chrono::year_month_day date = {
            std::chrono::year{year}, std::chrono::month{static_cast<unsigned>(month)},
            std::chrono::day{static_cast<unsigned>(day)}
        };

        std::cout << "Enter time: " << std::endl;
        std::cin >> time;

        std::cout << "Enter number of people attending: " << std::endl;
        std::cin >> numberOfPeople;

        std::string buffer;
        std::getline(std::cin, buffer);

        std::cout << "Enter link: " << std::endl;
        std::getline(std::cin, link);

        if (this->admin.addEventAdmin(title, description, date, time, numberOfPeople, link) == 0) {
            std::cout << "Successfully added event!" << std::endl;
        }
    } catch (...) {
        std::cout << "Invalid input." << std::endl;
    }
}

void UI::adminRemoveEvent() {
    try {
        int id;
        std::cout << "Enter event id to delete: " << std::endl;
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
        std::string title, description, link;
        int year, month, day;
        double time;
        int numberOfPeople;
        std::string field;

        std::cout << "Enter event id to update: " << std::endl;
        std::cin >> id;

        std::string buffer;
        std::getline(std::cin, buffer);

        std::cout << "What field do you want to update?" << std::endl;
        std::getline(std::cin, field);

        if (field == "title") {
            std::cout << "Enter new title: " << std::endl;
            std::getline(std::cin, title);
            if (this->admin.updateTitleAdmin(id, title) == 0) {
                std::cout << "Successfully updated title!" << std::endl;
            }
        } else if (field == "description") {
            std::cout << "Enter new description: " << std::endl;
            std::getline(std::cin, description);
            if (this->admin.updateDescriptionAdmin(id, description) == 0) {
                std::cout << "Successfully updated description!" << std::endl;
            }
        } else if (field == "date") {
            std::cout << "Enter new date: " << std::endl;
            std::cin >> year;
            std::cin >> month;
            std::cin >> day;

            std::chrono::year_month_day date = {
                std::chrono::year{year}, std::chrono::month{static_cast<unsigned>(month)},
                std::chrono::day{static_cast<unsigned>(day)}
            };
            if (this->admin.updateDateAdmin(id, date) == 0) {
                std::cout << "Successfully updated date!" << std::endl;
            }
        } else if (field == "time") {
            std::cout << "Enter new time: " << std::endl;
            std::cin >> time;
            if (this->admin.updateTimeAdmin(id, time) == 0) {
                std::cout << "Successfully updated time!" << std::endl;
            }
        } else if (field == "numberOfPeople") {
            std::cout << "Enter number of people attending: " << std::endl;
            std::cin >> numberOfPeople;
            if (this->admin.updateNumberOfPeopleAdmin(id, numberOfPeople) == 0) {
                std::cout << "Successfully updated numberOfPeople!" << std::endl;
            }
        } else if (field == "link") {
            std::cout << "Enter new link: " << std::endl;
            std::cin >> link;
            if (this->admin.updateLinkAdmin(id, link) == 0) {
            } else if (field == "all") {
                std::cout << "Enter new title: " << std::endl;
                std::getline(std::cin, title);

                std::cout << "Enter new description: " << std::endl;
                std::getline(std::cin, description);

                std::cout << "Enter new date: " << std::endl;
                std::cin >> year;
                std::cin >> month;
                std::cin >> day;

                std::chrono::year_month_day date = {
                    std::chrono::year{year}, std::chrono::month{static_cast<unsigned>(month)},
                    std::chrono::day{static_cast<unsigned>(day)}
                };

                std::cout << "Enter new time: " << std::endl;
                std::cin >> time;

                std::cout << "Enter number of people attending: " << std::endl;
                std::cin >> numberOfPeople;

                std::cout << "Enter new link: " << std::endl;
                std::cin >> link;

                if (this->admin.updateEventAdmin(id, title, description, date, time, numberOfPeople, link) == 0) {
                    std::cout << "Successfully updated event!" << std::endl;
                }
            }
        }
    } catch (...) {
        std::cout << "Invalid input." << std::endl;
    }
}

void UI::userAddEvent() {
    std::string month;
    std::cout << "Enter the month for which you want to see the events: " << std::endl;
    std::getline(std::cin, month);

    bool cont = true;
    while (cont) {
        if (month == "") {
            for (int i = 0; i < this->user.getSortedEvents().get_size(); i++) {
                Event event = this->user.getSortedEvents().get_elem(i);
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
        } else  {
            auto events = this->user.getSortedEvents();
            int size = events.get_size();

            for (int i = 0; i < size; ++i) {
                Event event = events.get_elem(i);

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
}

void UI::userRemoveEvent() {
    try {
        int id;
        std::cin >> id;
        if (this->user.removeEventFromUserList(id) == 0) {
            std::cout << "Successfully removed event!" << std::endl;
        }
    } catch (...) {
        std::cout << "Invalid input." << std::endl;
    }
}

void UI::userGetEventsToAttend() {
    auto events = this->user.getUserEvents();
    int size = events.get_size();

    for (int i = 0; i < size; ++i) {
        Event event = events.get_elem(i);
        std::cout << event.to_string() << std::endl;
    }

    std::cout << std::endl;
}

void UI::adminGetEvents() {
    auto events = this->admin.getAllEventsAdmin();
    int size = events.get_size();

    for (int i = 0; i < size; ++i) {
        Event event = events.get_elem(i);
        std::cout << event.to_string() << std::endl;
    }

    std::cout << std::endl;
}
