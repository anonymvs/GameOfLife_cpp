#include <iostream>
#include "header.h"
#include "field.h"

using namespace std;

int cntr = 0;

void startf(Field &baseField) {
    clrscr();
    cout << baseField;
    cntr++;
    Cell *alive = makeList(baseField);
    Cell *deathList = death(alive, baseField);
    born(baseField);
    kill(deathList, baseField);
}
Cell* makeList(Field &arg) {
    int n = db(arg);
    Cell *l = new Cell[n];
    for (int i = 0; i < arg.getY(); ++i) {
        for (int j = 0; j < arg.getX(); ++j) {
            l[n].setX(j);
            l[n].setY(i);
            l[n].setB(true);
            n++;
        }
    }
    return l;
}

int db(Field &f) {
    int db = 0;
    for (int i = 0; i < f.getY(); ++i) {
        for (int j = 0; j < f.getX(); ++j) {
            if (f.getP()[i][j].getB()) {
                db++;
            }
        }
    }
    return db;
}

Cell* death(Cell *l, Field &arg) {
    int n = db(arg);
    int Cellcntr;
    Cell* deathList;
    if (l == NULL)
        throw "Nincs elo sejt!";
    int meret = 0;
    for(int i = 0; i < n; ++i) {
        Cellcntr = 0;
        if(l[i].getX() == 0 || l[i].getY() == 0 || l[i].getX() == arg.getX() || l[i].getY() == arg.getY()) {
            l[i].setB(0);
        } else {
            for(int a = (l[i].getX()-1); a < l[i].getX()+1; ++a) {
                if(arg.getP()[l[i].getY()][l[i].getX()].getB() == 1)
                    Cellcntr++;
            }
            //itt már megvan hány szomszéd van
            if((Cellcntr - 1) < 2 || (Cellcntr - 1) < 3)
                meret++;
                deathList = listAdd(deathList, meret, l[i]);
        }
    }
    return deathList;
}

Cell* listAdd(Cell* lista, int meret, Cell sejt) {
    Cell* uj = new Cell[meret];
    for(int i = 0; i < meret - 1; i++) {
        uj[i] = lista[i];
    }
    uj[meret] = sejt;
    delete lista;
    return uj;
}

void born(Field &baseField) {

}

void kill(Cell *list, Field &arg) {

}
