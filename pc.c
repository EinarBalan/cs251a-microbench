#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define ARRAY_SIZE (16 * 1024 * 1024) // 16M elements (~64MB if pointers are 4 bytes)

int main() {
    // Allocate an array of pointers
    int **array = malloc(ARRAY_SIZE * sizeof(int *));
    if (!array) {
        perror("malloc");
        return 1;
    }
    
    // Initialize the array to form a circular linked list
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        array[i] = (int *)((uintptr_t)&array[(i + 1) % ARRAY_SIZE]);
    }
    
    int **ptr = array;
    volatile int dummy = 0;
    clock_t start = clock();
    
    // Traverse the pointer chain
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        ptr = (int **)((uintptr_t)*ptr);
        dummy++;  // Prevent loop elimination
    }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Memory latency benchmark (pointer chasing):\n");
    printf("Time: %f seconds, Dummy count: %d\n", time_taken, dummy);
    
    free(array);
    return 0;
}
