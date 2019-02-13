#pragma once
#include <stdint.h>
#include "../projectile/projectile.h"
#include "../Textures/Textures.h"

class Item
{
    uint32_t ItemType;
    float Weight;
    public:
        Item(uint32_t);
        virtual ~Item();
        uint32_t GetItemType();
        float GetWeight();
        void SetFractions(uint32_t);
        virtual float GetSeenRange();
        sf::Sprite & GetImage();
    protected:
        void SetItemType(uint32_t);
        void SetWeight(float);
        uint32_t fractions;
        sf::Sprite image;
    private:
};

/// ///////////////////////// ///
/// Item Type:                ///
/// 0 - None                  ///
/// 1 - Combat                ///
/// 2 - Tool                  ///
/// 3 - Resource              ///
/// 4 - Armor                 ///
/// ///////////////////////// ///
