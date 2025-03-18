#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 100000

// Función de comparación para qsort (para ordenar de menor a mayor)
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void rellenar_arreglo(int arr[], int n, int rango_min, int rango_max) {
    srand(time(NULL));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (rango_max - rango_min + 1) + rango_min;
    }
}

// Función de búsqueda binaria iterativa
int busqueda_binaria(int arr[], int n, int objetivo) {
    int izquierda = 0, derecha = n - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == objetivo)
            return medio;
        if (arr[medio] < objetivo)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    return -1;
}

int main() {
    int arr[L];  // Declaración del arreglo
    int rango_min = 1, rango_max = 1000;  // Rango de los números aleatorios
    int objetivo = 500;  // Número a buscar

    // Rellenar el arreglo con números aleatorios
    rellenar_arreglo(arr, L, rango_min, rango_max);

    clock_t inicio,fin;

    // Ordenar el arreglo con qsort
    inicio = clock();
    qsort(arr, L, sizeof(int), comparar);
    
    // Realizar la búsqueda binaria
    int resultado = busqueda_binaria(arr, L, objetivo);
    
    fin = clock();

    if (resultado != -1)
        printf("Elemento %d encontrado en el índice %d\n", objetivo, resultado);
    else
        printf("Elemento %d no encontrado\n", objetivo);

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.10f segundos\n", tiempo);  

    return 0;
}
