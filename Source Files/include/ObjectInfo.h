#ifndef OBJECTINFO_H
#define OBJECTINFO_H

#include "../Anoyher/MainControler.hpp"
#include "GUIObjectInfoElement.h"
#include <list>

class GUIObjectInfoElement;

class ObjectInfo
{
    public:
        ObjectInfo();
        virtual ~ObjectInfo();
        virtual GUIObjectInfoElement * Create(Position);
    protected:
    private:
};

class OIPicture:public ObjectInfo
{
    Position wAh;
    sf::Color col;
    sf::Texture & tex;
public:
    OIPicture(Position,sf::Color,sf::Texture&);
    virtual GUIObjectInfoElement * Create(Position);

    Position GetWah();
    sf::Color GetCol();
    sf::Texture & GetTexture();
};

class OIText:public ObjectInfo
{
    Position wAh;
    sf::Color col;
    std::string str;
public:
    OIText(Position,sf::Color,std::string);
    virtual GUIObjectInfoElement * Create(Position);

    Position GetWah();
    sf::Color GetCol();
    std::string GetStr();
};

class OINumber:public ObjectInfo
{
    Position wAh;
    sf::Color col;
    int32_t num;
public:
    OINumber(Position,sf::Color,int32_t);
    virtual GUIObjectInfoElement * Create(Position);
};

class OIPointedu32:public ObjectInfo
{
    uint32_t_pointer * poi;
    OINumber num;
public:
    OIPointedu32(uint32_t_pointer*,OINumber);
    virtual GUIObjectInfoElement * Create(Position);
};

class OIPT:public ObjectInfo
{
    OIPicture pic;
    OIText tex;
public:
    OIPT(Position,sf::Color,sf::Texture&,Position,sf::Color,std::string);
    virtual GUIObjectInfoElement * Create(Position);

    OIPicture GetPic();
    OIText GetTex();
};


struct ObjectInfoStorage
{
    bool changed = false;
    std::list <ObjectInfo*> Information;
};

#endif // OBJECTINFO_H
