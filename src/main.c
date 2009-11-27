/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Fri Nov 27 14:23:29 2009 sebastien rannou
*/

#include "lib.h"
#include "devices.h"
#include "screen.h"

void
kmain(void * mbd, unsigned int magic)
{
  int a;

  if (magic == 0x2BADB002)
    {
      screen_clear();
      if (sizeof(scr_char_t) == sizeof(short))
        {
          while (42)
            {
              for (a = 0; a < 2; a++)
                {
                  screen_putc(a + '0');
                }
            }
        }
      while (42)
        {
          continue;
        }
    }

}
