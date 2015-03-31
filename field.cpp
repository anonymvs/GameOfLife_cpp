#include <iostream>
#include "header.h"
#include "field.h"

//Cell functions
Cell::Cell(int a, int b, bool boolean) : x(a), y(b), b(boolean) {} // ctor
Cell::Cell(const Cell& ar) : x(ar.x), y(ar.y), b(ar.b) {} // copy ctor
Cell::~Cell() {} //dtor
bool Cell::getB() {
    return this->b;
}

//Field functions
Field::Field(int a, int b) : x(a), y(b) {
    Cell** ptr = new Cell*[b];
    for (int i = 0; i < b; ++i) {
        ptr[i] = new Cell[a];
        for(int j = 0; j < a; ++j)
            ptr[i][j] = Cell(j, i,false);
    }
}

Field::Field(const Field &arg) {
    this->x = arg.x;
    this->y = arg.y;
    for (int i = 0; i < arg.y; ++i) {
        for (int j = 0; j < arg.x; ++j) {
            this->p[i][j] = arg.p[i][j];
        }
    }
}

Field::~Field() {
    for (int i = 0; i < y; ++i) {
        delete [] p[i];
    }
    delete [] p;
}

int Field::getX() {
    return x;
}

Cell** Field::getP() {
    return p;
}
int Field::getY() {
    return y;
}


Field& Field::operator=(const Field &arg) {
    for (int i = 0; i < this->y; ++i) {
        delete [] p[i];
    }
    delete [] p;

    this->x = arg.x;
    this->y = arg.y;

    this->p = new Cell*[this->y];
    for (int i = 0; i < this->y; ++i) {
        this->p[i] = new Cell[this->x];
        for(int j = 0; j < this->x; ++j) {
            this->p[i][j] = Cell(j, i, false);
            this->p[i][j] = arg.p[i][j];
        }
    }
}
