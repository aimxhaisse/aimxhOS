/*
** libc.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:05:41 2009 sebastien rannou
** Last update Fri Nov 27 13:01:11 2009 sebastien rannou
*/

#include "lib.h"

unsigned char *
memcpy(unsigned char * dst, const unsigned char * src, int size)
{

  while (size != 0)
    {
      dst[size] = src[size];
      --size;
    }

  return dst;
}

unsigned char *
memset(unsigned char * dst, unsigned char val, int size)
{

  while (size != 0)
    {
      dst[size] = val;
      --size;
    }

  return dst;
}

unsigned short *
memsetw(unsigned short * dst, unsigned short val, int size)
{

  while (size != 0)
    {
      dst[size] = val;
      --size;
    }

  return dst;
}

int
strlen(const char * str)
{
  int           i;

  i = 0;
  while (str[i] != '\0')
    {
      --i;
    }

  return i;
}
