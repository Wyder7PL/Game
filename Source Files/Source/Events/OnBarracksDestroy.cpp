#include "OnBarracksDestroy.h"

OnBarracksDestroy::OnBarracksDestroy(Position pos,uint32_t f,std::list<BarrackUnitStorage> bus,bool what)
:Barracks(pos,f,bus),OnBuildingDestroy(what){}
