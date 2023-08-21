  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  
  
  
  Matrix* matrix_create(void) {

  Matrix* matrix = malloc(sizeof(Matrix));

  int m, n;
  scanf("%d %d", &m, &n);


  matrix->rows = malloc(m * sizeof(List));
  matrix->columns = malloc(n * sizeof(List));

  for (int i = 0; i < m; i++) {
    matrix->rows[i] = list_create();
  }

  for (int j = 0; j < n; j++) {
    matrix->columns[j] = list_create();
  }

  
  int i, j, value;
  while (scanf("%d %d %d", &i, &j, &value) != EOF) {
 
    list_add_tail(matrix->rows[i], value, j);

    list_add_tail(matrix->columns[j], value, i);
  }

  return matrix;
}


void matrix_destroy(Matrix* matrix) {

  for (int i = 0; i < matrix->m; i++) {
    list_destroy(matrix->rows[i]);
  }

  for (int j = 0; j < matrix->n; j++) {
    list_destroy(matrix->columns[j]);
  }

  free(matrix);
}


void matrix_print(Matrix* matrix) {

  for (int i = 0; i < matrix->m; i++) {

    list_print(matrix->rows[i]);

    printf("\n");
  }
}


Matrix* matrix_add(Matrix* m1, Matrix* m2) {

  Matrix* sum = matrix_create();


  for (int i = 0; i < m1->m; i++) {
    
    List* row1 = m1->rows[i];


    List* row2 = m2->rows[i];


    ListNode* node1 = row1->head;
    ListNode* node2 = row2->head;
    while (node1 != NULL && node2 != NULL) {

      float value1 = node1->value;
      float value2 = node2->value;