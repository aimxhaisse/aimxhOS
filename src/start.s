;;; Main entry of the kernel
;;; Jump from GRUB to kmain

global  loader
extern  kmain
extern  ping

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

;;; This macro registers a new ISR without error handling
;;; We push 0x0 for a default error value
        
%macro  isr_noerr 1

global  isr_%1
        
isr_%1:
        
        push BYTE %1
        push 0x0
        jmp isr_handler

%endmacro

isr_noerr 0                     ; floating exception
isr_noerr 1                     ; debug exceptions
isr_noerr 2                     ; intel reserved
isr_noerr 3                     ; breakpoint
isr_noerr 4                     ; overflow
isr_noerr 5                     ; bounds check
isr_noerr 6                     ; invalid opcode
isr_noerr 7                     ; coprocessor not available
isr_noerr 8                     ; double fault
isr_noerr 9                     ; coprocessor segment overrun
isr_noerr 10                    ; invalid tss
isr_noerr 11                    ; segment not present
isr_noerr 12                    ; stack exception
isr_noerr 13                    ; triple fault

global  isr_14                  ; page fault
        
isr_14:

        push BYTE 14
        mov eax, cr2
        push eax                ; Address that faulted
        jmp isr_handler
        
isr_noerr 15                    ; intel reserved
isr_noerr 16                    ; corprocessor error

isr_handler:
        
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
