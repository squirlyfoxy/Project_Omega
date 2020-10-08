#pragma once

#ifndef _IDT_H
#define _IDT_H

#include "..//typedef.h"
#include "IO.h"
#include "../../IDT/Keyboard/KBScanCode.cpp"

void IDTinit();
extern "C" void isr1Handler();

extern void (*MainKeyboardHandler) (uint_8 scanCode, uint_8 chr);

#endif