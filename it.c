#include <stdio.h>
#include <time.h>

#define N 1000000000UL

int main() {
    volatile long a = 1;
    volatile long b = 3;
    volatile long c = 5;
    clock_t start = clock();
    for (unsigned long i = 0; i < N; i++) {
        a = (a + b) * c;
        b = (b ^ a) + (a % 7);
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Integer arithmetic throughput benchmark:\n");
    printf("Result: %ld, Time: %f seconds\n", a, time_taken);
    return 0;
}
