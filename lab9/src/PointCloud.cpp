#include "PointCloud.h"

Point3D::Point3D() : _cords{0, 0 ,0}{}

Point3D::Point3D(double n) : Point3D({n, n, n}){};

Point3D::Point3D(std::array<double,3> tab) : _cords{tab}{}

void Point3D::displayCoordinates() const{
    std::cout << "(";
    for(int i=0; i<_cords.size()-1; i++){
        std::cout << std::fixed << std::setprecision(2) << _cords[i] << ", ";
    }
    std::cout << std::fixed << std::setprecision(2) << _cords[_cords.size()-1] << ")" << std::endl;
}

Point3D Point3D::operator=(double n){
    return Point3D(n);
}

Point3D::operator double(){
    return sqrt(_cords[0]*_cords[0] + _cords[1]*_cords[1] + _cords[2]*_cords[2]);
}

std::string Point3D::to_string(Point3D source){
    return "(" + std::to_string(source._cords[0]) + "," + std::to_string(source._cords[1]) + "," + std::to_string(source._cords[2]) + ")";
}


Point3D::operator std::string() const{
    return "(" + std::to_string(_cords[0]) + "," + std::to_string(_cords[1]) + "," + std::to_string(_cords[2]) + ")";
}

void VPointCloud::addPoint(){
    _VPoint.push_back(new Point3D(0));
}

void VPointCloud::addPoint(Point3D* point){
    _VPoint.push_back(point);
}

void VPointCloud::displayPoints() const{
    for(int i=0; i<_VPoint.size(); i++){
        (*_VPoint[i]).displayCoordinates();
    }
}

void VPointCloud::add(VPointCloud& point_cloud){
    if(this != &point_cloud){
        int size = point_cloud._VPoint.size();
        for(int i=0; i<size; i++){
            _VPoint.push_back(new Point3D(*point_cloud._VPoint[i]));
        }
    }
}

VPointCloud::VPointCloud(){}

VPointCloud::VPointCloud(VPointCloud&& source) : _VPoint{source._VPoint}{
    source._VPoint.clear();
}


VPointCloud::~VPointCloud(){
    for(int i=0; i<_VPoint.size(); i++){
        delete _VPoint[i];
    }
}