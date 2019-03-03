#pragma once

#include "../../Anoyher/mainControler.hpp"
#include "GUIObjectInfoElement.h"
#include <list>

class ObjectInfo
{
    public:
        ObjectInfo();
        virtual ~ObjectInfo();
        virtual GUIObjectInfoElement * Create(Position);
    protected:
    private:
};

struct ObjectInfoStorage
{
    bool changed = false;
    std::list <ObjectInfo*> Information;
};
