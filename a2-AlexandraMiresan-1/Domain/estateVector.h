//
// Created by Ale on 3/6/2025.
//

#ifndef ESTATEVECTOR_H
#define ESTATEVECTOR_H

#include "estate.h"

typedef struct {
    Estate* data;
    int size;
    int capacity;
}EstateVector;

#endif //ESTATEVECTOR_H
