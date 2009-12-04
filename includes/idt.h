/*
** idt.h for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec  3 15:43:04 2009 sebastien rannou
** Last update Fri Dec  4 14:24:55 2009 sebastien rannou
*/

#ifndef __IDT_HH__
#define __IDT_HH__

#include "types.h"

typedef struct          idt_entry
{
  ushort                base_low;
  ushort                sel;
  uchar                 zero;
  uchar                 flags;
  ushort                base_high;
} __attribute__((packed)) idt_entry_t;

typedef struct          idt_ptr
{
  ushort                limit;
  unsigned int          base;
} __attribute__((packed)) idt_ptr_t;

void
idt_load(void); /* implemented in start.asm */

void
idt_install(void);

#endif /* __IDT_HH__ */
