//
// Created by Ale on 5/7/2025.
//

#ifndef SURGERY_H
#define SURGERY_H
#include "HospitalDepartment.h"


class Surgery : public HospitalDepartment{
protected:
    int numberOfPatients;
public:
    Surgery(int numberOfPatients, std::string hospitalName, int numberOfDoctors);
    bool isEfficient() override;
    std::string toString() override;
    int getNumberOfPatients(){return this->numberOfPatients;}
    ~Surgery() override = default;
    std::string fileToString();
};



#endif //SURGERY_H
