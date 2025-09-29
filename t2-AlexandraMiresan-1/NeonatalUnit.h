//
// Created by Ale on 5/7/2025.
//

#ifndef NEONATALUNIT_H
#define NEONATALUNIT_H
#include "HospitalDepartment.h"


class NeonatalUnit : public HospitalDepartment {
protected:
    double averageGrade;
public:
    NeonatalUnit(double averageGrade, std::string hospitalName, int numberOfDoctors);
    bool isEfficient() override;
    std::string toString() override;
    double getAverageGrade(){return this->averageGrade;}
    ~NeonatalUnit() override=default;
    std::string fileToString();
};



#endif //NEONATALUNIT_H
