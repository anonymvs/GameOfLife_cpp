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

Field::Field(const Field& nf) {
    std::cout << "masolas tortent" << std::endl;
    Field uj(nf.a, nf.b);
    for (int i = 0; i < uj.b; i++) {
        for (int j = 0; j < uj.a; j++) {
            uj.field[i][j] = nf.field[i][j];
        }
    }
}

Field::~Field() {
    for(int i = 0; i < this->b; i++) {
        delete[] field[i];
    }
    delete[] this->field;
    //std::cout << "I am the field deconstructor" << std::endl;
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

void Field::setA(int a) {
    this->a = a;
}

void Field::setB(int b) {
    this->b = b;
}

void Field::setPointerField(Cell **p) {
    this->field = p;
}

Field& Field::operator=(const Field& a){
    Field uj(a.a, a.b);
    for (int i = 0; i < a.b; i++) {
        for (int j = 0; j < a.a; j++) {
            uj.field[i][j] = a.field[i][j];
        }
    }
}

void fieldCout(Field &a) {
    for(int i = 0; i < a.getB(); i++) {
        for(int j = 0; j < a.getA(); j++)
            std::cout << a.getPointerField()[i][j].getBool();
        std::cout << std::endl;
    }
}


