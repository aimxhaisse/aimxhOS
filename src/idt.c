/*
** idt.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Sun Nov 29 17:35:53 2009 sebastien rannou
** Last update Thu Dec  3 16:53:42 2009 sebastien rannou
*/

#include "klib.h"
#include "idt.h"

/**!
 * The code here is taken from:
 * http://www.osdever.net/bkerndev/Docs/idt.htm
 * It will evolute when I be more aware of what I really want to do
 */

idt_entry_t
idt[256];

idt_ptr_t
idt_p;

void
idt_set_gate(uchar num, ulong base, ushort sel, uchar flags)
{

  idt[num].base_low = (base & 0xFFFF);
  idt[num].base_high = (base >> 16) & 0xFFFF;

  idt[num].flags = flags;
  idt[num].sel = sel;
  idt[num].zero = 0;

}

void
idt_install(void)
{

  idt_p.limit = sizeof(idt) - 1;
  idt_p.base = (int) &idt;
  memset((void *) &idt, 0, sizeof(idt));

  idt_load();

}
