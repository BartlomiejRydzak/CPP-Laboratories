#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>
#include <cmath>

class Angle{
    private:
        float _angle;
        void convert(float *angle);
    public:
        Angle(float angle);
        Angle(float angle, float multiply);
        static Angle fromRadians(float angle);
        static Angle fromDegrees(float angle);
        void print() const;

        Angle& add(Angle obj);

        float toDeg() const;
};

#endif