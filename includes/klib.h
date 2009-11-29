/*
** libc.h for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:20:37 2009 sebastien rannou
** Last update Sun Nov 29 19:29:04 2009 sebastien rannou
*/

#ifndef __LIBC_H_
#define __LIBC_H_

unsigned char *
memcpy(unsigned char * dst, const unsigned char * src, int size);

unsigned char *
memset(unsigned char * dst, unsigned char val, int size);

unsigned short *
memsetw(unsigned short * dst, unsigned short val, int size);

int
strlen(const char * str);

void
putnbr(int number);

void
dumpmem(void * ptr, int size);

void
puts(const char * s);

#endif /* __LIBC_H_ */
