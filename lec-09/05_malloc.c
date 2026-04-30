// Compile:  gcc -o malloc 05_malloc.c
// Run:      ./malloc
//
// Demo: malloc, calloc, realloc, free
// C vs C++: no new/delete — always malloc/free; always check NULL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // --- malloc: uninitialized ---
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("malloc failed\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;  // arr[i] --> *(arr+i)
    }
    printf("malloc'd array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // --- realloc: grow to 10 elements ---
    arr = (int *)realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("realloc failed\n");
        return 1;
    }
    for (int i = 5; i < 10; i++) {
        arr[i] = i * 10;
    }
    printf("realloc'd array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;   // good practice: avoids dangling pointer

    // --- calloc: zero-initialized ---
    int *zeros = (int *)calloc(5, sizeof(int));
    if (zeros == NULL) {
        printf("calloc failed\n");
        return 1;
    }
    printf("calloc'd array (all zeros): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", zeros[i]);
    }
    printf("\n");
    free(zeros);
    zeros = NULL;

    // --- dynamically allocated string ---
    char src[64] = "Hello";
    int  len     = strlen(src);
    char *dyn    = (char *)malloc((len + 1) * sizeof(char));
    if (dyn == NULL) {
        printf("malloc for string failed\n");
        return 1;
    }
    strcpy(dyn, src);
    strcat(src, " There");
    printf("src = %s\n", src);
    printf("dyn = %s  (unchanged copy)\n", dyn);
    free(dyn);
    dyn = NULL;

    return 0;
}
