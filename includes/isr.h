/*
** irs.h for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Sun Nov 29 19:18:10 2009 sebastien rannou
** Last update Fri Dec  4 14:23:46 2009 sebastien rannou
*/

#ifndef __ISR_HH__
#define __ISR_HH__

#include "types.h"

/**!
 * Used to register our interruptions
 */

typedef struct          isr_entry
{
  const char *          message;
  void                  (* handler)(void);
} isr_entry_t;

/**!
 * These symbols are implemented in start.s
 */

extern void             isr_0(void);
extern void             isr_1(void);
extern void             isr_2(void);
extern void             isr_3(void);
extern void             isr_4(void);
extern void             isr_5(void);
extern void             isr_6(void);
extern void             isr_7(void);
extern void             isr_8(void);
extern void             isr_9(void);
extern void             isr_10(void);
extern void             isr_11(void);
extern void             isr_12(void);
extern void             isr_13(void);
extern void             isr_14(void);
extern void             isr_15(void);
extern void             isr_16(void);

#endif /* __ISR_HH__ */
