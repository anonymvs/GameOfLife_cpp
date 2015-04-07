#include <iostream>
#include "header.h"
#include "field.h"

using namespace std;

int cntr = 0;

void startf(Field &baseField) {
    clrscr();
    cout << baseField;
    cntr++;
    Cell *list = NULL;
    list = death(list, baseField);
    born(baseField);
    kill(list, baseField);
}

int db(const Field &f) {
    int db = 0;
    for (int i = 0; i < f.getY(); ++i) {
        for (int j = 0; j < f.getX(); ++j) {
            if (f.getP()[i][j].getB()) {
                db++;
            }
        }
    }

}

Cell* death(Cell *list, const Field &arg) {
    int db = db(arg);
    if (list != NULL) {delete [] list;}
    list = new Cell[db];

}

void born(Field &baseField) {

}

void kill(Cell *list, Field &arg) {

}
