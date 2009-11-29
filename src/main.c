/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Sun Nov 29 17:58:13 2009 sebastien rannou
*/

#include "klib.h"
#include "devices.h"
#include "screen.h"

void
gdt_install(void);

void
idt_install(void);

void
kmain(void * mbd, unsigned int magic)
{

  if (magic == 0x2BADB002)
    {
      gdt_install();
      idt_install();
      screen_clear();

      { /* Temporary code */
        char * s = "Hello world !\n";
        screen_puts(s);
        dumpmem(s, 3);
      } /* /Temporary code */

      while (42)
        {
          continue;
        }
    }

}
