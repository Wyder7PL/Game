#pragma once


#include <stdint.h>

class EconomyElement
{
    int32_t amount;
    uint32_t reserved;
    bool locked;
public:
    EconomyElement();
    ~EconomyElement();

    uint32_t GetType();
    void SetAmount(int32_t);
    void ChangeAmount(int32_t);
    void UnReserve(int32_t);
    void Reserve(uint32_t);
    int32_t GetAmount();
    int32_t GetNonReservedAmount();
    void Lock(bool);
};
