#pragma once

#ifndef _IO_H
#define _IO_H

#include "./8259.h"
#include "../typedef.h"

void outb(unsigned short port, unsigned char val);
unsigned char inb(unsigned short port);
void sti();
void cli();

#endif