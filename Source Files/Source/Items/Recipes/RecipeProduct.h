#pragma once
#include "RecipeIngredient.h"

class RecipeProduct:public RecipeIngredient
{
    uint32_t chance;
public:
    RecipeProduct(uint32_t,uint32_t,uint32_t=1);
    uint32_t GetChance();
};
