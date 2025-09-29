//
// Created by Ale on 5/7/2025.
//

#include "NeonatalUnit.h"

NeonatalUnit::NeonatalUnit(double averageGrade, std::string hospitalName, int numberOfDoctors) : HospitalDepartment(hospitalName, numberOfDoctors) {
    this->averageGrade = averageGrade;
}

std::string NeonatalUnit::toString() {
    return "Department: NeonatalUnit, Hospital name: " + hospitalName + ",number of doctors: " + std::to_string(numberOfDoctors) + ",average grade: " + std::to_string(averageGrade);
}

std::string NeonatalUnit::fileToString() {
    return "Department: NeonatalUnit, Hospital name: " + hospitalName + ",number of doctors: " + std::to_string(numberOfDoctors) + ",average grade: " + std::to_string(averageGrade) + "- isEfficient?" + std::to_string(isEfficient());
}

bool NeonatalUnit::isEfficient() {
    if(averageGrade >= 8.5) {
        return true;
    }
    return false;
}
