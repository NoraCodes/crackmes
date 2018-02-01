#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Reads characters from a given file 

void succeed() {
    printf("Access granted!\n");
    exit(0);
}

void fail() {
    printf("Access denied.\n");
    exit(1);
}

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char* filename = argv[1];
    FILE* f = fopen(filename, "r");
    if (errno != 0) {
        perror("PANIC! Aborting due to");
        return -1;
    }

    char buffer[16];
    int read = fread(buffer, 16, 1, f);
    if (errno != 0) {
        perror("PANIC! Aborting due to");
        return -1;
    }

    if (strncmp("leotindall.com", buffer, 16) != 0) {
        fail();
    }
    
    succeed();
}
