#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // matriz

int main() {
    float a[N][N]; 
    float x;
    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = (float)rand() / RAND_MAX;
        }
    }

    //tiempo de ejecución
    start = clock();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x = a[i][j];
        }
    }
    end = clock();

    // Calcular tiempo de CPU
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);

    return 0;
}
