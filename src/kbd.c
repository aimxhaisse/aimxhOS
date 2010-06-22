/*
** kbd.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Mon Dec  7 10:59:03 2009 sebastien rannou
** Last update Mon Dec  7 11:12:41 2009 sebastien rannou
*/

#include "kdb.h"
#include "system.h"
#include "klib.h"

void
kbd_handler(struct regs *r)
{
  uchar scancode;

  scancode = importb(0x60);
  if (!(scancode & 0x80))
    {
      kprintf("%c", kbdus[scancode]);
    }

}

void
kbd_install(void)
{
  irq_register_handler(1, &kbd_handler);
}
