#include "constructiontoolEff.h"

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
