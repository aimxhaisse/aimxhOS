/*
** screen.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Nov 27 11:11:49 2009 sebastien rannou
** Last update Mon Dec  7 11:08:54 2009 sebastien rannou
*/

#include "screen.h"
#include "klib.h"

static scr_char_t *
screen_memory = SCR_PTR;

static int
screen_cursor_x = 0;

static int
screen_cursor_y = 0;

/**!
 * Internal functions
 */

static scr_char_t *
screen_getc(int x, int y);

static void
screen_cursor_forward(void);

static void
screen_cursor_tab(void);

/**!
 * Simply clears the screen
 */

void
screen_clear(void)
{

  memset((uchar *) screen_memory, 0, SCR_SIZE * sizeof(scr_char_t));
  screen_cursor_x = 0;
  screen_cursor_y = 0;

}

/**!
 * Scroll down, no history is kept so we can't scroll up
 */

#define SIZE_LINE       (SCR_W * sizeof(scr_char_t))

void
screen_scroll(void)
{
  int                   y;

  for (y = 1; y < SCR_H; ++y)
    {
      memcpy((uchar *) SCR_PTR + (y - 1) * SIZE_LINE,
             (uchar *) SCR_PTR + y * SIZE_LINE,
             SIZE_LINE);
    }
  memset((uchar *) SCR_PTR + (SCR_H - 1) * SIZE_LINE, 0, SIZE_LINE);

}

/**!
 * Insert a charactere on the screen and increments the cursor
 */

void
screen_insertc(char c)
{
  scr_char_t *          scr_c = screen_getc(screen_cursor_x, screen_cursor_y);
  
  if (scr_c)
    {
      scr_c->c = c;
      scr_c->fg = LIGHT_GREEN;
      scr_c->bg = BLACK;
      screen_cursor_forward();
    }

}

/**!
 * Move the cursor down
 */

void
screen_cursor_down(void)
{

  screen_cursor_x = 0;
  ++screen_cursor_y;
  if (screen_cursor_y == SCR_H)
    {
      screen_scroll();
      --screen_cursor_y;
    }

}

/**!
 * Put a charactere on the screen, performing specific
 * actions if the char is special (\n, \a, ...)
 */

int
screen_putc(char c)
{
  int           val = 0;

  switch (c)
    {

    case '\n':
      screen_cursor_down();
      break;

    case '\t':
      screen_cursor_tab();
      break;

    case '\0':
      break;

    default:
      ++val;
      screen_insertc(c);

    }

  return val;
}

/**!
 * Prints a string on the screen
 */

int
screen_puts(const char * s)
{
  int                   i;
  int                   val = 0;

  for (i = 0; s[i] != '\0'; ++i)
    {
      val += screen_putc(s[i]);
    }

  return val;
}

/**!
 * Internal function that returns the adress of the scr_char_t
 */

static scr_char_t *
screen_getc(int x, int y)
{

  if (x >= 0 && x < SCR_W && y >= 0 && y < SCR_H)
    {
      return &SCR_PTR[x + y * SCR_W];
    }

  return 0;
}

/**!
 * Moves the cursor forwards
 */

static void
screen_cursor_forward(void)
{

  ++screen_cursor_x;
  if (screen_cursor_x == SCR_W)
    {
      screen_cursor_x = 0;
      ++screen_cursor_y;
      if (screen_cursor_y == SCR_H)
        {
          screen_cursor_y--;
          screen_scroll();
        }
    }

}

static void
screen_cursor_tab(void)
{
  int           i;

  for (i = 0; i < 4; ++i)
    {
      screen_cursor_forward();
    }

}
