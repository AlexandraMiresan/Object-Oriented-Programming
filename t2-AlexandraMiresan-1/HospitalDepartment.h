//
// Created by Ale on 5/7/2025.
//


#ifndef HOSPITALDEPARTMENT_H
#define HOSPITALDEPARTMENT_H

#include <string>

class HospitalDepartment {
protected:
    std::string hospitalName;
    int numberOfDoctors;
public:
    HospitalDepartment(std::string &hospitalName, int numberOfDoctors);
    virtual ~HospitalDepartment();
    std::string getHospitalName(){return this->hospitalName;}
    virtual bool isEfficient();
    virtual std::string toString();
    virtual std::string fileToString() {
        return "hospitalDepartment";
    }
};



#endif //HOSPITALDEPARTMENT_H
