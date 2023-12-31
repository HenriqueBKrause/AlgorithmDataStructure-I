// Nomes: Henrique Krause & Rodrigo Cesar  
// Trabalho final de AED 1

#include <stdio.h>
#include "matrix.h"

int main(void) {

    freopen("saida.txt", "w", stdout);

 
    Matriz* A = matrix_create();
    matrix_print(A);

    Matriz* B = matrix_create();
    matrix_print(B);

    Matriz* C = matrix_add(A, B);
    matrix_print(C);
    matrix_destroy(C);

    C = matrix_multiply(A, B);
    matrix_print(C);
    matrix_destroy(C);

    C = matrix_transpose(A);
    matrix_print(C);
    matrix_destroy(C);

    matrix_destroy(A);
    matrix_destroy(B);

    return 0;
}
