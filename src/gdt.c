/*
** gdt.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Nov 27 17:08:19 2009 sebastien rannou
** Last update Sun Nov 29 18:03:18 2009 sebastien rannou
*/

#include "types.h"

/**!
 * The code here is taken from:
 * http://www.osdever.net/bkerndev/Docs/gdt.htm
 * It will evolute when I be more aware of what I really want to do
 */

typedef struct                  gdt_entry
{
  ushort                        limit_low;
  ushort                        base_low;
  uchar                         base_middle;
  uchar                         access;
  uchar                         granularity;
  uchar                         base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct                  gdt_ptr
{
  ushort                        limit;
  uint                          base;
} __attribute__((packed)) gdt_ptr_t;

#define GDT_ENTRY_NUMBER        3

#define GDT_CODE_SEG            0x9A
#define GDT_DATA_SEG            0x92

gdt_entry_t
gdt[GDT_ENTRY_NUMBER];

gdt_ptr_t
gdt_p;

/**!
 * gdt_flush is from assembly
 */

extern void
gdt_flush(void);

/**!
 * Sets up a gdt entry
 */

static void 
gdt_set_gate(int num, ulong base, ulong limit, uchar access, uchar gran)
{

  gdt[num].base_low = (base & 0xFFFF);
  gdt[num].base_middle = (base >> 16) & 0xFF;
  gdt[num].base_high = (base >> 24) & 0xFF;

  gdt[num].limit_low = (limit & 0xFFFF);
  gdt[num].granularity = ((limit >> 16) & 0x0F);

  gdt[num].granularity |= (gran & 0xF0);
  gdt[num].access = access;

}

/**!
 * Called during initialization of the kernel
 */

void
gdt_install(void)
{

  gdt_p.limit = sizeof(gdt) - 1;
  gdt_p.base = (uint) gdt;

  gdt_set_gate(0, 0, 0, 0, 0);
  gdt_set_gate(1, 0, 0xFFFFFFFF, GDT_CODE_SEG, 0xCF);
  gdt_set_gate(2, 0, 0xFFFFFFFF, GDT_DATA_SEG, 0xCF);

  gdt_flush();

}
