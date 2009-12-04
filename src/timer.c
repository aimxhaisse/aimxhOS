/*
** timer.c for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Dec  4 14:36:33 2009 sebastien rannou
** Last update Fri Dec  4 14:42:50 2009 sebastien rannou
*/

#include "system.h"
#include "klib.h"

#define INPUT_CLOCK     1193180

/**!
 * More about CLOCK_CMD's value can be found here:
 * http://www.osdever.net/bkerndev/Docs/pit.htm
 */

#define CLOCK_CMD       0x36

void
timer_phase(int hz)
{
  int   d = INPUT_CLOCK / hz;

  outportb(0x43, CLOCK_CMD);
  outportb(0x40, d & 0xFF);
  outportb(0x40, d >> 8);
  
}
