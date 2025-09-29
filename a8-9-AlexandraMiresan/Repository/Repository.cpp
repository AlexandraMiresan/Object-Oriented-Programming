#include "Repository.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "../Validator/RepositoryValidator.h"

void Repository::addRepo(Event &event) {
    for(int i = 0; i < this->events.size(); i++){
        Event &existingEvent = this->events[i];
        if(event.getTitle() == existingEvent.getTitle() && event.getDate() == existingEvent.getDate() && event.getTime() == existingEvent.getTime()) {
            throw RepositoryValidator{"Event already exists!\n"};
        }
    }
    events.push_back(event);
    saveToFile();
}

bool Repository::removeRepo(int id) {
    auto it = std::remove_if(events.begin(), events.end(),
                             [id](Event &e) { return e.getId() == id; });

    if (it != events.end()) {
        events.erase(it, events.end());
        saveToFile();
        return true;
    }

    throw RepositoryValidator{"The event with the specified ID does not exist!\n"};
}

bool Repository::updateRepo(int id, Event &event) {
    for (int i = 0; i < this->events.size(); i++) {
        Event &existingEvent = this->events[i];
        if (existingEvent.getId() == id) {

            existingEvent.setTitle(event.getTitle());
            existingEvent.setDescription(event.getDescription());
            existingEvent.setDate(event.getDate());
            existingEvent.setTime(event.getTime());
            existingEvent.setNumberOfPeople(event.getNumberOfPeople());
            existingEvent.setLink(event.getLink());

            saveToFile();
            return true;
        }
    }

    throw RepositoryValidator{"The event with the specified ID does not exist!"};
}


std::string Repository::formatDate(std::chrono::year_month_day &date) {
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << int(date.year()) << "-"
            << std::setw(2) << std::setfill('0') << unsigned(date.month()) << "-"
            << std::setw(2) << std::setfill('0') << unsigned(date.day());
    return oss.str();
}

std::chrono::year_month_day Repository::parseDate(std::string &dateStr) {
    std::istringstream iss(dateStr);
    int year, month, day;
    char sep1, sep2;

    if (iss >> year >> sep1 >> month >> sep2 >> day && sep1 == '-' && sep2 == '-') {
        return std::chrono::year_month_day{
            std::chrono::year{year},
            std::chrono::month{unsigned(month)},
            std::chrono::day{unsigned(day)}
        };
    }

    throw std::invalid_argument("Invalid date format");
}

std::vector<Event> Repository::loadFromFile() {
    std::vector<Event> loaded;
    std::ifstream fin { this->filename };

    if (!fin.is_open()) {
        std::cerr << "Failed to open file for reading: " << this->filename << std::endl;
        return {};
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string title, desc, dateStr, timeStr, peopleStr, link;

        std::getline(ss, title, ',');
        std::getline(ss, desc, ',');
        std::getline(ss, dateStr, ',');
        std::getline(ss, timeStr, ',');
        std::getline(ss, peopleStr, ',');
        std::getline(ss, link);

        try {
            double time = std::stod(timeStr);
            int people = std::stoi(peopleStr);
            std::chrono::year_month_day date = parseDate(dateStr);

            Event e(title, desc, date, time, people, link);
            if(loaded.size() == 0) {
                loaded.push_back(e);
            }
            else {
                for(int i = 0; i < loaded.size(); i++) {
                    Event &existingEvent = loaded[i];
                    if(e.getTitle() == existingEvent.getTitle() && e.getDate() == existingEvent.getDate() && e.getTime() == existingEvent.getTime()) {
                        throw RepositoryValidator{"Event already exists!"};
                    }
                }
                loaded.push_back(e);
            }

        } catch (...) {
            std::cerr << "Skipping invalid line in file: " << line << "\n";
        }
    }

    fin.close();
    return loaded;
}

void Repository::saveToFile() {
    std::ofstream fout(filename);

    if (!fout.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

    if (events.empty()) {
        std::cerr << "No events to save." << std::endl;
        return;
    }

    for (auto &e: events) {

        fout    << e.getTitle() << ","
                << e.getDescription() << ","
                << formatDate(e.getDate()) << ","
                << e.getTime() << ","
                << e.getNumberOfPeople() << ","
                << e.getLink() << "\n";
    }

    fout.close();
}