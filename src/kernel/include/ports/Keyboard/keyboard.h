#pragma once

#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "../../typedef.h"
#include "../../kprint.h"

void StandardKeyboardHandler(uint_8 scanCode, uint_8 chr);
void KeyboardHandler0xe0(uint_8 scanCode);
void KeyboardHandler(uint_8 scanCode, uint_8 chr);

#endif