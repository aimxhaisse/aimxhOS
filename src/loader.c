/*
** loader.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec 17 13:13:03 2009 sebastien rannou
** Last update Thu Dec 17 13:25:50 2009 sebastien rannou
*/

#include "system.h"
#include "klib.h"
#include "splash.h"

typedef struct	loading_component
{
  void		(*ptr)(void);
  char *	text;
} loading_component_t;

static loading_component_t
components[] = 
  {

    {
      .ptr	= &gdt_install,
      .text	= "gdt"
    },

    {
      .ptr	= &idt_install,
      .text	= "idt"
    },

    {
      .ptr	= &isr_install,
      .text	= "isr"
    },

    {
      .ptr	= &irq_install,
      .text	= "irq"
    },

    {
      .ptr	= &sched_install,
      .text	= "scheduler"
    },

    {
      .ptr	= &kbd_install,
      .text	= "keyboard"
    },

    {
      .ptr	= &timer_install,
      .text	= "timer"
    },

    {0,0}

  };

void
kloader(void)
{
  int	i;

  splash_screen();
  for (i = 0; components[i].ptr != 0; ++i)
    {
      kprintf("loading [%s] ", components[i].text);
      components[i].ptr();
      kprintf("OK\n");
    }
  kprintf("\n");

}
