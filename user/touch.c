//1.3
// This C program implements a "touch" command that creates a new empty file with the specified name (argv[1]) if it doesn't already exist, exiting with an error if the file exists or cannot be created.
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(int argc, char *argv[]) {
    int fd;
    struct stat st;

    if (argc != 2) {
        fprintf(2, "Usage: touch <filename>\n");
        exit(1);
    }

    if (stat(argv[1], &st) == 0) {
        fprintf(2, "touch: %s already exists\n", argv[1]);
        exit(1);
    }

    fd = open(argv[1], O_CREATE | O_WRONLY);
    if (fd < 0) {
        fprintf(2, "touch: cannot create %s\n", argv[1]);
        exit(1);
    }
    close(fd);
    exit(0);
}
