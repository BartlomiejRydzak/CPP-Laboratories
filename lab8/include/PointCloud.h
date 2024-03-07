#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <vector>
#include <iomanip>

class Point3D{
    private:
        std::array<double, 3> _cords;
    public:
        static int DISPLAY_PRESITION;
        Point3D();
        Point3D(double n);
        Point3D(std::array<double,3> tab);
        void displayCoordinates() const;
};

class VPointCloud{
    private:
        std::vector<Point3D*> _VPoint;
    public:
        VPointCloud();
        void addPoint(Point3D* point);
        void addPoint(std::array<double, 3> point);

        void displayPoints() const;

        Point3D* getCopyPoint(int indx);
        void add(VPointCloud& point_cloud);
        // VPointCloud(const VPointCloud& source);
        VPointCloud(VPointCloud&& source);
        ~VPointCloud();
        // void add(APointCloud& point_cloud);
        // int count();
        // Point3D geoCentre();
};

#endif