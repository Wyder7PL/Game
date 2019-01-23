#include <vector>
#include <list>

#include "../include/PhysicObject.h"

using namespace std;

struct uint32X2
{
    uint32X2();
    uint32X2(uint32_t,uint32_t);
    uint32_t X;
    uint32_t Y;
};

class PhysicControler
{
    std::vector <PhysicObject*> MainPhysicObjContainer;

    std::vector <std::vector<PhysicObject*>> MaskSortedObj;

    public:
        PhysicControler();
        ~PhysicControler();

        void MaskSort();

        void SimulatePhysic();

        void SimulatePhysicV2();

        void TESTaddPhysic(PhysicObject*);

        void ClearArray();

        std::list <uint32X2> Collisions;

};
