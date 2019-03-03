#include "Recipe.h"

Recipe * CreateRecipes()
{
    Recipe * r = new Recipe[2];

    RecipeIngredient ri1(3,1);
    RecipeProduct rp1(2,1);
    r->RecIng.push_back(ri1);
    r->RecPro.push_back(rp1);
    r->WorkDemand = 300;

    RecipeIngredient ri2(4,1);
    RecipeProduct rp2(1,1);
    (r+1)->RecIng.push_back(ri2);
    (r+1)->RecPro.push_back(rp2);
    (r+1)->WorkDemand = 500;
    return r;
}

Recipe * Recipe::Recipes = CreateRecipes();

uint32_t Recipe::RecipesAmount(){return 2;}
