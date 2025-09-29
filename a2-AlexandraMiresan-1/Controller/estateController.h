//
// Created by Ale on 3/6/2025.
//

#ifndef ESTATECONTROLLER_H
#define ESTATECONTROLLER_H

#include "../Repository/estates_repository.h"

typedef struct {
    Repository* repo;
} Service;

Service* createService();
void destroyService(Service *service);
int addElementToController(Service* service, char *type, char *address, double surface, double price);
int deleteEstateFromController(Service* service, char *address);
int updateEstateController(Service* service, char *type, char *address, double surface, double price);
TElem* getAllEstatesController(Service* service, int *size);
DynamicArray* searchEstatesController(Service *service, char *searchStr, int *size);
DynamicArray* displayEstatesByType(Service *service, char *type, double surface, int *size);

#endif //ESTATECONTROLLER_H
