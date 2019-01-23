#include "../include/projectile.h"

projectileEff::projectileEff(){}
projectileEff::~projectileEff(){}
uint32_t projectileEff::GetFractions()
{
    return fractions;
}
void projectileEff::SetFractions(uint32_t f)
{
    fractions = f;
}

projectile::projectile(Position pos,uint32_t f):Object(pos),fractions(f){SetZIndex(6);}
projectile::~projectile(){}
uint32_t projectile::GetFractions()
{
    return fractions;
}
void projectile::SetFractions(uint32_t f)
{
    fractions = f;
}

spearEff::spearEff(uint32_t a)
{
    affected = a;
}

spearEff::~spearEff(){}

void spearEff::Step(ObjectInserter&,Object*){}
void spearEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    Markable * mar = dynamic_cast<Markable*>(obj);
    if(mar != NULL && (*Fraction::Fractions)[GetFractions()]->CompareFractions(mar->GetFraction())==0)
        mar->DealDamage(5,1);
}

void spearEff::OnDestroy(ObjectInserter & ins)
{

}

spear::spear(Position pos,uint32_t f)
:projectile(pos,f)
{
    spearEff * eff = new spearEff(GetID());
    eff->SetFractions(GetFractions());
    AddObject add;
    add.Add(eff);

    physicshape = new Circle(10);
    mask = 1;

    TEST.setRadius(10);
    TEST.setOrigin(10,10);
    TEST.setFillColor(sf::Color(20,20,20));
}

spear::~spear()
{
    //dtor
}

void spear::Step()
{
    Destroy();
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void spear::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}

swordEff::swordEff(uint32_t a,uint32_t d)
:damage(d)
{
    affected = a;
}

void swordEff::Step(ObjectInserter&,Object*){}
void swordEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    Markable * mar = dynamic_cast<Markable*>(obj);
    if(mar != NULL && (*Fraction::Fractions)[GetFractions()]->CompareFractions(mar->GetFraction())==0)
        mar->DealDamage(damage,2);
}

void swordEff::OnDestroy(ObjectInserter & ins)
{

}

sword::sword(Position pos,uint32_t f,float range,uint32_t damage)
:projectile(pos,f)
{
    swordEff * eff = new swordEff(GetID(),damage);
    eff->SetFractions(GetFractions());
    AddObject add;
    add.Add(eff);

    physicshape = new Circle(range);
    mask = 1;

    TEST.setRadius(range);
    TEST.setOrigin(range,range);
    TEST.setFillColor(sf::Color(120,120,120));
}

void sword::Step()
{
    Destroy();
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void sword::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}











bulletEff::bulletEff(uint32_t a,uint32_t d)
:pos(0,0),pierce(1),damage(d)
{
    affected = a;
}

bulletEff::~bulletEff(){}

void bulletEff::Step(ObjectInserter&i,Object*obj)
{
    pos = obj->GetPosition();
    if(pierce == 0)
    {
        bullet * b = dynamic_cast<bullet*>(obj);
        if(b!=NULL)
            b->Existance = 0;
    }
}
void bulletEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    if(pierce>0)
    {
        Markable * bil = dynamic_cast<Markable*>(obj);
        if(bil != NULL &&(*Fraction::Fractions)[GetFractions()]->CompareFractions(bil->GetFraction())==0)
        {
            bil->DealDamage(damage,1);
            bil->Push(Position(pos.angle(obj->GetPosition()),1.0));
            pierce--;
        }
    }

}

void bulletEff::OnDestroy(ObjectInserter & ins)
{

}

bullet::bullet(Position pos,uint32_t f,uint32_t d)
:projectile(pos,f),damage(d),step(0),Existance(100)
{


    physicshape = new Circle(1);
    mask = 1;
    SetMass(0.1);
    PhysicObject::SetMaxSpeed(10);

    TEST.setRadius(2);
    TEST.setOrigin(1,1);
    TEST.setFillColor(sf::Color(120,180,20));
}

bullet::~bullet()
{
    //dtor
}

void bullet::Step()
{
    step++;
    if(step>2&&step<4)
    {
        bulletEff * eff = new bulletEff(GetID(),damage);
        eff->SetFractions(GetFractions());
        AddObject add;
        add.Add(eff);
    }
    if(Existance == 0)
        {Destroy();TEST.setFillColor(sf::Color(240,120,120));}
    else
        Existance--;
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void bullet::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}






chaineffect::chaineffect(Position pos)
:Object(pos),Existance(20)
{
    SetZIndex(6);

    physicshape = new Circle(6);
    mask = 1;
    SetMass(0.3);


    TEST.setRadius(2);
    TEST.setOrigin(3,3);
    TEST.setFillColor(sf::Color(0,0,0,0));
    TEST.setOutlineThickness(1);
}

chaineffect::~chaineffect()
{
    //dtor
}

void chaineffect::Step()
{
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    TEST.setOutlineColor(sf::Color(120,120,120,255*Existance/20));
    if(Existance == 0)
        {Destroy();}
    else
        Existance--;
}
void chaineffect::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}







