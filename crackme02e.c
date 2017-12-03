#include <stdio.h>
#include <string.h>

// A less simple crackme which has its own string comparison function and uses
// a hardcoded, unchanging transform over a hardcoded password.

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char* correct = "yuvmnpoi";
    // The actual correct value is wstklnmg
    
    int i = 0;
    while(correct[i] != 0 && argv[1][i] != 0) {
        if (correct[i] - 2 != argv[1][i]) {
            printf("No, %s is not correct.\n", argv[1]);
            return 1;
        }
        i++;
    }

    printf("Yes, %s is correct!\n", argv[1]);
    return 0;

}
