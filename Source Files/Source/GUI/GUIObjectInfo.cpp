#include "GUI.h"

GUIObjectInfo::GUIObjectInfo()
:Object(Position(0,500))
{
    physicshape = new Circle(1);
    mask = 0;
}

GUIObjectInfo::~GUIObjectInfo(){ClearElements();}

void GUIObjectInfo::Step()
{
    uint32_t height = 0;
    for(std::vector <GUIObjectInfoElement*>::iterator ite = Elements.begin();ite!=Elements.end();ite++)
    {
        (*ite)->ChangePosition(Position(position.GetX()+5,position.GetY()+10+height));
        height+=(*ite)->GetHeight()+5;
        (*ite)->Step();
    }
}
void GUIObjectInfo::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    for(uint32_t i = 0;i < Elements.size();i++)
    {
        Elements[i]->draw(target,states);
    }
}
void GUIObjectInfo::Refresh()
{
    uint32_t height = 0;
    if(Markable::MarkedObjectInfo.changed)
    {
        Markable::MarkedObjectInfo.changed = false;
        ClearElements();
        for(std::list <ObjectInfo*>::iterator ite = Markable::MarkedObjectInfo.Information.begin()
            ;ite!=Markable::MarkedObjectInfo.Information.end();)
        {
            GUIObjectInfoElement * obj = (*ite)->Create(Position(position.GetX()+5,
                                                                 position.GetY()+10+height));
            height+=obj->GetHeight()+5;
            Elements.push_back(obj);
            QuickDelete(ite);
        }
    }
    else if(Markable::GetSelectedType() == 0 ||(Keyboard::MouseLP() && !(Keyboard::MouseX()<170&&Keyboard::MouseY()>500)
             && Markable::GetSelectedType() != 4 && Markable::GetSelectedType() != 5))
    {
        ClearElements();
    }
}
void GUIObjectInfo::QuickDelete(std::list <ObjectInfo*>::iterator& ite)
{
    delete (*ite);
    ite = Markable::MarkedObjectInfo.Information.erase(ite);
}
void GUIObjectInfo::ClearElements()
{
    for(std::vector <GUIObjectInfoElement*>::iterator ite = Elements.begin();ite!=Elements.end();ite++)
        (*ite)->SetToDestroy();
    Elements.clear();
}

void GUIObjectInfo::SetPlayerFraction(uint32_t * f)
{
    PlayerFraction = f;
}

