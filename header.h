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

///OSZTALYOK
//SEJT
class Cell {
private:
    int x, y;
    bool state;
public:
    Cell(int x = 0, int y = 0, bool b = false);
    ~Cell();
    int getX() const;
    int getY() const;
    bool getBool() const;
    void setX(int x);
    void setY(int y);
    void setBool(bool b);
};

//PALYA
class Field {
private:
    int a, b;
    Cell **field;
public:
    Field(int a = 0, int b = 0);
    ~Field();
    int getA() const;
    int getB() const;
    Cell** getPointerField() const;
    //Field operator=(const Field& a) const;
};

void fieldCout(Field &a);

//ÉLÕ SEJTEK LISTÁJA
class CellList {
private:
    int n;
    Cell *pointer;
public:
    CellList(int n = 0);
    int getN() const;
    Cell* getPointerList() const;
    void setN(int n);
};

#endif // HEADER_H_INCLUDED
