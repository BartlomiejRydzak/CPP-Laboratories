#ifndef MAPPOINT_H
#define MAPPOINT_H

#include <iostream>
#include <cmath>

class MapPoint{
    private:
        double _longitude;
        double _latitude;
    public:
        MapPoint();
        MapPoint(double longitude, double latitude);

        void print() const;
        void set_coordinates(double longitude, double latitude);
        double distanceVal(MapPoint place) const;
        double distanceVal(MapPoint* place) const;
};


#endif