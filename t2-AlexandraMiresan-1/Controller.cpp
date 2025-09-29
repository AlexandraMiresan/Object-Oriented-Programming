//
// Created by Ale on 5/7/2025.
//

#include "Controller.h"

#include <algorithm>
#include <fstream>

void Controller::addDepartment(std::shared_ptr<HospitalDepartment> department) {
    this->hospitalDepartments.push_back(department);
}

std::vector<std::shared_ptr<HospitalDepartment> > Controller::getAllDepartments() {
    return this->hospitalDepartments;
}

std::vector<std::shared_ptr<HospitalDepartment> > Controller::getEfficientDepartments() {
    std::vector<std::shared_ptr<HospitalDepartment>> efficientDepartments;
    for (auto department : this->hospitalDepartments) {
        if(department->isEfficient()) {
            efficientDepartments.push_back(department);
        }
    }

    for(auto dep1 : efficientDepartments) {
        for(auto dep2 : efficientDepartments) {
            if(dep1->getHospitalName() < dep2->getHospitalName()) {
                auto dep = dep1;
                dep1 = dep2;
                dep2 = dep;
            }
        }
    }

    return efficientDepartments;
}

void Controller::writeToFile(std::string fileName) {
    std::ofstream fout(fileName);

    for(auto dep: this->hospitalDepartments) {
        fout << dep->fileToString() << std::endl;
    }

    fout.close();

}


