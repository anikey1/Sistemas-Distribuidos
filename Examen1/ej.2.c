#include <stdio.h>
#include <time.h>

#define N 1000 // Definir el tamaño del arreglo

int main() {
    float a[N];
    for (int i = 0; i < N; i++) {
        a[i] = i + 1; // Llenar el arreglo con valores del 1 al 1000
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Medir tiempo A
    for (int i = 0; i < N; i++) {
        float x = a[i]; // Recorrer todos los elementos del arreglo
    }
    end = clock(); // Medir tiempo B

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución (Programa 2): %f segundos\n", cpu_time_used);

    return 0;
}
