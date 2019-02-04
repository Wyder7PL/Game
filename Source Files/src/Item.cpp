#include "../include/Item.h"

Item::Item(uint32_t f)
:ItemType(0),fractions(f),Weight(0.3)
{

}

Item::~Item()
{
    //dtor
}

uint32_t Item::GetItemType()
{
    return ItemType;
}

float Item::GetWeight()
{
    return Weight;
}

void Item::SetItemType(uint32_t it)
{
    ItemType = it;
}

void Item::SetWeight(float it)
{
    Weight = it;
}

void Item::SetFractions(uint32_t f)
{
    fractions = f;
}

float Item::GetSeenRange()
{
    return 0;
}
sf::Sprite & Item::GetImage()
{
    return image;
}


CloseCombatItem::CloseCombatItem(uint32_t f)
:Item(f)
{
    SetItemType(1);
    cooldown = 0;
}
CloseCombatItem::~CloseCombatItem()
{

}

float CloseCombatItem::GetRange()
{
    return range;
}
void CloseCombatItem::SetRange(float r)
{
    range = r;
}
float CloseCombatItem::GetSpeed()
{
    return speed;
}
void CloseCombatItem::SetSpeed(uint32_t s)
{
    speed = s;
}
uint32_t CloseCombatItem::GetCooldown()
{
    return cooldown;
}
void CloseCombatItem::SetCooldown(uint32_t c)
{
    cooldown = c;
}
float CloseCombatItem::GetSeenRange()
{
    return 210;
}

Spear::Spear(uint32_t f)
:CloseCombatItem(f)
{
    SetRange(80);
    SetSpeed(10);
    image.setTexture(Textures::textures->Spear);
}
Spear::~Spear()
{

}

bool Spear::Attack(Position pos,Position target)
{
    if(GetCooldown() == 0 && pos.distance(target) < GetRange())
    {
        spear * p = new spear(target,fractions);
        p->SetFractions(fractions);
        AddObject add;
        add.Add(p);
        SetCooldown(GetSpeed());
        return true;
    }
    else if(GetCooldown() > 0)
        SetCooldown(GetCooldown()-1);
    return false;
}

Sword::Sword(uint32_t f)
:CloseCombatItem(f)
{
    SetRange(60);
    SetSpeed(10);
    image.setTexture(Textures::textures->Sword);
}


bool Sword::Attack(Position pos,Position target)
{
    if(GetCooldown() == 0 && pos.distance(target) < GetRange())
    {
        sword * p = new sword(pos.GMP(pos.angle(target),20),fractions,GetRange()/2,5);
        p->SetFractions(fractions);
        AddObject add;
        add.Add(p);
        SetCooldown(GetSpeed());
        return true;
    }
    else if(GetCooldown() > 0)
        SetCooldown(GetCooldown()-1);
    return false;
}

SingleShot::SingleShot(uint32_t f)
:Item(f),damage(1)
{
    SetItemType(1);
    SetActualReload(0);
    SetCooldown(0);
}
SingleShot::~SingleShot()
{

}

bool SingleShot::Shoot(Position pos,Position target)
{
    if(pow( pow(pos.GetX()-target.GetX(),2.0)+pow(pos.GetY()-target.GetY(),2.0) ,0.5) < GetRange())
    {
        if(magazine > 0 && cooldown == 0)
        {
            if(Charged())
            {
                CreateBullet(pos,target);
                magazine--;
                cooldown+=shootrate;
            }
            return true;
        }
        else if(magazine == 0 && actualreload == 0)
        {
            actualreload = reloadtime;
            return false;
        }
        if(cooldown>0)
        {
            cooldown--;
            return true;
        }
    }
    return false;
}

void SingleShot::Reload(uint32_t r)
{
    if(r >= actualreload)
    {
        actualreload = 0;
        magazine = fullmagazine;
    }
    else
        actualreload-=r;
}

