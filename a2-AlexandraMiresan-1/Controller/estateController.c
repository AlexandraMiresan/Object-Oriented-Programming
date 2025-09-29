//
// Created by Ale on 3/6/2025.
//

#include "estateController.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Repository/estates_repository.h"


Service* createService() {
    Service *service = (Service*)malloc(sizeof(Service));
    if (service == NULL) {
        return NULL;
    }

    service-> repo = createRepository();
    if (service->repo == NULL) {
        free(service);
        return NULL;
    }
    return service;

}

void destroyService(Service* service) {
    if (service == NULL)
        return;

    destroyRepository(service->repo);
    free(service);
}

int addElementToController(Service *service, char* type, char* address, double surface, double price) {
    if (service == NULL || service->repo == NULL) {
        return 2;
    }

    Estate* estate = createEstate(type, address, surface, price);

    addElementRepo(service->repo, &estate);
    return 1;
}

int deleteEstateFromController(Service* service, char *address) {
    if(strlen(address) == 0) {
        return 2;
    }

    if(deleteElementRepo(service->repo, address) == 1) {
        return 1;
    };

    return 0;

}

int updateEstateController(Service* service, char *type, char* address, double surface, double price) {
    if(surface <= 0 || price <= 0) {
        return 2;
    }

    if(strlen(type) <= 0 || strlen(address) <= 0) {
        return 2;
    }

    Estate* estate = createEstate(type, address, surface, price);

    if(updateElementRepo(service->repo, address, &estate) == 1) {
        return 1;
    }

    return 0;
}

TElem* getAllEstatesController(Service *service, int *size) {
    return getAllEstates(service->repo, size);
}


void sortByPrice(DynamicArray *array) {
    if (array == NULL || array->size <= 1) {
        return; // No need to sort if the array is empty or has one element
    }

    int swapped;
    for (int i = 0; i < array->size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < array->size - i - 1; j++) {
            if (array->elems[j]->price > array->elems[j + 1]->price) {
                // Swap elements
                Estate *temp = array->elems[j];
                array->elems[j] = array->elems[j + 1];
                array->elems[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no swaps were made, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

DynamicArray* searchEstatesController(Service *service, char *searchStr, int *size) {

    if(searchStr == NULL) {
        return getAllElements(service->repo);
    }

    DynamicArray *filtered = createDynamicArray(*size);

    if(!filtered->elems) {
        return NULL;
    }

    for(int i = 0; i < *size; i++) {
        if(strlen(searchStr) == 0 || strstr(service->repo->dynamicArray->elems[i]->address, searchStr)) {
            append(filtered, service->repo->dynamicArray->elems[i]);
        }
    }

    sortByPrice(filtered);

    *size = filtered->size;
    return filtered;
}

DynamicArray *displayEstatesByType(Service *service, char *type, double surface, int *size) {
    DynamicArray* filtered = createDynamicArray(*size);

    if(!filtered->elems) {
        return NULL;
    }

    for(int i = 0; i < *size; i++) {
        if(strcmp(service->repo->dynamicArray->elems[i]->type, type) == 0) {
            if(service->repo->dynamicArray->elems[i]->surface > surface) {
                append(filtered,service->repo->dynamicArray->elems[i]);
            }
        }
    }

    *size = filtered->size;
    return filtered;
}