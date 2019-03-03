#pragma once

#include "Tile.h"
#include <math.h>
#include <random>

class Map
{
    uint32_t width;
    uint32_t height;

    Tile * tile;

    bool ConstructionSight;

    bool SomethingIsNoYes;

    public:
        static Map * ActualMap;

        Map(uint32_t,uint32_t);
        ~Map();

        void TEST_LoadMap();
        void TEST_LoadMap1();
        void TEST_LoadMap2();

        Tile * GetTiles();
        Tile GetTile(uint32_t,uint32_t);
        uint32_t GetTileType(float,float);
        void BlockTile(bool,float,float);
        uint32_t GetTilePosition(float,float,uint32_t);

        uint32_t GetWidth();
        uint32_t GetHeight();

        void SetConSight(bool);
        bool GetConSight();

        bool IsSomethingNoYes();
    protected:
    private:
        Tile * GetTileF(float,float);
};
