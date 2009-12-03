/*
** idt.h for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec  3 15:43:04 2009 sebastien rannou
** Last update Thu Dec  3 15:49:26 2009 sebastien rannou
*/

#ifndef __IDT_HH__
#define __IDT_HH__

#include "types.h"

void
idt_set_gate(uchar num, ulong base, ushort sel, uchar flags);

void
idt_load(void); /* implemented in start.asm */

void
idt_install(void);

#endif /* __IDT_HH__ */
