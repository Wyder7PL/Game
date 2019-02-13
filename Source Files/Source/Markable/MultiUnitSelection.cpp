#include "MultiUnitSelection.h"



MultiUnitSelection::MultiUnitSelection()
:Object(Position(0,0)),SelectedCount(0),selecte(false),Afterselecte(false),pressed(false)
,Begin(Position(0,0)),GUISkilltpyeButton(0),GUICommonOrderButton(0),GUIEnemyIgnore(0)
{
    physicshape = new NRR(Position(0,0));
    mask = 0;
    SetZIndex(7);
    shape.setFillColor(sf::Color(255,255,255,100));

    GUISkilltpyeButtonPoint = new uint32_t_pointer(&GUISkilltpyeButton);
    GUICommonOrderButtonPoint = new uint32_t_pointer(&GUICommonOrderButton);
    GUIEnemyIgnorePoint = new uint32_t_pointer(&GUIEnemyIgnore);
}
MultiUnitSelection::~MultiUnitSelection(){}
void MultiUnitSelection::Step()
{
    if(selecte)
    {
        if(Afterselecte)
            GenerateGUIButtons();
        if(SelectedCount == 0 || (Keyboard::MouseLW() && !(Keyboard::MouseX()<170&&Keyboard::MouseY()>500)) )
        {
            Markable::SetSelectedType(0);
            selecte = false;
        }
    }
    else
    {
        if(Markable::GetSelectedType()==0&&!pressed&&Keyboard::MouseLW())
        {
            Position MP = MousePos();
            Begin.Set(MP.GetX(),MP.GetY());
            pressed = true;
            shape.setSize(sf::Vector2f(0,0));
        }
        else if(pressed && Keyboard::MouseLP())
        {
            pressed = false;
            Position MP = MousePos();
            if(pow( pow(Begin.GetX()-MousePos().GetX(),2)
                        +pow(Begin.GetY()-MousePos().GetY(),2),0.5) > 15
                    && Markable::GetSelectedType()==6)
                {
                    selecte = true;
                    Afterselecte = true;
                    delete physicshape;
                    physicshape = new NRR( AboveZero(Position(MP.GetX()-Begin.GetX(),MP.GetY()-Begin.GetY())) );
                    SetPosition(LesserValue(Begin.GetX(),MP.GetX()) , LesserValue(Begin.GetY(),MP.GetY()));
                    Markable::SetSelectedType(7);
                    Markable::MarkedObjectInfo.changed = true;
                }

        }
        else if(!pressed&&Markable::GetSelectedType()==6)
            Markable::SetSelectedType(0);
        if(pressed&&pow( pow(Begin.GetX()-MousePos().GetX(),2)
                        +pow(Begin.GetY()-MousePos().GetY(),2),0.5) > 15)
        {
            Markable::SetSelectedType(6);
            shape.setPosition(sfLocalPos(Begin));
            Position MP = MousePos();
            shape.setSize(sf::Vector2f(MP.GetX()-Begin.GetX(),MP.GetY()-Begin.GetY()));
        }
    }

}
void MultiUnitSelection::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    if(pressed)
        target.draw(shape,states);
}
Position MultiUnitSelection::AboveZero(Position pos)
{
    if(pos.GetX() < 0)
        pos.SetX(pos.GetX()*-1);
    if(pos.GetY() < 0)
        pos.SetY(pos.GetY()*-1);
    return pos;
}

float MultiUnitSelection::LesserValue(float a,float b)
{
    if(a>b)
        return b;
    return a;
}

uint32_t MultiUnitSelection::GetSelectedCount()
{
    return SelectedCount;
}

bool MultiUnitSelection::AreSelected()
{
    return selecte;
}
bool MultiUnitSelection::AfterSelect()
{
    return Afterselecte;
}
uint32_t MultiUnitSelection::GetSkillTypeButtonState()
{
    if(GUISkilltpyeButton==0)
        return GUISkilltpyeButton;
    return 1<<(GUISkilltpyeButton-1);
}
uint32_t MultiUnitSelection::GetCommonOrderButtonState()
{
    return GUICommonOrderButton;
}
uint32_t MultiUnitSelection::GetIfEnemyIgnored()
{
    return GUIEnemyIgnore;
}
void MultiUnitSelection::increase()
{
    SelectedCount++;
}
void MultiUnitSelection::decrease()
{
    if(SelectedCount>0)
        SelectedCount--;
}
