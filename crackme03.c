#include <stdio.h>
#include <string.h>

// This crackme adds a changing but hardcoded mask to its hardcoded password.

#define CORRECT_LEN 8

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char correct[CORRECT_LEN + 1] = "password1";
    char mask[CORRECT_LEN + 1] = {1, 1, 3, 5, 1, 3, 4, 6, 0};
    // This makes the real password "qbvx"

    // Look at each character of the submitted string, computing the mask along
    // the way.
    int i = 0;
    do {
        char masked_char = correct[i] + mask[i];
        if (masked_char != argv[1][i]) {
            break;
        }
        i++;
    } while (correct[i] != 0 && argv[1][i] != 0);

    // The submitted password is too long, or we exited early from the loop,
    // the password is wrong
    if ((correct[i] == 0 && argv[1][i] != 0) || correct[i] != 0) {
        printf("No, %s is not correct.\n", argv[1]);
        return 1;
    }
    
    // If all checks passed, the password is right
    printf("Yes, %s is correct!\n", argv[1]);
    return 0;

}
