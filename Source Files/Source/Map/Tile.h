#pragma once

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include <stdint.h>

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


/// /////////////////////////////// ///
/// 0.Nothing                       ///
/// 1.Grass                         ///
/// 20.Ores                         ///
/// 21.Iron                         ///
/// 22.Gold                         ///
///                                 ///
/// /////////////////////////////// ///
