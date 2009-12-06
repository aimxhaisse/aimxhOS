/*
** kprintf.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Sun Dec  6 12:51:12 2009 sebastien rannou
** Last update Sun Dec  6 22:01:54 2009 sebastien rannou
*/

#include "system.h"
#include "klib.h"

static int
return_value;

static int
position;

/**!
 * An extensible printf-like function with minimalistic features.
 *
 * int kprintf(const char * fmt, ...);
 *
 * fmt is a string representing what will be printed.
 * fmt can contains arguments, like the c-printf, with the % character
 *
 * an argument is composed of two parts:
 * -> an optional integer called n, that will be given to the requested feature
 * -> a letter representing the feature to call
 *
 * here are some examples of arguments:
 *
 * %s           : will call the s feature with n = 0
 * %3s          : will call the s feature with n = 3
 * %42x         : will call the x feature with n = 42
 *
 * The following features are available:
 *
 * s - prints a string, if n is provided, prints n characteres from the string
 * d - prints a number, if n is provided, prints n characteres from the number
 * p - prints an adress, if n is provided, dump its content of n bytes
 */

void
kprintf_blanks(int n)
{

  while (n > 0)
    {
      return_value += putc(' ');
      --n;
    }

}

/**!
 * %nd with n = number of characters to print
 * if n == 0 (default), prints everything
 */

int
kprintf_put_number(int param, int n)
{
  char  s[16];
  int   i = 0;
  int   return_value = 0;

  memset((uchar *) s, 0, sizeof(s));
  if (param < 0)
    {
      return_value += putc('-');
      param = - param;
    }
  while (param > 0)
    {
      s[i] = param % 10;
      ++i;
      param /= 10;
    }
  while (i > 0)
    {
      if (!n || i < n)
        {
          return_value += putc(s[i - 1] + '0');
        }
      --i;
    }
  if (!return_value)
    {
      return_value += putc('0');
    }
  if (n > 0)
    {
      kprintf_blanks(n - return_value);
    }
  
  return return_value;
}

/**!
 * %ns with n = number of characters to print
 * if n == 0 (default), prints everything
 * if n > strlen(param), outputs n - strlen(param) spaces
 */

int
kprintf_put_string(const char * param, int n)
{
  int   i;
  int   val = 0;

  if (n > 0)
    {
      for (i = 0; i < n && param[i] != '\0'; ++i)
        {
          val += putc(param[i]);
        }
      kprintf_blanks(n - i);
    }
  else
    {
      for (i = 0; param[i] != '\0'; ++i)
        {
          val += putc(param[i]);
        }      
    }

  return val;
}

/**!
 * %nc - prints a char
 */

int
kprintf_put_char(int c, int n)
{
  int   val = 0;

  val += putc(c);
  kprintf_blanks(n - 1);

  return val;
}

/**!
 * Returns n, optionnal part of an argument, default = 0
 */

int
kprintf_get_n(const char * ptr)
{
  int   res = 0;

  while (ptr[position] >= '0' && ptr[position] <= '9')
    {
      res *= 10;
      res += ptr[position] - '0';
      ++position;
    }

  return res;
}

/**!
 * Dispatchs arguments to features
 */

void
kprintf_put_arg(const char * ptr, va_list * va)
{
  int   n = kprintf_get_n(ptr);

  if (ptr[position])
    {
      switch (ptr[position])
        {

        case '%':
          return_value += putc('%');
          ++position;
          break;

        case 's':
          return_value += kprintf_put_string(va_arg(*va, char *), n);
          ++position;
          break;

        case 'c':
          return_value += kprintf_put_char(va_arg(*va, int), n);
          ++position;
          break;

        case 'd':
          return_value += kprintf_put_number(va_arg(*va, int), n);
          ++position;
          break;

        }
    }

}

void
kprintf_initialize(void)
{

  return_value = 0;
  position = 0;

}

/**!
 * Main entry
 */

int
kprintf(const char * fmt, ...)
{
  va_list       va;

  kprintf_initialize();
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
          return_value += putc(fmt[position]);
          ++position;
        }
    }
  va_end(va);

  return return_value;
}