hookEff::hookEff(uint32_t a)
:pos(0,0),pierce(1),step(0)
{
    affected = a;
}

hookEff::~hookEff(){}

void hookEff::Step(ObjectInserter&i,Object*obj)
{
    step++;
    pos = obj->GetPosition();
    if(pierce == 0)
    {
        hook * b = dynamic_cast<hook*>(obj);
        if(b!=NULL)
            b->Existance = 0;
    }

        chaineffect * eff = new chaineffect(obj->GetPosition());
        AddObject add;
        add.Add(eff);


}
void hookEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    if(pierce>0)
    {
        Markable * bil = dynamic_cast<Markable*>(obj);
        if(bil != NULL &&(*Fraction::Fractions)[GetFractions()]->CompareFractions(bil->GetFraction())==0)
        {
            bil->DealDamage(3,1);
            bil->Push(Position(obj->GetPosition().angle(pos),7.0*step));
            pierce--;
        }
    }

}

void hookEff::OnDestroy(ObjectInserter & ins)
{

}

hook::hook(Position pos,uint32_t f)
:projectile(pos,f),step(0),Existance(100)
{


    physicshape = new Circle(10);
    mask = 1;
    SetMass(0.3);
    PhysicObject::SetMaxSpeed(7);

    TEST.setRadius(10);
    TEST.setOrigin(5,5);
    TEST.setFillColor(sf::Color(120,120,120));
}

hook::~hook()
{
    //dtor
}

void hook::Step()
{
    step++;
    if(step>2&&step<4)
    {
        hookEff * eff = new hookEff(GetID());
        eff->SetFractions(GetFractions());
        AddObject add;
        add.Add(eff);
    }
    if(Existance == 0)
        {Destroy();TEST.setFillColor(sf::Color(240,120,120));}
    else
        Existance--;
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void hook::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}



SCMEff::SCMEff(uint32_t a,uint32_t id)
:ID(id)
{
    affected = a;
}
SCMEff::~SCMEff(){}
void SCMEff::Step(ObjectInserter&,Object*){}
void SCMEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    if(obj->GetID()==ID)
        Communicate(obj);

}
void SCMEff::OnDestroy(ObjectInserter & ins){}
void SCMEff::ChangeAffected(uint32_t a){affected = a;}

SCM::SCM(SCMEff * eff,uint32_t f)
:projectile(Position(0,0),f)
{
    eff->ChangeAffected(GetID());
    AddObject add;
    add.Add(eff);
    physicshape = new CollideAll();
    mask = 1;
}
SCM::~SCM()
{
    //dtor
}
void SCM::Step()
{
    Destroy();
}
void SCM::draw(sf::RenderTarget & target,sf::RenderStates states) const{}



constructiontoolEff::constructiontoolEff(uint32_t a,uint32_t r)
:Rtype(r)
{
    affected = a;
}
constructiontoolEff::~constructiontoolEff(){}
void constructiontoolEff::Step(ObjectInserter&,Object*){}
void constructiontoolEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{

    Construction * con = dynamic_cast<Construction*>(obj);
    if(con != NULL )
    {
        if((con->GetFraction()&GetFractions())!=0)
            con->GiveResource(Rtype,1);
    }

}
void constructiontoolEff::OnDestroy(ObjectInserter & ins){}

constructiontool::constructiontool(Position pos,uint32_t f,uint32_t Rtype)
:projectile(pos,f)
{
    constructiontoolEff * eff = new constructiontoolEff(GetID(),Rtype);
    eff->SetFractions(GetFractions());
    AddObject add;
    add.Add(eff);
    physicshape = new Circle(5);
    mask = 1;

    TEST.setRadius(5);
    TEST.setOrigin(5,5);
    TEST.setFillColor(sf::Color(120,120,120));
}
constructiontool::~constructiontool()
{
    //dtor
}
void constructiontool::Step()
{
    TEST.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    Destroy();
}
void constructiontool::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TEST,states);
}

gathertollEff::gathertollEff(uint32_t a,uint32_t i):id(i)
{
    affected = a;
}
void gathertollEff::Step(ObjectInserter&,Object*){}
void gathertollEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{

    NaturalResource * nat = dynamic_cast<NaturalResource*>(obj);
    if(nat != NULL && nat->GetID() == id)
        nat->TakeResource();

}
void gathertollEff::OnDestroy(ObjectInserter & ins){}

gathertoll::gathertoll(Position pos,uint32_t f,uint32_t i)
:projectile(pos,f),id(i)
{
    gathertollEff * eff = new gathertollEff(GetID(),id);
    eff->SetFractions(GetFractions());
    AddObject add;
    add.Add(eff);
    physicshape = new Circle(5);
    mask = 1;
}
gathertoll::~gathertoll()
{
    //dtor
}
void gathertoll::Step()
{
    Destroy();
}
void gathertoll::draw(sf::RenderTarget & target,sf::RenderStates states) const{}







