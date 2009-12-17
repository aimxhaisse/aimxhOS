/*
** loader.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec 17 13:13:03 2009 sebastien rannou
** Last update Thu Dec 17 13:31:05 2009 sebastien rannou
*/

#include "system.h"
#include "klib.h"
#include "splash.h"

/**!
 * This structure allow to register a new component
 * - ptr is the function to be called
 * - text is a description of what's beeing loaded
 */

typedef struct	loading_component
{
  void		(*ptr)(void);
  char *	text;
} loading_component_t;

/**!
 * The order of declaration is really important here
 * You have to choose wisely where you need to load your component
 */

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

/**!
 * Called at the entry of kmain, prints a splash, loads each component
 * Interruptions are finally enabled
 */

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
  __asm__ __volatile__ ("sti");

}
