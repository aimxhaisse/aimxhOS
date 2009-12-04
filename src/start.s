;;; Main entry of the kernel
;;; Jump from GRUB to kmain
;;; 
;;; Contains also ways to deal with:
;;; GDT: Global Descriptor Table
;;; ISR: Interrupt Service Routine
;;; IDT: Interrupt Descriptor Table
;;; IRQ: Interrupt ReQuest

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

hang:
        hlt
        jmp hang

;;; ================= GDT =================
;;; This part concerns the GDT and is strongly
;;; linked to gdt.c
;;; =======================================

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

;;; ================= IDT =================
;;; This part concerns the IDT and is strongly
;;; linked to idt.c
;;; =======================================

global  idt_load
extern  idt_p

idt_load:

        lidt [idt_p]
        ret

;;; ================= ISR =================
;;; This part concerns ISRs and is strongly
;;; lined to isr.c
;;; =======================================
        
extern  isr_handler

;;; This macro registers a new ISR without error handling
;;; We push 0x0 for a default error value
        
%macro  isr_noerr 1

global  isr_%1
        
isr_%1:

        push BYTE 0x0
        push BYTE %1
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
        jmp isr_jumper
        
isr_noerr 15                    ; intel reserved
isr_noerr 16                    ; corprocessor error

isr_jumper:
        
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
        mov eax, isr_handler
        call eax
        pop eax

        pop gs
        pop fs
        pop es
        pop ds
        popa
        add esp, 8              ; error + id previously pop
        iret
        
;;; ================= IRQ =================
;;; This part concerns IRQs and is strongly
;;; linked to irq.c
;;; =======================================

extern irq_handler

;;; This macro registers a new IRQ

%macro  irq 1

global  irq_%1

irq_%1:

        cli
        push BYTE 0x0
        push BYTE 32+%1
        jmp irq_jumper
        
%endmacro

irq 0
irq 1
irq 2
irq 3
irq 4
irq 5
irq 6
irq 7
irq 8
irq 9
irq 10
irq 11
irq 12
irq 13
irq 14
irq 15

irq_jumper:

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
        mov eax, irq_handler
        call eax
        pop eax

        pop gs
        pop fs
        pop es
        pop ds
        popa
        add esp, 8              ; dummy error + id previously pop
        iret        
        
SECTION .bss
ALIGN   4

stack:
        resb STACKSIZE
