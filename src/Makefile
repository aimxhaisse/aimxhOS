##
## Makefile for aimxOS in /home/rannou_s/work/c/aimxOS
## 
## Made by sebastien rannou
## Login   <rannou_s@epitech.net>
## 
## Started on  Thu Nov 26 15:45:42 2009 sebastien rannou
## Last update Fri Nov 27 13:00:12 2009 sebastien rannou
##

include ../Makefile.inc

ASM_SRCS	=	start.asm
C_SRCS		=	devices.c lib.c main.c screen.c

all:
	$(NASM) -f elf $(ASM_SRCS)
	$(CC) $(CFLAGS) -c $(C_SRCS) -I../includes/
	$(LD)  -T link.ld -o $(KERNEL_IMAGE) *.o

clean:
	$(RM) *.o *~ $(KERNEL_IMAGE)

re:	all clean
