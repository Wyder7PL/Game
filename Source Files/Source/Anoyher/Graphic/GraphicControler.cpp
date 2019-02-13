#include "GraphicControler.hpp"

ViewInfo GraphicControler::viewinfo;

GraphicControler::GraphicControler()
:Scene(sf::VideoMode(1024,768,32),"Anojy",sf::Style::Titlebar | sf::Style::Close)
{

}

GraphicControler::~GraphicControler()
{

    GraphicObjects.clear();
}

void GraphicControler::IndexSort()
{
    sort(GraphicObjects.begin(),GraphicObjects.end(),GraphicIndexComparation);
}

void GraphicControler::DrawEverything()
{
    IndexSort();
    Scene.clear(sf::Color(0,0,0));
    for(std::vector <GraphicObject*>::iterator ite = GraphicObjects.begin();ite != GraphicObjects.end();ite++)
    {
        Scene.draw(*(*ite));
    }
    Scene.display();
}

void GraphicControler::TESTCreateGraphic(GraphicObject * obj)
{
   GraphicObjects.push_back(obj);
}

void GraphicControler::ClearArray()
{
    for(std::vector <GraphicObject*>::iterator ite = GraphicObjects.begin();ite != GraphicObjects.end();)
    {
        if((*ite)->ToClear())
            ite = GraphicObjects.erase(ite);
        else
            ite++;
    }
}

void GraphicControler::SetKeyboard()
{
    key.SetWindow(&Scene);
    key.ResetKeys();
    key.SetKeys();
}

void GraphicControler::SetView(int32_t x,int32_t y)
{
    viewinfo.SetView(x,y);
}




bool GraphicIndexComparation(GraphicObject * a,GraphicObject * b)
{
    return(a->GetZIndex() < b ->GetZIndex());
}






