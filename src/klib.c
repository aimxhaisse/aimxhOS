/*
** libc.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:05:41 2009 sebastien rannou
** Last update Fri Dec  4 13:39:39 2009 sebastien rannou
*/

#include "screen.h"
#include "klib.h"

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

/**!
 * Simply puts a number on the screen
 */

void
putnbr(int number)
{

  if (number < 0)
    {
      screen_putc('-');
      putnbr(-number);
    }
  else if (number)
    {
      putnbr(number / 10);
      screen_putc('0' + number % 10);
    }
  else
    {
      screen_putc('0');
    }

}

/**!
 * Let's see what's on that chunk of memory
 */

void
dumpmem(void * ptr, int size)
{
  int           i, j;

  screen_putc('\n');
  putnbr((int) ptr);
  screen_putc('\n');
  for (i = 0; i < size; ++i)
    {
      screen_putc('\t');
      putnbr(*(int *) ptr + i);
      screen_putc('\t');
      for (j = 0; j < 4; ++j)
        {
          screen_putc(' ');
          screen_putc(*((char *) ptr + i * sizeof(int) + j));
        }
      screen_putc('\n');
    }

}

void
puts(const char * s)
{

  screen_puts(s);

}

void
putc(char c)
{
  screen_putc(c);
}

void
ping(void)
{
  puts("Ping\n");
}
