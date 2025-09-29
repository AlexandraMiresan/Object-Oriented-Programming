//
// Created by Ale on 3/18/2025.
//
#include "../DynnamicArray/dynnamicArray.h"
#include "../Domain/estate.h"
#include <stdlib.h>

DynamicArray* createDynamicArray(int capacity)
{
    DynamicArray* arr = malloc(sizeof(DynamicArray));
    arr->elems = malloc(capacity * sizeof(TElem));
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void destroyArray(DynamicArray* arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; i < arr->size; i++)
        destroyEstate(arr->elems[i]);
    free(arr->elems);
    free(arr);
}

int resize(DynamicArray* arr)
{
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        TElem* aux = realloc(arr->elems, arr->capacity * sizeof(TElem));
        if (aux == NULL)
        {
            return 1;
        }
        arr->elems = aux;
        return 0;
    }

    return 1;
}

void append(DynamicArray* arr, TElem elem)
{
    resize(arr);
    arr->elems[arr->size++] = elem;
}

void removeElement(DynamicArray* arr, int index) {

    for(int i = index; i < arr->size; i++) {
        arr->elems[i] = arr->elems[i + 1];
    }
    arr->size--;

}

void updateElement(DynamicArray* arr, int index, TElem elem) {
    arr->elems[index] = elem;
}

TElem getElement(DynamicArray* arr, int index) {
    return arr->elems[index];
}

int getSize(DynamicArray* arr)
{
    return arr->size;
}
