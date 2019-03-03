#include "Mine.h"

Mine::Mine(Position pos,uint32_t f)
:Building(pos,f),work(0),workdemand(1),emptyreserve(0)
{
    mark.setTexture(Textures::textures->Tmine);
    SlotPointer = new list_pointer(&RDV);
    Slot s;
    worker.push_back(s);
    for(std::list <Slot>::iterator ite = worker.begin();ite != worker.end();ite++)
    {
        RDV.push_back(&(*ite));
    }
    BarWork = new uint32_t_pointer(&work);
    BarWorkDemand = new uint32_t_pointer(&workdemand);
}
Mine::~Mine()
{
    SlotPointer->TurnOff();
    if((*worker.begin()).Occupant != NULL)
        delete (*worker.begin()).Occupant;
}
void Mine::Step()
{
    if(FirstStep())
    {
        switch(Map::ActualMap->GetTileType(position.GetX()-160,position.GetY()))
        {
        case 11:{materialtype=3;workdemand=300;break;}
        case 12:{materialtype=4;workdemand=500;break;}
        default:
            {Destroy();break;}
        }
    }
    if((*worker.begin()).Occupant != NULL)
    {
        if((*worker.begin()).FirstHour)
        {
            (*worker.begin()).FirstHour = false;
            emptyreserve = 0;
        }
        work++;
        if(work>workdemand)
        {
            Unit * u = dynamic_cast<Unit*>((*worker.begin()).Occupant);
            if(u!=NULL)
            {
                ResourceItem * r = new ResourceItem(1,materialtype);
                if(u->GiveItem(r))
                {
                    work = 0;
                    u->Activate();
                    AddObject add;
                    add.Add(u);
                    (*worker.begin()).Occupant = NULL;
                    (*worker.begin()).reserved = false;
                    (*worker.begin()).FirstHour = true;
                }
                else
                    delete r;
            }
        }
    }
    if((*worker.begin()).Occupant == NULL&&(*worker.begin()).reserved==true)
    {
        emptyreserve++;
        if(emptyreserve>=500)
        {
            emptyreserve = 0;
            (*worker.begin()).reserved = false;
        }
    }
    Building::Step();
}
void Mine::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 6;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    inf.lpointer = SlotPointer;
    Objects.push_back(inf);
}
void Mine::Selected()
{
    MarkBuilding::Selected();
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tmine,
                               Position(100,50),sf::Color(30,30,30),"Wooden Mine");
    Markable::MarkedObjectInfo.Information.push_back(obj);

    SetHPonGUI();

    OIBar * bar = new OIBar(BarWork,BarWorkDemand,sf::Color(130,80,30),150);
    Markable::MarkedObjectInfo.Information.push_back(bar);
}
