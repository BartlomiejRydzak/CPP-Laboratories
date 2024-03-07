#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car{
    private:
        const char* _brand;
        int _year;
        int* _mileage;
    public:
        Car(const char* brand, int year, int mileage);
        Car(const Car& source);
        Car(Car&& source);

        Car& operator=(const Car& source);
        Car& operator=(Car&& source);

        void displayInfo() const;

        ~Car();
};
#endif