#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE (64 * 1024 * 1024) // 64 MB

int main() {
    char *src = malloc(SIZE);
    char *dst = malloc(SIZE);
    if (!src || !dst) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    // Initialize source data
    for (size_t i = 0; i < SIZE; i++) {
        src[i] = (char)(i % 256);
    }
    clock_t start = clock();
    for (size_t i = 0; i < SIZE; i++) {
        dst[i] = src[i];
    }
    clock_t end = clock();
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Memory bandwidth benchmark (streaming copy):\n");
    printf("Time: %f seconds\n", elapsed);
    free(src);
    free(dst);
    return 0;
}
