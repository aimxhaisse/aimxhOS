/*
** sched.c for aimxhOS in /home/rannou_s/work/aimxhOS/src
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec 10 14:24:06 2009 sebastien rannou
** Last update Thu Dec 10 15:23:35 2009 sebastien rannou
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

int
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

void
sched_resume_process(process_t * process)
{

  if (process)
    {
      kprintf("let's run process: %d\n", process->pid);
      current_process = process;
    }
  
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
  running_process[1].nice = 200;

  running_process[2].pid = 3;
  running_process[2].nice = 300;

  running_process[3].pid = 4;
  running_process[3].nice = 400;

}
