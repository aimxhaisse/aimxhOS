/*
** irq.h for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Dec  4 13:06:46 2009 sebastien rannou
** Last update Fri Dec  4 13:22:18 2009 sebastien rannou
*/

#ifndef __IRQ_HH__
#define __IRQ_HH__

#include "types.h"

extern void     irq_0(void);
extern void     irq_1(void);
extern void     irq_2(void);
extern void     irq_3(void);
extern void     irq_4(void);
extern void     irq_5(void);
extern void     irq_6(void);
extern void     irq_7(void);
extern void     irq_8(void);
extern void     irq_9(void);
extern void     irq_10(void);
extern void     irq_11(void);
extern void     irq_12(void);
extern void     irq_13(void);
extern void     irq_14(void);
extern void     irq_15(void);

void
irq_install(void);

#endif /* __IRQ_HH__ */
