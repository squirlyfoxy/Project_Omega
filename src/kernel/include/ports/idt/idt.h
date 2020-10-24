#pragma once

#ifndef _IDT_H
#define _IDT_H

#include "../../typedef.h"
#include "../IO.h"
#include "../../../IDT/Keyboard/KBScanCode.cpp"

void IDTinit();
extern "C" void irq0Handler();
extern "C" void irq1Handler();
extern "C" void irq2Handler();
extern "C" void irq3Handler();
extern "C" void irq4Handler();
extern "C" void irq5Handler();
extern "C" void irq6Handler();
extern "C" void irq7Handler();
extern "C" void irq8Handler();
extern "C" void irq9Handler();
extern "C" void irq10Handler();
extern "C" void irq11Handler();
extern "C" void irq12Handler();
extern "C" void irq13Handler();
extern "C" void irq14Handler();
extern "C" void irq15Handler();

extern void (*MainKeyboardHandler) (uint_8 scanCode, uint_8 chr);

#endif