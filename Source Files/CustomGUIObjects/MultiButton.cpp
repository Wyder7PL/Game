#include "MultiButton.h"


GOIESingleClickButton::GOIESingleClickButton(Position pos,Position dim,void_pointer * st,void_pointer * dis)
:Clickable2(pos),state(st),disabled(dis)
{
    physicshape = new NRR(dim);
    mask = 0;
    shape.setSize(sf::Vector2f(dim.GetX(),dim.GetY()));
    shape.setFillColor(sf::Color(190,90,90));
}
GOIESingleClickButton::GOIESingleClickButton(Position pos,Position dim,sf::Texture & t,void_pointer * st,void_pointer * dis)
:Clickable2(pos),state(st),disabled(dis)
{
    physicshape = new NRR(dim);
    mask = 0;
    shape.setSize(sf::Vector2f(dim.GetX(),dim.GetY()));
    shape.setFillColor(sf::Color(190,90,90));

    sprite.setTexture(t);
    sprite.setScale((dim.GetX()/100),(dim.GetY()/100));
}
void GOIESingleClickButton::Step()
{
    Clickable2::Step();
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    sprite.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    if((*reinterpret_cast<bool*>(disabled->GetPointer())))
       shape.setFillColor(sf::Color(130,50,50));
}
void GOIESingleClickButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable2::draw(target,states);
    target.draw(shape,states);
    target.draw(sprite,states);
}
uint32_t GOIESingleClickButton::GetHeight()
{
    return physicshape->GetSize().GetY();
}
void GOIESingleClickButton::SetToDestroy()
{
    Destroy();
}
void GOIESingleClickButton::ChangePosition(Position pos)
{
    position = pos;
}
void GOIESingleClickButton::Selected()
{
    if(!(*reinterpret_cast<bool*>(disabled->GetPointer())))
    {
        shape.setFillColor(sf::Color(150,50,50));
        (*reinterpret_cast<bool*>(state->GetPointer()))=true;
    }
}

GOIEMBSelectOneButton::GOIEMBSelectOneButton(Position pos,Position dim)
:Clickable2(pos),selected(false),disabled(false)
{
    shape.setSize(sf::Vector2f(dim.GetX(),dim.GetY()));
    shape.setFillColor(sf::Color(90,90,90));
    physicshape = new NRR(dim);
    mask = 0;
}
GOIEMBSelectOneButton::GOIEMBSelectOneButton(Position pos,Position dim,sf::Texture & t)
:Clickable2(pos),selected(false),disabled(false)
{
    shape.setSize(sf::Vector2f(dim.GetX(),dim.GetY()));
    shape.setFillColor(sf::Color(90,90,90));
    physicshape = new NRR(dim);
    mask = 0;
    sprite.setTexture(t);
    sprite.setScale((dim.GetX()/100),(dim.GetY()/100));
}
void GOIEMBSelectOneButton::Step()
{
    Clickable2::Step();
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    sprite.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void GOIEMBSelectOneButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable2::draw(target,states);
    target.draw(shape,states);
    target.draw(sprite,states);
}

void GOIEMBSelectOneButton::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEMBSelectOneButton::GetHeight()
{
    return shape.getSize().y;
}

void GOIEMBSelectOneButton::SetToDestroy()
{
    Destroy();
}
void GOIEMBSelectOneButton::Selected()
{
    if(!disabled)
    {
        shape.setFillColor(sf::Color(70,70,70));
        selected = true;
    }
}
bool GOIEMBSelectOneButton::IsSelected()
{
    return selected;
}
void GOIEMBSelectOneButton::Deselect()
{
    selected = false;
    shape.setFillColor(sf::Color(90,90,90));
}
void GOIEMBSelectOneButton::Disable(bool d)
{
    disabled = d;
    if(disabled)
        shape.setFillColor(sf::Color(50,50,50));
    else
        shape.setFillColor(sf::Color(90,90,90));
}

