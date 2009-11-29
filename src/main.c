/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Sun Nov 29 20:00:15 2009 sebastien rannou
*/

#include "klib.h"
#include "devices.h"

void
gdt_install(void);

void
idt_install(void);

void
irs_install(void);

void
splash_screen(void);

void
kmain(void * mbd, unsigned int magic)
{
  int   a;

  if (magic == 0x2BADB002)
    {

      splash_screen();

      gdt_install();
      idt_install();      

      a = 42 / 0;

      while (42)
        {
          continue;
        }
    }

}
