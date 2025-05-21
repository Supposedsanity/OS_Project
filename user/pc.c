//2.3,2.4
// This C program retrieves information about up to 64 processes using getptable, stores it in a procinfo structure, and prints a table of process details including PID, PPID, state (translated to a string via statename), name, and size, exiting with an error if getptable fails.
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

struct procinfo {
  int pid;
  int ppid;
  int state;
  char name[16];
  uint64 sz;
};

const char*
statename(int state) {
  switch(state) {
    case 0: return "UNUSED";
    case 1: return "USED";
    case 2: return "SLEEPING";
    case 3: return "RUNNABLE";
    case 4: return "RUNNING";
    case 5: return "ZOMBIE";
    default: return "UNKNOWN";
  }
}

int
main(int argc, char *argv[])
{
  int max = 64; // max number of processes to fetch
  struct procinfo table[max];

  int n = getptable(max, (void*)table);
  if(n <= 0){
    printf("getptable failed\n");
    exit(1);
  }

  printf("PID\tPPID\tSTATE\t\tNAME\t\tSIZE\n");
  for(int i = 0; i < n; i++){
    printf("%d\t%d\t%s\t\t%s\t\t%lu\n",
   table[i].pid,
   table[i].ppid,
   statename(table[i].state),
   table[i].name,
   table[i].sz);
  }

  exit(0);
}
