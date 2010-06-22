/*
** libc.c for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:05:41 2009 sebastien rannou
** Last update Mon Dec  7 10:02:21 2009 sebastien rannou
*/

#include "screen.h"
#include "klib.h"

/**!
 * Copy size bytes of src to dst
 */
uchar *
memcpy(uchar * dst, const uchar * src, int size)
{
  int   i;

  for (i = 0; i < size; ++i)
    {
      dst[i] = src[i];
    }

  return dst;
}

/**!
 * Copy [size] bytes of val on dst
 */
uchar *
memset(uchar * dst, uchar val, int size)
{
  int   i;

  for (i = 0; i < size; ++i)
    {
      dst[i] = val;
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
  kprintf("%d", number);
}

/**!
 * Let's see what's on that chunk of memory
 */
void
dumpmem(void * ptr, int size)
{
  int           i, j;

  kprintf("\n%d\n", (int) ptr);
  for (i = 0; i < size; ++i)
    {
      kprintf("\t%d\t", *(int *) ptr + i);
      for (j = 0; j < 4; ++j)
        {
          kprintf(" %c", *((char *) ptr + i * sizeof(int) + j));
        }
      kprintf("\n");
    }
}

/**!
 * Puts a string on the screen
 */
int
puts(const char * s)
{
  return screen_puts(s);
}

/**!
 * Puts a char on the screen
 */
int
putc(char c)
{
  return screen_putc(c);
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
