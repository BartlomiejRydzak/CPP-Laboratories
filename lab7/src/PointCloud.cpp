#include "PointCloud.h"

Point3D::Point3D(){}

Point3D::Point3D(std::array<double,3> tab) : _cords{tab}{}

void Point3D::displayCoordinates() const{
    std::cout << "(";
    for(int i=0; i<_cords.size()-1; i++){
        std::cout << _cords[i] << ", ";
    }
    std::cout << _cords[_cords.size()-1] << ")";
}

void APointCloud::addPoint(Point3D point){
    if(_APoint == nullptr){
        _size = 1;
        _APoint = new Point3D [_size];
        _APoint[0] = point;
        return;
    }
    _size++;

    Point3D* temp = new Point3D [_size];
    for(int i=0; i<_size-1; i++){
        temp[i] = _APoint[i];
    }
    delete [] _APoint;
    _APoint = temp;

    _APoint[_size-1] = point;
}

void APointCloud::add(APointCloud& point_cloud){
    int size = point_cloud._size;
    for(int i=0; i<size; i++){
        this->addPoint(point_cloud._APoint[i]);
    }
}

void APointCloud::displayPoints() const{
    std::cout << "Chmura punktów [APC]:" << std::endl;
    for(int i=0; i<_size; i++){
        _APoint[i].displayCoordinates();
        std::cout << std::endl;
    }
}

Point3D APointCloud::geoCentre(){
    double x = 0;
    double y = 0;
    double z = 0;

    for(int i=0; i<_size; i++){
        x += _APoint[i]._cords[0];
        y += _APoint[i]._cords[1];
        z += _APoint[i]._cords[2];
    }

    return Point3D({x/_size, y/_size, z/_size});
}

APointCloud::~APointCloud(){
    delete [] _APoint;
}

void VPointCloud::addPoint(Point3D point){
    _VPoint.push_back(point);
}

void VPointCloud::add(APointCloud& point_cloud){
    for(int i=0; i<point_cloud._size; i++){
        _VPoint.push_back(point_cloud._APoint[i]);
    }
}

int VPointCloud::count(){
    return _VPoint.size();
}

Point3D VPointCloud::geoCentre(){
    double x = 0;
    double y = 0;
    double z = 0;
    int size = _VPoint.size();

    for(int i=0; i<size; i++){
        x += _VPoint[i]._cords[0];
        y += _VPoint[i]._cords[1];
        z += _VPoint[i]._cords[2];
    }

    return Point3D({x/size, y/size, z/size});
}
