##
## Makefile for aimxOS in /home/rannou_s/work/c/aimxOS
## 
## Made by sebastien rannou
## Login   <rannou_s@epitech.net>
## 
## Started on  Thu Nov 26 15:45:42 2009 sebastien rannou
## Last update Fri Dec 11 13:25:58 2009 sebastien rannou
##

include ../Makefile.inc

C_SRCS		=	klib.c main.c screen.c gdt.c idt.c splash.c isr.c irq.c \
			timer.c kprintf.c kbd.c sched.c
C_OBJS		=	$(C_SRCS:.c=.o)
CFLAGS 		+=	-I../includes/

all:	$(C_OBJS)
	$(NASM) -f elf start.s
	$(NASM) -f elf sched.s -o sched_asm.o
	$(LD)  -T link.ld -o $(KERNEL_IMAGE) *.o

clean:
	$(RM) *.o *~ $(KERNEL_IMAGE)

re:	all clean
