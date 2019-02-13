#include "TileOccupy.h"


TileOccupy::TileOccupy():grid(NULL){}
TileOccupy::~TileOccupy()
{
    if(grid!=NULL)
    {
        for(uint32_t i = 0;i < currentgrid.X*currentgrid.Y;i++)
            grid[i]->SetFree(false);
        delete[] grid;
    }
}
bool TileOccupy::SetGrid(Position pos,Position shape)
{
    Map * m = Map::ActualMap;
    Tile * tiles = m->GetTiles();

    uint32_t width = m->GetWidth(),height = m->GetHeight();
    uint32_t TP = m->GetTilePosition(pos.GetX()+175,pos.GetY(),width);
    if(m->IsSomethingNoYes())
        return true;
    uint32_t x = (TP%width),y = (TP-(TP%width))/height;
    CountXGrid(pos,shape,uint32X2(width,height),uint32X2(x,y));
    CountYGrid(pos,shape,uint32X2(width,height),uint32X2(x,y));
    if(currentgrid.Y >= height||currentgrid.X >= width)
        return true;
    for(uint32_t j = 0;j < currentgrid.Y;j++)
    {
        for(uint32_t i = 0;i < currentgrid.X;i++)
        {
            if((tiles + (currentgridstart.X+i)+((currentgridstart.Y+j)*width))->IsFree())
                return true;
        }
    }
    grid = new Tile*[ currentgrid.X*currentgrid.Y];
    for(uint32_t j = 0;j < currentgrid.Y;j++)
    {
        if(j >= height)
            return true;
        for(uint32_t i = 0;i < currentgrid.X;i++)
        {
            if(i >= width)
                return true;
            (*(grid+(i+j*currentgrid.X))) = &(*(tiles + (currentgridstart.X+i)+((currentgridstart.Y+j)*width)));
            grid[i+j*currentgrid.X]->SetFree(true);
        }
    }
    return false;
}
void TileOccupy::CountXGrid(Position pos,Position shape,uint32X2 dim,uint32X2 tilepos)
{
    uint32_t Xl;
    if(floor(pos.GetX()-175-(25))>=0)
       Xl = floor(pos.GetX()-175-(shape.GetX()/2));
    else
        Xl = 0;
    uint32_t XL = (Xl-(Xl%20))/20;
    uint32_t Xr = floor(pos.GetX()-175+(shape.GetX()/2));
    uint32_t XR = (Xr-(Xr%20))/20;
    currentgrid.X = 1+(tilepos.X-XL)+(XR-tilepos.X);
    currentgridstart.X = XL;
}
void TileOccupy::CountYGrid(Position pos,Position shape,uint32X2 dim,uint32X2 tilepos)
{
    uint32_t Yl = floor(pos.GetY()-(shape.GetY()/2));
    uint32_t YL = (Yl-(Yl%20))/20;
    uint32_t Yr = floor(pos.GetY()+(shape.GetY()/2));
    uint32_t YR = (Yr-(Yr%20))/20;
    currentgrid.Y = 1+(tilepos.Y-YL)+(YR-tilepos.Y);
    currentgridstart.Y = YL;
}
