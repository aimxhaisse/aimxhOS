/*
** timer.c for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Dec  4 14:36:33 2009 sebastien rannou
** Last update Mon Dec  7 10:29:23 2009 sebastien rannou
*/

#include "system.h"
#include "klib.h"

#define INPUT_CLOCK     1193180
#define CLOCK_FREQ      100

static int
timer_tick = 0;

/**!
 * More about CLOCK_CMD's value can be found here:
 * http://www.osdever.net/bkerndev/Docs/pit.htm
 */

#define CLOCK_CMD       0x36

static void
timer_phase(int hz)
{
  int   d = INPUT_CLOCK / hz;

  outportb(0x43, CLOCK_CMD);
  outportb(0x40, d & 0xFF);
  outportb(0x40, d >> 8);
  
}

void
timer_handler(regs_t * r)
{

  ++timer_tick;
  if (timer_tick % CLOCK_FREQ == 0)
    {
      kprintf("uptime: %d\n", timer_tick / CLOCK_FREQ);
    }

}

/**!
 * Installs the timer
 * Sets up its frequence
 * Registers it in irqs
 */

void
timer_install(void)
{

  timer_phase(CLOCK_FREQ);
  irq_register_handler(0, &timer_handler);

}
