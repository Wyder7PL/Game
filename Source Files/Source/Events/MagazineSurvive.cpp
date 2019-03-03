#include "MagazineSurvive.h"

MagazineSurvive::MagazineSurvive(Position pos,uint32_t f,bool what,uint32_t SurvivalTime)
:Magazine(pos,f),BuildingSurvive(what,SurvivalTime)
{

}
void MagazineSurvive::Step()
{
    Magazine::Step();
    BuildingSurvive::Step();
}
