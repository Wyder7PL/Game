#include "Workshop.h"

Workshop::Workshop(Position pos,uint32_t f)
:Building(pos,f),res(NULL),work(0),workdemand(1),RecipeNumber(1),GatcheredResources(0)
{
    mark.setTexture(Textures::textures->Tworkshop);
    SlotPointer = new list_pointer(&RDV);
    Slot s;
    worker.push_back(s);
    RDV.push_back(&worker);
    CreateDemand();
    RDV.push_back(&ResDem);
    GUIRecipe = RecipeNumber;
    GUIRecipeButtonPoint  = new uint32_t_pointer(&GUIRecipe);
    BarWork = new uint32_t_pointer(&work);
    BarWorkDemand = new uint32_t_pointer(&workdemand);
}
Workshop::~Workshop()
{
    SlotPointer->TurnOff();
    if((*worker.begin()).Occupant != NULL)
        delete (*worker.begin()).Occupant;
    if(res!=NULL)
        delete res;
    if(GUIRecipeButtonPoint!=NULL)
    {
        GUIRecipeButtonPoint->TurnOff();
        GUIRecipeButtonPoint = NULL;
    }
}
void Workshop::Step()
{
    Building::Step();
    if(GUIRecipe != RecipeNumber)
        ChangeRecipe(GUIRecipe);
    if((*worker.begin()).Occupant != NULL)
    {
        bool changed = false;
        if((*worker.begin()).FirstHour)
        {
            (*worker.begin()).FirstHour = false;
            Unit * u = dynamic_cast<Unit*>((*worker.begin()).Occupant);
            for(std::list <ResourceDemand>::iterator ite = ResDem.begin();ite!=ResDem.end();)
            {
                res = u->TakeItem((*ite).GetID(),1);
                if(res != NULL)
                {
                    changed = true;
                    Ingredients.push_back(res);
                    (*ite).Give(1);
                    if((*ite).GetDemand() == 0)
                        ite = ResDem.erase(ite);
                    else
                        ite++;
                }
                else
                    ite++;
            }
        }
        if(Trash.size()>0)
        {
            Unit * u = dynamic_cast<Unit*>((*worker.begin()).Occupant);
            bool kick = false;
            for(std::list <ResourceItem*>::iterator ite = Trash.begin();ite != Trash.end();)
            {
                if(u->GiveItem((*ite)))
                {
                    kick = true;
                    ite = Trash.erase(ite);
                }
                else
                    ite++;
            }
            if(kick)
                Kick(u);
        }
        if(changed)
            PackForProduction();
        if(GatcheredResources>0)
        {
            work++;
            Recipe * r = (Recipe::Recipes+RecipeNumber-1);
            workdemand = r->WorkDemand;
            if(work>workdemand)
            {
                work-=r->WorkDemand;
                GatcheredResources--;
                for(std::list <RecipeProduct>::iterator ite = r->RecPro.begin();ite != r->RecPro.end();ite++)
                {
                    if(rand()%(*ite).GetChance()==0)
                    {
                        ResourceItem * ri = new ResourceItem(fraction,(*ite).GetType());
                        Trash.push_back(ri);
                    }
                }
                CreateDemand();
                return;
            }
        }
        else
        {
            Unit * u = dynamic_cast<Unit*>((*worker.begin()).Occupant);
            if(u!=NULL)
                Kick(u);
        }
    }
}

void Workshop::Kick(Unit*u)
{
    u->Activate();
    AddObject add;
    add.Add(u);
    (*worker.begin()).Occupant = NULL;
    (*worker.begin()).reserved = false;
    (*worker.begin()).FirstHour = true;
}
void Workshop::CreateDemand()
{
    Recipe * r = (Recipe::Recipes+RecipeNumber-1);
    for(std::list <RecipeIngredient>::iterator ite = r->RecIng.begin();ite != r->RecIng.end();ite++)
    {
        ResourceDemand rd((*ite).GetType(),(*ite).GetAmount());
        ResDem.push_back(rd);
    }
}
void Workshop::PackForProduction()
{
    Recipe * r = (Recipe::Recipes+RecipeNumber-1);
    uint32_t ITAN = 0;///IngredientsTypeAmountNeeded
    for(std::list <RecipeIngredient>::iterator ite = r->RecIng.begin();ite != r->RecIng.end();ite++)
    {
        uint32_t Amount = 0;
        uint32_t type = (*ite).GetType();
        for(std::list <ResourceItem*>::iterator ite2 = Ingredients.begin(); ite2!=Ingredients.end();ite2++)
        {
            if((*ite2)->GetType()==type)
            {
                Amount++;
                if(Amount == (*ite).GetAmount())
                {
                    ITAN++;
                    break;
                }
            }
        }
    }
    if(ITAN == r->RecIng.size())
    {
        GatcheredResources++;
        for(std::list <RecipeIngredient>::iterator ite = r->RecIng.begin();ite != r->RecIng.end();ite++)
        {
            uint32_t Amount = (*ite).GetAmount();
            uint32_t type = (*ite).GetType();
            for(std::list <ResourceItem*>::iterator ite2 = Ingredients.begin(); ite2!=Ingredients.end();)
            {
                if((*ite2)->GetType()==type)
                {
                    Amount--;
                    ite2 = Ingredients.erase(ite2);
                    if(Amount == 0)
                        break;
                }
                else
                    ite2++;
            }
        }
    }
}
void Workshop::ChangeRecipe(uint32_t rec)
{
    if(rec > Recipe::RecipesAmount())
        return;
    ResDem.clear();
    Recipe * r = (Recipe::Recipes+RecipeNumber-1);
    if(GatcheredResources>0)
    {
        for(std::list <RecipeIngredient>::iterator ite = r->RecIng.begin();ite != r->RecIng.end();ite++)
        {
            for(uint32_t i = 0; i < GatcheredResources*(*ite).GetAmount();i++)
            {
                ResourceItem * ri = new ResourceItem(fraction,(*ite).GetType());
                Trash.push_back(ri);
            }
        }
        GatcheredResources = 0;
    }
    work = 0;
    RecipeNumber=rec;
    CreateDemand();
}

void Workshop::CreateInfo(std::list<Info>& Objects)
{
    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 7;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    inf.lpointer = SlotPointer;
    Objects.push_back(inf);
}
void Workshop::Selected()
{
    MarkBuilding::Selected();
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tworkshop,
                               Position(100,50),sf::Color(30,30,30),"Wooden Workshop");
    Markable::MarkedObjectInfo.Information.push_back(obj);

    SetHPonGUI();

    //SafePointer::Pointers.push_back(GUIRecipeButtonPoint);
    OIMBSelectOne * multi = new OIMBSelectOne(2,Position(200,20),Position(20,20),GUIRecipeButtonPoint);
    Markable::MarkedObjectInfo.Information.push_back(multi);

    OIBar * bar = new OIBar(BarWork,BarWorkDemand,sf::Color(30,30,30),150);
    Markable::MarkedObjectInfo.Information.push_back(bar);
}
