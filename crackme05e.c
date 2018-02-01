#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void succeed(char* string) {
    printf("Yes, %s is correct!\n", string);
    exit(0);
}

void fail(char* string) {
    printf("No, %s is not correct.\n", string);
    exit(1);
}

int check_with_mod(char* substring, int n, int mod) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + substring[i];
    }
    return (sum % mod) == 0;
}

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char* input = argv[1];

    int len = strnlen(input, 1000);
    if (len != 16) {
        fail(input);
    }

    // Add some fixed characters
    if (input[2] != 'm') {
        fail(input);
    }

    if (input[10] != '\'') {
        fail(input);
    }

    // Make the actual modulo checks
    if (!check_with_mod(input, 4, 2)) {
        fail(input);
    }

    if (!check_with_mod(input + 4, 4, 3)) {
        fail(input);
    }

    if (!check_with_mod(input + 8, 4, 5)) {
        fail(input);
    }

    if (!check_with_mod(input + 12, 4, 2)) {
        fail(input);
    }

    succeed(input);
}
