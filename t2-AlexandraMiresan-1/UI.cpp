//
// Created by Ale on 5/7/2025.
//

#include "UI.h"

#include <iostream>

#include "NeonatalUnit.h"
#include "Surgery.h"

void printMenu() {
    std::cout << ">> Add department. <add>" << std::endl;
    std::cout << ">> Show all departments. <show>" << std::endl;
    std::cout << ">> Show efficient departments. <efficient>" << std::endl;
    std::cout << ">> Save all departments to file. <save>" << std::endl;
    std::cout << ">> exit." << std::endl;
}

void UI::addStartDeps() {
    auto dep2 = std::make_shared<Surgery>(120, "Regina Maria", 20);
    auto dep1 = std::make_shared<NeonatalUnit>(9.5, "Policlinica", 13);
    auto dep3 = std::make_shared<Surgery>(300, "Sanovil", 40);
    this->controller.addDepartment(dep1);
    this->controller.addDepartment(dep2);
    this->controller.addDepartment(dep3);
}

void UI::start() {
    addStartDeps();
    while(true) {
        printMenu();

        std::string cmd;
        std::getline(std::cin, cmd);
        if (cmd == "add") {
            addDepartment();
        }
        else if (cmd == "show") {
            showDepartments();
        }
        else if (cmd == "efficient") {
            showEfficientDepartments();
        }
        else if (cmd == "save") {
            saveToFile();
        }
        else if (cmd == "exit") {
            break;
        }
        else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}

void UI::addDepartment() {
    std::cout << "Enter type of department(S/NU): " << std::endl;
    std::string department;
    std::getline(std::cin, department);
    if(department == "S") {
        std::string hospitalName;
        int numberOfDoctors;
        int numberOfPatients;

        std::cout << "Enter hospital name: " << std::endl;
        std::getline(std::cin, hospitalName);
        std::cout << "Enter number of doctors: " << std::endl;
        std::cin >> numberOfDoctors;
        std::cout << "Enter number of patients: " << std::endl;
        std::cin >> numberOfPatients;

        auto dep = std::make_shared<Surgery>(numberOfPatients, hospitalName, numberOfDoctors);
        this->controller.addDepartment(dep);

        std::string buffer;
        std::getline(std::cin, buffer);
    }else if (department == "NU") {
        std::string hospitalName;
        int numberOfDoctors;
        double averageGrade;

        std::cout << "Enter hospital name: " << std::endl;
        std::getline(std::cin, hospitalName);
        std::cout << "Enter number of doctors: " << std::endl;
        std::cin >> numberOfDoctors;
        std::cout << "Enter average grade: " << std::endl;
        std::cin >> averageGrade;

        auto dep = std::make_shared<NeonatalUnit>(averageGrade, hospitalName, numberOfDoctors);
        this->controller.addDepartment(dep);

        std::string buffer;
        std::getline(std::cin, buffer);
    }else {
        std::cout << "Invalid department. Please try again." << std::endl;
    }

}

void UI::showDepartments() {
    for(auto dep : this->controller.getAllDepartments()) {
        std::cout << dep->toString() << std::endl;
    }
    std::cout << std::endl;
}

void UI::showEfficientDepartments() {
    for(auto dep: this->controller.getEfficientDepartments()) {
        std::cout << dep->toString() << std::endl;
    }
    std::cout << std::endl;
}

void UI::saveToFile() {
    std::string fileName;
    std::cout << "Enter file name: " << std::endl;
    std::getline(std::cin, fileName);
    this->controller.writeToFile(fileName);
}
