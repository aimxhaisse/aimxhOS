/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Thu Dec  3 16:07:40 2009 sebastien rannou
*/

#include "klib.h"
#include "devices.h"
#include "idt.h"
#include "gdt.h"
#include "isr.h"
#include "splash.h"

void
kmain(void * mbd, unsigned int magic)
{
  int   a = 0x42;
  int   z = 0;

  if (magic == 0x2BADB002)
    {

      splash_screen();

      gdt_install();
      idt_install();      
      isr_install();

      { /* sandbox */
        puts("Can I divide by zero?\n");
        a /= z;
        puts("Ooooh yeah!\n");
      }

      while (42)
        {
          continue;
        }
    }

}
