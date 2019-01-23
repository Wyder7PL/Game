#ifndef GUI_H
#define GUI_H

#include "GUIObjectCreateButton.h"
#include "../CustomBuildings/Tavern.h"

class ResourceInfo:public Object
{
    sf::RectangleShape resource;
    sf::Sprite resource2;
    GOIENumber Value;
public:
    ResourceInfo(Position);
    virtual ~ResourceInfo();

    void SetTexture(sf::Texture&);

    void Step();
    void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void SetAmount(int32_t);
};

class GUIResource:public Object
{
    ResourceInfo wood;
    ResourceInfo stone;
    ResourceInfo iron;
    ResourceInfo gold;
    ResourceInfo residens;
    ResourceInfo maxresidens;
    uint32_t * PlayerFraction;
public:
    GUIResource();
    virtual ~GUIResource();
    void Step();
    void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void SetPlayerFraction(uint32_t*);
};

class GUIBlueprintButton:public Object
{
    uint32_t * PlayerFraction;
    std::vector <BlueprintButton*> Buttons;
public:
    GUIBlueprintButton();
    virtual ~GUIBlueprintButton();
    void Step();
    void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void SetPlayerFraction(uint32_t*);
    void SetButtons();
};

class GUIObjectInfo:public Object
{
    uint32_t * PlayerFraction;
    vector <GUIObjectInfoElement*> Elements;
    void QuickDelete(std::list <ObjectInfo*>::iterator&);
    void ClearElements();
public:
    GUIObjectInfo();
    virtual ~GUIObjectInfo();
    void Step();
    void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void Refresh();
    void SetPlayerFraction(uint32_t*);

};

class GUI:public Object
{
    GUIResource Resources;
    GUIBlueprintButton BlueprintButtons;
    GUIObjectInfo ObjectsInfo;
    uint32_t PlayerFraction;
    sf::RectangleShape background;
    sf::RectangleShape lines[2];
    public:
        GUI();
        virtual ~GUI();
        void DestroyElements();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
        void Refresh();
        void SetPlayerFraction(uint32_t);

    protected:
    private:
        void ConnectFractionToObjects();
};

#endif // GUI_H
