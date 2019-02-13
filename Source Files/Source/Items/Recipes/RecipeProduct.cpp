#include "RecipeProduct.h"

RecipeProduct::RecipeProduct(uint32_t t,uint32_t a,uint32_t ch)
:RecipeIngredient(t,a),chance(ch){}

uint32_t RecipeProduct::GetChance()
{
    return chance;
}
