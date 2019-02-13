#include "Dereserve.h"

Dereserve::Dereserve(uint32_t id,uint32_t type,uint32_t amount)
:SCMEff(0,id),Rtype(type),Amount(amount){}
Dereserve::~Dereserve(){}
void Dereserve::Communicate(Object * obj)
{
    Construction * con = dynamic_cast<Construction*>(obj);
    if(con!=NULL)
    {
        con->Dereserve(Rtype,Amount);
    }
}
