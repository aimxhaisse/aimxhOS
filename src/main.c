/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Sun Dec  6 18:33:21 2009 sebastien rannou
*/

#include "klib.h"
#include "splash.h"
#include "system.h"

void
kmain(void * mbd, uint magic)
{

  if (magic /* == 0x2BADB002 */)
    {
      splash_screen();

      gdt_install();
      idt_install();
      isr_install();
      irq_install(); 

      timer_install();

      __asm__ __volatile__ ("sti");
      
      while (42)
        {
          continue;
        }
    }

}
