/*
** screen.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Nov 27 11:11:49 2009 sebastien rannou
** Last update Fri Nov 27 13:01:31 2009 sebastien rannou
*/

#include "screen.h"
#include "lib.h"

static scr_char_t *
screen_memory = SCR_PTR;

void
screen_clear(void)
{

  memset((uchar *) screen_memory, 0, SCR_SIZE);

}
