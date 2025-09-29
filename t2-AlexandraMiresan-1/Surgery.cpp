//
// Created by Ale on 5/7/2025.
//

#include "Surgery.h"

Surgery::Surgery(int numberOfPatients, std::string hospitalName, int numberOfDoctors) : HospitalDepartment(hospitalName, numberOfDoctors) {
    this->numberOfPatients = numberOfPatients;
}

std::string Surgery::toString() {
    return "Department: Surgery, Hospital name: " + hospitalName + " ,number of doctors: " + std::to_string(numberOfDoctors) + " ,number of patients: " + std::to_string(numberOfPatients);
}

std::string Surgery::fileToString() {
    return "Department: Surgery, Hospital name: " + hospitalName + " ,number of doctors: " + std::to_string(numberOfDoctors) + " ,number of patients: " + std::to_string(numberOfPatients) + " -isEfficient?" + std::to_string(isEfficient());

}

bool Surgery::isEfficient() {
    if(numberOfPatients/numberOfDoctors >= 2) {
        return true;
    }
    return false;
}

