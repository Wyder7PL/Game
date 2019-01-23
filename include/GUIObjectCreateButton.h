#ifndef GUIOBJECTCREATEBUTTON_H
#define GUIOBJECTCREATEBUTTON_H

#include "PreBuilding.h"
#include "GUIObjectInfoElement.h"


class GOITESTCREATE:public Clickable2,public GUIObjectInfoElement
{
    GOIEText tex;
    uint32_t PlayerFraction;
public:
    GOITESTCREATE(Position,Position,GOIEText,uint32_t);
    virtual ~GOITESTCREATE();
    virtual void Istep();
    virtual void Idraw(sf::RenderTarget & target,sf::RenderStates states);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void Selected();
};

class OITest:public ObjectInfo
{
    OIText tex;
    uint32_t PlayerFraction;
public:
    virtual GUIObjectInfoElement * Create(Position);

    OITest(OIText,uint32_t);
    OIText GetTex();
};

#endif // GUIOBJECTCREATEBUTTON_H
