#include "../include/Markable.h"

Info::Info()
:position(0,0),shapesize(0,0)
{

}

uint32_t Markable::SelectedType = 0;

uint32_t Markable::GetSelectedType()
{
    return Markable::SelectedType;
}

void Markable::SetSelectedType(uint32_t type)
{
    Markable::SelectedType = type;
}

void Markable::RestartSelectedType()
{
    if(Markable::SelectedType == 5)
        Markable::SelectedType = 3;
}

ObjectInfoStorage Markable::MarkedObjectInfo;

Markable::Markable(Position pos)
:Object(pos),firststep(true)
{
    PhysicObject::SetPosition(pos.GetX(),pos.GetY());
    SetZIndex(5);
    selected = false;
}

Markable::~Markable()
{
    //dtor
}
uint32_t Markable::GetFraction(){return 0;}

void Markable::Step(){if(FirstStep()){firststep = false;}}
void Markable::draw(sf::RenderTarget & target,sf::RenderStates states) const{}

void Markable::DealDamage(uint32_t d,uint32_t t){}

void Markable::CreateInfo(std::list <Info>& Objects){}

bool Markable::FirstStep(){return firststep;}

Slot::Slot()
:type(0),reserved(false),FirstHour(true)
{
    Occupant = NULL;
}

TileOccupy::TileOccupy():grid(NULL){}
TileOccupy::~TileOccupy()
{
    if(grid!=NULL)
    {
        for(uint32_t i = 0;i < currentgrid.X*currentgrid.Y;i++)
            grid[i]->SetFree(false);
        delete[] grid;
    }
}
bool TileOccupy::SetGrid(Position pos,Position shape)
{
    Map * m = Map::ActualMap;
    Tile * tiles = m->GetTiles();

    uint32_t width = m->GetWidth(),height = m->GetHeight();
    uint32_t TP = m->GetTilePosition(pos.GetX()+175,pos.GetY(),width);
    if(m->IsSomethingNoYes())
        return true;
    uint32_t x = (TP%width),y = (TP-(TP%width))/height;
    CountXGrid(pos,shape,uint32X2(width,height),uint32X2(x,y));
    CountYGrid(pos,shape,uint32X2(width,height),uint32X2(x,y));
    if(currentgrid.Y >= height||currentgrid.X >= width)
        return true;
    for(uint32_t j = 0;j < currentgrid.Y;j++)
    {
        for(uint32_t i = 0;i < currentgrid.X;i++)
        {
            if((tiles + (currentgridstart.X+i)+((currentgridstart.Y+j)*width))->IsFree())
                return true;
        }
    }
    grid = new Tile*[ currentgrid.X*currentgrid.Y];
    for(uint32_t j = 0;j < currentgrid.Y;j++)
    {
        if(j >= height)
            return true;
        for(uint32_t i = 0;i < currentgrid.X;i++)
        {
            if(i >= width)
                return true;
            (*(grid+(i+j*currentgrid.X))) = &(*(tiles + (currentgridstart.X+i)+((currentgridstart.Y+j)*width)));
            grid[i+j*currentgrid.X]->SetFree(true);
        }
    }
    return false;
}
void TileOccupy::CountXGrid(Position pos,Position shape,uint32X2 dim,uint32X2 tilepos)
{
    uint32_t Xl;
    if(floor(pos.GetX()-175-(25))>=0)
       Xl = floor(pos.GetX()-175-(shape.GetX()/2));
    else
        Xl = 0;
    uint32_t XL = (Xl-(Xl%20))/20;
    uint32_t Xr = floor(pos.GetX()-175+(shape.GetX()/2));
    uint32_t XR = (Xr-(Xr%20))/20;
    currentgrid.X = 1+(tilepos.X-XL)+(XR-tilepos.X);
    currentgridstart.X = XL;
}
void TileOccupy::CountYGrid(Position pos,Position shape,uint32X2 dim,uint32X2 tilepos)
{
    uint32_t Yl = floor(pos.GetY()-(shape.GetY()/2));
    uint32_t YL = (Yl-(Yl%20))/20;
    uint32_t Yr = floor(pos.GetY()+(shape.GetY()/2));
    uint32_t YR = (Yr-(Yr%20))/20;
    currentgrid.Y = 1+(tilepos.Y-YL)+(YR-tilepos.Y);
    currentgridstart.Y = YL;
}

NonClickable::NonClickable(Position pos)
:Markable(pos)
{

}
NonClickable::~NonClickable(){}

Clickable1::Clickable1(Position pos)
:Markable(pos),pressed(false)
{

}
Clickable1::~Clickable1(){}

void Clickable1::Step()
{
    bool wait = false;
    if(!pressed)
    {
        if(Keyboard::MouseLW() && InArea( MousePos() ) )
            pressed = true;
    }
    else if(Keyboard::MouseLP() &&((1 << GetSelectedType()) & ( (1<<4) + (1<<6) + (1<<7))) == 0)
    {
        pressed = false;
        if(InArea( MousePos()))
        {
            selected = true;
            this->Selected();
            wait = true;
        }
    }
    if(selected && !wait && Keyboard::MouseLW()
                    && (!InArea( MousePos())
                         && !(Keyboard::MouseX()<170&&Keyboard::MouseY()>500) )
                         && (GetSelectedType() != 4 ||  GetSelectedType() == 5))
    {
        selected = false;
        this->Deselected();
    }

    Markable::Step();
}
void Clickable1::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Markable::draw(target,states);
}

