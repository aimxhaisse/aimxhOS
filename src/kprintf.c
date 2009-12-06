/*
** kprintf.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Sun Dec  6 12:51:12 2009 sebastien rannou
** Last update Sun Dec  6 13:08:15 2009 sebastien rannou
*/

#include "types.h"

static int
return_value = 0;

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

int
kprintf(const char * fmt, ...)
{
  int i = 0;

  for (i = 0; fmt[i] != '\0'; ++i)
    {
      
    }
  return return_value;
}
