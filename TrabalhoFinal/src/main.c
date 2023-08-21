#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

struct matrix {
  int rows;
  int columns;
  float info[MAX_ROWS][MAX_COLUMNS];
};

Matrix* matrix_create(int rows, int columns) {
  Matrix* m = (Matrix*)malloc(sizeof(Matrix));
  m->rows = rows;
  m->columns = columns;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m->info[i][j] = 0.0;
    }
  }
  return m;
}

void matrix_destroy(Matrix* m) {
  free(m);
}

void matrix_print(Matrix* m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      printf("%f ", m->info[i][j]);
    }
    printf("\n");
  }
}

Matrix* matrix_add(Matrix* m1, Matrix* m2) {
  Matrix* sum = matrix_create(m1->rows, m1->columns);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m1->columns; j++) {
      sum->info[i][j] = m1->info[i][j] + m2->info[i][j];
    }
  }
  return sum;
}

Matrix* matrix_multiply(Matrix* m1, Matrix* m2) {
  Matrix* product = matrix_create(m1->rows, m2->columns);
  for (int i = 0; i < m1->rows; i++) {
    for (int j = 0; j < m2->columns; j++) {
      product->info[i][j] = 0.0;
      for (int k = 0; k < m1->columns; k++) {
        product->info[i][j] += m1->info[i][k] * m2->info[k][j];
      }
    }
  }
  return product;
}

Matrix* matrix_transpose(Matrix* m) {
  Matrix* transpose = matrix_create(m->columns, m->rows);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      transpose->info[j][i] = m->info[i][j];
    }
  }
  return transpose;
}

float matrix_getelem(Matrix* m, int x, int y) {
  if (x < 0 || x >= m->rows || y < 0 || y >= m->columns) {
    return 0.0;
  }
  return m->info[x][y];
}

void matrix_setelem(Matrix* m, int x, int y, float value) {
  if (x < 0 || x >= m->rows || y < 0 || y >= m->columns) {
    return;
  }
  m->info[x][y] = value;
}

int main(void) {
  Matrix* A = matrix_create(44, 4);
  for (int i = 0; i < 44; i++) {
    for (int j = 0; j < 4; j++) {
      Matrix_setelem(A, i, j, 0.0);
    }
  }
  Matrix_setelem(A, 0, 0, 50.0);
  Matrix_setelem(A, 1, 0, 10.0);
  Matrix_setelem(A, 2, 0, 20.0);
  Matrix_
