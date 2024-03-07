#include "GOperations.h"

float *temp;

float* InicjalizujCiagGeometryczny(int rozmiar, float iloraz){
    delete temp;
    temp = new float [rozmiar];
    temp[0] = 1;
    for(int i=1; i<rozmiar; i++){
        temp[i] = temp[i-1]*iloraz;
    }
    return temp;
}

void Wypisz(float* ciag, int rozmiar){
    std::cout << "(";
    for(int i=0; i<rozmiar-1; i++){
        std::cout << ciag[i] << ", ";
    }
    std::cout << ciag[rozmiar-1] << ")" << std::endl;
}

float Suma(float* ciag, int rozmiar){
    float suma = 0;
    for(int i=0;i<rozmiar; i++){
        suma += ciag[i];
    }
    return suma;
}

float Srednia(float* ciag, int rozmiar){
    float suma = Suma(ciag, rozmiar);
    return suma/rozmiar;
}

void UsunCiagi(){
    delete temp;
}

float Wykonaj(float (*funkcja)(float*, int), float* ciag, int rozmiar){
    return funkcja(ciag, rozmiar);
}