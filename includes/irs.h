/*
** irs.h for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Sun Nov 29 19:18:10 2009 sebastien rannou
** Last update Sun Nov 29 19:27:33 2009 sebastien rannou
*/

#ifndef __IRS_HH__
#define __IRS_HH__

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

typedef struct          irs_entry
{
  const char *          message;
  void                  (* handler)(void);
} irs_entry_t;

extern void     irs_0(void);    /* Floating exception */

#endif /* __IRS_HH__ */
