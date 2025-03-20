#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000

int main() {
    volatile double a = 1.0;
    volatile double b = 1.000001;
    volatile double c = 1.000002;
    clock_t start = clock();
    for (unsigned long i = 0; i < N; i++) {
        a = a * b + c;
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Floating-point throughput benchmark:\n");
    printf("Result: %f, Time: %f seconds\n", a, time_taken);
    return 0;
}
