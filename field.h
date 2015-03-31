#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

class Cell {
    int x, y;
    bool b;
public:
    Cell() : x(0), y(0), b(false) {};
    Cell(int x, int y, bool b);
    Cell(const Cell&);
    ~Cell();
    bool getB();
};

class Field {
    int x, y;
    Cell **p;
public:
    Field() : x(0), y(0), p(NULL) {};
    Field(int x, int y);
    Field(const Field&);
    ~Field();
    int getX();
    Cell** getP();
    int getY();
    Field& operator=(const Field&);
};

#endif // FIELD_H_INCLUDED
