#include "CustomBuildings.h"

GOIECreateButton::GOIECreateButton(Position pos,Position dim,GOIEText & t,uint32_t fraction)
:Clickable2(pos),tex(t),PlayerFraction(fraction)
{
    physicshape = new NRR(dim);
    mask = 0;
}
void GOIECreateButton::Istep(){Step();}
void GOIECreateButton::Idraw(sf::RenderTarget & target,sf::RenderStates states){draw(target,states);}
void GOIECreateButton::Step()
{
    Clickable2::Step();
    Position pos = GetPosition();
    tex.SetPosition(pos.GetX(),pos.GetY());
    tex.Step();
}
void GOIECreateButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable2::draw(target,states);
    tex.draw(target,states);
}

void GOIECreateButton::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIECreateButton::GetHeight()
{
    return tex.GetHeight();
}

void GOIECreateButton::SetToDestroy()
{
    tex.SetToDestroy();
    Destroy();
}

PreBuilding * GOIECreateButton::CreatePre(Position pos,Object * obj)
{
    return new PreBuilding(position,obj);
}
void GOIECreateButton::Selected()
{
    if(Markable::GetSelectedType() != 4)
    {
        Markable::SetSelectedType(4);
        BuildingConstruction * b = CreateBuildingConstruction();
        AddObject a;
        a.Add(CreatePre(position,b));
    }
}
BuildingConstruction* GOIECreateButton::CreateBuildingConstruction()
{
    BuildingConstruction * b = new BuildingConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    b->TESTCreateDemand(1,10);
    return b;
}

OICreateButton::OICreateButton(OIText t,uint32_t pfr)
:tex(t),PlayerFraction(pfr){}
OIText OICreateButton::GetTex()
{
    return tex;
}
OICreateButton::~OICreateButton(){}
GUIObjectInfoElement * OICreateButton::Create(Position pos)
{
    return new GOIECreateButton(pos,tex.GetWah(),*static_cast<GOIEText*>(tex.Create(pos)),PlayerFraction);
}
uint32_t OICreateButton::GetPlayerFraction(){return PlayerFraction;}




Magazine::Magazine(Position pos,uint32_t f)
:Building(pos,f)
{
    mark.setTexture(Textures::textures->Tmagazine);
}

uint32_t Magazine::GiveResources(uint32_t t,uint32_t a)
{
    if(Fraction::Fractions == NULL || Fraction::Fractions->size() <= fraction)
        return a;
    (*Fraction::Fractions)[fraction]->GetEco()->GEE(t)->SetAmount((*Fraction::Fractions)[fraction]->GetEco()->GEE(t)->GetAmount()+a);
    return 0;
}

void Magazine::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 3;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}

MagazineConstruction::MagazineConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void MagazineConstruction::Create()
{
    AddObject add;
    Magazine * m = new Magazine(position,fraction);
    add.Add(m);
}


