#include "RecipeIngredient.h"


RecipeIngredient::RecipeIngredient(uint32_t t,uint32_t a)
:type(t),amount(a){}

uint32_t RecipeIngredient::GetType()
{
    return type;
}

uint32_t RecipeIngredient::GetAmount()
{
    return amount;
}


