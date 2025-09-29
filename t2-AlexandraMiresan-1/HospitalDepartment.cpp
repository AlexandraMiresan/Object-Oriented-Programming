//
// Created by Ale on 5/7/2025.
//

#include "HospitalDepartment.h"

HospitalDepartment::HospitalDepartment(std::string &hospitalName, int numberOfDoctors) {
    this->hospitalName = hospitalName;
    this->numberOfDoctors = numberOfDoctors;
}

HospitalDepartment::~HospitalDepartment() {

}

std::string HospitalDepartment::toString() {
    return "Hospital department";
}

bool HospitalDepartment::isEfficient() {
    return true;
}
