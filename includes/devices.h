/*
** devices.h for aimxhOS in /home/rannou_s/work/c/aimxOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Nov 26 16:22:40 2009 sebastien rannou
** Last update Thu Nov 26 16:34:26 2009 sebastien rannou
*/

#ifndef __DEVICES_H__
#define __DEVICES_H__

unsigned char 
device_importb(unsigned short _port);

void
device_outportb (unsigned short _port, unsigned char _data);

#endif /* __DEVICES_H__ */
