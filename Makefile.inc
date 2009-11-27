##
## Makefile.inc for aimxhOS in /home/rannou_s/work/c/aimxOS/src
## 
## Made by sebastien rannou
## Login   <rannou_s@epitech.net>
## 
## Started on  Thu Nov 26 16:24:49 2009 sebastien rannou
## Last update Fri Nov 27 10:09:02 2009 sebastien rannou
##

# Change this is you need to custom your paths

LD		=	ld
NASM		=	nasm
CC		=	gcc
MV		=	mv
MAKE		=	gmake
RM		=	rm -f
CAT		=	cat

# Change this if you need to custom outputs

KERNEL_IMAGE	=	kernel.bin
GRUB_IMAGE	=	floppy.img
CFLAGS		=	-Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin
