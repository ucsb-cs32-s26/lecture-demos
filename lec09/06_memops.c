// Compile:  gcc -o memops 06_memops.c
// Run:      ./memops
//
// Demo: void*, memset, memcpy
// Key point: memset works byte-by-byte — only reliable for 0 and -1 with ints

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ints(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // --- void* ---
    // malloc returns void* — must cast before use
    void *raw = malloc(4 * sizeof(int));
    int  *arr  = (int *)raw;            // explicit cast required in C
    for (int i = 0; i < 4; i++) {
        arr[i] = i + 1;
    }
    printf("via void* cast: ");
    print_ints(arr, 4);

    // --- memset to 0 (works correctly) ---
    memset(arr, 0, 4 * sizeof(int));
    printf("after memset 0: ");
    print_ints(arr, 4);

    // --- memset to 8 (WRONG for ints) ---
    memset(arr, 8, 4 * sizeof(int));
    printf("after memset 8 (byte trick!): ");
    print_ints(arr, 4);
    // Each int's 4 bytes are all set to 0x08:
    // 0x08080808 = 134744072

    free(arr);
    arr = NULL;

    // --- memcpy ---
    int src[5] = {10, 20, 30, 40, 50};
    int dst[5];

    memcpy(dst, src, 5 * sizeof(int));  // raw byte copy
    printf("memcpy'd dst: ");
    print_ints(dst, 5);

    // modify src — dst is independent (shallow copy of plain ints)
    src[0] = 999;
    printf("after src[0]=999, dst[0] = %d (unchanged)\n", dst[0]);

    return 0;
}
