//2.2
// This C program retrieves and prints the total number of system calls made since system boot using the `countsyscall` function and then exits.
#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  printf("Total syscalls since boot: %d\n", countsyscall());
  exit(0);
}
