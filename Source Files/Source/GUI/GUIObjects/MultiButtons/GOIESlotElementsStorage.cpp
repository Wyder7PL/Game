#include "GOIESlotElementsStorage.h"

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
