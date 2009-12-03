/*
** gdt.h for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec  3 15:45:59 2009 sebastien rannou
** Last update Thu Dec  3 15:48:13 2009 sebastien rannou
*/

#ifndef __GDT_HH__
#define __GDT_HH__

void
gdt_install(void);

void
gdt_flush(void);        /* implemented is start.asm */

#endif /* __GDT_HH__ */
