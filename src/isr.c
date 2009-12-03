/*
** isrs.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec  3 15:40:56 2009 sebastien rannou
** Last update Thu Dec  3 16:08:06 2009 sebastien rannou
*/

#include "isr.h"
#include "idt.h"
#include "klib.h"

/**!
 * Here we register our IRS
 */

static isr_entry_t
isr_entries[] = 
  {

    /* Floating exception */
    {
      .message =        "Floating exception\n",
      .handler =        &isr_0
    },

    /* End of array */
    {0, 0}

  };

/**!
 * Initialize each entry of isr_entries
 */

void
isr_install(void)
{
  int           i;

  for (i = 0; isr_entries[i].message != 0; ++i)
    {
      idt_set_gate(i, (ulong) isr_entries[i].handler, 0x08, 0x8E);
    }

}

/**!
 * Here we treat our interuptions
 */

void
fault_handler(regs_t * regs)
{

  puts("Kernel panic !\n");
  puts(isr_entries[regs->int_no].message);

  while (42)
    {
      continue;
    }

}
