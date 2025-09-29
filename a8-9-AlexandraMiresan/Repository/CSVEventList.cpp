//
// Created by Ale on 5/8/2025.
//

#include "CSVEventList.h"

#include <fstream>

CSVEventList::CSVEventList() {
}

CSVEventList::~CSVEventList() = default;

void CSVEventList::writeToFile() {
    std::string filename = "../admin.csv";
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::string error = "Error opening file: " + filename + "\n";
        throw EventListRepoException(error);
    }

    for (auto &e: this->getEventList()) {
        fout << e.getTitle() << ","
                << e.getDescription() << ","
                << formatDate(e.getDate()) << ","
                << e.getTime() << ","
                << e.getNumberOfPeople() << ","
                << e.getLink() << "\n";
    }
};

std::string CSVEventList::formatDate(std::chrono::year_month_day &date) {
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << int(date.year()) << "-"
            << std::setw(2) << std::setfill('0') << unsigned(date.month()) << "-"
            << std::setw(2) << std::setfill('0') << unsigned(date.day());
    return oss.str();
};

void CSVEventList::openInApp() {
    std::string filename = "../admin.csv";
    std::string cmd = "notepad.exe " + filename;
    system(cmd.c_str());
}

CSVEventList::CSVEventList(std::vector<Event> event, int index) : EventList(std::move(event), index) {

}
