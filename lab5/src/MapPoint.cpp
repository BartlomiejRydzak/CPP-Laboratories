#include "MapPoint.h"

MapPoint::MapPoint(double longitude, double latitude){
    _longitude = longitude;
    _latitude = latitude;
}

MapPoint::MapPoint(){
    _longitude = 0;
    _latitude = 0;
}

void MapPoint::print() const{
    std::cout << "Point: (" << _longitude << ", " << _latitude << ")" << std::endl;
}

void MapPoint::set_coordinates(double longitude, double latitude){
    _latitude = latitude;
    _longitude = longitude;
}

double MapPoint::distanceVal(MapPoint place) const{
    double x = _latitude - place._latitude;
    double y = _longitude - place._longitude;
    return sqrt(abs(x*x - y*y));
}
double MapPoint::distanceVal(MapPoint* place) const{
    double x = _latitude - (*place)._latitude;
    double y = _longitude - (*place)._longitude;
    return sqrt(abs(x*x - y*y));
}