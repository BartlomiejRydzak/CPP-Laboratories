#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>

class Point3D{
    private:
        std::array<double, 3> _cords;
    public:
        Point3D();
        Point3D(double n);
        Point3D(std::array<double,3> tab);
        void displayCoordinates() const;
        Point3D operator=(double n);
        operator double();
        operator std::string() const;
        static std::string to_string(Point3D source);
};

class VPointCloud{
    private:
        std::vector<Point3D*> _VPoint;
    public:
        VPointCloud();
        void addPoint();
        void addPoint(Point3D* point);
        void displayPoints() const;
        void add(VPointCloud& point_cloud);
        VPointCloud(VPointCloud&& source);
        ~VPointCloud();
};

#endif