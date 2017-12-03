#include <stdio.h>
#include <string.h>

// This crackme adds a hardcoded mask to its hardcoded password.

#define CORRECT_LEN 8

// Returns one if the given password is equal to the given correct word masked
// with the given mask.
int check_pw(char* password, char* correct, char* mask) {
    // Look at each character of the submitted string, computing the mask along the way.
    int i = 0;
    // If this is never modified, the password was right.
    char success = 1;
    do {
        char masked_char = correct[i] + mask[i];
        if (masked_char != password[i]) {
            return 0;
        }
        i++;
    } while (correct[i] != 0 && password[i] != 0);
    return 1;
}

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char correct[CORRECT_LEN + 1] = "password";
    char mask[CORRECT_LEN + 1] = {3, 5, 2, 4, 1, 0, 3, 1};
    
    if (strlen(argv[1]) == CORRECT_LEN && check_pw(argv[1], correct, mask)) {
        printf("Yes, %s is correct!\n", argv[1]);
        return 0;
    }
    
    printf("No, %s is not correct.\n", argv[1]);
    return 1;

}
