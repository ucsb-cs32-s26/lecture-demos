// Compile:  gcc -o structs 04_structs.c
// Run:      ./structs
//
// Demo: struct definition, dot access, pointer + arrow, typedef
// C vs C++: no methods, no constructors, just data

#include <stdio.h>
#include <string.h>

// --- plain struct (must write "struct studentT" to declare a variable) ---
struct studentT {
    char  name[64];
    int   age;
    float gpa;
    int   grad_yr;
};

// --- typedef lets us drop the "struct" keyword ---
typedef struct {
    int x;
    int y;
} Point;

void print_student(struct studentT *s) {
    printf("Name: %s | Age: %d | GPA: %.2f | Grad: %d\n",
           s->name, s->age, s->gpa, s->grad_yr);
}

int main(void) {
    // --- declare and initialize via dot ---
    struct studentT s1;
    strcpy(s1.name, "Alice");
    s1.age     = 20;
    s1.gpa     = 3.8f;
    s1.grad_yr = 2026;

    printf("Direct access: %s, %d\n", s1.name, s1.age);

    // --- pointer + arrow syntax ---
    struct studentT *sptr = &s1;
    sptr->age = 21;                    // same as (*sptr).age = 21
    (*sptr).grad_yr = 2027;            // both forms are equivalent

    print_student(sptr);

    // --- typedef in action ---
    Point p;
    p.x = 3;
    p.y = 4;
    printf("Point: (%d, %d)\n", p.x, p.y);

    // --- sizeof ---
    printf("sizeof(struct studentT) = %zu\n", sizeof(struct studentT));  // %zu: format specifier for size_t data type.
    printf("sizeof(Point) = %zu\n", sizeof(Point));

    return 0;
}