MagazineBlueprintButton::MagazineBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(200,20,20));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void MagazineBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void MagazineBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void MagazineBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tmagazine,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Magazine");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBMagazine * ttt = new OICBMagazine(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
OICBMagazine::OICBMagazine(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBMagazine::Create(Position pos)
{
    GOIECBMagazine * g = new GOIECBMagazine(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
    return g;
}
GOIECBMagazine::GOIECBMagazine(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBMagazine::~GOIECBMagazine(){}
BuildingConstruction* GOIECBMagazine::CreateBuildingConstruction()
{
    MagazineConstruction * m = new MagazineConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    m->TESTCreateDemand(1,5);
    return m;
}




House::House(Position pos,uint32_t f)
:Building(pos,f)
{
    mark.setTexture(Textures::textures->Thouse);
    (*Fraction::Fractions)[f]->ChangeMaxResidents(1);
}
House::~House(){(*Fraction::Fractions)[GetFraction()]->ChangeMaxResidents(-1);}

void House::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 4;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}

HouseConstruction::HouseConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void HouseConstruction::Create()
{
    AddObject add;
    House * m = new House(position,fraction);
    add.Add(m);
}


HouseBlueprintButton::HouseBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(20,20,200));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void HouseBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void HouseBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void HouseBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Thouse,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden House");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBHouse * ttt = new OICBHouse(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
OICBHouse::OICBHouse(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBHouse::Create(Position pos)
{
    return new GOIECBHouse(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
}
GOIECBHouse::GOIECBHouse(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBHouse::~GOIECBHouse(){}
BuildingConstruction* GOIECBHouse::CreateBuildingConstruction()
{
    HouseConstruction * m = new HouseConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    m->TESTCreateDemand(1,8);
    return m;
}








Mine::Mine(Position pos,uint32_t f)
:Building(pos,f),work(0),workdemand(1),emptyreserve(0)
{
    mark.setTexture(Textures::textures->Tmine);
    SlotPointer = new list_pointer(&RDV);
    Slot s;
    worker.push_back(s);
    for(std::list <Slot>::iterator ite = worker.begin();ite != worker.end();ite++)
    {
        RDV.push_back(&(*ite));
    }
    BarWork = new uint32_t_pointer(&work);
    BarWorkDemand = new uint32_t_pointer(&workdemand);
}
Mine::~Mine()
{
    SlotPointer->TurnOff();
    if((*worker.begin()).Occupant != NULL)
        delete (*worker.begin()).Occupant;
}
void Mine::Step()
{
    if(FirstStep())
    {
        switch(Map::ActualMap->GetTileType(position.GetX()-160,position.GetY()))
        {
        case 11:{materialtype=3;workdemand=300;break;}
        case 12:{materialtype=4;workdemand=500;break;}
        default:
            {Destroy();break;}
        }
    }
    if((*worker.begin()).Occupant != NULL)
    {
        if((*worker.begin()).FirstHour)
        {
            (*worker.begin()).FirstHour = false;
            emptyreserve = 0;
        }
        work++;
        if(work>workdemand)
        {
            Unit * u = dynamic_cast<Unit*>((*worker.begin()).Occupant);
            if(u!=NULL)
            {
                ResourceItem * r = new ResourceItem(1,materialtype);
                if(u->GiveItem(r))
                {
                    work = 0;
                    u->Activate();
                    AddObject add;
                    add.Add(u);
                    (*worker.begin()).Occupant = NULL;
                    (*worker.begin()).reserved = false;
                    (*worker.begin()).FirstHour = true;
                }
                else
                    delete r;
            }
        }
    }
    if((*worker.begin()).Occupant == NULL&&(*worker.begin()).reserved==true)
    {
        emptyreserve++;
        if(emptyreserve>=500)
        {
            emptyreserve = 0;
            (*worker.begin()).reserved = false;
        }
    }
    Building::Step();
}
void Mine::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 6;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    inf.lpointer = SlotPointer;
    Objects.push_back(inf);
}
void Mine::Selected()
{
    MarkBuilding::Selected();
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tmine,
                               Position(100,50),sf::Color(30,30,30),"Wooden Mine");
    Markable::MarkedObjectInfo.Information.push_back(obj);

    SetHPonGUI();

    OIBar * bar = new OIBar(BarWork,BarWorkDemand,sf::Color(130,80,30),150);
    Markable::MarkedObjectInfo.Information.push_back(bar);
}

PreMineConstruction::PreMineConstruction(Position pos,Object* obj)
:PreBuilding(pos,obj){}
bool PreMineConstruction::TileCheck()
{
    uint32_t t = Map::ActualMap->GetTileType(position.GetX()-160,position.GetY());
    if(t==11||t==12)
        return true;
    return false;
}


MineConstruction::MineConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void MineConstruction::Create()
{
    AddObject add;
    Mine * m = new Mine(position,fraction);
    add.Add(m);
}


MineBlueprintButton::MineBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(100,100,100));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void MineBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void MineBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void MineBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tmine,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Mine");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBMine * ttt = new OICBMine(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
OICBMine::OICBMine(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBMine::Create(Position pos)
{
    return new GOIECBMine(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
}
GOIECBMine::GOIECBMine(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBMine::~GOIECBMine(){}
BuildingConstruction* GOIECBMine::CreateBuildingConstruction()
{
    MineConstruction * m = new MineConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    m->TESTCreateDemand(1,15);
    return m;
}
PreBuilding * GOIECBMine::CreatePre(Position pos,Object* obj)
{
    return new PreMineConstruction(pos,obj);
}











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

WorkshopConstruction::WorkshopConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void WorkshopConstruction::Create()
{
    AddObject add;
    Workshop * w = new Workshop(position,fraction);
    add.Add(w);
}


WorkshopBlueprintButton::WorkshopBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(70,50,90));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void WorkshopBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void WorkshopBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void WorkshopBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tworkshop,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Workshop");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBWorkshop * ttt = new OICBWorkshop(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
OICBWorkshop::OICBWorkshop(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBWorkshop::Create(Position pos)
{
    return new GOIECBWorkshop(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
}
GOIECBWorkshop::GOIECBWorkshop(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBWorkshop::~GOIECBWorkshop(){}
BuildingConstruction* GOIECBWorkshop::CreateBuildingConstruction()
{
    WorkshopConstruction * w = new WorkshopConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    w->TESTCreateDemand(1,3);
    return w;
}







Forester::Forester(Position pos,uint32_t f)
:Building(pos,f)
{
    mark.setTexture(Textures::textures->Tforester);
    (*Fraction::Fractions)[f]->ChangeResidents(1);
}
Forester::~Forester(){(*Fraction::Fractions)[GetFraction()]->ChangeResidents(-1);}
void Forester::Step()
{
    Building::Step();
    if(rand()%2000==0)
    {
        Position pos(position.GetX()+(rand()%300)-150,position.GetY()+(rand()%300)-150);
        CommonTree * tree = new CommonTree(pos);
        AddObject add;
        add.Add(tree);
    }
}


void Forester::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 1;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}

ForesterConstruction::ForesterConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void ForesterConstruction::Create()
{
    AddObject add;
    Forester * m = new Forester(position,fraction);
    add.Add(m);
}


ForesterBlueprintButton::ForesterBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(20,200,20));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void ForesterBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void ForesterBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void ForesterBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tforester,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Forester");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBForester * ttt = new OICBForester(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
OICBForester::OICBForester(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBForester::Create(Position pos)
{
    return new GOIECBForester(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
}
GOIECBForester::GOIECBForester(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBForester::~GOIECBForester(){}
BuildingConstruction* GOIECBForester::CreateBuildingConstruction()
{
    ForesterConstruction * m = new ForesterConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    m->TESTCreateDemand(1,12);
    return m;
}









