#pragma once
#include <stdint.h>

class RecipeIngredient
{
protected:
    uint32_t type;
    uint32_t amount;
public:
    RecipeIngredient(uint32_t,uint32_t);
    uint32_t GetType();
    uint32_t GetAmount();
};
