/*
** process.h for aimxhOS in /home/rannou_s/work/aimxhOS
** 
** Made by sebastien rannou
** Login   <rannou_s@epitech.net>
** 
** Started on  Thu Dec 10 14:35:41 2009 sebastien rannou
** Last update Thu Dec 10 15:03:02 2009 sebastien rannou
*/

#ifndef __PROCESS_H__
#define __PROCESS_H__

/**!
 * State of the process (what we need to keep before switching)
 */

typedef struct  pstate
{
  uint          eax, ecx, edx, ebx;
  uint          esp, ebp, esi, edi;
  uint          eip, eflags;
  uint          cs:16, ss:16, ds:16, es:16, fs:16, gs:16;
  uint          cr3;
} __attribute__ ((packed)) pstate_t;

/**!
 * Structure of a process
 */

typedef struct  process
{
  uint          pid;            /* process ID */
  uint          nice;           /* priority */
  uint          stime;          /* time since starting */
  uint          rtime;          /* ticks since last execution */
  char          name[128];      /* process' name */
  pstate_t      state;          /* process's state */
} __attribute__((packed)) process_t;

#endif /* __PROCESS_H__ */
