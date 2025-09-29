//
// Created by Ale on 5/7/2025.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>
#include <vector>

#include "HospitalDepartment.h"


class Controller {
private:
    std::vector<std::shared_ptr<HospitalDepartment>> hospitalDepartments;
public:
    Controller(){}
    void addDepartment(std::shared_ptr<HospitalDepartment> department);
    std::vector<std::shared_ptr<HospitalDepartment>> getAllDepartments();
    std::vector<std::shared_ptr<HospitalDepartment>> getEfficientDepartments();
    void writeToFile(std::string fileName);
};



#endif //CONTROLLER_H
