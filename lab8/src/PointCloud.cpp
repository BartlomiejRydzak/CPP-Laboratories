#include "PointCloud.h"

Point3D::Point3D() : _cords{0, 0 ,0}{}

Point3D::Point3D(double n) : _cords{n, n, n}{}

Point3D::Point3D(std::array<double,3> tab) : _cords{tab}{}

int Point3D::DISPLAY_PRESITION = 1;

void Point3D::displayCoordinates() const{
    std::cout << "(";
    for(int i=0; i<_cords.size()-1; i++){
        std::cout << std::fixed << std::setprecision(DISPLAY_PRESITION) << _cords[i] << ", ";
    }
    std::cout << std::fixed << std::setprecision(DISPLAY_PRESITION) << _cords[_cords.size()-1] << ")" << std::endl;
}

void VPointCloud::addPoint(Point3D* point){
    _VPoint.push_back(point);
}

void VPointCloud::addPoint(std::array<double, 3> point){
    _VPoint.push_back(new Point3D(point));
}

void VPointCloud::displayPoints() const{
    for(int i=0; i<_VPoint.size(); i++){
        (*_VPoint[i]).displayCoordinates();
    }
}

Point3D* VPointCloud::getCopyPoint(int indx){

    return new Point3D(*_VPoint[indx]);
}

void VPointCloud::add(VPointCloud& point_cloud){
    int size = point_cloud._VPoint.size();
    for(int i=0; i<size; i++){
        _VPoint.push_back(new Point3D(*point_cloud._VPoint[i]));
    }
}

VPointCloud::VPointCloud(){}

VPointCloud::VPointCloud(VPointCloud&& source) : _VPoint{source._VPoint}{
    source._VPoint.clear();
}


VPointCloud::~VPointCloud(){
    std::cout << "Destrukcja" << std::endl;
    for(int i=0; i<_VPoint.size(); i++){
        delete _VPoint[i];
    }
}

// VPointCloud(const VPointCloud& source){

// }
