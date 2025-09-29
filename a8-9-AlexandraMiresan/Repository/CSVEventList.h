//
// Created by Ale on 5/8/2025.
//

#ifndef CSVEVENTLIST_H
#define CSVEVENTLIST_H
#include <chrono>

#include "EventList.h"


class Event;

class CSVEventList : public EventList{
public:
    CSVEventList();
    CSVEventList(std::vector<Event> e, int index);
    ~CSVEventList();

    void addEventList(Event &e) override {EventList::addEventList(e); this->writeToFile();}
    void removeEventList(Event &e) override {EventList::removeEventList(e); this->writeToFile();}
    std::string formatDate(std::chrono::year_month_day &date);

    void writeToFile() override;
    void openInApp() override;

};



#endif //CSVEVENTLIST_H
