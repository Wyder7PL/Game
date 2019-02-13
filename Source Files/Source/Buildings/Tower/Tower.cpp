#include "Tower.h"


BoolPointer::BoolPointer():variable(false){point = new void_pointer(&variable);}
BoolPointer::~BoolPointer(){delete point;}


Tower::Tower(Position pos,uint32_t f):Building(pos,f),Creature(f)
{
    mark.setTexture(Textures::textures->Ttower);
    for(uint32_t i = 0;i < 2;i++)
    {
        Slot s;
        shooter.push_back(s);
    }
    //shooter.push_back()
    SlotPointer = new list_pointer(&RDV);
    RDV.push_back(&shooter);


}
Tower::Tower(Position pos,uint32_t f,Unit*u1,Unit*u2)
:Tower(pos,f)
{
    std::list <Slot>::iterator ite = shooter.begin();
    if(u1!=NULL)
    {
        (*ite).Occupant = u1;
        (*ite).reserved = true;
    }
    ite++;
    if(u2!=NULL)
    {
        (*ite).Occupant = u2;
        (*ite).reserved = true;
    }
}
Tower::~Tower()
{
    if(SlotPointer->DestroyMe())
        delete SlotPointer;
    for(std::list <Slot>::iterator ite = shooter.begin();ite != shooter.end();ite++)
    {
        if((*ite).Occupant!=NULL)
            delete (*ite).Occupant;
    }
}
void Tower::Step()
{
    Building::Step();
    Unit * Occupants[2]={NULL,NULL};
    SeenRange = 0;
    uint32_t i = 0;
    bool reselect = false;
    for(std::list <Slot>::iterator ite = shooter.begin();ite != shooter.end();ite++)
    {
        if((*ite).Occupant!=NULL)
        {
            if(State[i].variable)
            {
                State[i].variable=false;
                reselect = true;
                Kick(ite);
                i++;
                continue;
            }
            Occupants[i]=dynamic_cast<Unit*>((*ite).Occupant);
            if(Occupants[i]!=NULL)
            {
                SingleShot * ss=dynamic_cast<SingleShot*>(Occupants[i]->GetActiveTool());
                if(ss!=NULL&&ss->GetRange()>SeenRange)
                    SeenRange = ss->GetRange();
            }
        }
        i++;
    }
    if(SeenRange>0&&Look(position))
    {
        float distance = 10000;
        Info * inf = GetNearest(distance,position);
        if(distance < 10000)
        {
            i=0;
            for(std::list <Slot>::iterator ite = shooter.begin();ite != shooter.end();ite++)
            {
                if(Occupants[i]==NULL){i++;continue;}

                SingleShot * singleshot = dynamic_cast<SingleShot*>(Occupants[i]->GetActiveTool());
                if(singleshot!=NULL)
                {
                    if(singleshot->GetActualReload()>0)
                        singleshot->Reload(100);
                    else
                        singleshot->Shoot(position,inf->position);
                }
                else
                {
                    float angle = position.angle(inf->position);
                    if(dynamic_cast<Item*>(Occupants[i]->GetActiveTool())!=NULL&&dynamic_cast<Item*>(Occupants[i]->GetActiveTool())->GetItemType()!=1)
                        angle += 180;
                   (*ite).Occupant->SetPosition(position.GetX()+cos(angle)*3,position.GetY()+sin(angle)*3+1);
                   Kick(ite);
                }
                i++;
            }
        }
    }
    if(reselect)
        Selected();
}
void Tower::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 5;
    inf.fraction = Building::GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    inf.lpointer = SlotPointer;
    Objects.push_back(inf);
}
void Tower::Selected()
{
    MarkBuilding::Selected();
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Ttower,
                               Position(100,50),sf::Color(30,30,30),"Wooden Tower");
    Markable::MarkedObjectInfo.Information.push_back(obj);

    SetHPonGUI();

    if(fraction==2)
    {
        std::list<void_pointer*> p;
        for(uint32_t i = 0;i < 2;i++)
        {
            p.push_back(State[i].point);p.push_back(Disable[i].point);
        }
        std::list<CTextureReferenceIllusion> t;
        for(std::list <Slot>::iterator ite = shooter.begin();ite != shooter.end();ite++)
        {
            if((*ite).Occupant!=NULL)
            {
                Unit * u = dynamic_cast<Unit*>((*ite).Occupant);
                CTextureReferenceIllusion tri(*u->GetActiveTool()->GetImage().getTexture());
                t.push_back(tri);
            }
            else
                t.push_back(CTextureReferenceIllusion(Textures::textures->NoTexture));
        }
        OISlotElementsStorage * oises = new OISlotElementsStorage(p,t);
        Markable::MarkedObjectInfo.Information.push_back(oises);
    }
}

bool Tower::TypeComparation(std::list <Info>::iterator ite)
{
    if((*ite).type < 100)
        return true;
    return false;
}

void Tower::Kick(std::list<Slot>::iterator & ite)
{
    (*ite).Occupant->Activate();
    AddObject add;
    add.Add((*ite).Occupant);
    (*ite).Occupant = NULL;
    (*ite).reserved = false;
    (*ite).FirstHour = true;
}
