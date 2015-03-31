#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/// MENU
// Menü szerkezete
enum main_menu {
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
void areaf();
void menu_text();
//kezdőpontok
void basef();
//betöltés
void loadf();
//algorithm.cpp
void startf();
void quitf();

///GLOBÁLIS FÜGGVÉNYEK
int beolv();

#endif // HEADER_H_INCLUDED
