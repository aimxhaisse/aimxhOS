/*
** system.h for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Dec  4 14:21:57 2009 sebastien rannou
** Last update Fri Dec  4 14:51:05 2009 sebastien rannou
*/

#ifndef __SYSTEM_HH__
#define __SYSTEM_HH__

#include "types.h"

/**!
 * ISR
 */

void    isr_install(void);

/**!
 * GDT
 */

void    gdt_install(void);

/**!
 * IDTs
 */

void    idt_set_gate(uchar num, ulong base, ushort sel, uchar flags);
void    idt_install(void);

/**!
 * IRQs
 */

void    irq_install(void);
void    irq_register_handler(int rank, void * handler);
void    irq_remove_handler(int rank);

void    timer_install(void);

#endif // __SYSTEM_HH__
