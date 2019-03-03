#include "Unit.h"

Unit::Unit(Position pos,uint32_t f,bool ho)
:MarkUnit(pos),Creature(f),HouseOccupy(ho),EnemyIgnore(true),
FocusedOnFortification(false),FocusedID(0),FocusedSlot(0),ItemMass(0)
{
    if(HouseOccupy)
        (*Fraction::Fractions)[Fraction]->ChangeResidents(1);
}

Unit::~Unit()
{
    if(Fraction::Fractions!=NULL&&HouseOccupy)
        (*Fraction::Fractions)[Fraction]->ChangeResidents(-1);
}

void Unit::Step()
{
    MarkUnit::Step();
    if(FocusedOnFortification)
    {
        if(Look(position))
        {
            float distance = 10000;
            Slot * slot = NULL;
            Info * inf = NULL;
            if(FocusedID==0)
            {
                for(std::list <Info>::iterator ite = SeenObjects.begin();ite!=SeenObjects.end();ite++)
                {
                    if((*ite).type == 5&&(*Fraction::Fractions)[Creature::GetFraction()]->CompareFractions((*ite).fraction)!=0 && position.distance((*ite).position) < distance)
                    {
                        if((*ite).lpointer != NULL){
                            if((*ite).lpointer->DestroyMe())
                            continue;}

                        uint32_t focusedslot = 0;
                        std::list <void*>::iterator ite2 = (*ite).lpointer->GetPointer()->begin();
                        std::list <Slot> * s = &(*(reinterpret_cast<std::list<Slot>*>((*ite2))));
                        ite2++;
                        bool exit = false;
                        for(std::list <Slot>::iterator ite3 = s->begin();ite3!=s->end()&&!exit&&focusedslot<2;)
                        {
                            if((*ite3).Occupant==NULL&&!(*ite3).reserved)
                            {
                                inf = &(*ite);
                                slot = &(*ite3);
                                (*ite3).reserved = true;
                                FocusedID = (*ite).id;
                                FocusedSlot = focusedslot;
                                distance = position.distance((*ite).position);
                                exit = true;
                                break;
                            }
                            focusedslot++;
                            if(ite3!=s->end())
                                ite3++;
                        }
                    }
                }
                if(FocusedID==0)
                    FocusedOnFortification=false;
            }
            else
            {
                bool exit = false;
                for(std::list <Info>::iterator ite = SeenObjects.begin();ite!=SeenObjects.end()&&!exit;)
                {
                    if((*ite).id==FocusedID)
                    {
                        inf = &(*ite);
                        uint32_t focusedslot = 0;
                        if((*ite).lpointer == NULL||(*ite).lpointer->DestroyMe())
                            continue;
                        std::list <void*>::iterator ite2 = (*ite).lpointer->GetPointer()->begin();
                        std::list <Slot> * s = &(*(reinterpret_cast<std::list<Slot>*>((*ite2))));
                        for(std::list <Slot>::iterator ite3 = s->begin();ite3!=s->end()&&!exit;)
                        {
                            if(focusedslot==FocusedSlot)
                            {

                                slot = &(*ite3);
                                distance = position.distance((*ite).position);
                                exit = true;
                                break;

                            }
                            if(ite3!=s->end())
                                ite3++;
                            focusedslot++;
                        }}
                    if(ite!=SeenObjects.end())
                        ite++;
                }
                if(!exit)
                    FocusedOnFortification = false;
            }
            if(inf!=NULL&&slot!=NULL)
            {
                if(distance<70)
                {
                    FocusedOnFortification = false;
                    FocusedID = 0;
                    Desactivate();
                    slot->Occupant = this;
                    return;
                }
                Push(Position(position.angle(inf->position),8));
                return;
            }
        }
    }
    else if(selected&&MUS->GetCommonOrderButtonState()==4)
        EnterNeartestFortification();
    if(selected)
    {
        if(MUS->GetCommonOrderButtonState()>0)
        {
            NonCombatSkill * NCS = dynamic_cast<NonCombatSkill*>(GetActiveSkill());
            if(NCS!=NULL)
            {
                if(MUS->GetCommonOrderButtonState()==1||MUS->GetCommonOrderButtonState()==2)
                    NCS->CanelWork(true);
                if(MUS->GetCommonOrderButtonState()==2)
                    NCS->AbortWork(true);
                if(MUS->GetCommonOrderButtonState()==3)
                {
                    NCS->CanelWork(false);
                    NCS->AbortWork(false);
                }
            }
        }
        uint32_t eneig = MUS->GetIfEnemyIgnored();
        if(eneig==1)
            EnemyIgnore = false;
        else if(eneig==2)
            EnemyIgnore = true;
    }
}
void Unit::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    MarkUnit::draw(target,states);
}

uint32_t Unit::GetFraction()
{
    return Creature::GetFraction();
}

void Unit::StartOccupying()
{
    if(HouseOccupy)
        return;
    HouseOccupy = true;
    (*Fraction::Fractions)[Fraction]->ChangeResidents(1);
}

void Unit::EnterNeartestFortification()
{
    FocusedOnFortification = true;
}
void Unit::ForceToIgnoreEnemy(bool b)
{
    EnemyIgnore = b;
}

bool Unit::TypeComparation(std::list <Info>::iterator ite)
{
    if((*ite).type == 5)
        return true;
    return false;
}

void Unit::ResetMass(float m)
{
    ItemMass += m;
    SetMass(DefaultMass+ItemMass);
}


UnitTask::UnitTask(uint32_t id){affected = id;}




