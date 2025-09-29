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


// // Constructor to initialize the ID generator starting at 1
// int IdGenerator::ID = 0;
//
// IdGenerator::IdGenerator() {
//     id = ++ID;
// }
//
// IdGenerator::IdGenerator(const IdGenerator &A) {
//     id = A.id;
// }
//
// IdGenerator& IdGenerator::operator=(const IdGenerator &A) {
//     id = A.id;
//     return *this;
// }

