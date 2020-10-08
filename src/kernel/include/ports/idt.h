#pragma once

#include "..//typedef.h"
#include "IO.h"
#include "../../IDT/Keyboard/KBScanCode.cpp"

void IDTinit();
extern "C" void isr1Handler();

void (*MainKeyboardHandler) (uint_8 scanCode, uint_8 chr);
