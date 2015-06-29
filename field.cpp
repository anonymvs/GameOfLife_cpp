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

Cell& Cell::operator=(const Cell &arg) {
    //std::cout << "Cell eq operator" << std::endl;
    x = arg.x;
    y = arg.y;
    b = arg.b;
    return *this;
}

void Cell::setX(int a) {
    x = a;
}
void Cell::setY(int a) {
    y = a;
}
void Cell::setB(bool x) {
    this->b = x;
}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

//Field functions
Field::Field(int a, int b) : x(a), y(b) {
    //std::cout << "Field ctor" << std::endl;
    Cell** ptr = new Cell*[b];
    for (int i = 0; i < b; ++i) {
        ptr[i] = new Cell[a];
        for(int j = 0; j < a; ++j) {
            ptr[i][j].setX(j);
            ptr[i][j].setY(i);
            ptr[i][j].setB(false);
        }
    }
    this->p = ptr;
}

Field::Field(const Field &arg) {
    //std::cout << "Field copy ctor" << std::endl;
    this->x = arg.x;
    this->y = arg.y;

    Cell** ptr = new Cell*[arg.y];
    for (int i = 0; i < arg.y; ++i) {
        ptr[i] = new Cell[arg.x];
        for(int j = 0; j < arg.x; ++j) {
            ptr[i][j].setX(j);
            ptr[i][j].setY(i);
            ptr[i][j].setB(arg.p[i][j].getB());
        }
    }
    this->p = ptr;
}

Field::~Field() {
    //std::cout << "Field dtor" << std::endl;
    for (int i = 0; i < y; ++i) {
        delete [] p[i];
    }
    delete [] p;
}

int Field::getX() {
    return x;
}

Cell** Field::getP() {
    return this->p;
}
int Field::getY() {
    return y;
}


Field& Field::operator=(const Field &arg) {

    //std::cout << "Field eq operator" << std::endl;

    if(this->p != NULL || (this->x != 0 || this->y != 0)) {
        for (int i = 0; i < this->y; ++i) {
            delete [] this->p[i];
        }
        delete [] this->p;
    }

    this->x = arg.x;
    this->y = arg.y;

    Cell** ptr = new Cell*[this->y];
    for (int i = 0; i < this->y; ++i) {
        ptr[i] = new Cell[this->x];
        for(int j = 0; j < this->x; ++j) {
            ptr[i][j].setX(j);
            ptr[i][j].setY(i);
            ptr[i][j].setB(arg.p[i][j].getB());
        }
    }
    this->p = ptr;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Field f) {
    for (int k = 0; k < f.x+2; ++k)
        std::cout << '#';
    std::cout << std::endl;
    for (int i = 0; i < f.y; ++i) {
        std::cout << '#';
        for (int j = 0; j < f.x; ++j) {
            os << f.p[i][j].getB();
        }
        std::cout << '#';
        os << std::endl;
    }
    for (int k = 0; k < f.x+2; ++k)
        std::cout << '#';
    return os;
}
