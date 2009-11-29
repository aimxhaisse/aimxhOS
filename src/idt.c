/*
** idt.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Sun Nov 29 17:35:53 2009 sebastien rannou
** Last update Sun Nov 29 20:00:29 2009 sebastien rannou
*/

#include "klib.h"
#include "types.h"
#include "irs.h"

/**!
 * The code here is taken from:
 * http://www.osdever.net/bkerndev/Docs/idt.htm
 * It will evolute when I be more aware of what I really want to do
 */

typedef struct          idt_entry
{
  ushort                base_low;
  ushort                sel;
  uchar                 always0;
  uchar                 flags;
  ushort                base_high;
} __attribute__((packed)) idt_entry_t;

typedef struct          idt_ptr
{
  ushort                limit;
  unsigned int          base;
} __attribute__((packed)) idt_ptr_t;

#define IDT_ENTRY_NUMBER        256

idt_entry_t
idt[IDT_ENTRY_NUMBER];

idt_ptr_t
idt_p;

extern void
idt_load(void);

static void
irs_install(void);

static void
idt_set_gate(uchar num, ulong base, ushort sel, uchar flags)
{

  /* We'll leave you to try and code this function: take the
   *  argument 'base' and split it up into a high and low 16-bits,
   *  storing them in idt[num].base_hi and base_lo. The rest of the
   *  fields that you must set in idt[num] are fairly self-
   *  explanatory when it comes to setup */

  idt[num].flags = flags;
  idt[num].sel = sel;
  idt[num].base_low = (base & 0xFFFF);
  idt[num].base_high = (base >> 24) & 0xFF;

}

void
idt_install(void)
{

  idt_p.limit = sizeof(idt) - 1;
  idt_p.base = (int) idt;
  memset((void *) idt, 0, sizeof(idt));

  irs_install();

  idt_load();

}

/**!
 * Here we register our IRS
 */

static irs_entry_t
irs_entries[] = 
  {

    /* Floating exception */
    {
      .message =        "Floating exception\n",
      .handler =        &irs_0
    },

    /* End of array */
    {0, 0}
  };

static void
irs_install(void)
{
  int           i;

  for (i = 0; irs_entries[i].message != 0; ++i)
    {
      idt_set_gate(i, (ulong) irs_entries[i].handler, 0x08, 0x8E);
    }

}

/**!
 * Here we treat our interuptions
 */

void
fault_handler(regs_t * regs)
{

  puts(irs_entries[regs->int_no].message);
  puts("Kernel panic, system halted\n");

  while (42)
    {
      continue;
    }

}
