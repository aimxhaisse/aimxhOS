/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Fri Nov 27 09:51:30 2009 sebastien rannou
*/

#include "libc.h"
#include "devices.h"

void
kmain(void * mbd, unsigned int magic)
{
  char *        boot_loader_name;

  if (magic == 0x2BADB002)
    {
      boot_loader_name = (char*) ((long*) mbd)[16];
      
      unsigned char * videoram = (unsigned char *) 0xb8000;
      videoram[0] = 65;
      videoram[1] = 0x07;

      while (42)
        {
          continue;
        }
    }

}
