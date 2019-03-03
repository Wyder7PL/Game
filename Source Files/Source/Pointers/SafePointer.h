#pragma once

#include <stdint.h>
#include <list>

class SafePointer
{
public:
    SafePointer();
    virtual ~SafePointer();

    static std::list <SafePointer*> Pointers;

    bool DestroyMe();
    void TurnOff();
    bool StepnWait();
protected:
    bool toDestroy;
    uint32_t wait;
private:
};
