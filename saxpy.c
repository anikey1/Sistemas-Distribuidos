#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


#define L 5000



void get_walltime(double* wcTime) {
    struct timeval time;
    gettimeofday(&time, NULL);
    *wcTime = (double)time.tv_sec + (double)time.tv_usec * 1.0e-6;
}


void ordenijk();
void ordenikj();
void ordenjki();
void ordenjik();
void ordenkji();
void ordenkij();


int main(int argc, char* argv[]) {
    ordenijk();
    ordenikj();
    ordenjki();
    ordenjik();
    ordenkji();
    ordenkij();
    return 0;
}


void ordenijk(){
    int i, j, k, n = L;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    
    // Inicializando matrices
    matrizA = (int**) malloc(n * sizeof(int*));
    matrizB = (int**) malloc(n * sizeof(int*));
    matrizC = (int**) malloc(n * sizeof(int*));
    
    for (i = 0; i < n; i++) {
        *(matrizA+i) = (int*) malloc(n * sizeof(int));
        *(matrizB+i) = (int*) malloc(n * sizeof(int));
        *(matrizC+i) = (int*) malloc(n * sizeof(int));
    }
    
    // Llenando matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0; // Inicializar la matriz C con ceros
        }
    }
    
    get_walltime(&S1);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    
    get_walltime(&E1);
    
    printf("Tiempo método ijk: %f s\n", (E1-S1));
    
    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
    
}

void ordenikj(){
    int i, j, k, n = L;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    
    // Inicializando matrices
    matrizA = (int**) malloc(n * sizeof(int*));
    matrizB = (int**) malloc(n * sizeof(int*));
    matrizC = (int**) malloc(n * sizeof(int*));
    
    for (i = 0; i < n; i++) {
        *(matrizA+i) = (int*) malloc(n * sizeof(int));
        *(matrizB+i) = (int*) malloc(n * sizeof(int));
        *(matrizC+i) = (int*) malloc(n * sizeof(int));
    }
    
    // Llenando matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0; // Inicializar la matriz C con ceros
        }
    }
    
    get_walltime(&S1);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                matrizC[i][k] += matrizA[i][j] * matrizB[j][k];
            }
        }
    }
    
    get_walltime(&E1);
    
    printf("Tiempo método ikj: %f s\n", (E1-S1));
    
    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
   

}



void ordenjki(){
    int i, j, k, n = L;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    
    // Inicializando matrices
    matrizA = (int**) malloc(n * sizeof(int*));
    matrizB = (int**) malloc(n * sizeof(int*));
    matrizC = (int**) malloc(n * sizeof(int*));
    
    for (i = 0; i < n; i++) {
        *(matrizA+i) = (int*) malloc(n * sizeof(int));
        *(matrizB+i) = (int*) malloc(n * sizeof(int));
        *(matrizC+i) = (int*) malloc(n * sizeof(int));
    }
    
    // Llenando matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0; // Inicializar la matriz C con ceros
        }
    }
    
    get_walltime(&S1);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                matrizC[j][k] += matrizA[j][i] * matrizB[i][k];
            }
        }
    }
    
    get_walltime(&E1);
    
    printf("Tiempo método jki: %f s\n", (E1-S1));
    
    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
    
    
}

void ordenjik(){
    int i, j, k, n = L;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    
    // Inicializando matrices
    matrizA = (int**) malloc(n * sizeof(int*));
    matrizB = (int**) malloc(n * sizeof(int*));
    matrizC = (int**) malloc(n * sizeof(int*));
    
    for (i = 0; i < n; i++) {
        *(matrizA+i) = (int*) malloc(n * sizeof(int));
        *(matrizB+i) = (int*) malloc(n * sizeof(int));
        *(matrizC+i) = (int*) malloc(n * sizeof(int));
    }
    
    // Llenando matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0; // Inicializar la matriz C con ceros
        }
    }
    
    get_walltime(&S1);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                matrizC[j][i] += matrizA[j][k] * matrizB[k][i];
            }
        }
    }
    
    get_walltime(&E1);
    
    printf("Tiempo método jik: %f s\n", (E1-S1));
    
    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
    
    
}



void ordenkji(){
    int i, j, k, n = L;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    
    // Inicializando matrices
    matrizA = (int**) malloc(n * sizeof(int*));
    matrizB = (int**) malloc(n * sizeof(int*));
    matrizC = (int**) malloc(n * sizeof(int*));
    
    for (i = 0; i < n; i++) {
        *(matrizA+i) = (int*) malloc(n * sizeof(int));
        *(matrizB+i) = (int*) malloc(n * sizeof(int));
        *(matrizC+i) = (int*) malloc(n * sizeof(int));
    }
    
    // Llenando matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0; // Inicializar la matriz C con ceros
        }
    }
    
    get_walltime(&S1);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                matrizC[k][j] += matrizA[k][i] * matrizB[i][j];
            }
        }
    }
    
    get_walltime(&E1);
    
    printf("Tiempo método kji: %f s\n", (E1-S1));
    
    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
   


}


void ordenkij(){
    int i, j, k, n = L;
    int **matrizA, **matrizB, **matrizC;
    double S1, E1;
    
    // Inicializando matrices
    matrizA = (int**) malloc(n * sizeof(int*));
    matrizB = (int**) malloc(n * sizeof(int*));
    matrizC = (int**) malloc(n * sizeof(int*));
    
    for (i = 0; i < n; i++) {
        *(matrizA+i) = (int*) malloc(n * sizeof(int));
        *(matrizB+i) = (int*) malloc(n * sizeof(int));
        *(matrizC+i) = (int*) malloc(n * sizeof(int));
    }
    
    // Llenando matrices
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
            matrizC[i][j] = 0; // Inicializar la matriz C con ceros
        }
    }
    
    get_walltime(&S1);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < n; ++k) {
                matrizC[k][i] += matrizA[k][j] * matrizB[j][i];
            }
        }
    }
    
    get_walltime(&E1);
    
    printf("Tiempo método kij: %f s\n", (E1-S1));
    
    // Liberar memoria
    for (i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
       


}