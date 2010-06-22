/*
** mm.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec 17 15:44:54 2009 sebastien rannou
** Last update Thu Dec 17 16:31:48 2009 sebastien rannou
*/

#include "klib.h"
#include "system.h"

/**!
 * Let's install memory mapping!
 */

#include "types.h"

#define KP_FLAG		0x80000000

#define KP_DIR		0x20000
#define KP_TABLE	0x21000

void
mm_install(void)
{
  uint *	kernel_pagedir = (uint *) KP_DIR;
  uint *	kernel_pagetable = (uint *) KP_TABLE;
  uint		paddr = 0;
  uint		i;

  kernel_pagedir[0] = KP_TABLE | 3;
  memset((uchar *) (kernel_pagedir + sizeof(uint)), 0, 1023 * sizeof(uint));

  for (i = 0; i < 1024; i++)
    {
      kernel_pagetable[i] = paddr | 3;
      paddr += 4096;
    }

  asm("mov %0, %%eax    \n	\
       mov %%eax, %%cr3 \n	\
       mov %%cr0, %%eax \n	\
       or %1, %%eax     \n	\
       mov %%eax, %%cr0" :: "i"(KP_DIR), "i"(KP_FLAG));
}
