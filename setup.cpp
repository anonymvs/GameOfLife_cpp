#include <iostream>
#include <stdlib.h>
#include "header.h"
#include "field.h"

using namespace std;

//képernyő törlése
void clrscr() {
    system("cls");
}

// a 10-et az a-adik hatványára emeli
int hatvany(int a) {
    int ans = 1;
    for(int i = 0; i < a; i++) {
        ans *= 10;
    }
    return ans;
}

//intet stringé alakít
int intToStr(string str) {
    int ans = 0, i = 0;
    while (str[i] != '\0') {
        i++;
    }
    int meret = i;
    for(int j = 0; j < meret; j++) {
        ans += ((int)str[j] - '0') * hatvany(i - 1);
        i--;
    }
    return ans;
}

// jó e a bemenet
bool valid(string str) {
      int i = 0;
      bool validation = true;
      while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
          validation = false;
        }
        i++;
      }
      return validation;
}

//beovlasás: Beolvas egy stringet és visszaadja az értékét ha szám
int beolv() {
    bool loop = true;
    string x;
    while(getline(cin, x) && !valid(x)) {
        cout << "Invalid input" << endl;
    }
    return intToStr(x);
}

//kiírás: Kiírja a pályát.
void kiir(Field& f) {
    for (int i = 0; i < f.getY(); ++i) {
        for (int j = 0; j < f.getX(); ++j) {
            cout << f.getP()[i][j].getB();
        }
        cout << endl;
    }
}
//terület beállítása
Field areaf() {
    clrscr();
    cout << "Mekkora legyen a palya terulete?" << endl;
    cout << "Szelesseg: ";
    int x = beolv();
    cout << "Magassag: ";
    int y = beolv();
    Field baseField(x, y);
    kiir(baseField);
    menu_text();
}

void basef() {

}

void loadf() {

}
