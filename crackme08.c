#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cpuid.h>

// Requires that the user input the CPUID,
// plus the bytes "3" and "Q";

void succeed(char* string) {
    printf("Yes, %s is correct!\n", string);
    exit(0);
}

void fail(char* string) {
    printf("No, %s is not correct.\n", string);
    exit(1);
}

void shift_int_to_char(int i, char* buff) {
    buff[0] = (i) & 0xFF;
    buff[1] = (i >> 8) & 0xFF;
    buff[2] = (i >> 16) & 0xFF;
    buff[3] = (i >> 24) & 0xFF;
}

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    unsigned int eax, ebx, ecx, edx;
    char* buff = malloc(sizeof(char) * 15);
    __get_cpuid(0, &eax, &ebx, &ecx, &edx);
    shift_int_to_char(ebx, buff);
    shift_int_to_char(edx, buff + 4);
    shift_int_to_char(ecx, buff + 8);
    buff[12] = '3';
    buff[13] = 'Q';
    buff[14] = '\0';
    
    int correct = (strcmp(buff, argv[1]) == 0);
    free(buff);

    if (correct) {
        succeed(argv[1]);
    } else {
        fail(argv[1]);
    }
}
