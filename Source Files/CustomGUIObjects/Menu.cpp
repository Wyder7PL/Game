#include "Menu.h"

Menu::Menu():Object(Position(0,0)),levelbuttonstate(0)
{
    levelbuttonstatepointer = new uint32_t_pointer(&levelbuttonstate);
    levelbuttons = new GOIEMBClickandDo(Position(0,0),Position(310,1000),Position(300,100),3,levelbuttonstatepointer);

    background.setFillColor(sf::Color(100,100,100));
    background.setSize(sf::Vector2f(1024,786));

    sf::Text * t;
    for(uint32_t i = 0;i<3;i++)
    {
        t = new sf::Text;
        t->setCharacterSize(32);
        t->setFont(Fonts::SMB);
        t->setPosition(position.GetX()+10+i*310,position.GetY()+10);
        if(i==0)
            t->setString("Destroy Enemy");
        else if(i==1)
            t->setString("Offensive");
        else
            t->setString("Survive");
        ButtonDescription.push_back(t);
    }

}

Menu::~Menu()
{
    delete levelbuttons;
    delete levelbuttonstatepointer;
    for(std::list <sf::Text*>::iterator ite = ButtonDescription.begin();ite != ButtonDescription.end();ite++)
        delete (*ite);
}

void Menu::draw(sf::RenderTarget&target,sf::RenderStates states) const
{
    target.draw(background,states);
    levelbuttons->draw(target,states);
    for(std::list <sf::Text*>::const_iterator ite = ButtonDescription.begin();ite != ButtonDescription.end();ite++)
        target.draw(*(*ite),states);
}

void Menu::Step()
{
    levelbuttons->Step();
}

void Menu::SetToDestroy()
{
    Destroy();
}

uint32_t Menu::Get()
{
    return levelbuttonstate;
}
