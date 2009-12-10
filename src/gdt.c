/*
** gdt.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Nov 27 17:08:19 2009 sebastien rannou
** Last update Mon Dec  7 20:19:37 2009 sebastien rannou
*/

#include "types.h"
#include "gdt.h"
#include "system.h"

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

#define GDT_ENTRY_NUMBER        5

gdt_entry_t
gdt[GDT_ENTRY_NUMBER];

gdt_ptr_t
gdt_p;

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

  /* Kernel's  GDT*/
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

  /* Userland's GDT */  
  gdt_set_gate(3, 0, 0xFFFFFFFF, 0xF8, 0xC);
  gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF0, 0xC);

  gdt_flush();

}
