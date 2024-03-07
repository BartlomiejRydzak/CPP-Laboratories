#pragma once
#include <iostream>

class Obszar{
    public:
        virtual void wyswietlInformacje() = 0;
        virtual ~Obszar() = default;
};

class Kontynent final : public Obszar{
    public:
        virtual void wyswietlInformacje() override final;
        virtual ~Kontynent() = default;
};

class Kraj final : public Obszar{
    public:
        virtual void wyswietlInformacje() override final;
        virtual ~Kraj() = default;
};