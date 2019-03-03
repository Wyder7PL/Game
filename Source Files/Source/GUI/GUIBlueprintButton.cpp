#include "GUI.h"

GUIBlueprintButton::GUIBlueprintButton()
:Object(Position(0,250))
{
    physicshape = new Circle(1);
    mask = 0;
}

GUIBlueprintButton::~GUIBlueprintButton()
{
    for(std::vector <BlueprintButton*>::iterator ite = Buttons.begin();ite!=Buttons.end();ite++)
        delete (*ite);
    Buttons.clear();
}

void GUIBlueprintButton::Step()
{
    uint32_t i = 0,j = 0;
    for(std::vector <BlueprintButton*>::iterator ite = Buttons.begin();ite!=Buttons.end();ite++)
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
    for(std::vector <BlueprintButton*>::iterator ite = Buttons.begin();ite!=Buttons.end();ite++)
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

