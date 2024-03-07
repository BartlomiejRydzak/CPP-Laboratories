#ifndef LINE_H
#define LINE_H

#include <iostream>

class LPrint;
class LArray;

class Line{
    friend LPrint;
    private:
        double _a;
        double _b;
    public:
        Line();
        Line(double x);
        double operator () (double x);
        double X0();
};

class LPrint{
    public:
        void operator () (Line source);
        void operator () (LArray& source);

};

class LArray{
    friend LPrint;
    private:
        Line* _tab;
        int _size;
        int _end;
    public:
        LArray(int size);
        void Add(Line obj);
        LArray& Add(int n);
        ~LArray();
};

#endif