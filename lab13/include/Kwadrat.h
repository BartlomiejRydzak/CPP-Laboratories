#pragma once
#include <iostream>

class Ksztalt{
    protected:
        int wartosc;
    public:
        Ksztalt(int x);
        virtual void wypisz() const;
        virtual double polePow() const;
};

class Kwadrat : public Ksztalt{
    public:
        Kwadrat(int x);
        void wypisz() const;
        virtual double polePow() const;
};

void wypisz(const Ksztalt& source);