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
//setup
void areaf();
void basef();
void loadf();
//algorithm
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
    int getA() const;
    int getB() const;
    Cell** getPointerField() const;
};

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
