#ifndef GOPERATIONS_H
#define GOPERATIONS_H

#include <iostream>
using namespace std;

float* InicjalizujCiagGeometryczny(int rozmiar, float iloraz);

void Wypisz(float* ciag, int rozmiar);

float Suma(float* ciag, int rozmiar);

float Srednia(float* ciag, int rozmiar);

void UsunCiagi();

float Wykonaj(float (*funkcja)(float*, int), float* ciag, int rozmiar);

#endif