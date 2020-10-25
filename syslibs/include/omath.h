// Omega Math Library v.1.0
// Copyright (c) 2020 - squirlyfoxy (Leonardo Baldazzi)

#pragma once

#ifndef _MATH_H
#define _MATH_H

extern int SplitByte(int byte, int who = 0);
extern double pow(double x, double y);

namespace CONVERT
{
    extern unsigned char bcd2bin(unsigned char bcd);
}

#endif