/*
** gdt.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Fri Nov 27 17:08:19 2009 sebastien rannou
** Last update Fri Dec 11 09:54:24 2009 sebastien rannou
*/

#include "types.h"
#include "gdt.h"
#include "system.h"

/**!
 * The code here is taken from:
 * http://www.osdever.net/bkerndev/Docs/gdt.htm
 * It will evolute when I be more aware of what I really want to do
 */

typedef struct  tss
{
  ushort        previous_task, __previous_task_unused;
  uint          esp0;
  ushort        ss0, __ss0_unused;
  uint          esp1;
  ushort        ss1, __ss1_unused;
  uint          esp2;
  ushort        ss2, __ss2_unused;
  uint          cr3;
  uint          eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi;
  ushort        es, __es_unused;
  ushort        cs, __cs_unused;
  ushort        ss, __ss_unused;
  ushort        ds, __ds_unused;
  ushort        fs, __fs_unused;
  ushort        gs, __gs_unused;
  ushort        ldt_selector, __ldt_sel_unused;
  ushort        debug_flag, io_map;
} __attribute__ ((packed)) tss_t;

typedef struct  gdt_entry
{
  ushort        limit_low;
  ushort        base_low;
  uchar         base_middle;
  uchar         access;
  uchar         granularity;
  uchar         base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct  gdt_ptr
{
  ushort        limit;
  uint          base;
} __attribute__((packed)) gdt_ptr_t;

#define GDT_ENTRY_NUMBER        6

/**!
 * Global symbols
 */

gdt_entry_t
gdt[GDT_ENTRY_NUMBER];

gdt_ptr_t
gdt_p;

tss_t
gdt_default_tss;

/**!
 * Sets up a gdt entry
 */

static void 
gdt_set_gate(int num, ulong base, ulong limit, uchar access, uchar gran)
{

  gdt[num].base_low = (base & 0xFFFF);
  gdt[num].base_middle = (base >> 16) & 0xFF;
  gdt[num].base_high = (base >> 24) & 0xFF;

  gdt[num].limit_low = (limit & 0xFFFF);
  gdt[num].granularity = ((limit >> 16) & 0x0F);

  gdt[num].granularity |= (gran & 0xF0);
  gdt[num].access = access;

}

/**!
 * Initialize TSS
 */

static void
gdt_tss_init(void)
{

  gdt_default_tss.debug_flag = 0x00;
  gdt_default_tss.io_map = 0x00;
  gdt_default_tss.esp0 = 0x1FFF0;
  gdt_default_tss.ss0 = 0x18;

}

/**!
 * Called during initialization of the kernel
 */

void
gdt_install(void)
{

  gdt_tss_init();
  gdt_p.limit = sizeof(gdt) - 1;
  gdt_p.base = (uint) gdt;
  gdt_set_gate(0, 0, 0, 0, 0);

  /* Kernel's  GDT*/
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

  /* Userland's GDT */  
  gdt_set_gate(3, 0, 0xFFFFFFFF, 0xF8, 0xC);
  gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF0, 0xC);

  /* TSS */
  gdt_set_gate(5, (uint) &gdt_default_tss, sizeof(gdt_default_tss), 0x89, 0xC);

  gdt_flush();

  /* Load Task Register, 0x28 <=> 6'th rank in GDT */
  asm("movw $0x28, %ax \n \
       ltr %ax");

}
