/*
** devices.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:22:20 2009 sebastien rannou
** Last update Thu Nov 26 16:23:08 2009 sebastien rannou
*/

#include "devices.h"

unsigned char 
device_importb(unsigned short _port)
{
  unsigned char rv;

  __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));

  return rv;
}

void
device_outportb (unsigned short _port, unsigned char _data)
{

  __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));

}
