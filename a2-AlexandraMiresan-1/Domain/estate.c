//
// Created by Ale on 3/18/2025.
//

#include "estate.h"
#include <stdlib.h>
#include <string.h>

Estate* createEstate(char* type, char* address, double surface, double price)
{
    Estate* estate  = malloc(sizeof(Estate));
    if (estate == NULL)
        return NULL;

    estate->address = malloc(sizeof(char) * (strlen(address) + 1));
    if (estate->address == NULL)
        return NULL;
    strcpy(estate->address, address);

    estate->type = malloc(sizeof(char) * (strlen(type) + 1));
    if (estate->type == NULL)
        return NULL;
    strcpy(estate->type, type);

    estate->surface = surface;
    estate->price = price;

    return estate;
}

void destroyEstate(Estate* estate)
{
    if (estate == NULL)
        return;

    free(estate->address);
    free(estate->type);
    free(estate);

}

char* getAddress(Estate* estate)
{
    return estate->address;
}
