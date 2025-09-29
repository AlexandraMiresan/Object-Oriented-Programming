// //
// // Created by Ale on 3/6/2025.


#include <stdlib.h>
#include "../Repository/estates_repository.h"
Repository* createRepository()
{
    Repository* repo = malloc(sizeof(Repository));
    if (repo == NULL)
        return NULL;
    repo->dynamicArray = createDynamicArray(1);
    return repo;
}

void destroyRepository(Repository* repo)
{
    if (repo == NULL)
        return;
    destroyArray(repo->dynamicArray);
    free(repo);
}

void addElementRepo(Repository* repo, TElem *elem)
{
    if (repo->dynamicArray == NULL)
        return;
    append(repo->dynamicArray, *elem);
}

int deleteElementRepo(Repository* repo, char* address) {

    for(int i = 0; i < getSize(repo->dynamicArray); i++) {
        if(repo->dynamicArray->elems[i]->address == address) {
            destroyEstate(repo->dynamicArray->elems[i]);
            return 1;
        }
    }
    return 0;
}

int updateElementRepo(Repository* repo, char* address, TElem newElem) {

    for(int i = 0; i < getSize(repo->dynamicArray); i++) {
        if(repo->dynamicArray->elems[i]->address == address) {
            updateElement(repo->dynamicArray, i, newElem);
            return 1;
        }
    }

    return 0;
}

TElem* getAllEstates(Repository* repo, int *size) {
    *size = getSize(repo->dynamicArray);
    return repo->dynamicArray->elems;
}

DynamicArray* getAllElements(Repository* repo) {
    return repo->dynamicArray;
}

//
// #include "estates_repository.h"
// #include "Domain/estateVector.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// EstateVector estateList;
//
//
// int addEstate(Repository *estateList, TElem *estate) {
//     for(int i = 0; i < getSize(estateList->dynamicArray); i++) {
//         if(strcmp(estateList.data[i].address, address) == 0) {
//             printf("Address already exists\n");
//             return 0;
//         }
//     }
//
//     if (estateList.size >= estateList.capacity) {
//         resizeRepository();
//     }
//
//     strcpy(estateList.data[estateList.size].address, address);
//     strcpy(estateList.data[estateList.size].type, type);
//     estateList.data[estateList.size].surface = surface;
//     estateList.data[estateList.size].price = price;
//     estateList.size++;
//     return 1;
//
// }
//
// int deleteEstate(char *address) {
//     for(int i = 0; i < estateList.size; i++) {
//         if(strcmp(estateList.data[i].address, address) == 0) {
//             for(int j = i; j < estateList.size - 1; j++) {
//                 estateList.data[j] = estateList.data[j + 1];
//             }
//             estateList.size--;
//             return 1;
//         }
//     }
//
//     return 0;
// }
//
// int updateEstate(char *type, char *address, double surface, double price) {
//     for(int i = 0; i < estateList.size; i++) {
//         if(strcmp(estateList.data[i].address, address) == 0) {
//             strcpy(estateList.data[i].type, type);
//             estateList.data[i].surface = surface;
//             estateList.data[i].price = price;
//             return 1;
//         }
//     }
//     return 0;
// }
//
//
//
//
// Estate *getAllEstates(int *size) {
//     *size = estateList.size;
//     return estateList.data;
// }