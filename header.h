#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "field.h"

/// MENU
// Menü szerkezete
enum main_menu {
    full = '0',
    area = '1',
    base = '2',
    load = '3',
    start = '4',
    quit = '5'
};

//MENÜ SZERKEZETE
//mainMenu
void mainMenu();
//setup.cpp
void clrscr();
int intToStr(std::string str);
//terület
Field& areaf();
void menu_text(char c);
//kezdőpontok
void basef(Field&);
void manual(Field&);
void random(Field&);
//betöltés
void loadf();
//algorithm.cpp
void startf(Field&);
void quitf();

///GLOBÁLIS FÜGGVÉNYEK
int beolv();
void kiir(const Field& f);
int db(const Field &f);

#endif // HEADER_H_INCLUDED
