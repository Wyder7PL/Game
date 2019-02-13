#pragma once

#include "../Buildings/Building.h"

class PreBuilding:public Object
{
    bool wait;
    sf::RectangleShape shape;
    Object * object;

    Position pervious;
    Tile ** grid;
    uint32X2 currentgrid;
    uint32X2 currentgridstart;

    public:
        PreBuilding(Position,Object*);
        virtual ~PreBuilding();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    protected:
        virtual bool TileCheck();
    private:
    void RefreshGrid();
    void CountXGrid(uint32X2,uint32X2,uint32_t);
    void CountYGrid(uint32X2,uint32X2,uint32_t);
    bool FreeSpace();
};

