//
// Created by Ale on 4/28/2025.
//

#ifndef REPOSITORYVALIDATOR_H
#define REPOSITORYVALIDATOR_H
#include <string>

class RepositoryValidator : public std::exception{
private:
    std::string message;
public:
    RepositoryValidator(const std::string& s) : message { s } {}

    const char * what() const throw() override {
        return this->message.c_str();
    }
};

#endif //REPOSITORYVALIDATOR_H
