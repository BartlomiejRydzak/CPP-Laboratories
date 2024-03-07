#include "GOperations.h"

float **temp = nullptr;
int size = 0;

float* InicjalizujCiagGeometryczny(int rozmiar, float start, float iloraz){
    size++;
    float **temp2 = new float* [size];
    for(int i=0; i<size-1; i++){
        temp2[i] = temp[i];
    }
    delete [] temp;
    temp = temp2;
    temp[size-1] = new float [rozmiar];
    temp[size-1][0] = start;
    for(int i=1; i<rozmiar; i++){
        temp[size-1][i] = temp[size-1][i-1]*iloraz;
    }
    return temp[size-1];
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
    for(int i=0; i<size; i++){
        delete temp[i];
    }
    // delete [] temp;
    size = 0;
}

float Wykonaj(float (*funkcja)(float*, int), float* ciag, int rozmiar){
    return funkcja(ciag, rozmiar);
}