void SingleShot::CreateBullet(Position pos,Position target)
{
    bullet * p = new bullet(pos,fractions,damage);
    p->Push(Position(pos.angle(target),15.0));
    p->SetFractions(fractions);
    AddObject add;
    add.Add(p);
}

float SingleShot::RandomBullet()
{
    float acc = (rand()%628)-314;
    acc/=(100*accuarity);
    return acc;
}

bool SingleShot::Charged()
{
    return true;
}

void SingleShot::SetDamage(uint32_t d)
{
   damage = d;
}
uint32_t SingleShot::GetDamage()
{
    return damage;
}

float SingleShot::GetRange()
{
    return range;
}
void SingleShot::SetRange(float r)
{
    range = r;
}

float SingleShot::GetAccuarity()
{
    return accuarity;
}
void SingleShot::SetAccuarity(float a)
{
    accuarity = a;
}
uint32_t SingleShot::GetCooldown()
{
    return cooldown;
}
void SingleShot::SetCooldown(uint32_t c)
{
    cooldown = c;
}
uint32_t SingleShot::GetShootRate()
{
    return shootrate;
}
void SingleShot::SetShootRate(uint32_t s)
{
    shootrate = s;
}
uint32_t SingleShot::GetFullMagazine()
{
    return fullmagazine;
}
void SingleShot::SetFullMagazine(uint32_t fm)
{
    fullmagazine = fm;
}
uint32_t SingleShot::GetMagazine()
{
    return magazine;
}
void SingleShot::SetMagazine(uint32_t m)
{
    magazine = m;
}
uint32_t SingleShot::GetReloadTime()
{
    return reloadtime;
}
void SingleShot::SetReloadTime(uint32_t rt)
{
    reloadtime = rt;
}
uint32_t SingleShot::GetActualReload()
{
    return actualreload;
}
void SingleShot::SetActualReload(uint32_t ar)
{
    actualreload = ar;
}
float SingleShot::GetSeenRange()
{
    return 250;
}


SniperRifle::SniperRifle(uint32_t f)
:SingleShot(f)
{
    SetDamage(22);
    SetRange(280);
    SetAccuarity(130);
    SetShootRate(1);
    SetFullMagazine(1);
    SetMagazine(1);
    SetReloadTime(20*100);
    image.setTexture(Textures::textures->SniperRifle);
}


MiniGun::MiniGun(uint32_t f)
:SingleShot(f)
{
    SetRange(200);
    SetAccuarity(80);
    SetShootRate(0);
    SetFullMagazine(100);
    SetMagazine(45);
    SetReloadTime(50*100);
    image.setTexture(Textures::textures->Minigun);
}

MiniGun::~MiniGun(){}


Uzi::Uzi(uint32_t f)
:SingleShot(f)
{
    SetDamage(6);
    SetRange(180);
    SetAccuarity(70);
    SetShootRate(3);
    SetFullMagazine(30);
    SetMagazine(30);
    SetReloadTime(30*100);
    image.setTexture(Textures::textures->Uzi);
}

Uzi::~Uzi(){}

Musket::Musket(uint32_t f)
:SingleShot(f)
{
    SetDamage(10);
    SetRange(210);
    SetAccuarity(100);
    SetShootRate(10);
    SetFullMagazine(1);
    SetMagazine(1);
    SetReloadTime(30*100);
    image.setTexture(Textures::textures->Musket);
}

Shootgun::Shootgun(uint32_t f)
:SingleShot(f)
{
    SetDamage(8);
    SetRange(220);
    SetAccuarity(120);
    SetShootRate(10);
    SetFullMagazine(2);
    SetMagazine(2);
    SetReloadTime(20*100);
    image.setTexture(Textures::textures->DoubleShoot);
}

void Shootgun::CreateBullet(Position pos,Position target)
{
    AddObject add;
    bullet * b;
    for(uint32_t i = 0;i<5;i++)
    {
        float anglemod = (rand()%100-50),powermod = (rand()%100-50);
        anglemod/=200;
        powermod/=10;
        b = new bullet(pos,fractions,GetDamage());
        b->Push(Position(pos.angle(target)+anglemod,15.0+powermod));
        b->SetFractions(fractions);
        add.Add(b);
    }
}

