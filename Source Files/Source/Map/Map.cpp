#include "Map.h"

Map * Map::ActualMap = NULL;

Map::Map(uint32_t x,uint32_t y)
:width(x),height(y),tile(new Tile[x*y]),ConstructionSight(false),SomethingIsNoYes(false)
{

}

Map::~Map()
{
    delete[] tile;
    if(Map::ActualMap == this)
        Map::ActualMap = NULL;
}

void Map::TEST_LoadMap()
{
    for(uint32_t i = 0;i < width*height;i++)
    {
        int32_t I = i,Ix = I%width;;
        if(pow(pow(Ix-30,2)+pow(((I-Ix)/width)-30,2),0.5)<10)
            {*(tile + i) = 11;continue;}
        if(i>300&&i<1300&&Ix+(I-Ix)/width > 20 && Ix+(I-Ix)/width < 30)
            {*(tile + i) = 12;continue;}
        *(tile + i) = 2;
    }
}

void Map::TEST_LoadMap1()
{
    for(uint32_t i = 0;i < width*height;i++)
    {
        if(i%110>30&&i%110<45&&i>1100&&i<1788&&sin(i+1)>0.5)
            {*(tile + i) = 12;continue;}
        if(i%110>47&&i%110<52&&i>3025&&i<3600)
            {*(tile + i) = 11;continue;}
        *(tile + i) = 2;
    }
}

void Map::TEST_LoadMap2()
{
    uint32_t X = rand()%35+45, Y = rand()%35+45;
    uint32_t X2, Y2;
    do{
    X2 = rand()%35+45, Y2 = rand()%35+45;
    }while(X==X2||Y==Y2);
    for(uint32_t i = 0;i < width*height;i++)
    {
        if(i%110>30&&i%110<45&&i>1100&&i<1788&&sin(i+1)>0.5)
            {*(tile + i) = 12;continue;}
        if(i%110>47&&i%110<52&&i>3025&&i<3600)
            {*(tile + i) = 11;continue;}

        if(i%width>X-(3+rand()%7)&&i%width<X+(3+rand()%6)&&i>(Y-(3+rand()%5))*width&&i<(Y+(3+rand()%5))*width&&sin(i)>0.7)
            {*(tile + i) = 11;continue;}
        if(i%width>X2-(3+rand()%5)&&i%width<X2+(3+rand()%5)&&i>(Y2-(3+rand()%5))*width&&i<(Y2+(3+rand()%5))*width&&cos(i)>0.7)
            {*(tile + i) = 12;continue;}

        *(tile + i) = 2;
    }
}


Tile * Map::GetTileF(float x,float y)
{
    return &(*(tile + GetTilePosition(x,y,width)));
}
Tile Map::GetTile(uint32_t x,uint32_t y)
{
    return (*(tile +(x+width*y)));
}
Tile * Map::GetTiles()
{
    return tile;
}
uint32_t Map::GetTileType(float x,float y)
{
    return GetTileF(x,y)->Get();
}
void Map::BlockTile(bool b,float x,float y)
{
    GetTileF(x,y)->SetFree(b);
}

uint32_t Map::GetTilePosition(float x,float y,uint32_t w)
{
    uint32_t Xr = floor(x);
    uint32_t X = (Xr-(Xr%20))/20;
    uint32_t Yr = floor(y);
    uint32_t Y = (Yr-(Yr%20))/20;
    //if(X>=width||Y>=height)
        //SomethingIsNoYes = true;
    return X+Y*w;
}

bool Map::IsSomethingNoYes()
{
    bool temp = SomethingIsNoYes;
    SomethingIsNoYes = false;
    return temp;
}

uint32_t Map::GetWidth()
{
   return width;
}
uint32_t Map::GetHeight()
{
   return height;
}

void Map::SetConSight(bool s)
{
    ConstructionSight = s;
}
bool Map::GetConSight()
{
    return ConstructionSight;
}
