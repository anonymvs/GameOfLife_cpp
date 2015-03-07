#include <iostream>
#include "header.h"

///SEJTEK LIST�JA
//class CellList:

CellList::CellList(int n) {
    this->n = n;
    this->pointer = new Cell[this->n];
}

int CellList::getN() const {
    return this->n;
}

Cell* CellList::getPointerList() const {
    return this->pointer;
}

void CellList::setN(int n) {
    this->n = n;
}
