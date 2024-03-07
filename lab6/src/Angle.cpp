#include "Angle.h"

void Angle::convert(float *angle){
    while(*angle > 2*M_PI){
        *angle -= 2*M_PI;
    }
    while(*angle < 0){
        *angle += 2*M_PI;
    }
}

Angle::Angle(float angle) : _angle{angle}{
    std::cout << "... creating angle from radians." << std::endl;
    convert(&_angle);
}

Angle::Angle(float angle, float multiply) : _angle{angle*multiply}{
    std::cout << "... creating angle from degrees." << std::endl;
    convert(&_angle);
}

Angle Angle::fromRadians(float angle){
    return Angle(angle);
}

Angle Angle::fromDegrees(float angle){
    return Angle(angle, 2*M_PI/360);
}

void Angle::print() const{
    std::cout << "Angle [rad]: " << _angle << std:: endl;
}

Angle& Angle::add(Angle obj){
    _angle += obj._angle;
    convert(&_angle);

    return *this;
}

float Angle::toDeg() const{
    return _angle*360/2/M_PI;
}