#include "Zwierze.h"

Ptak::Ptak(Kraj* source) : _miejsce{*source}{};


void Ptak::wydajDzwiek(){
    std::cout << "Ptak wydaje dzwiek!" << std::endl;
}

void Ptak::wyswietlInformacje(){
    _miejsce.wyswietlInformacje();
}

void Ssak::wydajDzwiek(){
    std::cout << "Ssak wydaje dzwiek!" << std::endl;
}
void Ssak::wyswietlInformacje(){};