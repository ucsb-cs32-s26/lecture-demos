// Compile:  gcc -o io 02_io.c
// Run:      ./io
//
// Demo: printf format specifiers, scanf with & (vs C++ cin)
// what happens if you forget & in scanf?

#include <stdio.h>

int main(void) {
    int age;
    float gpa;
    char initial;

    // --- printf ---
    int x = 5, y = 10;
    float pi = 3.14f;

    printf("x is %d and y is %d\n", x, y);
    printf("pi = %f\n", pi);
    printf("pi (shorter) = %g\n", (double)pi);
    printf("tab-separated:\t%d\t%f\n", x, pi);

    // --- scanf ---
    // WRONG (do NOT do this):
    scanf("%d", age);          // missing &, undefined behavior

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    printf("Enter your first initial: ");
    scanf(" %c", &initial);     // note space before %c to skip newline

    // most specifiers (like %d, %f, and %s) automatically skip leading whitespace (newlines, spaces, and tabs)
    // %c do not skip whitespace. They read the very next character in the buffer, even if that character 
    // is a space or a newline from a previous Enter key press.

    printf("Age: %d, GPA: %.2f, Initial: %c\n", age, gpa, initial);

    return 0;
}
