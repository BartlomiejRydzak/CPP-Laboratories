#include "Car.h"

Car::Car(const char* brand, int year, int mileage) : _brand{brand}, _year{year}{
    std::cout << "Konstrukcja" << std::endl;

    _mileage = new int;
    *_mileage = mileage;
}

void Car::displayInfo() const{
    if(_year == 0&& !_mileage)
        std::cout << "Brand:  ?, Year:  ?" << ", Mileage: ?" << std::endl;
    else
        std::cout << "Brand: " << _brand << ", Year: " << _year << ", Mileage: " << *_mileage << " km" << std::endl;
}


Car::Car(const Car& source) : _brand{source._brand}, _year{source._year}{
    std::cout << "k kopia" << std::endl;

    int* temp = new int;
    *temp = *source._mileage;
    _mileage = temp;
}

Car& Car::operator=(const Car& source){
    std::cout << "O kopia" << std::endl;
    if(this == &source)
        return *this;
    return *this=Car(source);
}

Car::Car(Car&& source) : _brand{source._brand}, _year{source._year}, _mileage{source._mileage} {
    std::cout << "K move" << std::endl;

    source._mileage = nullptr;
    source._brand = nullptr;
    source._year = 0;
}

Car& Car::operator=(Car&& source){
    std::cout << "O move" << std::endl;
    if(this == &source)
        return *this;
    delete _mileage;
    _brand = source._brand;
    _year = source._year;
    _mileage = source._mileage;

    source._brand = nullptr;
    source._year = 0;
    source._mileage = nullptr;
    return *this;
}

Car::~Car(){
    std::cout << "Destrukcja" << std::endl;
    _brand = nullptr;
    _year = 0;
    delete _mileage;
    _mileage = nullptr;
}
