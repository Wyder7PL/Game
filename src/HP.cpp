#include "../include/HP.h"

HP::HP(uint32_t Max,uint32_t current)
{
    if(current == 0)
        hp = Max;
    else
        hp = current;
    full = Max;
}

HP::~HP()
{
    //dtor
}

void HP::Step(){}

void HP::TakeDamage(uint32_t damage,uint32_t type)
{
    hp -= damage;
}

int32_t HP::GetHP()
{
    return hp;
}
int32_t HP::GetMaxHP()
{
    return full;
}

WoodenHP::WoodenHP(uint32_t Max,uint32_t current)
:HP(Max,current),FireStrenght(0),FireExistance(0)
{

}
WoodenHP::~WoodenHP(){}

void WoodenHP::Step()
{
    if(FireExistance > 0)
    {HP::TakeDamage(FireStrenght,0);
    FireExistance--;}
}

void WoodenHP::TakeDamage(uint32_t damage,uint32_t type)
{
    HP::TakeDamage(damage,type);
    if(type == 4)
    {
        FireExistance += 10;
        FireStrenght++;
    }
    else if(type == 5)
    {
        if(FireStrenght <= 3)
        {
            FireStrenght = 0;
            FireExistance = 0;
        }
        else
        {
            if(FireExistance <= 15)
                FireExistance = 0;
            else
                FireExistance -= 15;
            FireStrenght -= 3;
        }
    }
}

