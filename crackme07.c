#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <time.h>

// Checks that the password is correct and that the time is between 0500 and 0659 local
#define PASSWORD "password1"
#define PASSLEN 9

void succeed() {
    printf("Access granted!\n");
    exit(0);
}

void fail() {
    printf("Access denied.\n");
    exit(1);
}

int cur_hour() {
    time_t rawtime;
    time(&rawtime);
    if (errno != 0) {
        printf("ERROR: Could not get time: %s", strerror(errno));
        return(-1);
    }
    struct tm *current_time = localtime(&rawtime);
    if (errno != 0) {
        printf("ERROR: Could not get time: %s", strerror(errno));
        return(-1);
    }
    return current_time->tm_hour;
}

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    int hour = cur_hour();
    char* input = argv[1];

    if (strncmp(input, PASSWORD, PASSLEN) != 0) {
        fail();
    }

    // Fail if not between 0500 and 0659
    if (hour < 5 || hour > 6) {
        fail();
    }

    succeed();
}
