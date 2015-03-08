#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;

void clrscr() {
    system("cls");
}

int hatvany(int a) {
    int ans = 1;
    for(int i = 0; i < a; i++) {
        ans *= 10;
    }
    return ans;
}

int intToStr(string str) {
    int ans = 0, i = 0;
    while (str[i] != '\0') {
        i++;
    }
    int meret = i;
    for(int j = 0; j < meret; j++) {
        ans += ((int)str[j] - '0') * hatvany(i-1);
        i--;
    }
    return ans;
}

int valid(string str) {
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

Field beolv() {
    cout << "Mekkora legyen a palya terulete?" << endl;
    string str;
    int a, b;
    bool setted = false;
    cout << "Szelesseg: ";
    while(getline(cin, str)) {
        if(!valid(str)) {
            cout << "Invalid input: " << str << endl;
        } else {
            if (!setted) {
                a = intToStr(str);
                setted = true;
            } else {
                b = intToStr(str);
                Field ans(a, b);
                return ans;
            }
        }
        if (!setted) {
            cout << "Szelesseg: ";
        } else {
            cout << "Magassag: ";
        }
    }
}

//terület beállítása
void areaf() {
    clrscr();
    Field def;
    def = beolv();
    for(int i = 0; i < def.getB(); i++) {
        for(int j = 0; j < def.getA(); j++) {
            if (def.getPointerField()[i][j].getBool()) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
    menu_text();
}

void basef() {

}

void loadf() {

}
