/*
** types.h for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Nov 27 11:18:12 2009 sebastien rannou
** Last update Fri Dec 11 11:25:43 2009 sebastien rannou
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

/**!
 * Task register
 */

typedef struct          tss
{
  ushort                previous_task, __previous_task_unused;
  uint                  esp0;
  ushort                ss0, __ss0_unused;
  uint                  esp1;
  ushort                ss1, __ss1_unused;
  uint                  esp2;
  ushort                ss2, __ss2_unused;
  uint                  cr3;
  uint                  eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi;
  ushort                es, __es_unused;
  ushort                cs, __cs_unused;
  ushort                ss, __ss_unused;
  ushort                ds, __ds_unused;
  ushort                fs, __fs_unused;
  ushort                gs, __gs_unused;
  ushort                ldt_selector, __ldt_sel_unused;
  ushort                debug_flag, io_map;
} __attribute__ ((packed)) tss_t;

#endif /* __TYPES_HH__ */
