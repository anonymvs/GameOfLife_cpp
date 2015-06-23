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
    void setX(int a);
    void setY(int a);
    void setB(bool x);
    int getX();
    int getY();
    bool getB();
    Cell& operator=(const Cell&);
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
    friend std::ostream& operator<<(std::ostream&, const Field f);
};

#endif // FIELD_H_INCLUDED