GOIEMBSelectOne::GOIEMBSelectOne(Position pos,Position dim,Position bdim,uint32_t bc,uint32_t_pointer * s)
:Object(pos),Selected(s),ButtonWidth(bdim.GetX())
{
    physicshape = new NRR(dim);
    mask = 0;
    for(uint32_t i = 0;i < bc;i++)
    {
        GOIEMBSelectOneButton * b = new GOIEMBSelectOneButton(Position(pos.GetX()+25*i+5,pos.GetX()+5),bdim);
        if(i+1==*Selected->GetPointer())
            b->Selected();
        Buttons.push_back(b);
    }
}
GOIEMBSelectOne::GOIEMBSelectOne(Position pos,Position dim,std::list<TextureReferenceIllusion> t,Position bdim,uint32_t bc,uint32_t_pointer * s)
:Object(pos),Selected(s),ButtonWidth(bdim.GetX())
{
    physicshape = new NRR(dim);
    mask = 0;
    std::list<TextureReferenceIllusion>::iterator ite = t.begin();
    for(uint32_t i = 0;i < bc;i++)
    {
        GOIEMBSelectOneButton * b;
        if(ite!=t.end())
            b = new GOIEMBSelectOneButton(Position(pos.GetX()+25*i+5,pos.GetX()+5),bdim,(*ite++).Ref);
        else
            b = new GOIEMBSelectOneButton(Position(pos.GetX()+25*i+5,pos.GetX()+5),bdim);
        if(i+1==*Selected->GetPointer())
            b->Selected();
        Buttons.push_back(b);
    }
}
GOIEMBSelectOne::~GOIEMBSelectOne()
{
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();)
    {
        delete (*ite);
        ite = Buttons.erase(ite);
    }
}
void GOIEMBSelectOne::Step()
{

    uint32_t i = 0;
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->SetPosition(position.GetX()+i*(ButtonWidth+5)+5,position.GetY()+5);
        (*ite)->Step();
        i++;
    }
    i = 1;
    for(std::list<GOIEMBSelectOneButton*>::const_iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        if((*ite)->IsSelected() && *Selected->GetPointer() != i)
        {
            DeselectAll();
            *Selected->GetPointer() = i;
            (*ite)->Selected();
            break;
        }
        i++;
    }
}
void GOIEMBSelectOne::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    for(std::list<GOIEMBSelectOneButton*>::const_iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->draw(target,states);
    }
}

void GOIEMBSelectOne::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEMBSelectOne::GetHeight()
{
    if(Buttons.size()>0)
        return (*Buttons.begin())->GetHeight()+5;
    return 0;
}

void GOIEMBSelectOne::SetToDestroy()
{
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->SetToDestroy();
    }
    Destroy();
}

void GOIEMBSelectOne::Disable(uint32_t b,bool s)
{
    if(b <= Buttons.size())
        (*(Buttons.begin()) + b-1)->Disable(s);
}

void GOIEMBSelectOne::DeselectAll()
{
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->Deselect();
    }
}


OIMBSelectOne::OIMBSelectOne(uint32_t buam,Position dim,Position bdim,uint32_t_pointer * sel)
:Selected(sel),ButtonsAmount(buam),Dimension(dim),ButtonDimension(bdim),triset(false){}
OIMBSelectOne::OIMBSelectOne(uint32_t buam,Position dim,std::list<TextureReferenceIllusion> t,Position bdim,uint32_t_pointer * sel)
:Selected(sel),ButtonsAmount(buam),Dimension(dim),ButtonDimension(bdim),TRI(t),triset(true){}
OIMBSelectOne::~OIMBSelectOne(){}
GUIObjectInfoElement * OIMBSelectOne::Create(Position pos)
{
    if(triset)
        return new GOIEMBSelectOne(pos,Dimension,TRI,ButtonDimension,ButtonsAmount,Selected);
    return new GOIEMBSelectOne(pos,Dimension,ButtonDimension,ButtonsAmount,Selected);
}
uint32_t OIMBSelectOne::GetButtonsAmount(){return ButtonsAmount;}
Position OIMBSelectOne::GetDimension()
{
    return Dimension;
}
Position OIMBSelectOne::GetButtonDimension()
{
    return ButtonDimension;
}
uint32_t_pointer* OIMBSelectOne::GetSelected()
{
    return Selected;
}
std::list<TextureReferenceIllusion> OIMBSelectOne::GetTRI()
{
    return TRI;
}
bool OIMBSelectOne::Gettriset()
{
    return triset;
}

GOIEMBClickandDo::GOIEMBClickandDo(Position pos,Position dim,Position bdim,uint32_t bc,uint32_t_pointer * s)
:GOIEMBSelectOne(pos,dim,bdim,bc,s){}
GOIEMBClickandDo::GOIEMBClickandDo(Position pos,Position dim,std::list<TextureReferenceIllusion> t,Position bdim,uint32_t bc,uint32_t_pointer * s)
:GOIEMBSelectOne(pos,dim,t,bdim,bc,s){}
void GOIEMBClickandDo::Step()
{

    uint32_t i = 0;
    DeselectAll();
    for(std::list<GOIEMBSelectOneButton*>::iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        (*ite)->SetPosition(position.GetX()+i*(ButtonWidth+5)+5,position.GetY()+5);
        (*ite)->Step();
        i++;
    }
    i = 1;
    *Selected->GetPointer() = 0;
    for(std::list<GOIEMBSelectOneButton*>::const_iterator ite = Buttons.begin();ite != Buttons.end();ite++)
    {
        if((*ite)->IsSelected())
        {
            *Selected->GetPointer() = i;
            (*ite)->Selected();
            break;
        }
        i++;
    }
}

