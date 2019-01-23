#include "../include/GUI.h"

ResourceInfo::ResourceInfo(Position pos)
:Object(pos),Value(Position(pos.GetX()+30,pos.GetY()+5),Position(50,20),sf::Color(30,30,30))
{
    resource.setSize(sf::Vector2f(20,20));
    resource.setOrigin(10,10);
    resource.setFillColor(sf::Color(100,0,0));

    resource2.setOrigin(50,50);
    resource2.setScale(0.2,0.2);


    physicshape = new Circle(1);
    mask = 0;
}
ResourceInfo::~ResourceInfo(){}
void ResourceInfo::Step()
{
    Value.SetPosition(position.GetX()+30,position.GetY()+5);
    Position pos = LocalPos(position);
    resource.setPosition(pos.GetX()+15,pos.GetY()+15);
    resource2.setPosition(pos.GetX()+15,pos.GetY()+15);
    Value.Step();
}
void ResourceInfo::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(resource,states);
    target.draw(resource2,states);
    Value.draw(target,states);
}

void ResourceInfo::SetAmount(int32_t a)
{
    Value.SetNumber(a);
}
void ResourceInfo::SetTexture(sf::Texture&t)
{
    resource2.setTexture(t);
}

GUIResource::GUIResource()
:Object(Position(0,0)),wood(Position(0,0)),stone(Position(80,0)),
iron(Position(0,0)),gold(Position(80,0)),
residens(Position(0,0)),maxresidens(Position(0,0))
{
    wood.SetTexture(Textures::textures->Wood);
    stone.SetTexture(Textures::textures->Stone);
    iron.SetTexture(Textures::textures->Iron);
    gold.SetTexture(Textures::textures->Gold);
    residens.SetTexture(Textures::textures->Occupants);
    maxresidens.SetTexture(Textures::textures->MaxOccupants);
}
GUIResource::~GUIResource(){}
void GUIResource::Step()
{
    wood.SetPosition(position.GetX(),position.GetY());
    wood.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetEco()->GEE(1)->GetAmount());
    wood.Step();
    stone.SetPosition(position.GetX()+80,position.GetY());
    stone.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetEco()->GEE(2)->GetAmount());
    stone.Step();
    iron.SetPosition(position.GetX(),position.GetY()+25);
    iron.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetEco()->GEE(3)->GetAmount());
    iron.Step();
    gold.SetPosition(position.GetX()+80,position.GetY()+25);
    gold.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetEco()->GEE(4)->GetAmount());
    gold.Step();
    residens.SetPosition(position.GetX(),position.GetY()+50);
    residens.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetResidents());
    residens.Step();
    maxresidens.SetPosition(position.GetX()+80,position.GetY()+50);
    maxresidens.SetAmount((*Fraction::Fractions)[*PlayerFraction]->GetMaxResidents());
    maxresidens.Step();
}
void GUIResource::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    wood.draw(target,states);
    stone.draw(target,states);
    iron.draw(target,states);
    gold.draw(target,states);
    residens.draw(target,states);
    maxresidens.draw(target,states);
}
void GUIResource::SetPlayerFraction(uint32_t * f)
{
    PlayerFraction = f;
}

GUIBlueprintButton::GUIBlueprintButton()
:Object(Position(0,250))
{
    physicshape = new Circle(1);
    mask = 0;
}

GUIBlueprintButton::~GUIBlueprintButton()
{
    for(vector <BlueprintButton*>::iterator ite = Buttons.begin();ite!=Buttons.end();ite++)
        delete (*ite);
    Buttons.clear();
}

void GUIBlueprintButton::Step()
{
    uint32_t i = 0,j = 0;
    for(vector <BlueprintButton*>::iterator ite = Buttons.begin();ite!=Buttons.end();ite++)
    {
        (*ite)->SetPosition(position.GetX()+30+i*50,position.GetY()+30+j*70);
        (*ite)->Step();
        i++;
        if(i == 3)
        {
            i = 0;j++;
        }
    }
}

void GUIBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    for(uint32_t i = 0;i < Buttons.size();i++)
    {
        Buttons[i]->draw(target,states);
    }
}

void GUIBlueprintButton::SetPlayerFraction(uint32_t * f)
{
    PlayerFraction = f;
}

