#include "Kolo.h"

Kolo::Kolo(int x) : Ksztalt(x){};

void Kolo::wypisz() const{
    std::cout << "Kolo o promieniu: " << wartosc << std::endl;
}

double Kolo::polePow() const{
    return 3.1415*wartosc*wartosc;
}