//1.7
#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc != 2){
    fprintf(2, "Usage: fact <non-negative integer>\n");
    exit(1);
  }

   // check for both negative and non-integer inputs
  for(int i = 0; argv[1][i]; i++){
    if(argv[1][i] < '0' || argv[1][i] > '9'){
      fprintf(2, "Error: argument must be a non-negative integer\n");
      exit(1);
    }
  }

  int n = atoi(argv[1]); // converts input to integer

  uint64 res = 1;

  // loop for factorial calculation (starting from n=2)
  for(int i = 2; i <= n; i++){
    res *= i;
  }

  printf("%ld\n", res);
  exit(0);
}
