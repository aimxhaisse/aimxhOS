/*
** irs.h for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Sun Nov 29 19:18:10 2009 sebastien rannou
** Last update Thu Dec  3 16:08:29 2009 sebastien rannou
*/

#ifndef __ISR_HH__
#define __ISR_HH__

#include "types.h"

/**!
 * Regs are pushed by our assembly routine irs_handler
 */

typedef struct          regs
{
  uint                  gs, fs, es, ds;
  uint                  edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint                  int_no, err_code;
  uint                  eip, cs, eflags, useresp, ss;
} regs_t;

/**!
 * Used to register our interruptions
 */

typedef struct          isr_entry
{
  const char *          message;
  void                  (* handler)(void);
} isr_entry_t;

void
isr_install(void);

/**!
 * These symbols are implemented in start.s
 */

extern void             isr_0(void);    /* Floating exception */

#endif /* __ISR_HH__ */
