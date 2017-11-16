#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Never stores the correct password; instead, accepts any password
// whose length is 16 and whose characters, in ASCII, sum to 1652.
// This is 16 * 110 + 2, so the characters average on 'n', but two must be higher.

#define CORRECT_LEN 16
#define CORRECT_SUM 1652

int main(int argc, char** argv) {

    char correct = 0;

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    // Loop over the whole string
    int i = 0;
    int sum = 0;
    while (argv[1][i] != 0) {
        i++;
        sum += argv[1][i];
    }

    correct = (i == CORRECT_LEN) && (sum == CORRECT_SUM);
    printf("i is %d, sum is %d, correct is %d\n", i, sum, correct);

    if (correct) {
        printf("Yes, %s is correct!\n", argv[1]);
        return 0;
    } else {
        printf("No, %s is not correct.\n", argv[1]);
        return 1;
    }
}
