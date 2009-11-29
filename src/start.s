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

;;; This part concerns the IDT and is strongly
;;; linked to idt.c

global  idt_load
extern  idt_p

idt_load:

        lidt [idt_p]
        ret

;;; ISRS

extern  fault_handler

global  irs_0                   ; Floating exception

;;; Floating Exception
;;; No error, ID = 0x0

irs_0:

        push BYTE 0
        push 0x0
        jmp irs_handler

irs_handler:

        pusha
        push ds
        push es
        push fs
        push gs
        
        mov ax, 0x10
        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov eax, esp
        push eax
        mov eax, fault_handler
        call eax
        pop eax

        pop gs
        pop fs
        pop es
        pop ds
        popa
        add esp, 8              ; error + id previously pop
        iret
        
SECTION .bss
ALIGN   4

stack:
        resb STACKSIZE
