//
// Created by Ale on 3/18/2025.
//

#ifndef DYNNAMICARRAY_H
#define DYNNAMICARRAY_H

#pragma once
#include "../Domain/estate.h"

typedef Estate* TElem;

typedef struct {
    TElem* elems;
    int size, capacity;
} DynamicArray;


DynamicArray* createDynamicArray(int capacity);
void append(DynamicArray* arr, TElem estate);
void removeElement(DynamicArray* arr, int index);
void updateElement(DynamicArray* arr, int index, TElem newEstate);
void destroyArray(DynamicArray* arr);
int getSize(DynamicArray* arr);
TElem getElement(DynamicArray* arr, int index);

#endif //DYNNAMICARRAY_H
