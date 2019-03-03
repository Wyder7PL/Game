#include "Keyboard.h"

int32_t Keyboard::mouseX=0;
int32_t Keyboard::mouseY=0;
bool Keyboard::mouseLW=false;
bool Keyboard::mouseLK=false;
bool Keyboard::mouseLP=false;
bool Keyboard::mouseLT=false;

bool Keyboard::mousePW=false;
bool Keyboard::mousePP=false;

bool Keyboard::up=false;
bool Keyboard::down=false;
bool Keyboard::left=false;
bool Keyboard::right=false;

bool Keyboard::exit=false;

bool Keyboard::f=false;
bool Keyboard::g=false;
bool Keyboard::i=false;

int16_t Keyboard::MouseX()
{
    return mouseX;
}
int16_t Keyboard::MouseY()
{
    return mouseY;
}
bool Keyboard::MouseLW()
{
    return mouseLW;
}
bool Keyboard::MouseLK()
{
    return mouseLK;
}
bool Keyboard::MouseLP()
{
    return mouseLP;
}
bool Keyboard::MousePW()
{
    return mousePW;
}
bool Keyboard::MousePP()
{
    return mousePP;
}
bool Keyboard::Up()
{
    return up;
}
bool Keyboard::Down()
{
    return down;
}
bool Keyboard::Left()
{
    return left;
}
bool Keyboard::Right()
{
    return right;
}
bool Keyboard::Exit()
{
    return exit;
}
bool Keyboard::F()
{
    return f;
}
bool Keyboard::G()
{
    return g;
}
bool Keyboard::I()
{
    return i;
}

Keyboard::Keyboard()
{

}
Keyboard::~Keyboard(){}

void Keyboard::SetWindow(sf::RenderWindow * Okno)
{
    okno = Okno;
}

void Keyboard::SetKeys()
{
    sf::Vector2i temp = sf::Mouse::getPosition(*okno);
    Keyboard::mouseX = temp.x;
    Keyboard::mouseY = temp.y;

    sf::Event ewa;
    while(okno->pollEvent(ewa))
    {
        if(ewa.type == sf::Event::MouseButtonPressed)
        {
            if(ewa.mouseButton.button == sf::Mouse::Left)
            {
                Keyboard::mouseLW = true;
                if(!Keyboard::mouseLT)
                    Keyboard::mouseLK = true;
                Keyboard::mouseLT = true;
            }
            if(ewa.mouseButton.button == sf::Mouse::Right)
            {
                Keyboard::mousePW = true;

            }
        }
        if(ewa.type == sf::Event::MouseButtonReleased)
        {
            if(ewa.mouseButton.button == sf::Mouse::Left)
            {
                Keyboard::mouseLW = false;
                Keyboard::mouseLP = true;
                Keyboard::mouseLT = false;
            }
            if(ewa.mouseButton.button == sf::Mouse::Right)
            {
                Keyboard::mousePW = false;
                Keyboard::mousePP = true;
            }
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){Keyboard::up=true;}else{Keyboard::up=false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){Keyboard::down=true;}else{Keyboard::down=false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){Keyboard::left=true;}else{Keyboard::left=false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){Keyboard::right=true;}else{Keyboard::right=false;}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){Keyboard::exit=true;}else{Keyboard::exit=false;}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){Keyboard::f=true;}else{Keyboard::f=false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){Keyboard::g=true;}else{Keyboard::g=false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){Keyboard::i=true;}else{Keyboard::i=false;}

}

void Keyboard::ResetKeys()
{
    if(Keyboard::mouseLP){Keyboard::mouseLP = false;}
    if(Keyboard::mousePP){Keyboard::mousePP = false;}
    if(Keyboard::mouseLT){Keyboard::mouseLK = false;}
}
