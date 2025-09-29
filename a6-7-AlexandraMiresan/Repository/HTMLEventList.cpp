//
// Created by Ale on 5/8/2025.
//

#include "HTMLEventList.h"

#include <fstream>

HTMLEventList::HTMLEventList() = default;

HTMLEventList::~HTMLEventList() = default;

void HTMLEventList::writeToFile() {
    std::string filename = "../admin.html";
    std::ofstream fout(filename);

    if (!fout.is_open()) {
        std::string error = "Could not open file ";
        throw std::invalid_argument(error);
    }

    fout << "<!DOCTYPE html>" << "\n";
    fout << "<html>" << "\n";

    fout << "<head>" << "\n";
    fout << "<title>Movie Playlist</title>" << "\n";
    fout << "</head>" << "\n";

    fout << "<body>" << "\n";

    fout << "<table border=\"1\">" << "\n";

    fout << "<tr>" << "\n";
    fout << "<td>Title</td>" << "\n";
    fout << "<td>Description</td>" << "\n";
    fout << "<td>Date</td>" << "\n";
    fout << "<td>Time</td>" << "\n";
    fout << "<td>Number of people attending</td>" << "\n";
    fout << "<td>Link</td>" << "\n";
    fout << "</tr>" << "\n";

    for (auto &e: events) {
        fout << "<tr>" << "\n";
        fout << "<td>" << e.getTitle() << "</td>" << "\n";
        fout << "<td>" << e.getDescription() << "</td>" << "\n";
        fout << "<td>" << formatDate(e.getDate()) << "</td>" << "\n";
        fout << "<td>" << e.getTime() << "</td>" << "\n";
        fout << "<td>" << e.getNumberOfPeople() << "</td>" << "\n";
        fout << "<td><a href =" << e.getLink() << ">LINK</a></td>" << "\n";
        fout << "</tr>" << "/n";
    }

    fout << "</table>" << "\n";
    fout << "</body>" << "\n";
    fout << "</html>" << "\n";
    fout.close();
}

void HTMLEventList::openInApp() {
    std::string link ="../admin.html";
    std::string s = "start " + link;
    system(s.c_str());
}

std::string HTMLEventList::formatDate(std::chrono::year_month_day &date) {
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << int(date.year()) << "-"
            << std::setw(2) << std::setfill('0') << unsigned(date.month()) << "-"
            << std::setw(2) << std::setfill('0') << unsigned(date.day());
    return oss.str();
}