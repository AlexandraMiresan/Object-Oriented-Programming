//
// Created by Ale on 4/15/2025.
//

#include <iostream>

#include "CSVEventList.h"
#include "HTMLEventList.h"
#include "UI/UI.h"
#include "Repository/Repository.h"
#include "Service/Administrator.h"
#include "Service/User.h"

void print_file_option() {
    std::cout << "Choose which file type you want to  use: " << std::endl;
    std::cout << ">> CSV file" << std::endl;
    std::cout << ">> HTML file" << std::endl;
    std::cout << ">> Exit" << std::endl;
}

int main() {
    try {
        std::string filename = "../admin.txt";
        Repository *repository = new Repository(filename);

        Administrator adminService(repository);
        EventList* user;

        std::string filetype;
        std::cout << "Enter the file type(CSV/HTML): ";
        std::getline(std::cin, filetype);
        if (filetype == "CSV") {
            user = new CSVEventList();
        }else if (filetype == "HTML") {
            user = new HTMLEventList();
        }else {
            throw std::invalid_argument("File type not recognized");
        }

        User userRepo(repository, user);


        UI ui(adminService, userRepo);


        ui.start();

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
