/*
** irq.c for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Dec  4 13:05:55 2009 sebastien rannou
** Last update Fri Dec  4 13:36:43 2009 sebastien rannou
*/

#include "idt.h"
#include "irq.h"
#include "devices.h"

/**!
 * Will contain fucntion pointers to irq_x
 */

void *
irq_routines[] = 
  {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
  };

/**!
 * Registers a new irq routine
 */

void
irq_register_handler(int rank, void * handler)
{

  irq_routines[rank] = handler;

}

/**!
 * Reset an irq
 */

void
irq_remove_handler(int rank)
{

  irq_routines[rank] = 0x0;

}

/**!
 * http://www.osdever.net/bkerndev/Docs/irqs.htm
 * remap irq for protected mode
 */

static void
irq_remap(void)
{

  device_outportb(0x20, 0x11);
  device_outportb(0xA0, 0x11);
  device_outportb(0x21, 0x20);
  device_outportb(0xA1, 0x28);
  device_outportb(0x21, 0x04);
  device_outportb(0xA1, 0x02);
  device_outportb(0x21, 0x01);
  device_outportb(0xA1, 0x01);
  device_outportb(0x21, 0x0);
  device_outportb(0xA1, 0x0);

}

/**!
 * Register IRQs
 */

void
irq_install(void)
{

  idt_set_gate(32, (uint) irq_0, 0x08, 0x8E);
  idt_set_gate(33, (uint) irq_1, 0x08, 0x8E);
  idt_set_gate(34, (uint) irq_2, 0x08, 0x8E);
  idt_set_gate(35, (uint) irq_3, 0x08, 0x8E);
  idt_set_gate(36, (uint) irq_4, 0x08, 0x8E);
  idt_set_gate(37, (uint) irq_5, 0x08, 0x8E);
  idt_set_gate(38, (uint) irq_6, 0x08, 0x8E);
  idt_set_gate(39, (uint) irq_7, 0x08, 0x8E);
  idt_set_gate(40, (uint) irq_8, 0x08, 0x8E);
  idt_set_gate(41, (uint) irq_9, 0x08, 0x8E);
  idt_set_gate(42, (uint) irq_10, 0x08, 0x8E);
  idt_set_gate(43, (uint) irq_11, 0x08, 0x8E);
  idt_set_gate(44, (uint) irq_12, 0x08, 0x8E);
  idt_set_gate(45, (uint) irq_13, 0x08, 0x8E);
  idt_set_gate(46, (uint) irq_14, 0x08, 0x8E);
  idt_set_gate(47, (uint) irq_15, 0x08, 0x8E);
                      
}

/**!
 * Let's catch an IRQ
 * When the IRQ is between 0 and 7, we need to send EOI to
 * the slave controller. After this, we activate IRQs with sti
 */

void
irq_handler(regs_t * regs)
{

  void (* h)(regs_t *) = irq_routines[regs->int_no - 32];

  if (h)
    {
      h(regs);
    }
  if (regs->int_no >= 40)
    {
      device_outportb(0xA0, 0x20);
    }
  device_outportb(0x20, 0x20);
  asm("sti");

}
