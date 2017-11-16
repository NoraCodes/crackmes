#include <stdio.h>
#include <string.h>

// A very simple crackme which stores the correct password in program memory
// and uses the builtin string comparison function to check it.

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char* correct = "password1";

    if (strncmp(argv[1], correct, strlen(correct))) {
        printf("No, %s is not correct.\n", argv[1]);
        return 1;
    } else {
        printf("Yes, %s is correct!\n", argv[1]);
        return 0;
    }

}
