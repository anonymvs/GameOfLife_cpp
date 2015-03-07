#include <iostream>
#include "header.h"

///SEJT
//class cell:
Cell::Cell(int x, int y, bool b) {
    this->x = x;
    this->y = y;
    state = 0;
}

int Cell::getX() const {
    return this->x;
}

int Cell::getY() const {
    return this->y;
}

bool Cell::getBool() const {
    return this->state;
}

void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

void Cell::setBool(bool b) {
    state = b;
}

