//1.4
// This C program implements a "mv" command that moves a file by creating a hard link from the source (argv[1]) to the destination (argv[2]) and then unlinking the source, exiting with an error if either operation fails.
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(2, "Usage: mv <source> <destination>\n");
        exit(1);
    }

    if (link(argv[1], argv[2]) < 0) {
        fprintf(2, "mv: cannot link %s to %s\n", argv[1], argv[2]);
        exit(1);
    }

    if (unlink(argv[1]) < 0) {
        fprintf(2, "mv: cannot unlink %s\n", argv[1]);
        exit(1);
    }

    exit(0);
}
