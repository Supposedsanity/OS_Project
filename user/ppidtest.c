#include "kernel/types.h"
#include "user/user.h"

int main()
{
  int pid = fork();

  if(pid == 0) {
    // Child process
    printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    exit(0);
  } else {
    // Parent process
    wait(0);
    printf("Parent PID: %d, Parent's Parent PID: %d\n", getpid(), getppid());
  }

  exit(0);
}
