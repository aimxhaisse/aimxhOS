/*
** sched.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec 10 14:24:06 2009 sebastien rannou
** Last update Fri Dec 11 13:53:20 2009 sebastien rannou
*/

#include "system.h"
#include "klib.h"
#include "process.h"

/**!
 * This scheduler is quite basic, each process has a nice, which is it's priority.
 *
 * Sched is called each time IRQ's timer is raised and switches the living process
 * with the most appropriated one, according to its nice.
 */

/**!
 * Temporary code here, current list of running processes
 */
static process_t
running_process[4];

/**!
 * Pointer to the living process
 */
static process_t *
current_process = 0;

static uint *
stack;

/**!
 * Updates the last living process
 */
static void
sched_update_process(process_t * process)
{
  if (process)
    {
      process->rtime = 0;
    }
}

/**!
 * Returns the priority of the thread
 * Highest is better
 */
static int
sched_process_priority(process_t * process)
{
  if (process)
    {
      return process->nice * process->rtime;
    }

  return 0;
}

/**!
 * Resume the chosen process
 */
static void
sched_resume_process(process_t * process)
{
  if (process)
    {
      kprintf("let's run process: %d\n", process->pid);
      current_process = process;
    }  
}

/**!
 * Save the current state of the current process
 * Current state of the stack is the following:
 * http://a.michelizza.free.fr/uploads/TutoOS/user_sched_stack.png
 */

static void
sched_save_process(void)
{
  asm("mov (%%ebp), %%eax; mov %%eax, %0" : "=m" (stack) : );
  
  current_process->state.eflags = stack[16];
  current_process->state.cs  = stack[15];
  current_process->state.eip = stack[14];
  current_process->state.eax = stack[13];
  current_process->state.ecx = stack[12];
  current_process->state.edx = stack[11];
  current_process->state.ebx = stack[10];
  current_process->state.ebp = stack[8];
  current_process->state.esi = stack[7];
  current_process->state.edi = stack[6];
  current_process->state.ds = stack[5];
  current_process->state.es = stack[4];
  current_process->state.fs = stack[3];
  current_process->state.gs = stack[2];
  current_process->state.esp = stack[17];
  current_process->state.ss = stack[18];
}

/**!
 * Switches to the new process
 */

static void
sched_switch_process(void)
{
  extern tss_t  gdt_default_tss;
  uint          esp0, eflags;
  ushort        ss, cs;

  gdt_default_tss.esp0 = (uint) (&stack[19]);  

  ss = current_process->state.ss;
  cs = current_process->state.cs;
  eflags = (current_process->state.eflags | 0x200) & 0xFFFFBFFF;
  esp0 = gdt_default_tss.esp0;

  asm("mov %0, %%esp; \
       push %1;                                 \
       push %2;                                 \
       push %3;                                 \
       push %4;                                 \
       push %5;                                 \
       push %6;                                 \
       ljmp $0x08, $do_switch"                  \
      ::                                        \
       "m" (esp0),                              \
       "m" (ss),                                \
       "m" (current_process->state.esp),        \
       "m" (eflags),                            \
       "m" (cs),                                \
       "m" (current_process->state.eip),        \
       "m" (current_process)
      );
}

/**!
 * Main entry of the scheduler
 */

void
sched(void)
{
  int           i;
  int           priority;
  int           highest_priority = 0;
  process_t *   next_process = 0;

  sched_update_process(current_process);
  for (i = 0; i < 4; ++i)
    {
      running_process[i].rtime++;
      running_process[i].stime++;
      priority = sched_process_priority(&running_process[i]);
      if (priority > highest_priority)
        {
          highest_priority = priority;
          next_process = &running_process[i];
        }
    }
  sched_resume_process(next_process);
}

/**!
 * Let's initialize the scheduler
 */

void
sched_install(void)
{
  memset((uchar *) &running_process, 0, sizeof(running_process));  

  running_process[0].pid = 1;
  running_process[0].nice = 100;

  running_process[1].pid = 2;
  running_process[1].nice = 50;

  running_process[2].pid = 3;
  running_process[2].nice = 200;

  running_process[3].pid = 4;
  running_process[3].nice = 0;
}
