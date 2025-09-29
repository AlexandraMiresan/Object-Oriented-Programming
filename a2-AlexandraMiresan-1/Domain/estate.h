//
// Created by Ale on 3/6/2025.
//

#ifndef ESTATE_H
#define ESTATE_H

typedef struct {
    char* type;
    char* address;
    double surface;
    double price;
}Estate;

Estate* createEstate(char* type, char* address, double surface, double price);
void destroyEstate(Estate* estate);
char *getAddress(Estate* estate);

#endif //ESTATE_H
