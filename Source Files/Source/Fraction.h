#pragma once
#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include "Economy/Economy.h"
#include <SFML/Graphics.hpp>

class Fraction
{
    Economy eco;

    uint32_t FriendlyFractions;

    uint32_t MaxResidents;
    uint32_t Residents;

    sf::Color FractionColor;

    public:
        Fraction(uint32_t);
        virtual ~Fraction();
        static std::vector <Fraction*> * Fractions;
        Economy * GetEco();

        uint32_t GetMaxResidents();
        uint32_t GetResidents();
        void ChangeMaxResidents(int32_t);
        void ChangeResidents(int32_t);

        uint32_t GetFriendlyFractions();
        void SetFractionFriendly(uint32_t);
        void SetFractionUnfriendly(uint32_t);

        uint32_t CompareFractions(uint32_t);

        void SetFractionColor(sf::Color);
        sf::Color GetFractionColor();

    protected:
    private:
};
