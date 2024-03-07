#include "Line.h"

int LineSmartPtr::_count = 0;

Line::Line(double a, double b) : _a{a}, _b{b}{}

std::ostream& operator << (std::ostream &os, const Line &obj){
    os <<  "y = " << obj._a << "* x + " << obj._b << "\tx0 = "<< obj.X0();
    return os;
}

double Line::X0() const{
    return -_b/_a;
}

Line::~Line(){}

LineSmartPtr::LineSmartPtr(): _ptr{nullptr} {}

LineSmartPtr::LineSmartPtr(Line* obj) : _ptr{obj}{
    _count++;
}

Line LineSmartPtr::operator*(){
    return *_ptr;
}

LineSmartPtr::~LineSmartPtr(){
    if(_count == 0)
        delete _ptr;
    _count--;
}

void LineSmartPtr::operator = (LineSmartPtr obj){
    delete this->_ptr;
    this->_ptr = obj._ptr;
}
