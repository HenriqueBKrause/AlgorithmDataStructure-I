#include <stdio.h>
#include <stdlib.h>

struct matrix {
    struct matrix* right;
    struct matrix* below;
    int line;
    int column;
    float info;
};
typedef struct matrix Matrix;

Matrix* matrix_create(void) {
   int m, n;
    scanf("%d %d", &m, &n);

    Matrix* head = (Matrix*)malloc(sizeof(Matrix));
    head->line = -1;
    head->column = -1;
    head->right = head;
    head->below = head;

    Matrix* lastInRow[m];
    for (int i = 0; i < m; i++) {
        lastInRow[i] = head;
    }

    while (1) {
        int i, j;
        float value;
        scanf("%d %d %f", &i, &j, &value);
        if (i < 0 || j < 0) {
            break;
        }

        Matrix* newElem = (Matrix*)malloc(sizeof(Matrix));
        newElem->line = i;
        newElem->column = j;
        newElem->info = value;

        newElem->right = lastInRow[i]->right;
        lastInRow[i]->right = newElem;
        lastInRow[i] = newElem;

        Matrix* currentCol = head;
        while (currentCol->column != j) {
            currentCol = currentCol->right;
        }
        newElem->below = currentCol->below;
        currentCol->below = newElem;
    }

    return head;
}

void matrix_destroy(Matrix* m) {
    // TODO: Implement the matrix destruction function.
}

void matrix_print(Matrix* m) {
    // TODO: Implement the matrix printing function.
}

Matrix* matrix_add(Matrix* m, Matrix* n) {
    // TODO: Implement the matrix addition function.
}

Matrix* matrix_multiply(Matrix* m, Matrix* n) {
    // TODO: Implement the matrix multiplication function.
}

Matrix* matrix_transpose(Matrix* m) {
    // TODO: Implement the matrix transpose function.
}

float matrix_getelem(Matrix* m, int x, int y) {
    // TODO: Implement the function to get the element at position (x, y).
}

void matrix_setelem(Matrix* m, int x, int y, float elem) {
    // TODO: Implement the function to set the element at position (x, y).
}

int main(void) {
    /* Inicializacao da aplicacao ... */
    Matrix* A = matrix_create();
    matrix_print(A);
    Matrix* B = matrix_create();
    matrix_print(B);
    Matrix* C = matrix_add(A, B);
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