OIMBClickandDo::OIMBClickandDo(uint32_t buam,Position dim,Position bdim,uint32_t_pointer * sel)
:OIMBSelectOne(buam,dim,bdim,sel){}
OIMBClickandDo::OIMBClickandDo(uint32_t buam,Position dim,std::list<TextureReferenceIllusion> t,Position bdim,uint32_t_pointer * sel)
:OIMBSelectOne(buam,dim,t,bdim,sel){}
OIMBClickandDo::~OIMBClickandDo(){}
GUIObjectInfoElement * OIMBClickandDo::Create(Position pos)
{
    if(Gettriset())
        return new GOIEMBClickandDo(pos,GetDimension(),GetTRI(),GetButtonDimension(),GetButtonsAmount(),GetSelected());
    return new GOIEMBClickandDo(pos,GetDimension(),GetButtonDimension(),GetButtonsAmount(),GetSelected());
}



///
void MUSGUICreate::GenerateGUIButtons()
{
    Afterselecte = false;
    Markable::SetSelectedType(1);
    Markable::MarkedObjectInfo.changed = true;
    OIMBClickandDo * multi = new OIMBClickandDo(3,Position(200,30),Position(30,30),GUISkilltpyeButtonPoint);
    Markable::MarkedObjectInfo.Information.push_back(multi);
    std::list <TextureReferenceIllusion> TRI;
    {
        TextureReferenceIllusion tri(Textures::textures->HoldOn);TRI.push_back(tri);
        TextureReferenceIllusion tr2(Textures::textures->Canel);TRI.push_back(tr2);
        TextureReferenceIllusion tr3(Textures::textures->Allow);TRI.push_back(tr3);
        TextureReferenceIllusion tr4(Textures::textures->Enter);TRI.push_back(tr4);
    }
    multi = new OIMBClickandDo(4,Position(200,20),TRI,Position(40,40),GUICommonOrderButtonPoint);
    Markable::MarkedObjectInfo.Information.push_back(multi);
    TRI.clear();
    TextureReferenceIllusion tri(Textures::textures->DontIgnore);TRI.push_back(tri);
    TextureReferenceIllusion tr2(Textures::textures->Ignore);TRI.push_back(tr2);
    multi = new OIMBClickandDo(2,Position(200,20),TRI,Position(40,40),GUIEnemyIgnorePoint);
    Markable::MarkedObjectInfo.Information.push_back(multi);

}
///


GOIEDropDown::GOIEDropDown(Position pos,Position dim,void_pointer * l)
:Object(pos),Elements(l)
{
    physicshape = new NRR(dim);
    mask = 0;
}
GOIEDropDown::~GOIEDropDown(){}
void GOIEDropDown::Step()
{
    if(Elements==NULL||Elements->DestroyMe())
    {
        Destroy();
        return;
    }
    uint32_t height = 0;
    std::list <GUIObjectInfoElement*> * s = &(*(reinterpret_cast<std::list <GUIObjectInfoElement*>*>(Elements->GetPointer())));
    for(std::list <GUIObjectInfoElement*>::iterator ite = s->begin();ite != s->end();ite++)
    {
        (*ite)->ChangePosition(Position(position.GetX()+5,position.GetY()+5+height));
        (*ite)->Istep();
        height += (*ite)->GetHeight()+5;
    }
}
void GOIEDropDown::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    std::list <GUIObjectInfoElement*> * s = &(*(reinterpret_cast<std::list <GUIObjectInfoElement*>*>(Elements->GetPointer())));
    for(std::list <GUIObjectInfoElement*>::const_iterator ite = s->begin();ite != s->end();ite++)
    {
        (*ite)->Idraw(target,states);
    }
}

void GOIEDropDown::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEDropDown::GetHeight()
{
    if(Elements==NULL||Elements->DestroyMe())
    {
        Destroy();
        return 0;
    }
    uint32_t height = 0;
    std::list <GUIObjectInfoElement*> * s = &(*(reinterpret_cast< std::list <GUIObjectInfoElement*>* >(Elements->GetPointer())));
    for(std::list <GUIObjectInfoElement*>::iterator ite = s->begin();ite != s->end();ite++)
    {
        height += (*ite)->GetHeight();
    }
    return height;
}

