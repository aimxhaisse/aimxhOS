/*
** system.h for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Dec  4 14:21:57 2009 sebastien rannou
** Last update Thu Dec 17 15:46:07 2009 sebastien rannou
*/

#ifndef __SYSTEM_HH__
#define __SYSTEM_HH__

#include "types.h"

void	kloader(void);

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
void    kbd_install(void);

/**!
 * Memory mapping
 */

void	mm_install(void);

/**!
 * Scheduler
 */

void    sched_install(void);
void    sched(void);

#endif // __SYSTEM_HH__
