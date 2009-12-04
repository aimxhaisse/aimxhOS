/*
** libc.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:05:41 2009 sebastien rannou
** Last update Fri Dec  4 14:16:53 2009 sebastien rannou
*/

#include "screen.h"
#include "klib.h"

/**!
 * Copy size bytes of src to dst
 */

uchar *
memcpy(uchar * dst, const uchar * src, int size)
{

  while (size != 0)
    {
      dst[size] = src[size];
      --size;
    }

  return dst;
}

/**!
 * Copy [size] bytes of val on dst
 */

uchar *
memset(uchar * dst, uchar val, int size)
{

  while (size != 0)
    {
      dst[size] = val;
      --size;
    }

  return dst;
}

/**!
 * Same as memset, but with words
 */

ushort *
memsetw(ushort * dst, ushort val, int size)
{

  while (size != 0)
    {
      dst[size] = val;
      --size;
    }

  return dst;
}

/**!
 * Returns length of str
 */

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

/**!
 * Puts a string on the screen
 */

void
puts(const char * s)
{

  screen_puts(s);

}

/**!
 * Puts a char on the screen
 */

void
putc(char c)
{
  screen_putc(c);
}

/**!
 * Used to debug
 */

void
ping(void)
{
  puts("Ping\n");
}

/**!
 * Returns value pointed by _port
 */

uchar
importb(ushort _port)
{
  uchar         rv;

  __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));

  return rv;
}

/**!
 * Store _port into _data
 */

void
outportb (ushort _port, uchar _data)
{

  __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));

}
