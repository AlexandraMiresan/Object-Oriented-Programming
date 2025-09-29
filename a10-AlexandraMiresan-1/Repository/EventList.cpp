//
// Created by Ale on 5/8/2025.
//

#include "EventList.h"
#include "../Domain/Event.h"

EventList::EventList() {
    this->index = 0;
}

EventList::EventList(std::vector<Event> e, int index) : events{std::move(e)}, index{index} {}

void EventList::addEventList(Event &e) {
    int pos = findEventList(e);
    if(pos != -1) {
        std::string error = "Event already exists";
        throw EventListRepoException(error);
    }
    this->events.push_back(e);
}

void EventList::removeEventList(Event &e) {
    int pos = findEventList(e);
    if(pos == -1) {
        std::string error = "Event does not exist";
        throw EventListRepoException(error);
    }
    this->events.erase(this->events.begin() + pos);
}

int EventList::findEventList(Event &e) {
    int pos = 0;
    for(auto it : this->events) {
        if(e.getTitle() == it.getTitle() && e.getDescription() == it.getDescription() && e.getDate() == it.getDate() && e.getTime() == it.getTime()) {
            return pos + 1;
        }
        pos++;
    }

    return -1;
}

void EventList::next() {
    if(this->events.size() == this->index + 1) {
        this->index = 0;
        return;
    }
    this->index++;
}

bool EventList::isEmpty() {
    if(this->events.empty()) {
        return true;
    }
    return false;
}

void EventList::openLink() {
    if(this->events.empty()) {
        return;
    }
    Event e = this->getCurrentEvent();
    e.openLink();
}

Event EventList::getCurrentEvent() {
    return this->events.at(this->index);
}

EventList::~EventList() = default;

EventListRepoException::EventListRepoException(std::string message) {
    this->message = message;
}

const char *EventListRepoException::what() const noexcept {
    return this->message.c_str();
}






