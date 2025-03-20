#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE (32 * 1024 * 1024) // 32M integers (~128 MB assuming 4 bytes per int)

int main() {
    int *array = malloc(ARRAY_SIZE * sizeof(int));
    if (!array) {
        perror("malloc");
        return 1;
    }
    // Initialize the array
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }
    
    int sum = 0;
    int stride = 16;  // 16 ints = 64 bytes (typical cache line), forces conflict if associativity is limited
    clock_t start = clock();
    for (size_t i = 0; i < ARRAY_SIZE; i += stride) {
        sum += array[i];
    }
    clock_t end = clock();
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Cache conflict/stride benchmark:\n");
    printf("Sum: %d, Time: %f seconds (stride = %d)\n", sum, elapsed, stride);
    free(array);
    return 0;
}

