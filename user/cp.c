//1.5
// This C program implements a "cp" command that copies the contents of a source file (argv[1]) to a destination file (argv[2]), reading and writing in 512-byte chunks, exiting with an error if the source cannot be opened, the destination cannot be created, or a write operation fails.
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

#define BUF_SIZE 512

int
main(int argc, char *argv[])
{
  int src_fd, dst_fd, n;
  char buf[BUF_SIZE];

  if(argc != 3){
    fprintf(2, "Usage: cp <source> <destination>\n");
    exit(1);
  }

  src_fd = open(argv[1], O_RDONLY);
  if(src_fd < 0){
    fprintf(2, "cp: cannot open %s\n", argv[1]);
    exit(1);
  }

  dst_fd = open(argv[2], O_CREATE | O_WRONLY);
  if(dst_fd < 0){
    fprintf(2, "cp: cannot create %s\n", argv[2]);
    close(src_fd);
    exit(1);
  }

  while((n = read(src_fd, buf, sizeof(buf))) > 0){
    if(write(dst_fd, buf, n) != n){
      fprintf(2, "cp: write error\n");
      close(src_fd);
      close(dst_fd);
      exit(1);
    }
  }

  close(src_fd);
  close(dst_fd);
  exit(0);
}