void Clickable1::Deselected()
{
    SetSelectedType(0);
}

Clickable2::Clickable2(Position pos)
:Markable(pos),pressed(false)
{

}
Clickable2::~Clickable2(){}

void Clickable2::Step()
{
    if(!pressed)
    {
        if(Keyboard::MouseLW() && InArea( MousePos() ) )
            pressed = true;
    }
    else if(Keyboard::MouseLP())
    {
        pressed = false;
        if(InArea(MousePos()))
            this->Selected();
    }
    Markable::Step();
}
void Clickable2::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Markable::draw(target,states);
}

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



MultiUnitSelection * MarkUnit::MUS = NULL;

void MarkUnit::CreateMUS(MultiUnitSelection * m)
{
    MUS = m;
    AddObject add;
    add.Add(MUS);
}

MarkUnit::MarkUnit(Position pos)
:Markable(pos),pervious(false)
,ntm(false),ntmdenycooldown(0),Destination(0,0)
{
    mark.setRadius(20);
    mark.setOrigin(15,15);
    mark.setOutlineThickness(5);
    mark.setOutlineColor(sf::Color(150,150,150,100));
    mark.setFillColor(sf::Color(180,180,180));

    physicshape = new Circle(10);
    mask = 1;
}
MarkUnit::~MarkUnit()
{
    if(selected)
        MUS->decrease();
}

void MarkUnit::Step()
{
    if(MUS->AreSelected())
    {
        if(MUS->AfterSelect() && GetFraction() == 2 && MUS->InArea(position) && !pervious)
        {
            MUS->increase();
            pervious = true;
            selected = true;
        }
        if(selected && Keyboard::MousePP())
        {
            ntm = true;
            Destination = MousePos();
        }
        if(selected){
            uint32_t i = MUS->GetSkillTypeButtonState(),j = GetSkillType(),k = i&j;
            if(i!=0&&k==0)
                QuickDeselect();
        }
    }
    else if(pervious)
        QuickDeselect();

    if(position.distance(Destination)<30)
    {
        if(ntmdenycooldown>0)
            ntmdenycooldown--;
        else
            ntm = false;
    }


    mark.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    if(selected)
        mark.setOutlineColor(sf::Color(150,150,150));
    else
    mark.setOutlineColor(sf::Color(0,0,0,0));

    Markable::Step();
}
void MarkUnit::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Markable::draw(target,states);
    target.draw(mark,states);
}

void MarkUnit::MarkSize(float siz)
{
    mark.setRadius(siz);
    mark.setOrigin(siz,siz);
    mark.setOutlineThickness(5);
    mark.setOutlineColor(sf::Color(150,150,150));
}

void MarkUnit::CreateInfo(std::list<Info>& Objects)
{
    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 20;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}

void MarkUnit::Desactivate()
{
    Object::Desactivate();
    if(selected)
    {
        MUS->decrease();
        selected = false;
    }
}

bool MarkUnit::ForcedMove()
{
    return ntm;
}
Position MarkUnit::ForcedDestination()
{
    return Destination;
}
void MarkUnit::ForceDestination(Position pos)
{
    ntm = true;
    ntmdenycooldown = 5;
    Destination = pos;
}
void MarkUnit::QuickDeselect()
{
    pervious = false;
    selected = false;
    MUS->decrease();
}

MarkBuilding::MarkBuilding(Position pos)
:Clickable1(pos),TileOccupy()
{

}
MarkBuilding::~MarkBuilding()
{
    
}

void MarkBuilding::Step()
{


    if(FirstStep())
    {
        if(SetGrid(position,GetShape()->GetSize()))
            Destroy();
    }

    Clickable1::Step();

    mark.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    if(selected)
        mark.setOutlineColor(sf::Color(250,250,250,100));
    else
        mark.setOutlineColor(sf::Color(0,0,0,0));
}
void MarkBuilding::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable1::draw(target,states);
    target.draw(mark,states);
}

void MarkBuilding::Selected()
{
    Markable::SetSelectedType(1);
    Markable::MarkedObjectInfo.changed = true;

}

void MarkBuilding::MarkSize(float siz)
{
    mark.setRadius(siz);
    mark.setOrigin(siz,siz);
    mark.setOutlineThickness(5);
    mark.setOutlineColor(sf::Color(150,150,150,100));
    mark.setFillColor(sf::Color(0,0,0,0));
}

BlueprintButton::BlueprintButton(Position pos,uint32_t * f)
:Clickable1(pos)
{
    PlayerFraction = f;
    border.setSize(sf::Vector2f(20,20));
    //border.setOrigin(15,15);
    border.setFillColor(sf::Color(0,0,0,0));
    border.setOutlineThickness(5);
    border.setOutlineColor(sf::Color(30,30,30));
}
BlueprintButton::~BlueprintButton(){}

void BlueprintButton::Step()
{
    Position pos = PhysicObject::GetPosition();
    border.setPosition(sfLocalPos(pos));
    Clickable1::Step();
    if(!selected)
        border.setOutlineColor(sf::Color(30,30,30));
}
void BlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(border,states);
}

void BlueprintButton::Selected()
{
    Markable::SetSelectedType(3);
    Markable::MarkedObjectInfo.changed = true;
    border.setOutlineColor(sf::Color(240,240,240));
}