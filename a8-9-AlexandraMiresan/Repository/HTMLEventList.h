//
// Created by Ale on 5/8/2025.
//

#ifndef HTMLEVENTLIST_H
#define HTMLEVENTLIST_H
#include "EventList.h"


class HTMLEventList : public EventList{
public:
    HTMLEventList();
    ~HTMLEventList();

    void addEventList(Event& e) override {EventList::addEventList(e);this->writeToFile();}
    void removeEventList(Event &e) override {EventList::removeEventList(e);this->writeToFile();}

    void writeToFile() override;
    void openInApp() override;

    std::string formatDate(std::chrono::year_month_day &date);
};



#endif //HTMLEVENTLIST_H
