#include <iostream>
#include "header.h"

///PÁLYA
//class Field:
Field::Field(int a, int b) {
    this->a = a;
    this->b = b;
    this->field = new Cell*[this->a];
    for (int i = 0; i < this->a; i++) {
        field[i] = new Cell[this->b];
    }
}

Field::~Field() {
    for(int i = 0; i < this->a; i++) {
        delete[] field[i];
    }
    delete[] this->field;
}

int Field::getA() const {
    return this->a;
}

int Field::getB() const {
    return this->b;
}

Cell** Field::getPointerField() const {
    return this->field;
}
