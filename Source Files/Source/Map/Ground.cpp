#include "Ground.h"

Ground::Ground()
:Object(Position(175,0)),ScreenWidth(42+2),ScreenHeight(38+2),maptiles(new Tile*[ScreenWidth*ScreenHeight]),moved(true)
{
    mask = 0;
    SetZIndex(3);

    ground = new sf::Sprite[ScreenWidth*ScreenHeight];//(sf::Vector2f(20,20))
    for(uint32_t i = 0;i < ScreenWidth*ScreenHeight;i++)
        shaders.push_back(NULL);

    if(!shader.loadFromFile("../../Graphic/Irontile.frag",sf::Shader::Fragment)){}
    if(!Gold.loadFromFile("../../Graphic/Goldtile.frag",sf::Shader::Fragment)){}
}

Ground::~Ground()
{
    delete[] maptiles;
    delete[] ground;
}

void Ground::SetDimensions(uint32X2 dim)
{
    float X = dim.X,Y = dim.Y;
    for(uint32_t i = 0;i < ScreenWidth*ScreenHeight;i++)
    {
        ground[i].setTexture(TextureTiles::tiles->NoTile);
    }
}
void Ground::SetMapTiles(Tile * tiles,uint32X2 dim)
{
    moved = true;
    PhysicObject::SetPosition(GraphicControler::viewinfo.GetX()+160,GraphicControler::viewinfo.GetY());
    Position LocalTilePos = GetPosition();
    LocalTilePos.SetX(LocalTilePos.GetX()-160);
    uint32_t currentTile = GetTilePosition(LocalTilePos,dim.X);
    for(uint32_t j = 0;j < ScreenHeight;j++)
    {
        if((currentTile-(currentTile%dim.X))/dim.X < dim.Y)
        {
            uint32_t buffer = 0,aaa = currentTile%dim.X;
            for(uint32_t i = 0;i < ScreenWidth;i++)
            {
                if(aaa < dim.X)
                    {*(maptiles+(i+j*ScreenWidth)) = &(*(tiles + currentTile+buffer));buffer++;}
                else
                    **(maptiles+(i+j*ScreenWidth)) = 555;
                aaa++;
            }
            currentTile+=(dim.X);
        }
        else
        {
            for(uint32_t i = 0;i < ScreenWidth;i++)
            {
                **(maptiles+(i+j*ScreenWidth)) = 0;
                currentTile++;
            }
        }
    }
}

void Ground::Step()
{
        UpdateShaders();
        PhysicObject::SetPosition(GraphicControler::viewinfo.GetX()+160,GraphicControler::viewinfo.GetY());
        Position pos = GetPosition();
        uint32_t PPX = floor(pos.GetX()),PPY = floor(pos.GetY());
        float x = (PPX%20);
        float y = pos.GetY()-(PPY-(PPY%20));
        std::list<sf::Shader*>::iterator ite = shaders.begin();
        for(uint32_t j = 0;j < ScreenHeight;j++)
        {
            for(uint32_t i = 0;i < ScreenWidth;i++)
            {
                ground[i+j*ScreenWidth].setPosition(175+20*i-x,+20*j-y);
                if(Map::ActualMap->GetConSight()&&maptiles[i+j*ScreenWidth]->IsFree()||maptiles[i+j*ScreenWidth]->IsPre())
                {
                    (*ite) = NULL;
                    if(maptiles[i+j*ScreenWidth]->IsFree()&&maptiles[i+j*ScreenWidth]->IsPre())
                        ground[i+j*ScreenWidth].setTexture(TextureTiles::tiles->Red);
                    else if(maptiles[i+j*ScreenWidth]->IsPre())
                        ground[i+j*ScreenWidth].setTexture(TextureTiles::tiles->Yellow);
                    else
                        ground[i+j*ScreenWidth].setTexture(TextureTiles::tiles->Blue);
                }
                else{
                switch(maptiles[i+j*ScreenWidth]->Get())
                {
                case 1:
                    {
                        (*ite) = NULL;
                        ground[i+j*ScreenWidth].setTexture(TextureTiles::tiles->NoTile);

                        break;
                    }
                case 2:
                    {
                        (*ite) = NULL;
                        ground[i+j*ScreenWidth].setTexture(TextureTiles::tiles->GrassTile);
                        break;
                    }
                case 11:
                    {
                        (*ite) = &shader;
                        break;
                    }
                case 12:
                    {
                        (*ite) = &Gold;
                        break;
                    }
                default:
                    {
                        (*ite) = NULL;
                        ground[i+j*ScreenWidth].setColor(sf::Color(100,100,100));
                        break;
                    }
                }}
            ite++;
            }
        }

        moved = false;
}
void Ground::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    std::list<sf::Shader*>::const_iterator ite = shaders.begin();
    for(uint32_t i = 0;i < ScreenWidth*ScreenHeight;i++)
    {
        if((*ite)!=NULL)
        {
            (*ite)->setUniform("pos",ground[i].getPosition());
            target.draw(ground[i],(*ite));
        }
        else
            target.draw(ground[i],states);
        ite++;
    }
}

uint32_t Ground::GetTilePosition(Position pos,uint32_t width)
{
    uint32_t Xr = floor(pos.GetX());
    uint32_t X = (Xr-(Xr%20))/20;
    uint32_t Yr = floor(pos.GetY());
    uint32_t Y = (Yr-(Yr%20))/20;
    return X+Y*width;
}

void Ground::UpdateShaders()
{

}






