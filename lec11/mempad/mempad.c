#include <stdio.h>

struct Test {
    short a;
    int b;
    int c;
    double d;
} ;

int main() {
    printf("%-25s = %zu bytes\n", "Size of short",  sizeof(short));
    printf("%-25s = %zu bytes\n", "Size of int",    sizeof(int));
    printf("%-25s = %zu bytes\n", "Size of double", sizeof(double));

    struct Test test;
    printf("%-25s = %zu bytes\n", "Size of test object", sizeof(test));

    printf("\n");

    printf("%-35s = %p\n", "Address of Test object",     (void *)&test);
    printf("%-35s = %p\n", "Address of test.a (short)",  (void *)&test.a);
    printf("%-35s = %p\n", "Address of test.b (int)",    (void *)&test.b);
    printf("%-35s = %p\n", "Address of test.c (int)",    (void *)&test.c);
    printf("%-35s = %p\n", "Address of test.d (double)", (void *)&test.d);

    /*
    some notes about the printf statements above:
    1. sizeof() and the size_t type: 
        - sizeof() returns a value of type size_t.
        - size_t type: an unsigned integer type used to represent the size of any object in memory,
        and its size is chosen to be large enough to hold the maximum possible object size on the target system.
    2. %zu is used to print out the value of a size_t type. 
    3. %-25s, %-35s: this is to properly align the output to make it more readable.
        %s: This is the format specifier for a C string (char *).
        25: This is the minimum field width. The printed string will occupy at least 25 characters.
        - (minus sign): This means left-justify within that field. Without -, the string would be right-justified.
    4. %p: when we want to print out an adddres. 
        This expects a void *. Passing anything else is undefined behavior, so we explicitly cast.
    */

    return 0;
}
