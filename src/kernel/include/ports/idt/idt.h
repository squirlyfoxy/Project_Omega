#pragma once

#ifndef _IDT_H
#define _IDT_H

#include "../../typedef.h"
#include "../IO.h"
#include "../../../IDT/Keyboard/KBScanCode.cpp"

void IDTinit();
extern "C" void isr0Handler();
extern "C" void isr1Handler();
extern "C" void isr2Handler();
extern "C" void isr3Handler();
extern "C" void isr4Handler();
extern "C" void isr5Handler();
extern "C" void isr6Handler();
extern "C" void isr7Handler();
extern "C" void isr8Handler();
extern "C" void isr9Handler();
extern "C" void isr10Handler();
extern "C" void isr11Handler();
extern "C" void isr12Handler();
extern "C" void isr13Handler();
extern "C" void isr14Handler();
extern "C" void isr15Handler();

extern void (*MainKeyboardHandler) (uint_8 scanCode, uint_8 chr);

#endif