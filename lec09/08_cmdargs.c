// Compile:  gcc -o cmdargs 08_cmdargs.c
// Run:      ./cmdargs hello 10 "quotes for spaces"
//
// Demo: argc/argv, argv[0], atoi for numeric conversion

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc);

    // argv[0] is always the program name
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = \"%s\"\n", i, argv[i]);
    }

    // iterate without needing argc — argv is NULL-terminated
    printf("\nIterating via NULL sentinel:\n");
    for (char **ptr = argv; *ptr != NULL; ptr++) {
        printf("  %s\n", *ptr);
    }

    // numeric conversion: argv values are strings, not numbers
    if (argc >= 3) {
        int num = atoi(argv[2]);        // "10" -> 10
        printf("\nargv[2] as int: %d\n", num);
        printf("doubled: %d\n", num * 2);
    }

    return 0;
}
