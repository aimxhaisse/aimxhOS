/*
** kdb.h for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Mon Dec  7 10:59:17 2009 sebastien rannou
** Last update Mon Dec  7 11:07:28 2009 sebastien rannou
*/

#ifndef __KDB_H__
#define __KDB_H__

#include "types.h"

uchar
kbdus[128] =
  {
    0,
    27,
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '-',
    '=',
    '\b',
    '\t',
    'q',
    'w',
    'e',
    'r',
    't',
    'y',
    'u',
    'i',
    'o',
    'p',
    '[',
    ']',
    '\n',
    0,         /* 29   - Control */
    'a',
    's',
    'd',
    'f',
    'g',
    'h',
    'j',
    'k',
    'l',
    ';',
    '\'',
    '`',
    0,         /* Left shift */
    '\\',
    'z',
    'x',
    'c',
    'v',
    'b',
    'n',
    'm',
    ',',
    '.',
    '/',
    0,          /* Right shift */
    '*',
    0,          /* Alt */
    ' ',
    0,          /* Caps lock */
    0,          /* 59 - F1 key ... > */
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,          /* < ... F10 */
    0,          /* 69 - Num lock*/
    0,          /* Scroll Lock */
    0,          /* Home key */
    0,          /* Up Arrow */
    0,          /* Page Up */
    '-',
    0,          /* Left Arrow */
    0,
    0,          /* Right Arrow */
    '+',
    0,          /* 79 - End key*/
    0,          /* Down Arrow */
    0,          /* Page Down */
    0,          /* Insert Key */
    0,          /* Delete Key */
    0,0,0,
    0,          /* F11 Key */
    0,          /* F12 Key */
    0,          /* All other keys are undefined */
  };

#endif /* __KDB_H__ */