HookGun::HookGun(uint32_t f)
:SingleShot(f)
{
    SetRange(300);
    SetAccuarity(100);
    SetShootRate(0);
    SetFullMagazine(1);
    SetMagazine(1);
    SetReloadTime(5*100);
    image.setTexture(Textures::textures->HookGun);
}

HookGun::~HookGun(){}

void HookGun::CreateBullet(Position pos,Position target)
{
    hook * p = new hook(pos,fractions);
    p->Push(Position(pos.angle(target),7.0));
    p->SetFractions(fractions);
    AddObject add;
    add.Add(p);
}

Bow::Bow(uint32_t f)
:SingleShot(f),charge(0)
{
    SetRange(170);
    SetAccuarity(100);
    SetShootRate(0);
    SetFullMagazine(1);
    SetMagazine(1);
    SetReloadTime(5*100);
    SetChargeTime(10);
    image.setTexture(Textures::textures->Bow);
}

Bow::~Bow(){}

float Bow::GetSeenRange()
{
    return 200;
}

bool Bow::Charged()
{
    if(charge < chargetime)
    {
        charge++;
        return false;
    }
    charge = 0;
    return true;
}
void Bow::CreateBullet(Position pos,Position target)
{
    bullet * p = new bullet(pos,fractions,5);
    p->Push(Position(pos.angle(target),15.0));
    p->SetFractions(fractions);
    AddObject add;
    add.Add(p);
}

void Bow::SetChargeTime(uint32_t cht)
{
    chargetime = cht;
}

Tool::Tool(uint32_t f)
:Item(f),Type(0),Charge(0){SetItemType(2);}



float Tool::GetRange()
{
    return range;
}
void Tool::SetRange(float r)
{
    range = r;
}
uint32_t Tool::GetSpeed()
{
    return speed;
}
void Tool::SetSpeed(uint32_t s)
{
    speed = s;
}

void Tool::SetType(uint32_t t)
{
    Type = t;
}
uint32_t Tool::GetType()
{
    return Type;
}
float Tool::GetSeenRange()
{
    return 500;
}


ConstructionTool::ConstructionTool(uint32_t f):Tool(f){}

uint32_t ConstructionTool::Build(Position pos,Position target)
{
    if(pos.distance(target) < GetRange())
    {
        if(Charge == Price)
        {
            constructiontool * t = new constructiontool(target,fractions,GetType());
            AddObject add;
            add.Add(t);
            Charge = 0;
            return 2;
        }
        Charge++;
        return 1;
    }
    return 0;
}
bool ConstructionTool::Refill(Position pos,Position target)
{
    if(pos.distance(target) < GetRange())
    {
        WorkPoints = MaxWorkPoints;
        return true;
    }
    return false;
}
void ConstructionTool::setMaxWorkPoints(uint32_t wp)
{
    MaxWorkPoints = wp;
}
uint32_t ConstructionTool::GetMaxWorkPoints()
{
    return MaxWorkPoints;
}
void ConstructionTool::SetWorkPoints(uint32_t wp)
{
    WorkPoints = wp;
}
uint32_t ConstructionTool::GetWorkPoints()
{
    return WorkPoints;
}
void ConstructionTool::SetType(uint32_t t)
{
    Tool::SetType(t);
    Price = (*ResourceStorage::ResourcesList)[t]->build->buildcost;
}

PrimaryCTool::PrimaryCTool(uint32_t f)
:ConstructionTool(f)
{
    setMaxWorkPoints(20);
    SetWorkPoints(20);
    SetRange(70);
    image.setTexture(Textures::textures->Hammer);
}

