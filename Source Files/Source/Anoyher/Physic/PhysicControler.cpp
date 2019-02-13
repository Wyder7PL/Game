#include "PhysicControler.hpp"

PhysicControler::PhysicControler()
{

}
PhysicControler::~PhysicControler()
{
    MainPhysicObjContainer.clear();
    MaskSortedObj.clear();
}

void PhysicControler::MaskSort()
{
    for(std::vector<std::vector<PhysicObject*>>::iterator ite = MaskSortedObj.begin();ite!=MaskSortedObj.end();ite++)
    {
        (*ite).clear();
    }
    for(std::vector<PhysicObject*>::iterator ite = MainPhysicObjContainer.begin();ite!=MainPhysicObjContainer.end();ite++)
    {
        uint32_t mask = (*ite)->GetMask();
        for(uint32_t i = 0;i < 32;i++)
        {
            uint32_t j = 1 << i;
            if(j > mask)
                i = 32;
            else
            {
                uint32_t k = mask & j;
                if(k != 0)
                {
                    while(MaskSortedObj.size()<i+1)
                    {
                        std::vector<PhysicObject*> vec;
                        MaskSortedObj.push_back(vec);
                    }
                    MaskSortedObj[i].push_back(*ite);
                }
            }
        }
    }
}

void PhysicControler::SimulatePhysicV2()
{
    Collisions.clear();
    for(std::vector<std::vector<PhysicObject*>>::iterator ite = MaskSortedObj.begin();ite!=MaskSortedObj.end();ite++)
    {
        if((*ite).size() > 1)
        {
            for(uint32_t i = 0;i < (*ite).size()-1;i++)
            {
                for(uint32_t j = i + 1;j < (*ite).size();j++)
                {
                    if((*ite)[i]->CollideV2((*ite)[j])||(*ite)[j]->CollideV2((*ite)[i]))
                    {
                        uint32X2 temp;
                        temp.X = (*ite)[i]->VectorID;
                        temp.Y = (*ite)[j]->VectorID;
                        Collisions.push_back(temp);
                    }
                }
            }
        }
    }
    for(std::vector<PhysicObject*>::iterator ite = MainPhysicObjContainer.begin();ite!=MainPhysicObjContainer.end();ite++)
    {
        (*ite)->ApplyStoredForces();
    }
}

void PhysicControler::TESTaddPhysic(PhysicObject*physic)
{
    MainPhysicObjContainer.push_back(physic);
}

void PhysicControler::ClearArray()
{
    for(std::vector <PhysicObject*>::iterator ite = MainPhysicObjContainer.begin();ite != MainPhysicObjContainer.end();)
    {
        if((*ite)->ToClear())
            ite = MainPhysicObjContainer.erase(ite);
        else
            ite++;
    }
}















