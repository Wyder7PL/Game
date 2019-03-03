#pragma once
#include "../projectile.h"
#include "SCMEff.h"

class SCM:public projectile
{
public:
    SCM(SCMEff*,uint32_t);
    virtual ~SCM();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};