GatherTool::GatherTool(uint32_t f)
:StorageComponent(f)
{
    Price = 10;
    SetRange(70);
    image.setTexture(Textures::textures->Axe);
}
uint32_t GatherTool::Gather(Position pos,Position target,uint32_t id)
{
    if(pos.distance(target) < GetRange())
    {
        if(Charge == Price)
        {
            gathertoll * t = new gathertoll(target,fractions,id);
            AddObject add;
            add.Add(t);
            Charge = 0;
            return 2;
        }
        Charge++;
        return 1;
    }
    return 0;
}
StorageComponent::StorageComponent(uint32_t f)
:Tool(f),res(NULL){}
uint32_t StorageComponent::Store(Position pos,Position target,uint32_t type,uint32_t amount)
{
    if(pos.distance(target) < GetRange())
    {
        (*Fraction::Fractions)[fractions]->GetEco()->GEE(type)->ChangeAmount(amount);
        return 1;
    }
    return 0;
}
uint32_t StorageComponent::Extract(Position pos,Position target,uint32_t type,uint32_t amount)
{
    if(pos.distance(target) < GetRange())
    {
        if((*Fraction::Fractions)[fractions]->GetEco()->GEE(type)->GetNonReservedAmount() >= amount)
        {
            res = new ResourceItem(fractions,type);
            (*Fraction::Fractions)[fractions]->GetEco()->GEE(type)->ChangeAmount(-amount);
            return 2;
        }
        return 1;
    }
    return 0;
}
MiningTool::MiningTool(uint32_t f)
:StorageComponent(f)
{
    Price = 10;
    SetRange(70);
    image.setTexture(Textures::textures->Pickaxe);
}
ToolBox::ToolBox(uint32_t f)
:StorageComponent(f)
{
    Price = 30;
    SetRange(60);
    image.setTexture(Textures::textures->Toolbox);
}
RecipeIngredient::RecipeIngredient(uint32_t t,uint32_t a)
:type(t),amount(a){}
uint32_t RecipeIngredient::GetType(){return type;}
uint32_t RecipeIngredient::GetAmount(){return amount;}
RecipeProduct::RecipeProduct(uint32_t t,uint32_t a,uint32_t ch)
:RecipeIngredient(t,a),chance(ch){}
uint32_t RecipeProduct::GetChance(){return chance;}

ResourceItem * ToolBox::GetExtractedItem()
{
    ResourceItem * temp = res;
    res = NULL;
    return temp;
}
ResourceItem::ResourceItem(uint32_t f,uint32_t t):Item(f),type(t)
{
    amount = 1;maxamount = 1;
    switch(type)
    {
        case 1:{image.setTexture(Textures::textures->Wood);break;}
        case 2:{image.setTexture(Textures::textures->Stone);break;}
        case 3:{image.setTexture(Textures::textures->Iron);break;}
        case 4:{image.setTexture(Textures::textures->Gold);break;}
        default:{break;}
    }
}
uint32_t ResourceItem::GetType(){return type;}

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




Armor::Armor(uint32_t f):Item(f){SetItemType(4);}
uint32_t Armor::GTZ(uint32_t amount,uint32_t decrease)
{
    if(amount > decrease)
        return amount-decrease;
    return 0;
}
uint32_t Armor::GTO(uint32_t amount,uint32_t decrease)
{
    if(amount > decrease)
        return amount-decrease;
    return 1;
}

WoodenArmor::WoodenArmor(uint32_t f):Armor(f)
{
    image.setTexture(Textures::textures->WoodenArmor);
    image.setOrigin(50,50);
}

uint32_t WoodenArmor::DecreaseDamage(uint32_t damage,uint32_t type)
{
    return GTO(damage,2);
}

IronPlateArmor::IronPlateArmor(uint32_t f):Armor(f)
{
    image.setTexture(Textures::textures->IronPlateArmor);
    image.setOrigin(50,50);
}

uint32_t IronPlateArmor::DecreaseDamage(uint32_t damage,uint32_t type)
{
    return GTO(damage,4);
}

