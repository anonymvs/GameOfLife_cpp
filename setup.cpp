#include <iostream>
#include <cstdlib>
#include <ctime>
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
Field& areaf() {
    clrscr();
    cout << "Mekkora legyen a palya terulete?" << endl;
    cout << "Szelesseg: ";
    int x = beolv();
    cout << "Magassag: ";
    int y = beolv();
    Field baseField(x, y);
    cout << baseField;
    return baseField;
}

//kezdő sejtek lerakása
void basef(Field &baseField) {
    clrscr();
    cout << "A jatekter:" << endl;
    cout << baseField << endl;
    cout << endl << "1 - Jatekter megadasas sejtenkent, koordinatak beirasaval." << endl;
    cout << "2 - Jatekter veletlenszeru megadasa" << endl;
    string x;
    bool loop = true;
    while( loop && getline(cin, x)) {
        if (x[0] > '2' || x[0] < '1' || x.length() != 1) {
            cout << "Invalid input: " << x << endl;
        } else {
            loop = false;
        }
    }
    if(x[0] == '1') {
        manual(baseField);
    } else {
        random(baseField);
    }
    clrscr();
    cout << "On altal valasztott jatekter:" << endl << baseField << endl;
}

void manual(Field &arg) {
    clrscr();
    cout << "A jatekter:" << endl;
    cout << arg << endl;
    cout << "Kerem adja meg a koordinatakat" << endl;
    string s;
    while(s[0] != 'N' || s[0] != 'n') {
        cout << "x koordinata: ";
        int x = beolv();
        cout << "y koordinata: ";
        int y = beolv();
        arg.getP()[y][x].setB(true);
        cout << "Tovabb? Y/N" << endl;
        bool loop = true;
        while(loop && getline(cin, s) ) {
            if (s[0] != 'Y' || s[0] != 'y' || s[0] != 'N' || s[0] != 'n') {
                loop = false;
            } else {
                cout << "Invalid input: " << s << endl;
            }
        }
    }
    clrscr();
    cout << arg << endl;
}

void random(Field &arg) {
    srand(time(0));
    rand();
    for(int i = 0; i < ((arg.getX() * arg.getY())/3); ++i)
        arg.getP()[rand() % arg.getY()][rand() % arg.getX()].setB(true);
}

void loadf() {

}
