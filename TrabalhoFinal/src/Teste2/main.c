#include <stdio.h>
#include "matrix.h"




int main() {
    unsigned int matrixSize = 1000; 

    Matriz* matrixA = matrix_create(matrixSize);
    Matriz* matrixB = matrix_create(matrixSize);

    clock_t start, end;

    start = clock();
    Matriz* resultNormal = matrix_multiply(matrixA, matrixB);
    end = clock();
    double cpu_time_used_normal = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for normal matrix multiplication: %f seconds\n", cpu_time_used_normal);


    start = clock();
    Matriz* resultBruteForce = matrix_multiply_brute_force(matrixA, matrixB);
    end = clock();
    double cpu_time_used_bruteforce = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken for brute force matrix multiplication: %f seconds\n", cpu_time_used_bruteforce);

return 0;
}