// Compile:  gcc -o fileio 07_fileio.c
// Run:      ./fileio
//
// Demo: fopen/fclose, fprintf/fscanf, fread/fwrite, fseek, perror
// Creates "data.txt" in the current directory, then reads it back

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // --- fopen (write) ---
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        perror("fopen failed");   // prints: "fopen failed: <OS error message>"
        return 1;
    }

    // --- fprintf: like printf but to a file ---
    fprintf(fp, "Alice 20 3.80\n");
    fprintf(fp, "Bob   22 3.50\n");
    fprintf(fp, "Carol 21 3.95\n");
    fclose(fp);
    printf("Wrote 3 records to data.txt\n");

    // --- fopen (read) + fscanf ---
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("fopen failed");
        return 1;
    }

    char name[32];
    int  age;
    float gpa;

    printf("\nReading back with fscanf:\n");
    while (fscanf(fp, "%s %d %f", name, &age, &gpa) == 3) {
        printf("  Name: %-8s Age: %d  GPA: %.2f\n", name, age, gpa);
    }
    fclose(fp);

    // --- fseek + fread/fwrite (binary demo) ---
    FILE *bin = fopen("nums.bin", "w");
    if (bin == NULL) { perror("fopen"); return 1; }

    int write_buf[5] = {1, 2, 3, 4, 5};
    fwrite(write_buf, sizeof(int), 5, bin);   // write 5 ints
    fclose(bin);

    bin = fopen("nums.bin", "r");
    if (bin == NULL) { perror("fopen"); return 1; }

    // fseek to 3rd element (index 2): offset = 2 * sizeof(int)
    fseek(bin, 2 * sizeof(int), SEEK_SET);

    int read_buf[3];
    fread(read_buf, sizeof(int), 3, bin);     // read last 3 ints

    printf("\nfread from offset 2 (expected 3 4 5): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", read_buf[i]);
    }
    printf("\n");

    fclose(bin);
    return 0;
}
