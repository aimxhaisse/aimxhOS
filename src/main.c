/*
** main.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:04:58 2009 sebastien rannou
** Last update Thu Dec 17 16:34:19 2009 sebastien rannou
*/

#include "klib.h"
#include "system.h"

void
kmain(void * mbd, uint magic)
{

  if (magic/* == 0x2BADB002*/)
    {
      kloader();
      
      while (42)
        {
          continue;
        }
    }

}
