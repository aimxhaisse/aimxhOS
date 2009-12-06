/*
** screen.h for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Nov 27 11:11:25 2009 sebastien rannou
** Last update Sun Dec  6 14:25:08 2009 sebastien rannou
*/

#ifndef __SCREEN_HH__
#define __SCREEN_HH__

#include "types.h"

/**!
 * Available colors provided by VGA
 */

enum    SCR_COLOR
  {
    BLACK               = 0,
    BLUE                = 1,
    GREEN               = 2,
    CYAN                = 3,
    RED                 = 4,
    MAGENTA             = 5,
    BROWN               = 6,
    LIGHT_GREY          = 7,
    DARK_GREY           = 8,
    LIGHT_BLUE          = 9,
    LIGHT_GREEN         = 10,
    LIGHT_CYAN          = 11,
    LIGHT_RED           = 12,
    LIGHT_MAGENTA       = 13,
    LIGHT_BROWN         = 14,
    WHITE               = 15
  };

/**!
 * Describe a charactere on the screen
 * This is what we find in memory at 0xB8000
 */

typedef struct          scr_char
{
  uchar                 c;
  uchar                 fg: 4;
  uchar                 bg: 4;
} __attribute__((packed)) scr_char_t;

#define SCR_W           80
#define SCR_H           25
#define SCR_SIZE        (SCR_W * SCR_H)
#define SCR_PTR         ((scr_char_t *) 0xB8000)

void
screen_clear(void);

void
screen_scroll(void);

int
screen_putc(char c);

int
screen_puts(const char * s);

#endif /* __SCREEN_HH__ */
