/*
** isrs.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec  3 15:40:56 2009 sebastien rannou
** Last update Sun Dec  6 23:10:35 2009 sebastien rannou
*/

#include "isr.h"
#include "klib.h"
#include "system.h"

/**!
 * Here we register our IRS
 */
static isr_entry_t
isr_entries[] = 
  {

    /* Floating exception */
    {
      .message =        "Divide Error\n",
      .handler =        &isr_0
    },

    /* Debug */
    {
      .message =        "Debug Exceptions",
      .handler =        &isr_1
    },

    /* Non Maskable Interrupt */
    {
      .message =        "Intel reserved",
      .handler =        &isr_2
    },

    /* Breakpoint */
    {
      .message =        "Breakpoint",
      .handler =        &isr_3
    },

    /* Into detected overflow */
    {
      .message =        "Overflow",
      .handler =        &isr_4
    },

    /* Out of Bounds */
    {
      .message =        "Bounds Check",
      .handler =        &isr_5
    },

    /* Invalid Opcode */
    {
      .message =        "Invalid Opcode",
      .handler =        &isr_6
    },

    /* No coprocessor */
    {
      .message =        "Coprocessor Not Available",
      .handler =        &isr_7
    },

    /* Double Fault */
    {
      .message =        "Double Fault",
      .handler =        &isr_8
    },

    /* Bad TSS */
    {
      .message =        "Coprocessor Segment Overrun",
      .handler =        &isr_9
    },

    /* Segment not present */
    {
      .message =        "Invalid TSS",
      .handler =        &isr_10
    },

    /* Stack Fault */
    {
      .message =        "Segment Not Present",
      .handler =        &isr_11
    },

    /* General protection fault */
    {
      .message =        "Xtack Exception",
      .handler =        &isr_12
    },

    /* Page fault */
    {
      .message =        "General Protection Exception (Triple Fault)",
      .handler =        &isr_13
    },

    /* Unknown interrupt */
    {
      .message =        "Page Fault",
      .handler =        &isr_14
    },

    /* Coprocessor fault */
    {
      .message =        "Intel reserved",
      .handler =        &isr_15
    },

    /* Aligmnent check */
    {
      .message =        "Coprocessor Error",
      .handler =        &isr_16
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

  /* From 0 to 16 */

  for (i = 0; i <= 16 && isr_entries[i].message != 0; ++i)
    {
      idt_set_gate(i, (ulong) isr_entries[i].handler, 0x08, 0x8E);
    }
}

/**!
 * Here we treat our interuptions
 * This kind of stuff is ugly, we really need a kprintf() :(
 */
void
isr_handler(regs_t * regs)
{
  kprintf("# Kernel panic: %s (%d) - error=%d\n", 
          isr_entries[regs->int_no].message,
          regs->int_no,
          regs->err_code);
  while (42)
    {
      continue;
    }
}
