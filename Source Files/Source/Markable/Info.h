#pragma once

#include <stdint.h>
#include "../Anoyher/Position.h"
#include "../Pointers/list_pointer.h"

struct Info
{
    Info();
    uint32_t id = 0;
    Position position;
    uint32_t type = 0;
    uint32_t fraction = 0;
    uint32_t shapetype = 0;
    Position shapesize;
    list_pointer * lpointer=NULL;
};

/// //////////////////////// ///
/// Info type:               ///
/// 1.Building               ///
/// 2.Construction           ///
/// 3.Magazine               ///
/// 4.House                  ///
/// 5.Tower                  ///
/// 6.Mine                   ///
/// 7.Workshop               ///
/// ...                      ///
/// 20.Unit                  ///
/// ...                      ///
/// 100.Natural Resource     ///
/// 101.Tree                 ///
/// //////////////////////// ///
