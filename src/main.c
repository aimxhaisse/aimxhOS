/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Thu Dec 10 12:36:31 2009 sebastien rannou
*/

#include "klib.h"
#include "splash.h"
#include "system.h"

void
first_task(void)
{
  while (42)
    {
      continue;
    }
}

void
second_task(void)
{
  while (42)
    {
      continue;
    }
}

void
kmain(void * mbd, uint magic)
{

  if (magic/* == 0x2BADB002*/)
    {
      splash_screen();

      gdt_install();
      idt_install();
      isr_install();
      irq_install(); 

      kbd_install();
      timer_install();

      memcpy((uchar *) 0x30000, (uchar *) &first_task, 142);
      memcpy((uchar *) 0x40000, (uchar *) &second_task, 142);

      kprintf("Hey, this is a number: %10d$\n", 42);
      kprintf("Hey, this is a number: %10d$\n", -42);
      kprintf("Hey, this is a number: %10d$\n", 0);
      kprintf("Hey, this is a number: %10d$ %c %%\n", 4234, '1');

      __asm__ __volatile__ ("sti");
      
      while (42)
        {
          continue;
        }
    }

}
