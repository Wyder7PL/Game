#pragma once

#include "../Building.h"
#include "../../Textures/Textures.h"
#include "../../Items/ResourceItem.h"
#include "../../Items/Recipes/Recipe.h"
#include "../../Markable/Slot.h"
#include "../../Unit.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "../../GUI/GUIObjects/MultiButtons/OIMBSelectOne.h"

class Workshop:public Building
{
    ResourceItem * res;
    std::list <Slot> worker;
    std::list <ResourceDemand> ResDem;
    uint32_t work;
    uint32_t workdemand;
    uint32_t_pointer * BarWork;
    uint32_t_pointer * BarWorkDemand;

    uint32_t RecipeNumber;
    uint32_t GatcheredResources;

    std::list <ResourceItem*> Ingredients;
    std::list <ResourceItem*> Trash;

    uint32_t GUIRecipe;
    uint32_t_pointer * GUIRecipeButtonPoint;

public:
    Workshop(Position,uint32_t);
    virtual ~Workshop();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
    virtual void Selected();

    std::list <void*> RDV;
    list_pointer * SlotPointer;
private:
    void Kick(Unit*);
    void CreateDemand();
    void PackForProduction();
    void ChangeRecipe(uint32_t);
};
