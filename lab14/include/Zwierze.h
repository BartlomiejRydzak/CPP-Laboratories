#pragma once
#include <iostream>
#include "Obszar.h"

class Zwierze{
    public:
        void virtual wydajDzwiek() = 0;
        virtual void wyswietlInformacje() = 0;
        virtual ~Zwierze() = default;
};

class Ptak final : public Zwierze{
    private:
        Kraj _miejsce;
    public:
        Ptak(Kraj* source);
        void virtual wydajDzwiek() override;
        virtual void wyswietlInformacje() override final;
        virtual ~Ptak() = default;
};

class Ssak final : public Zwierze{
    public:
        void virtual wydajDzwiek() override;
        virtual void wyswietlInformacje() override final;
        virtual ~Ssak() = default;
};