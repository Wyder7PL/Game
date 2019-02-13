#include "Tile.h"

Tile::Tile():tile(0),free(false),pre(false){}

uint32_t Tile::Get(){return tile;}

bool Tile::IsFree(){return free;}

bool Tile::IsPre(){return pre;}

void Tile::Set(uint32_t t){tile = t;}

void Tile::SetFree(bool f){free = f;}

void Tile::SetPre(bool p){pre = p;}

Tile & Tile::operator =(const uint32_t t){tile = t;return * this;}
