#include <iostream>
#include <cstdlib>
#include "header.h"
#include "field.h"

using namespace std;

int endCntr = 0;

void startf(Field &baseField, int barrier) {
    cout << baseField;
    clrscr();
    endCntr++;
    Cell *deathList = makeList(baseField);
    death(deathList, baseField);
    born(baseField);
    kill(deathList, baseField);
    //cout << baseField;
    if(endCntr == barrier || db(baseField) == 0) {
        cout << baseField;
        return;
    } else {
        startf(baseField, barrier);
    }
}

Cell* makeList(Field &arg) {
    int n = db(arg);
    Cell *l = new Cell[n];
    int k = 0;
    for (int i = 0; i < arg.getY(); ++i) {
        for (int j = 0; j < arg.getX(); ++j) {
            if(arg.getP()[i][j].getB() == 1) {
                l[k].setX(j);
                l[k].setY(i);
                l[k].setB(true);
                k++;
            }
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

void death(Cell *l, Field &arg) {
    int n = db(arg);
    int Cellcntr;
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
            if((Cellcntr - 1) < 2 || (Cellcntr - 1) < 3) {
                meret++;
                l[i].setB(false);
            }
        }
    }
}

void born(Field &baseField) {
    for(int i = 0; i < baseField.getY(); ++i) {
        for(int j = 0; j < baseField.getX(); ++j) {
            if( i == 0 || j == 0 || i ==  (baseField.getY()-1) || j == (baseField.getX()-1) ) {
                baseField.getP()[i][j].setB(false);
            } else {
                int cntr = 0;
                for(int y = i - 1; y < i + 2; ++y){
                    for(int x = j - 1; x < j + 2; ++x) {
                        if(baseField.getP()[y][x].getB() == 1)
                            cntr++;
                    }
                }
                if(cntr == 3)
                    baseField.getP()[i][j].setB(true);
            }
        }
    }
}

void kill(Cell *l, Field &arg) {
    for(int i = 0; i < db(arg); ++i) {
        if(l[i].getB() == 0) {
            arg.getP()[l[i].getY()][l[i].getX()].setB(false);
        }
    }
}


