/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Fri Nov 27 18:12:33 2009 sebastien rannou
*/

#include "klib.h"
#include "devices.h"
#include "screen.h"

void
gdt_install();

void
kmain(void * mbd, unsigned int magic)
{

  if (magic == 0x2BADB002)
    {
      gdt_install();
      screen_clear();
      screen_puts((uchar *) "Hello world !\n");
      while (42)
        {
          continue;
        }
    }

}
