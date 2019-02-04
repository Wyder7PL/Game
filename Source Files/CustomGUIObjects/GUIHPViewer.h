#ifndef GUIHPVIEWER_H
#define GUIHPVIEWER_H

#include "../include/ObjectInfo.h"

class GUIDoubleUint:public GUIObjectInfoElement
{
protected:
    uint32_t_pointer * first;
    uint32_t_pointer * second;
public:
    GUIDoubleUint(uint32_t_pointer*,uint32_t_pointer*);
    virtual ~GUIDoubleUint();
    virtual void Istep();
    virtual void Idraw(sf::RenderTarget & target,sf::RenderStates states);
    virtual void Step()=0;
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const=0;
};

class OIDoubleUint:public ObjectInfo
{
    uint32_t_pointer * poi1;
    uint32_t_pointer * poi2;
public:
    OIDoubleUint(uint32_t_pointer*,uint32_t_pointer*);
    uint32_t_pointer * GetFirst();
    uint32_t_pointer * GetSecond();
};

class GUIHPViewer:public Object,public GUIDoubleUint
{
    sf::Text shlash;
    public:
        GUIHPViewer(Position,/*sf::RectangleShape,*/uint32_t_pointer*,uint32_t_pointer*);
        virtual ~GUIHPViewer();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
        virtual void ChangePosition(Position);
        virtual uint32_t GetHeight();
        virtual void SetToDestroy();
    protected:
    private:
    std::string U32PToString(uint32_t_pointer*);
};

class OIHPViewer:public OIDoubleUint
{
public:
    OIHPViewer(uint32_t_pointer*,uint32_t_pointer*);
    virtual GUIObjectInfoElement * Create(Position);
};

class GUIBar:public Object,public GUIDoubleUint
{
    float BarWidth;
    sf::RectangleShape bar;
    sf::RectangleShape frame;
    public:
        GUIBar(Position,float,sf::Color,uint32_t_pointer*,uint32_t_pointer*);
        virtual ~GUIBar();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
        virtual void ChangePosition(Position);
        virtual uint32_t GetHeight();
        virtual void SetToDestroy();
    protected:
    private:
    std::string U32PToString(uint32_t_pointer*);
};

class OIBar:public OIDoubleUint
{
    sf::Color col;
    float width;
public:
    OIBar(uint32_t_pointer*,uint32_t_pointer*,sf::Color,float);
    virtual GUIObjectInfoElement * Create(Position);
};

#endif // GUIHPVIEWER_H
