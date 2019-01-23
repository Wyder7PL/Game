#include "../include/PreBuilding.h"

PreBuilding::PreBuilding(Position pos,Object * obj)
:Object(pos),wait(true),pervious(pos)
{
    object = obj;
    shape.setSize(sf::Vector2f(30,30));
    shape.setOrigin(15,15);
    shape.setOutlineThickness(10);
    shape.setFillColor(sf::Color(50,50,50,150));
    shape.setOutlineColor(sf::Color(0,0,0,150));
    Markable::SetSelectedType(4);

    physicshape = new Circle(25*1.41);
    mask = 1;
    SetZIndex(7);
    uint32_t gridsize = floor((25)*2/20)+2;
    grid = new Tile*[gridsize*gridsize ];

    Map::ActualMap->SetConSight(true);
}

PreBuilding::~PreBuilding()
{
    for(uint32_t i = 0;i < currentgrid.X*currentgrid.Y;i++)
        grid[i]->SetPre(false);
    delete[] grid;
    Map::ActualMap->SetConSight(false);
}

bool PreBuilding::TileCheck(){return true;}

void PreBuilding::RefreshGrid()
{
    if(!(Keyboard::MouseX()>175&&Keyboard::MouseX()<1024&&Keyboard::MouseY()>0&&Keyboard::MouseY()<786))
        return;
    if(GetPosition().GetX()<25+160||GetPosition().GetY()<25)
        return;
    Map * m = Map::ActualMap;
    Tile * tiles = m->GetTiles();
    for(uint32_t j = 0;j < currentgrid.Y;j++)
    {
        for(uint32_t i = 0;i < currentgrid.X;i++)
        {
            grid[i+j*currentgrid.X]->SetPre(false);
        }
    }
    uint32_t width = m->GetWidth(),height = m->GetHeight();
    uint32_t TP = m->GetTilePosition(GetPosition().GetX()+175,GetPosition().GetY(),width);
    uint32_t x = (TP%width),y = (TP-(TP%width))/height;
    CountXGrid(uint32X2(width,height),uint32X2(x,y),TP);
    CountYGrid(uint32X2(width,height),uint32X2(x,y),TP);
    for(uint32_t j = 0;j < currentgrid.Y;j++)
    {
        for(uint32_t i = 0;i < currentgrid.X;i++)
        {
            (*(grid+(i+j*currentgrid.X))) = &(*(tiles + (currentgridstart.X+i)+((currentgridstart.Y+j)*width)));
            grid[i+j*currentgrid.X]->SetPre(true);
        }
    }
}
void PreBuilding::CountXGrid(uint32X2 dim,uint32X2 pos,uint32_t TP)
{
    uint32_t Xl;
    if(floor(GetPosition().GetX()-175-(25))>=0)
       Xl = floor(GetPosition().GetX()-175-(25));
    else
        Xl = 0;
    uint32_t XL = (Xl-(Xl%20))/20;
    uint32_t Xr = floor(GetPosition().GetX()-175+(25));
    uint32_t XR = (Xr-(Xr%20))/20;
    currentgrid.X = 1+(pos.X-XL)+(XR-pos.X);
    currentgridstart.X = XL;
}
void PreBuilding::CountYGrid(uint32X2 dim,uint32X2 pos,uint32_t TP)
{
    uint32_t Yl = floor(GetPosition().GetY()-(25));
    uint32_t YL = (Yl-(Yl%20))/20;
    uint32_t Yr = floor(GetPosition().GetY()+(25));
    uint32_t YR = (Yr-(Yr%20))/20;
    currentgrid.Y = 1+(pos.Y-YL)+(YR-pos.Y);
    currentgridstart.Y = YL;
}
bool PreBuilding::FreeSpace()
{
    for(uint32_t i = 0;i < currentgrid.X*currentgrid.Y;i++)
    {
        if(!grid[i]->IsPre()||grid[i]->IsFree())
            return false;
    }
    return true;
}

void PreBuilding::Step()
{
    //Markable::SetSelectedType(4);
    Position pos = MousePos();
    SetPosition(pos.GetX(),pos.GetY());
    shape.setPosition(Keyboard::MouseX(),Keyboard::MouseY());
    if(pos.GetX() != pervious.GetX()&&pos.GetY() != pervious.GetY())
    {
        RefreshGrid();
    }
    if(Keyboard::MousePW() && !wait)
    {
        Destroy();
        Markable::SetSelectedType(0);
    }
    else if(!(Keyboard::MouseX()<170)&&Keyboard::MouseLP()&&FreeSpace()&&TileCheck())
    {
        object->SetPosition(pos.GetX(),pos.GetY());
        AddObject a;
        a.Add(object);
        Destroy();
        Markable::SetSelectedType(5);
    }
    wait = false;
}
void PreBuilding::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shape,states);
}
