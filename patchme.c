#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void key_gen(char * pKey) {
    int i; // Declares integer used in the for loops
    for (i=0;i < 15; i++) {
        if (i == 4 || i == 9 || i == 14) {
            pKey[i] = '-';
        } else {
            // A random character 0x41-0x51 (A-Z) in the ASCII table range
            pKey[i] = rand() % (0x51 - 0x41) + 0x41;
        }
    }

    for (i=15;i < 19; i++) {
        // A random number 0x30-0x39 (0-9) in the ASCII table range
        pKey[i] = rand() % (0x39 - 0x30) + 0x30;
    }
    pKey[i] = 0; // Adds a nullbyte at the end of the string
}

int main(int argc, char *argv[]) {
    // Initial check, if number of arguments matched the expected
    if (argc != 2) {
        printf("Usage: %s <KEY>\n", argv[0]);
        exit(1);
    }

    char key[20];
    srand((unsigned) time(NULL)); // Creates seed number for the key generator, rand()
    key_gen(key); // Calls the key_gen function with key

    // compares the user input with the string
    if (strncmp(argv[1], key, 20) != 0) {
        printf("Wrong key! Expected: %s\n", key);
        exit(1);
    } else {
        printf("Congratz! You just learned patching\n");
    }
    return 0;
}
