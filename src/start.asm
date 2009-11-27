;;; Main entry of the kernel
;;; Jump from GRUB to kmain

global  loader
extern  kmain

;;; Grub related stuff

MODULEALIGN equ 1<<0
MEMINFO     equ 1<<1
FLAGS       equ MODULEALIGN | MEMINFO
MAGIC       equ 0x1BADB002
CHECKSUM    equ -(MAGIC + FLAGS)

SECTION .text
ALIGN   4
        
mboot:
        dd MAGIC
        dd FLAGS
        dd CHECKSUM

STACKSIZE equ 0x4000

loader:
        mov esp, stack+STACKSIZE
        push eax
        push ebx

        call kmain
        cli

hang:
        hlt
        jmp hang

SECTION .bss
ALIGN   4

stack:
        resb STACKSIZE
