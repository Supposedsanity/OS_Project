//2.2
// // This C program retrieves and prints the total number of system calls made since system boot using the countsyscall function and exits.
#include "types.h"

extern int syscall_count;

uint64
sys_countsyscall(void)
{
  return syscall_count;
}
