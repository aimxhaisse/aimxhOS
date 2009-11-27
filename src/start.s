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

;;; Let's call our main!

loader:
        mov esp, stack+STACKSIZE
        push eax
        push ebx

        call kmain
        cli

hang:
        hlt
        jmp hang

;;; This part concerns the GDT and is strongly
;;; linked to gdt.c

global  gdt_flush
extern  gdt_p                   ; declared in gdt.c

gdt_flush:
        lgdt [gdt_p]
        mov ax, 0x10            ; 0x10 is the offset in the GDT to our data segment
        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov ss, ax
        jmp 0x08:flush

flush:
        ret

SECTION .bss
ALIGN   4

stack:
        resb STACKSIZE