void GOIEDropDown::SetToDestroy()
{
    Destroy();
}



OIDropDown::OIDropDown(Position dim,void_pointer * ele)
:Elements(ele),Dimension(dim){}
GUIObjectInfoElement * OIDropDown::Create(Position pos)
{
    return new GOIEDropDown(pos,Dimension,Elements);
}




GOIESlotElement::GOIESlotElement(Position pos,void_pointer*poi1,void_pointer*poi2)
:Object(pos),kick(pos,Position(40,40),Textures::textures->Exit,poi1,poi2)
{
    Constructor();
}
GOIESlotElement::GOIESlotElement(Position pos,const sf::Texture&t,void_pointer*poi1,void_pointer*poi2)
:Object(pos),kick(pos,Position(40,40),Textures::textures->Exit,poi1,poi2)
{
    Constructor();
    item.setTexture(t);
    item.scale(0.4,0.4);
}
void GOIESlotElement::Constructor()
{
    border.setSize(sf::Vector2f(40,92));
    border.setFillColor(sf::Color(0,0,0,0));
    border.setOrigin(2,2);
    border.setOutlineColor(sf::Color(0,0,0));
    border.setOutlineThickness(2);

}
void GOIESlotElement::Step()
{
    Position pos = LocalPos(PhysicObject::GetPosition());
    border.setPosition(pos.GetX(),pos.GetY());
    item.setPosition(pos.GetX(),pos.GetY());
    kick.SetPosition(position.GetX(),position.GetY()+50);
    kick.Step();
}
void GOIESlotElement::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(border,states);
    target.draw(item,states);
    kick.draw(target,states);
}
uint32_t GOIESlotElement::GetHeight()
{
    return 90;
}
void GOIESlotElement::ChangePosition(Position pos)
{
    position = pos;
}
void GOIESlotElement::SetToDestroy()
{
    Destroy();
    kick.SetToDestroy();
}


GOIESlotElementsStorage::GOIESlotElementsStorage(Position pos,std::list<void_pointer*> voi,std::list<CTextureReferenceIllusion> tri)
:Object(pos)
{
    std::list <CTextureReferenceIllusion>::iterator ite2 = tri.begin();
    for(std::list <void_pointer*>::iterator ite = voi.begin();ite != voi.end();)
    {
        if(ite2!=tri.end())
        {
            std::list <void_pointer*>::iterator tmpite = ite;ite++;
            GOIESlotElement * gse = new GOIESlotElement(pos,(*ite2++).Ref,(*tmpite),(*ite));ite++;
            Slots.push_back(gse);
        }
        else
            Slots.push_back(new GOIESlotElement(pos,(*ite++),(*ite++)));
    }

}
GOIESlotElementsStorage::~GOIESlotElementsStorage()
{
    for(std::list <GOIESlotElement*>::iterator ite = Slots.begin();ite != Slots.end();ite++)
        delete (*ite);
}
void GOIESlotElementsStorage::Step()
{
    uint32_t i = 0,j = 0;
    for(std::list <GOIESlotElement*>::iterator ite = Slots.begin();ite != Slots.end();ite++)
    {
        (*ite)->SetPosition(position.GetX()+i*42,position.GetY()+j*90);
        (*ite)->Step();
        i++;
        if(i==4)
        {
            i=0;j++;
        }
    }
}
void GOIESlotElementsStorage::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    for(std::list <GOIESlotElement*>::const_iterator ite = Slots.begin();ite != Slots.end();ite++)
        (*ite)->draw(target,states);
}
uint32_t GOIESlotElementsStorage::GetHeight()
{
    uint32_t temp = Slots.size();
    return 90*( (temp-(temp%4))/4 );
}
void GOIESlotElementsStorage::ChangePosition(Position pos)
{
    position = pos;
}
void GOIESlotElementsStorage::SetToDestroy()
{
    Destroy();
    for(std::list <GOIESlotElement*>::iterator ite = Slots.begin();ite != Slots.end();ite++)
        (*ite)->SetToDestroy();
}


OISlotElementsStorage::OISlotElementsStorage(std::list<void_pointer*> poi,std::list<CTextureReferenceIllusion> tex)
:pointers(poi),textures(tex){}
GUIObjectInfoElement * OISlotElementsStorage::Create(Position pos)
{
    return new GOIESlotElementsStorage(pos,pointers,textures);
}
