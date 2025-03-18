#include <stdio.h>
#include <time.h>

int main() {
    float a[] = {1000000}; // Arreglo con un solo elemento
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Medir tiempo A
    float x = a[0];  // Acceder al único elemento
    end = clock();   // Medir tiempo B

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución (Programa 1): %f segundos\n", cpu_time_used);

    return 0;
}
