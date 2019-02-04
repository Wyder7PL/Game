#include "TestRace.h"

TestRace::TestRace(Position pos,uint32_t f,bool ho)
:Unit(pos,f,ho),armor(NULL),ccs(NULL)
{
    SetMass(2);
    DefaultMass = 2;

    hp = new HP(15);

    MarkSize(10);

    SetMaxSpeed(1.0);

    RightHand = NULL;
    LeftHand = NULL;

        Collision * col = new Collision(GetID());
        AddObject add;
        add.Add(col);

}

TestRace::~TestRace()
{
    delete hp;
    delete RightHand;
    delete LeftHand;
    delete armor;
    delete ccs;
}

void TestRace::Step()
{
    Unit::Step();
    sf::Vector2f pos = sfLocalPos(position);
    if(armor!=NULL)
    {
        sf::Sprite & armimg = armor->GetImage();
        armimg.setScale(0.2,0.2);
        armimg.setPosition(pos.x,pos.y+3);
    }
    if(LeftHand!=NULL)
    {
        sf::Sprite & lhs = LeftHand->GetImage();
        lhs.setScale(-0.25,0.25);
        if(RightHand!=NULL)
            lhs.setPosition(pos.x-5,pos.y-2);
        else
            lhs.setPosition(pos.x-10,pos.y-2);
    }
    if(RightHand!=NULL)
    {
        sf::Sprite & rhs = RightHand->GetImage();
        rhs.setScale(0.25,0.25);
        if(LeftHand!=NULL)
            rhs.setPosition(pos.x,pos.y-2);
        else
            rhs.setPosition(pos.x-10,pos.y-2);
    }
    if(Look(position))
    {
        if(ForcedMove()&&EnemyIgnore)
        {
            Push(Position(position.angle(ForcedDestination()),8*ccs->Speed()));
        }
        else if(ccs!=NULL){
            std::list <Item**> i;
            i.push_back(&RightHand);
            i.push_back(&LeftHand);
            switch(ccs->Step(position,&i,&SeenObjects))
            {
            case 0:
                {
                    if(ForcedMove()&&!EnemyIgnore)
                        Push(Position(position.angle(ForcedDestination()),8*ccs->Speed()));
                    break;
                }
            case 1:
                {Push(Position(position.angle(ccs->Destination()),8*ccs->Speed()));break;}
            case 2:
                {
                    Desactivate();
                    ccs->GetSlot()->Occupant = this;
                    break;
                }
            case 3:
                break;
            }
            float chm = ccs->GetChangedMass();
            if(chm!=0)
                ItemMass+=chm;
        }
        SeenObjects.clear();
    }
    if(hp->GetHP() <= 0)
    {
        Destroy();
    }
}
void TestRace::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Unit::draw(target,states);
    if(armor!=NULL)
        target.draw(armor->GetImage());
    if(RightHand!=NULL)
        target.draw(RightHand->GetImage());
    if(LeftHand!=NULL)
        target.draw(LeftHand->GetImage());
}

void TestRace::DealDamage(uint32_t damage,uint32_t type)
{
    if(armor!=NULL)
        damage = armor->DecreaseDamage(damage,type);
    hp->TakeDamage(damage,type);
}

bool TestRace::GiveItem(Item*i)
{
    if(RightHand==NULL)
    {
        RightHand = i;
        RightHand->SetFractions(Fraction);
        SetSeenRange(i->GetSeenRange());
        ResetMass(i->GetWeight());
        return true;
    }
    if(LeftHand==NULL)
    {
        LeftHand = i;
        LeftHand->SetFractions(Fraction);
        ResetMass(i->GetWeight());
        return true;
    }
    return false;
}
ResourceItem * TestRace::TakeItem(uint32_t type, uint32_t amount)
{
    if(RightHand != NULL)
    {
        ResourceItem * res = dynamic_cast<ResourceItem*>(RightHand);
        if(res != NULL)
        {
            if(res->GetType() == type)
            {
                ResetMass(-(RightHand->GetWeight()));
                RightHand = NULL;
                return res;
    }   }   }
    if(LeftHand != NULL)
    {
        ResourceItem * res = dynamic_cast<ResourceItem*>(LeftHand);
        if(res != NULL)
        {
            if(res->GetType() == type)
            {
                ResetMass(-(LeftHand->GetWeight()));
                LeftHand = NULL;
                return res;
    }   }   }
    return NULL;
}
Item * TestRace::GetActiveTool()
{
    if(RightHand != NULL && ((RightHand->GetItemType())&3)!=0)
        return RightHand;
    if(LeftHand != NULL && ((LeftHand->GetItemType())&3)!=0)
        return LeftHand;
    return NULL;
}

Skill * TestRace::GetActiveSkill()
{
    return ccs;
}

void TestRace::SetRightItem(Item*i)
{
    RightHand = i;
    RightHand->SetFractions(Fraction);
    SetSeenRange(i->GetSeenRange());
    ResetMass(i->GetWeight());
}
void TestRace::SetLeftItem(Item*i)
{
    LeftHand = i;
    LeftHand->SetFractions(Fraction);
    ResetMass(i->GetWeight());
}
void TestRace::WearArmor(Armor*a)
{
    armor = a;
    ResetMass(a->GetWeight());
}
void TestRace::SetSkill(Skill*s)
{
    ccs = s;
    ccs->ChangeFraction(Fraction);
}

uint32_t TestRace::GetSkillType()
{
   return ccs->GetSkillType();
}
