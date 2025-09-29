//
// Created by Ale on 3/23/2025.
//

#include "Event.h"
#include <windows.h>
#include <iomanip>

#include "IdGenerator.h"

Event::Event() {
    this->id = 0;
    this->title = "";
    this->description = "";
    this->date = {std::chrono::December/4/2025};
    this->time = 0;
    this->numberOfPeople = 0;
    this->link = "";
}

Event::Event(std::string title, std::string description, std::chrono::year_month_day date, double time, int numberOfPeople, std::string link) {
    this->id = IdGenerator::getId();
    this->title  = title;
    this->description = description;
    this->date = date;
    this->time = time;
    this->numberOfPeople = numberOfPeople;
    this->link = link;
}


std::string Event::to_string() {
    std::ostringstream oss;
    oss << "Id: " << id << "\n"
        << "Event: " << title << "\n"
        << "Description: " << description << "\n"
        << "Date & Time: " << date << " starting at: " << time << "\n"
        << "Number of People: " << numberOfPeople << "\n"
        << "Link: " << link;
    return oss.str();
}

void Event::openLink() {
    ShellExecuteA(NULL, "open", this->getLink().c_str(), NULL, NULL, SW_SHOWNORMAL);
}



