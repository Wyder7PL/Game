#ifndef MULTIBUTTON_H
#define MULTIBUTTON_H

#include "../include/Markable.h"


class GOIESingleClickButton:public GOIEvirtual,public Clickable2
{
    sf::RectangleShape shape;
    sf::Sprite sprite;
    void_pointer * state;
    void_pointer * disabled;
public:
    GOIESingleClickButton(Position,Position,void_pointer*,void_pointer*);
    GOIESingleClickButton(Position,Position,sf::Texture&,void_pointer*,void_pointer*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void ChangePosition(Position);
    virtual void Selected();
};

class GOIEMBSelectOneButton:public GOIEvirtual,public Clickable2
{
    bool selected;
    sf::RectangleShape shape;
    sf::Sprite sprite;
    bool disabled;
public:
    GOIEMBSelectOneButton(Position,Position);
    GOIEMBSelectOneButton(Position,Position,sf::Texture&);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void ChangePosition(Position);
    virtual void Selected();
    bool IsSelected();
    void Deselect();
    void Disable(bool);
};

class GOIEMBSelectOne:public Object,public GOIEvirtual
{
protected:
    uint32_t_pointer * Selected;
    std::list <GOIEMBSelectOneButton*> Buttons;
    uint32_t ButtonWidth;
public:
    GOIEMBSelectOne(Position,Position,Position,uint32_t,uint32_t_pointer*);
    GOIEMBSelectOne(Position,Position,std::list<TextureReferenceIllusion>,Position,uint32_t,uint32_t_pointer*);
    virtual ~GOIEMBSelectOne();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void ChangePosition(Position);
    void Disable(uint32_t,bool);
protected:
    void DeselectAll();
};

class OIMBSelectOne:public ObjectInfo
{
    uint32_t_pointer * Selected;
    uint32_t ButtonsAmount;
    Position Dimension;
    Position ButtonDimension;
    std::list<TextureReferenceIllusion> TRI;
    bool triset;
public:
    OIMBSelectOne(uint32_t,Position,Position,uint32_t_pointer*);
    OIMBSelectOne(uint32_t,Position,std::list<TextureReferenceIllusion>,Position,uint32_t_pointer*);
    virtual ~OIMBSelectOne();
    virtual GUIObjectInfoElement * Create(Position);
protected:
    uint32_t GetButtonsAmount();
    Position GetDimension();
    Position GetButtonDimension();
    uint32_t_pointer* GetSelected();
    std::list<TextureReferenceIllusion> GetTRI();
    bool Gettriset();
};

class GOIEMBClickandDo:public GOIEMBSelectOne
{
public:
    GOIEMBClickandDo(Position,Position,Position,uint32_t,uint32_t_pointer*);
    GOIEMBClickandDo(Position,Position,std::list<TextureReferenceIllusion>,Position,uint32_t,uint32_t_pointer*);
    virtual void Step();
};

class OIMBClickandDo:public OIMBSelectOne
{
public:
    OIMBClickandDo(uint32_t,Position,Position,uint32_t_pointer*);
    OIMBClickandDo(uint32_t,Position,std::list<TextureReferenceIllusion>,Position,uint32_t_pointer*);
    virtual ~OIMBClickandDo();
    virtual GUIObjectInfoElement * Create(Position);
};

///
class MUSGUICreate:public MultiUnitSelection
{
public:
    virtual void GenerateGUIButtons();
};
///

class GOIEDropDown:public Object,public GOIEvirtual
{
    void_pointer * Elements;
public:
    GOIEDropDown(Position,Position,void_pointer*);
    virtual ~GOIEDropDown();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void ChangePosition(Position);
private:
};
class OIDropDown:public ObjectInfo
{
    void_pointer * Elements;
    Position Dimension;
public:
    OIDropDown(Position,void_pointer*);
    virtual GUIObjectInfoElement * Create(Position);
};

class GOIESlotElement:public Object,public GOIEvirtual
{
    sf::Sprite item;
    GOIESingleClickButton kick;
    sf::RectangleShape border;

    void Constructor();
public:
    GOIESlotElement(Position,void_pointer*,void_pointer*);
    GOIESlotElement(Position,const sf::Texture&,void_pointer*,void_pointer*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void ChangePosition(Position);
    virtual void SetToDestroy();
};

class GOIESlotElementsStorage:public Object,public GOIEvirtual
{
    std::list<GOIESlotElement*> Slots;
public:
    GOIESlotElementsStorage(Position,std::list<void_pointer*>,std::list<CTextureReferenceIllusion>);
    ~GOIESlotElementsStorage();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void ChangePosition(Position);
    virtual void SetToDestroy();
};

class OISlotElementsStorage:public ObjectInfo
{
    std::list<void_pointer*> pointers;
    std::list<CTextureReferenceIllusion> textures;
public:
    OISlotElementsStorage(std::list<void_pointer*>,std::list<CTextureReferenceIllusion>);
    virtual GUIObjectInfoElement * Create(Position);
};

#endif // MULTIBUTTON_H



