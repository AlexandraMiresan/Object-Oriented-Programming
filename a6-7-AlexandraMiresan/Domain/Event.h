//
// Created by Ale on 3/23/2025.
//

#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <ctime>
#include <chrono>

#include "IdGenerator.h"


class Event {
private:
    int id;
    std::string title;
    std::string description;
    std::chrono::year_month_day date;
    double time;
    int numberOfPeople;
    std::string link;

public:
    Event();

    Event(std::string title, std::string description, std::chrono::year_month_day date, double time, int numberOfPeople,
          std::string link);


    int getId() { return this->id; };
    std::string getTitle() { return this->title; };
    std::string getDescription() { return this->description; };
    std::chrono::year_month_day &getDate() { return this->date; };
    double getTime() { return this->time; };
    int getNumberOfPeople() { return this->numberOfPeople; };
    std::string getLink() { return this->link; };

    void setTitle(std::string title) { this->title = title; };
    void setDescription(std::string description) { this->description = description; };
    void setDate(std::chrono::year_month_day date) { this->date = date; };
    void setTime(double time) { this->time = time; };
    void setNumberOfPeople(int number_of_people) { this->numberOfPeople = number_of_people; };
    void setLink(std::string link) { this->link = link; };


    std::string to_string();

    void openLink();
};

#endif //EVENT_H
