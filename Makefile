##
## Makefile for aimxOS in /home/rannou_s/work/c/aimxOS
## 
## Made by sebastien rannou
## Login   <rannou_s@epitech.net>
## 
## Started on  Thu Nov 26 15:45:42 2009 sebastien rannou
## Last update Fri Nov 27 10:10:58 2009 sebastien rannou
##

include Makefile.inc

all:

	make -C src/ all
	make -C img/ all

clean:
	make -C src/ clean
	make -C img/ clean

re:	clean all
