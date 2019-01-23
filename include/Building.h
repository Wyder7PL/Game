#ifndef BUILDING_H
#define BUILDING_H

#include "Construction.h"
#include "GUIObjectCreateButton.h"
#include "SafePointer.h"
#include "../CustomGUIObjects/GUIHPViewer.h"


class Collision:public EffectObject
{
    Position position;
public:
    Collision( uint32_t);
    virtual ~Collision();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
};

class Building:public MarkBuilding
{

    public:
        Building(Position,uint32_t);
        virtual ~Building();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
        virtual void Selected();
        virtual void DealDamage(uint32_t,uint32_t);
        uint32_t GetFraction();
        virtual void CreateInfo(std::list<Info>&);
    protected:
        uint32_t AllHP;
        uint32_t FullHP;
        uint32_t_pointer * GUIHPPoint;
        uint32_t_pointer * GUIMHPPoint;
        HP * OutHP;
        HP * InHP;
        void SetHPonGUI();

        uint32_t fraction;
        sf::Sprite mark;

        sf::RectangleShape shape;
    private:
};

class BuildingConstruction:public Construction
{

    sf::RectangleShape shape;
public:
    BuildingConstruction(Position,uint32_t=0);
    virtual ~BuildingConstruction();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void CreateInfo(std::list<Info>&);
    void TESTCreateDemand(uint32_t,uint32_t);
protected:
    virtual void Create();
};

class BuildingBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    BuildingBlueprintButton(Position,uint32_t*);
    virtual ~BuildingBlueprintButton();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};



#endif // BUILDING_H