void GUIBlueprintButton::SetButtons()
{
    for(vector <BlueprintButton*>::iterator ite = Buttons.begin();ite!=Buttons.end();ite++)
        delete (*ite);
    Buttons.clear();
    for(uint32_t j = 0;j < 3;j++)
    {
        for(uint32_t i = 0;i < 3;i++)
        {
            if(j==0)
            {
                if(i==0)
                {
                    BlueprintButton * obj = new MagazineBlueprintButton( Position(20+i*50,280+j*50),PlayerFraction );
                    Buttons.push_back(obj);
                    continue;
                }
                if(i==1)
                {
                    BlueprintButton * obj = new TavernBlueprintButton( Position(20+i*50,280+j*50),PlayerFraction );
                    Buttons.push_back(obj);
                    continue;
                }
                BlueprintButton * obj = new HouseBlueprintButton( Position(20+i*50,280+j*50),PlayerFraction );
                Buttons.push_back(obj);
                continue;
            }
            if(j==1)
            {
                if(i==0)
                {
                    BlueprintButton * obj = new MineBlueprintButton( Position(20+i*50,280+j*50),PlayerFraction );
                    Buttons.push_back(obj);
                    continue;
                }
                if(i==1)
                {
                    BlueprintButton * obj = new WorkshopBlueprintButton( Position(20+i*50,280+j*50),PlayerFraction );
                    Buttons.push_back(obj);
                    continue;
                }
                BlueprintButton * obj = new ForesterBlueprintButton( Position(20+i*50,280+j*50),PlayerFraction );
                Buttons.push_back(obj);
                continue;
            }

            if(i == 0)
            {
                BlueprintButton * obj = new TowerBlueprintButton( Position(20+i*50,280+j*50),PlayerFraction );
                Buttons.push_back(obj);
            }
        }
    }

}

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
    for(vector <GUIObjectInfoElement*>::iterator ite = Elements.begin();ite!=Elements.end();ite++)
    {
        (*ite)->ChangePosition(Position(position.GetX()+5,position.GetY()+10+height));
        height+=(*ite)->GetHeight()+5;
        (*ite)->Istep();
    }
}
void GUIObjectInfo::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    for(uint32_t i = 0;i < Elements.size();i++)
    {
        Elements[i]->Idraw(target,states);
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
    for(vector <GUIObjectInfoElement*>::iterator ite = Elements.begin();ite!=Elements.end();ite++)
        (*ite)->SetToDestroy();
    Elements.clear();
}

void GUIObjectInfo::SetPlayerFraction(uint32_t * f)
{
    PlayerFraction = f;
}


GUI::GUI()
:Object(Position(0,0))
{
    SetZIndex(7);
    SetPlayerFraction(2);
    ConnectFractionToObjects();

    BlueprintButtons.SetButtons();

    background.setSize(sf::Vector2f(175,786));
    background.setFillColor(sf::Color(50,50,50));

    for(uint32_t i = 0;i < 2;i++)
    {
        lines[i].setSize(sf::Vector2f(155,2));
        lines[i].setFillColor(sf::Color(0,0,0));
    }


    physicshape = new Circle(50);
    mask = 0;
}

GUI::~GUI()
{
    DestroyElements();
}

void GUI::DestroyElements()
{

}

void GUI::Step()
{
    PhysicObject::SetPosition(GraphicControler::viewinfo.GetX(),GraphicControler::viewinfo.GetY());
    Position pos = PhysicObject::GetPosition();
    background.setPosition(sfLocalPos(pos));
    for(uint32_t i = 0;i < 2;i++)
    {
        lines[i].setPosition(10+sfLocalPos(pos).x,
                             250+i*250+sfLocalPos(pos).y);
    }
    Resources.SetPosition(pos.GetX(),pos.GetY());
    Resources.Step();

    BlueprintButtons.SetPosition(pos.GetX(),pos.GetY()+250);
    BlueprintButtons.Step();

    ObjectsInfo.SetPosition(pos.GetX(),pos.GetY()+500);
    ObjectsInfo.Step();
}
void GUI::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(background,states);
    target.draw(lines[0],states);
    target.draw(lines[1],states);

    Resources.draw(target,states);
    BlueprintButtons.draw(target,states);
    ObjectsInfo.draw(target,states);
}

void GUI::Refresh()
{
    ObjectsInfo.Refresh();
}

void GUI::SetPlayerFraction(uint32_t f)
{
    PlayerFraction = f;
}

void GUI::ConnectFractionToObjects()
{
    Resources.SetPlayerFraction(&PlayerFraction);
    BlueprintButtons.SetPlayerFraction(&PlayerFraction);
    ObjectsInfo.SetPlayerFraction(&PlayerFraction);
}












