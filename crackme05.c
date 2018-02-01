#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Splits the string up into 4 segments and checks the modulus of their sums
// with a few fixed characters

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

    // EEBD ,,,, 2222 QQOO
    //  %3   %4   %5   %4
    // ..B. .... .... .Q..


    // Add some fixed characters
    if (input[2] != 'B') {
        fail(input);
    }

    if (input[13] != 'Q') {
        fail(input);
    }


    // Make the actual modulo checks
    if (!check_with_mod(input, 4, 3)) {
        fail(input);
    }

    if (!check_with_mod(input + 4, 4, 4)) {
        fail(input);
    }

    if (!check_with_mod(input + 8, 4, 5)) {
        fail(input);
    }

    if (!check_with_mod(input + 12, 4, 4)) {
        fail(input);
    }

    succeed(input);
}
