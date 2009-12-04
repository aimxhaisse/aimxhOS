/*
** libc.h for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:20:37 2009 sebastien rannou
** Last update Fri Dec  4 14:16:36 2009 sebastien rannou
*/

#ifndef __LIBC_H_
#define __LIBC_H_

#include "types.h"

uchar *
memcpy(uchar * dst, const uchar * src, int size);

uchar *
memset(uchar * dst, uchar val, int size);

ushort *
memsetw(ushort * dst, ushort val, int size);

int
strlen(const char * str);

void
putnbr(int number);

void
dumpmem(void * ptr, int size);

void
puts(const char * s);

void
putc(char c);

void
outportb(ushort _port, uchar _data);

uchar
importb(ushort _port);

#endif /* __LIBC_H_ */
