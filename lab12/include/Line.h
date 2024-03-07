#pragma once

#include <iostream>

class LineSmartPtr;

class Line{
    // friend LineSmartPtr;

    friend std::ostream& operator << (std::ostream &os, const Line &obj);

    private:
        double _a;
        double _b;
    public:
        Line();
        Line(double a, double b);
        double X0() const;
        ~Line();
};

class LineSmartPtr{
    private:
        Line* _ptr;
        static int _count;

    public:
        LineSmartPtr();
        LineSmartPtr(Line* obj);
        Line operator*();
        ~LineSmartPtr();

        void operator = (LineSmartPtr obj); 
};