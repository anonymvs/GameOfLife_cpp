#include <iostream>
#include "header.h"

///PÁLYA
//class Field:
Field::Field(int a, int b) {
    this->a = a;
    this->b = b;
    this->field = new Cell*[this->b];
    for (int i = 0; i < this->b; i++) {
        field[i] = new Cell[this->a];
    }
    for(int i = 0; i < this->b; i++) {
        for(int j = 0; j < this->a; j++) {
            field[i][j].setX(a);
            field[i][j].setY(b);
            //field[i][j].setBool(0);
        }
    }
}

Field::~Field() {
    for(int i = 0; i < this->b; i++) {
        delete[] field[i];
    }
    delete[] this->field;
    std::cout << "I am the field deconstructor" << std::endl;
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
/*
Field Field::operator=(const Field& a) const {
    return Field(a.getA(), a.getB());
}
*/
void fieldCout(Field &a) {
    for(int i = 0; i < a.getB(); i++) {
        for(int j = 0; j < a.getA(); j++)
            std::cout << a.getPointerField()[i][j].getBool();
        std::cout << std::endl;
    }
}
