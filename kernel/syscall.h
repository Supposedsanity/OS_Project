// System call numbers
#define SYS_fork    1 //1.6,1.7 Exit a process
#define SYS_exit    2 //1.6,1.7 Exit a process
#define SYS_wait    3 //1.6,1.7 Exit a process
#define SYS_pipe    4
#define SYS_read    5 //1.2,1.5 Read a file
#define SYS_kill    6 //1.6,1.7 Exit a process
#define SYS_exec    7 //1.6,1.7 Exit a process
#define SYS_fstat   8 //1.2,1.3 Get file status
#define SYS_chdir   9
#define SYS_dup    10
#define SYS_getpid 11
#define SYS_sbrk   12
#define SYS_sleep  13 //1.1 Sleep for a number of milliseconds
#define SYS_uptime 14
#define SYS_open   15 //1.2,1.3,1.5 Open a file
#define SYS_write  16 //1.2,1.5 Write to a file
#define SYS_mknod  17
#define SYS_unlink 18 //1.4 Delete a file
#define SYS_link   19 //1.4 Create a hard link
#define SYS_mkdir  20
#define SYS_close  21 //1.2,1.3,1.5 Close a file
#define SYS_kbdint 22 //2.1 Keyboard interrupt
#define SYS_countsyscall  23 //2.2 Count system calls
#define SYS_getppid 24
#define SYS_getptable 25 //2.4 Get process table
#define SYS_randd 26 //2.6 Random number generator
#define SYS_datetime 27 //2.5 Get current date and time
#define SYS_setscheduler  28
#define SYS_setpriority  29
#define SYS_printmetrics 30
