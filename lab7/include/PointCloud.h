#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <vector>

class APointCloud;
class VPointCloud;

class Point3D{
    friend class APointCloud;
    friend class VPointCloud;
    private:
        std::array<double, 3> _cords;
    public:
        Point3D();
        Point3D(std::array<double,3> tab);
        void displayCoordinates() const;
};

class APointCloud{
    friend class VPointCloud;
    private:
        Point3D* _APoint = nullptr;
        int _size = 0;
    public:
        void addPoint(Point3D point);
        void displayPoints() const;
        Point3D geoCentre();
        void add(APointCloud& point_cloud);
        ~APointCloud();
};

class VPointCloud{
    private:
        std::vector<Point3D> _VPoint;
    public:
        void addPoint(Point3D point);
        void add(APointCloud& point_cloud);
        int count();
        Point3D geoCentre();
};

#endif