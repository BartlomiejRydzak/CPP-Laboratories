#include "Line.h"

Line::Line() : _a{1}, _b{1}{};
Line::Line(double x) : _a{x}, _b{x}{};


double Line::operator () (double x){
    return _a*x + _b;
}
 
double Line::X0(){
    return -_b/_a;
}

void LPrint::operator () (Line source){
	std::cout << "y = " << source._a << "* x + " << source._b << "\tx0 = "<< source.X0() << std::endl;
}

void LPrint::operator () (LArray& source){
    for(int i=0; i<source._size; i++){
        std::cout << "[" << i << "] ";
        (*this)(source._tab[i]);
    }
}


LArray::LArray(int size) : _size{size}, _end{0} {
    _tab = new Line [size];
}

void LArray::Add(Line obj){
    _tab[_end] = obj;
    _end++;
}
LArray& LArray::Add(int n){
    this->Add(Line(n));
    return *this;
}

LArray::~LArray(){
    delete [] _tab;
}
