//
// Created by Ale on 3/6/2025.
//

#ifndef ESTATES_REPOSITORY_H
#define ESTATES_REPOSITORY_H

#include "../DynnamicArray/dynnamicArray.h"

typedef struct {
    DynamicArray* dynamicArray;
}Repository;

Repository* createRepository();
void destroyRepository(Repository* repo);
void addElementRepo(Repository *repo, TElem *elem);
int deleteElementRepo(Repository* repo, char *address);
int updateElementRepo(Repository* repo, char *address, TElem newElem);
TElem* getAllEstates(Repository* repo, int *size);
DynamicArray* getAllElements(Repository* repo);

#endif //ESTATES_REPOSITORY_H
