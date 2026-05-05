// Compile:  gcc -o strings 03_strings.c
// Run:      ./strings
//
// Demo: null termination, strlen, strcpy, strcat
// Key C vs C++ difference: no std::string — strings are char arrays

#include <stdio.h>
#include <string.h>

int main(void) {
    // --- null termination ---
    char str1[10];
    str1[0] = 'h';
    str1[1] = 'i';
    str1[2] = '\0';             // MUST terminate manually
    printf("str1 = %s\n", str1);

    // shorter: initialize from string literal
    char str2[10] = "hello";   // compiler adds '\0' automatically
    printf("str2 = %s\n", str2);

    // --- strlen ---
    int len = strlen(str2);
    printf("strlen(\"%s\") = %d\n", str2, len);

    // --- strcpy ---
    char dest[20];
    strcpy(dest, str2);         // copies str2 into dest
    printf("after strcpy: dest = %s\n", dest);

    // --- strcat ---
    strcat(dest, " world");     // appends " world" to dest
    printf("after strcat: dest = %s\n", dest);
    printf("new len = %zu\n", strlen(dest));

    // --- danger: buffer overflow ---
    // char tiny[5];
    // strcpy(tiny, "this string is too long");  // overflow!

    return 0;
}
