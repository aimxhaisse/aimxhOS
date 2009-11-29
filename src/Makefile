##
## Makefile for aimxOS in /home/rannou_s/work/c/aimxOS
## 
## Made by sebastien rannou
## Login   <rannou_s@epitech.net>
## 
## Started on  Thu Nov 26 15:45:42 2009 sebastien rannou
## Last update Sun Nov 29 19:55:53 2009 sebastien rannou
##

include ../Makefile.inc

ASM_SRCS	=	start.s
C_SRCS		=	devices.c klib.c main.c screen.c gdt.c idt.c splash.c

all:
	$(NASM) -f elf $(ASM_SRCS)
	$(CC) $(CFLAGS) -c $(C_SRCS) -I../includes/
	$(LD)  -T link.ld -o $(KERNEL_IMAGE) *.o

clean:
	$(RM) *.o *~ $(KERNEL_IMAGE)

re:	all clean
