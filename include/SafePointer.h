#ifndef SAFEPOINTER_H
#define SAFEPOINTER_H

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

class void_pointer:public SafePointer
{
    void * pointer;
public:
    void_pointer(void*);
    void * GetPointer();
};

class uint32_t_pointer:public SafePointer
{
    uint32_t * pointer;
public:
    uint32_t_pointer(uint32_t*);
    uint32_t * GetPointer();
};

class list_pointer:public SafePointer
{
    std::list <void*> * pointer;
public:
    list_pointer(std::list <void*>*);
    std::list <void*> * GetPointer();
};

#endif // SAFEPOINTER_H
