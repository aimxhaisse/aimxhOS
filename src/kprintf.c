/*
** kprintf.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Sun Dec  6 12:51:12 2009 sebastien rannou
** Last update Sun Dec  6 14:20:01 2009 sebastien rannou
*/

#include "system.h"
#include "klib.h"

static int
return_value = 0;

static int
position = 0;

/**!
 * An evolutive printf-like function with minimalistic features.
 *
 * int kprintf(const char * fmt, ...);
 *
 * fmt is a string representing what will be printed.
 * fmt can contains arguments, as the c-printf, with the % character
 *
 * an argument is composed of two parts:
 * -> an optionnal integer called n, that will be given to the requested feature
 * -> a letter representing the feature to call
 *
 * here are some examples of arguments:
 *
 * %s           : will call the s feature without n
 * %3s          : will call the s feature with n = 3
 * %42x         : will call the x feature with n = 42
 *
 * The following features are available:
 *
 * s - prints a string, if n is provided, prints n characteres from the string
 * d - prints a number, if n is provided, prints n characteres from the number
 */

void
kprintf_put_arg(const char * ptr, va_list * va)
{
  if (ptr[position])
    {
      switch (ptr[position])
        {
        case '%':
          putc('%');
          break;
        case 's':
          puts(va_arg(*va, char *));
          break;
        }
    }
}

int
kprintf(const char * fmt, ...)
{
  va_list       va;

  va_start(va, fmt);
  while (fmt[position] != '\0')
    {
      if (fmt[position] == '%')
        {
          ++position;
          kprintf_put_arg(fmt, &va);
        }
      else
        {
          putc(fmt[position]);
          ++position;
          ++return_value;
        }
    }
  va_end(va);

  return return_value;
}
