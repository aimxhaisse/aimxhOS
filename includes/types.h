/*
** types.h for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Nov 27 11:18:12 2009 sebastien rannou
** Last update Sun Dec  6 14:20:17 2009 sebastien rannou
*/

#ifndef __TYPES_HH__
#define __TYPES_HH__

/**!
 * Some shortcuts to have a clearer code
 */

typedef unsigned short          ushort;
typedef unsigned char           uchar;
typedef unsigned int            uint;
typedef unsigned long           ulong;

/**!
 * Varargs
 */

typedef __builtin_va_list       va_list;

#define va_start(ap, start)     __builtin_va_start((ap), (start))
#define va_arg(ap, type)        __builtin_va_arg((ap), type)
#define va_end(ap)              __builtin_va_end((ap));

/**!
 * Regs are pushed by our assembly routine irs_handler/irq_handler
 */

typedef struct          regs
{
  uint                  gs, fs, es, ds;
  uint                  edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint                  int_no, err_code;
  uint                  eip, cs, eflags, useresp, ss;
} regs_t;

#endif /* __TYPES_HH__ */
