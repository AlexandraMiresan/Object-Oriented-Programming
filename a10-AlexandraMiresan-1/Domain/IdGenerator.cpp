//
// Created by Ale on 3/23/2025.
//

#include "IdGenerator.h"

int IdGenerator::ID = 0;
//generates a unique id
int IdGenerator::getId(){
    ID++;
    return ID;
}