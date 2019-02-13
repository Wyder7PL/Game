#pragma once


#include "../Pointers/uint32_t_pointer.h"
#include "../Anoyher/Object.hpp"
#include "Markable.h"
#include "../Functions.h"

class MultiUnitSelection:public Object
{
    uint32_t SelectedCount;
    bool selecte;
    bool pressed;
    Position Begin;
    sf::RectangleShape shape;

    uint32_t GUISkilltpyeButton;
    uint32_t GUICommonOrderButton;
    uint32_t GUIEnemyIgnore;
protected:
    uint32_t_pointer * GUISkilltpyeButtonPoint;
    uint32_t_pointer * GUICommonOrderButtonPoint;
    uint32_t_pointer * GUIEnemyIgnorePoint;
    bool Afterselecte;
public:
    MultiUnitSelection();
    virtual ~MultiUnitSelection();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    uint32_t GetSelectedCount();
    bool AreSelected();
    bool AfterSelect();
    uint32_t GetSkillTypeButtonState();
    uint32_t GetCommonOrderButtonState();
    uint32_t GetIfEnemyIgnored();
private:
    Position AboveZero(Position);
    float LesserValue(float,float);
    friend class MarkUnit;
    friend class Unit;
    void increase();
    void decrease();
protected:
    virtual void GenerateGUIButtons()=0;
};
