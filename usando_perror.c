#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fout;
    if ((fout = fopen(argv[1], "w")) == NULL) {
        perror("fopen: Could not open file for writing");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}