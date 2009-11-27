/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Fri Nov 27 15:19:27 2009 sebastien rannou
*/

#include "lib.h"
#include "devices.h"
#include "screen.h"

void
kmain(void * mbd, unsigned int magic)
{

  if (magic == 0x2BADB002)
    {
      screen_clear();
      screen_puts("Hello world :)\n");
      screen_puts("Hello world :)\n");
      screen_puts("Hello world :)\n");
      while (42)
        {
          continue;
        }
    }

}
