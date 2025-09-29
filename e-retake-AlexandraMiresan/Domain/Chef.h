//
// Created by Ale on 7/10/2025.
//

#ifndef CHEF_H
#define CHEF_H
#include <string>


class Chef {
private:
    std::string name;
    std::string cuisine;
public:
    Chef(std::string name, std::string cuisine) : name(name), cuisine(cuisine) {}
    std::string getName() { return this->name; }
    std::string getCuisine() { return this->cuisine; }
    ~Chef()=default;
};



#endif //CHEF_H
