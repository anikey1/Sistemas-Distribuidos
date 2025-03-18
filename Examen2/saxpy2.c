#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define L 100   // para cambiar el orden de la matriz


void get_walltime(double* wcTime) {
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    *wcTime = time.tv_sec + time.tv_nsec / 1.0e9;
}

void multiplicar_matrices(int orden);

int main() {
    multiplicar_matrices(0); // ijk
    multiplicar_matrices(1); // ikj
    multiplicar_matrices(2); // jki
    multiplicar_matrices(3); // jik
    multiplicar_matrices(4); // kji
    multiplicar_matrices(5); // kij
    return 0;
}

void multiplicar_matrices(int orden) {
    int i, j, k, n = L;
    int **A, **B, **C;
    double S1, E1;
    
    A = (int**) malloc(n * sizeof(int*));
    B = (int**) malloc(n * sizeof(int*));
    C = (int**) malloc(n * sizeof(int*));
    
    for (i = 0; i < n; i++) {
        A[i] = (int*) malloc(n * sizeof(int));
        B[i] = (int*) malloc(n * sizeof(int));
        C[i] = (int*) malloc(n * sizeof(int));
    }
    
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j) {
            A[i][j] = rand() % 6;
            B[i][j] = rand() % 6;
            C[i][j] = 0;
        }
    
    get_walltime(&S1);
    
    switch (orden) {
        case 0: // ijk
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    for (k = 0; k < n; k++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 1: // ikj
            for (i = 0; i < n; i++)
                for (k = 0; k < n; k++)
                    for (j = 0; j < n; j++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 2: // jki
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    for (i = 0; i < n; i++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 3: // jik
            for (j = 0; j < n; j++)
                for (i = 0; i < n; i++)
                    for (k = 0; k < n; k++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 4: // kji
            for (k = 0; k < n; k++)
                for (j = 0; j < n; j++)
                    for (i = 0; i < n; i++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
        case 5: // kij
            for (k = 0; k < n; k++)
                for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        C[i][j] += A[i][k] * B[k][j];
            break;
    }
    
    get_walltime(&E1);
    
    printf("Tiempo metodo %s: %f s\n", (const char*[]){"ijk", "ikj", "jki", "jik", "kji", "kij"}[orden], (E1 - S1));
    
    for (i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

