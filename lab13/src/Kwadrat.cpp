#include "Kwadrat.h"

Ksztalt::Ksztalt(int x) : wartosc{x}{};

void Ksztalt::wypisz() const{
    std::cout << "Ksztalt" << std::endl;
}

double Ksztalt::polePow() const{
    return 0;
}


Kwadrat::Kwadrat(int x) : Ksztalt(x){};

void Kwadrat::wypisz() const{
    std::cout << "Kwadrat o boku: " << wartosc << std::endl;
}

void wypisz(const Ksztalt& source){
    source.wypisz();
};

double Kwadrat::polePow() const{
    return wartosc*wartosc;
}