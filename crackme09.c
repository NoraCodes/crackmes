#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cpuid.h>

// Require that the input string pass a state machine matching:
// Qz+327x*[^n]n+(l9)+

void succeed(char* string) {
    printf("Yes, %s is correct!\n", string);
    exit(0);
}

void fail(char* string) {
    printf("No, %s is not correct.\n", string);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Need exactly one argument.\n");
        return -1;
    }

    char state = 0;
    for (int i = 0; argv[1][i] != '\0'; i++) {
        char c = argv[1][i];
        switch (state) {
            case 0:
                if (c == 'Q') { state = 1; } else { state = 12; }
                break;
            case 1:
                if (c == 'z') { state = 2; } else { state = 12; }
                break;
            case 2:
                if (c == 'z') { state = 2; }
                else if (c == '3')  { state = 3; }
                else { state = 12; }
                break;
            case 3:
                if (c == '2') { state = 4; } else { state = 12; }
                break;
            case 4:
                if (c == '7') { state = 5; } else { state = 12; }
                break;
            case 5:
                if (c == 'x') { state = 7; } else { state = 6; }
                break;
            case 6:
                if (c == 'n') { state = 8; } else { state = 12; }
                break;
            case 7:
                if (c != 'x') { state = 6; }
                break;
            case 8:
                if (c == 'l') { state = 9; }
                else if (c != 'n') { state = 12; }
                break; 
            case 9:
                if (c == '9') { state = 10; } else { state = 12; }
                break;
            case 10:
                if (c == 'l') { state = 9; } else { state = 12; }
                break;
            default:
                state = 12;
                break;
        }
    } 
    if (state == 10) {
        succeed(argv[1]);
    } else {
        fail(argv[1]);
    }
}
