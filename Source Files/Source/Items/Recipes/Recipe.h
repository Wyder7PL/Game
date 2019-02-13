#pragma once
#include "RecipeProduct.h"
#include <list>

class Recipe
{
public:
    std::list <RecipeIngredient> RecIng;
    std::list <RecipeProduct> RecPro;
    static Recipe * Recipes;
    static uint32_t RecipesAmount();
    uint32_t WorkDemand;
};

Recipe * CreateRecipes();
