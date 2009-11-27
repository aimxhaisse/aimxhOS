##
## Makefile for aimxOS in /home/rannou_s/work/c/aimxOS
## 
## Made by sebastien rannou
## Login   <rannou_s@epitech.net>
## 
## Started on  Thu Nov 26 15:45:42 2009 sebastien rannou
## Last update Fri Nov 27 10:10:02 2009 sebastien rannou
##

include ../Makefile.inc

all:
	$(CAT) stage1 stage2 padding ../src/$(KERNEL_IMAGE) > ../$(GRUB_IMAGE)

clean:

	$(RM) ../$(GRUB_IMAGE)

re:	all clean
