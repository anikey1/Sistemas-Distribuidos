#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 792

static float a[L][L][L], x;

void llenarArreglo(float arr[L][L][L]);

int main() {
    srand(time(NULL));
    llenarArreglo(a);

    int i, j, k;

    clock_t inicio, fin; 

    inicio = clock(); 
    for (i = 0; i < L; i++) {
        for (j = 0; j < L; j++) {  
            for (k = 0; k < L; k++) {
                x = a[i][j][k];
            }
        }
    }
    fin = clock(); 

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.6f segundos\n", tiempo);

    return 0;
}

void llenarArreglo(float arr[L][L][L]) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            for (int k = 0; k < L; k++) {
                arr[i][j][k] = (float)rand() / RAND_MAX;
            }
        }
    }
}
