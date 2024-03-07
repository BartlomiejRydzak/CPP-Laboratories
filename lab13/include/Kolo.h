#pragma once
#include "Kwadrat.h"

class Kolo : public Ksztalt{
    public:
        Kolo(int x);
        void wypisz() const;
        virtual double polePow() const;
};