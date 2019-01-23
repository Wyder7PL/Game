#include "../include/GraphicControler.hpp"

ViewInfo::ViewInfo()
:width(0),height(0),x(0),y(0)
{

}
ViewInfo::~ViewInfo()
{

}
void ViewInfo::SetView(int32_t X,int32_t Y)
{
    x = X;
    y = Y;
}
void ViewInfo::MoveView(int32_t X,int32_t Y)
{
    SetView(x+X,y+Y);
}
int32_t ViewInfo::GetX()
{
    return x;
}
int32_t ViewInfo::GetY()
{
    return y;
}

ViewInfo GraphicControler::viewinfo;

GraphicControler::GraphicControler()
:Scena(sf::VideoMode(1024,768,32),"Anojy",sf::Style::Titlebar | sf::Style::Close)
{

}

GraphicControler::~GraphicControler()
{

    GraphicObjects.clear();
}

bool GraphicIndexComparation(GraphicObject * a,GraphicObject * b)
{
    return(a->GetZIndex() < b ->GetZIndex());
}

void GraphicControler::IndexSort()
{
    sort(GraphicObjects.begin(),GraphicObjects.end(),GraphicIndexComparation);
}

void GraphicControler::DrawEverything()
{
    IndexSort();
    Scena.clear(sf::Color(0,0,0));
    for(vector <GraphicObject*>::iterator ite = GraphicObjects.begin();ite != GraphicObjects.end();ite++)
    {
        Scena.draw(*(*ite));
    }
    Scena.display();
}

void GraphicControler::TESTCreateGraphic(GraphicObject * obj)
{
   GraphicObjects.push_back(obj);
}

void GraphicControler::ClearArray()
{
    for(vector <GraphicObject*>::iterator ite = GraphicObjects.begin();ite != GraphicObjects.end();)
    {
        if((*ite)->ToClear())
            ite = GraphicObjects.erase(ite);
        else
            ite++;
    }
}

void GraphicControler::SetKeyboard()
{
    key.SetWindow(&Scena);
    key.ResetKeys();
    key.SetKeys();
}

void GraphicControler::SetView(int32_t x,int32_t y)
{
    viewinfo.SetView(x,y);
}










