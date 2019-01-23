#ifndef MAP_H
#define MAP_H

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include <stdint.h>
#include <math.h>
#include <random>

class Tile
{
    uint32_t tile;
    bool free;
    bool pre;
public:
    Tile();
    uint32_t Get();
    bool IsFree();
    bool IsPre();
    void Set(uint32_t);
    void SetFree(bool);
    void SetPre(bool);
    Tile & operator = (const uint32_t);
};

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

/// /////////////////////////////// ///
/// 0.Nothing                       ///
/// 1.Grass                         ///
/// 20.Ores                         ///
/// 21.Iron                         ///
/// 22.Gold                         ///
///                                 ///
/// /////////////////////////////// ///

#endif // MAP_H
