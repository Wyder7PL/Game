#include "Creature.h"

Creature::Creature(uint32_t f)
:blink(false),Fraction(f)
{
    sight = NULL;
    SeenRange = 200;
}

Creature::~Creature()
{
    //dtor
}

uint32_t Creature::GetFraction()
{
    return Fraction;
}

bool Creature::Look(Position pos)
{
    if(sight == NULL)
    {
            AddObject add;
            sight = new Sight(pos,SeenRange);
            add.Add(sight);
            SightEffect * eff = NULL;
            eff = new SightEffect(sight->GetID());
            add.Add(eff);
            return false;
    }
    else if(sight->Ready())
    {
        SeenObjects.clear();
        for(std::list <Info>::iterator ite = sight->Objects.begin();ite!=sight->Objects.end();ite++)
            SeenObjects.push_back((*ite));
        sight->Erase();
        sight = NULL;

        blink = true;
        return true;
    }

    return false;
}

void Creature::SetSeenRange(float s)
{
    SeenRange = s;
}
float Creature::GetSeenRange()
{
    return SeenRange;
}

Info * Creature::GetNearest(float& distance,Position position)
{
    Info * inf = NULL;
    for(std::list <Info>::iterator ite = SeenObjects.begin();ite!=SeenObjects.end();ite++)
    {
        if(TypeComparation(ite)&&(*Fraction::Fractions)[Creature::GetFraction()]->CompareFractions((*ite).fraction)==0 && position.distance((*ite).position) < distance)
        {
            distance = position.distance((*ite).position);
            inf = &(*ite);
        }
    }
    return inf;
}
