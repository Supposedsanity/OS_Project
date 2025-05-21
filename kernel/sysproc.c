#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

extern struct proc proc[];

// Define SCHED_PRIORITY if not already defined
#ifndef SCHED_PRIORITY
#define SCHED_PRIORITY 2
#endif

uint64 sys_getppid(void); //2.3 Get parent process ID

uint64 sys_getptable(void); //2.4 Get process table


extern int getptable(int nproc, uint64 buffer); //2.4 Get process table

//2.4 Get process table
uint64
sys_getptable(void)
{
  int nproc;
  uint64 buffer;
  argint(0, &nproc);
  argaddr(1, &buffer);
  return getptable(nproc, buffer);
}

uint64
sys_getppid(void)
{
  struct proc *p = myproc();

  if(p->parent == 0) {
    return 1; // init process (pid 1) is root parent
  }

  return p->parent->pid;
}

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}
//2.3 Get process ID
uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}


uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}
//1.1 Sleep for a number of milliseconds
uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  if(n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_setscheduler(void)
{
  int mode;
  argint(0, &mode);
  if (mode == SCHED_ROUND_ROBIN || mode == SCHED_FCFS || mode == SCHED_PRIORITY) {
    sched_mode = mode;
    return 0;
  }
  return -1; // invalid mode
}

uint64
sys_setpriority(void)
{
  int pid, priority;
  argint(0, &pid);
  argint(1, &priority);

  struct proc *p;
  for(p = proc; p < &proc[NPROC]; p++){
    acquire(&p->lock);
    if(p->pid == pid){
      p->priority = priority;
      release(&p->lock);
      return 0;
    }
    release(&p->lock);
  }
  return -1; // pid not found
}

uint64
sys_printmetrics(void)
{
  print_metrics();
  return 0;
}
