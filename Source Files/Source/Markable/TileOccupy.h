#pragma once

#include "../Anoyher/uint32X2.hpp"
#include "../Functions.h"
#include "../Map/Map.h"




class TileOccupy
{
    void CountXGrid(Position,Position,uint32X2,uint32X2);
    void CountYGrid(Position,Position,uint32X2,uint32X2);
protected:
    TileOccupy();
    virtual ~TileOccupy();
    virtual bool SetGrid(Position,Position);
    Tile ** grid;
    uint32X2 currentgrid;
    uint32X2 currentgridstart;
};
