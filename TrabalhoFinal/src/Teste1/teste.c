#include <stdio.h>
#include <stdlib.h>


//Estrutura
struct matrix {
    struct matrix* right;
    struct matrix* below;
    int line;
    int column;
    float info;
};
typedef struct matrix Matriz;



// Função 1 =  Cria uma matriz
Matriz* matrix_create(void) {
    
    int m, n;

// Aqui inserimos o numero de colunas e linhas;
    scanf("%d %d", &m, &n);

    Matriz* head = (Matriz*)malloc(sizeof(Matriz));

    head->line = -1;
    head->column = -1;
    head->right = head;
    head->below = head;

 
    Matriz* lastInRow[m];
    for (int i = 0; i < m; i++) {
        lastInRow[i] = head;
    }


//aqui esta a solicitação dos valores da matriz em um laço 
    while (1) {

        int i, j;
        float value;
        scanf("%d %d %f", &i, &j, &value);
        if (i < 0 || j < 0) {
            break;
        }

        
        Matriz* newElem = (Matriz*)malloc(sizeof(Matriz));
        newElem->line = i;
        newElem->column = j;
        newElem->info = value;

        // Insere o elemento
        newElem->right = lastInRow[i]->right;
        lastInRow[i]->right = newElem;
        lastInRow[i] = newElem;

        // Insere o elemento na coluna 
        Matriz* currentCol = head;
        while (currentCol->column != j) {
            currentCol = currentCol->right;
        }
        newElem->below = currentCol->below;
        currentCol->below = newElem;
    }

    return head;
}

// Função 2 = destruir matriz
void matrix_destroy(Matriz* m) {
    
    Matriz* current = m->right;

    // Destruição dos elementos
    while (current != m) {
        Matriz* next = current->right;
        free(current);
        current = next;
    }

    free(m);
}


// Função 3 = imprimir matriz 
void matrix_print(Matriz* m) {

    Matriz* rowHead = m->right;

    // Imprimir os elemnetos
    while (rowHead != m) {
        Matriz* current = rowHead->right;
        while (current != rowHead) {
            printf("(%d,%d): %.2f\t", current->line, current->column, current->info);
            current = current->right;
        }
        printf("\n");
        rowHead = rowHead->below;
    }
}


// Função 4 = somar duas matrizes
Matriz* matrix_add(Matriz* m, Matriz* n) {
    if (m == NULL || n == NULL || m->line != n->line || m->column != n->column) {
        
        return NULL;
    }

    int numRows = m->line;
    int numCols = m->column;

    Matriz* result = (Matriz*)malloc(sizeof(Matriz));
    result->line = numRows;
    result->column = numCols;
    result->right = result;
    result->below = result;

    Matriz* mRowHead = m->right;
    Matriz* nRowHead = n->right;

    for (int i = 0; i < numRows; i++) {
        Matriz* mElem = mRowHead->right;
        Matriz* nElem = nRowHead->right;

        Matriz* newRowHead = (Matriz*)malloc(sizeof(Matriz));
        newRowHead->line = -1;
        newRowHead->column = -1;
        newRowHead->right = newRowHead;
        newRowHead->below = result->below;
        result->below = newRowHead;

        Matriz* lastInRow = newRowHead;

        for (int j = 0; j < numCols; j++) {
            if (mElem->column == j && nElem->column == j) {
                float sum = mElem->info + nElem->info;
                if (sum != 0.0) {
                    Matriz* newElem = (Matriz*)malloc(sizeof(Matriz));
                    newElem->line = i;
                    newElem->column = j;
                    newElem->info = sum;

                    lastInRow->right = newElem;
                    newElem->right = newRowHead;
                    lastInRow = newElem;
                }

                mElem = mElem->right;
                nElem = nElem->right;
            } else if (mElem->column == j) {
                lastInRow->right = mElem;
                lastInRow = mElem;
                mElem = mElem->right;
            } else if (nElem->column == j) {
                lastInRow->right = nElem;
                lastInRow = nElem;
                nElem = nElem->right;
            }
        }

        mRowHead = mRowHead->below;
        nRowHead = nRowHead->below;
    }

    return result;
}


// Função 5 = multiplicar duas matrizes
Matriz* matrix_multiply(Matriz* m, Matriz* n) {
    if (m == NULL || n == NULL || m->column != n->line) {
        // Matrizes inválidas para multiplicação
        return NULL;
    }

    int numRows = m->line;
    int numCols = n->column;

    Matriz* result = (Matriz*)malloc(sizeof(Matriz));
    result->line = numRows;
    result->column = numCols;
    result->right = result;
    result->below = result;

    Matriz* mRowHead = m->right;

    for (int i = 0; i < numRows; i++) {
        Matriz* nColHead = n->below;

        Matriz* newRowHead = (Matriz*)malloc(sizeof(Matriz));
        newRowHead->line = -1;
        newRowHead->column = -1;
        newRowHead->right = newRowHead;
        newRowHead->below = result->below;
        result->below = newRowHead;

        Matriz* lastInRow = newRowHead;

        for (int j = 0; j < numCols; j++) {
            float sum = 0.0;

            Matriz* mElem = mRowHead->right;
            Matriz* nElem = nColHead->below;

            while (mElem != mRowHead && nElem != nColHead) {
                if (mElem->column < nElem->line) {
                    mElem = mElem->right;
                } else if (mElem->column > nElem->line) {
                    nElem = nElem->below;
                } else {
                    sum += mElem->info * nElem->info;
                    mElem = mElem->right;
                    nElem = nElem->below;
                }
            }

            if (sum != 0.0) {
                Matriz* newElem = (Matriz*)malloc(sizeof(Matriz));
                newElem->line = i;
                newElem->column = j;
                newElem->info = sum;

                lastInRow->right = newElem;
                newElem->right = newRowHead;
                lastInRow = newElem;
            }

            nColHead = nColHead->below;
        }

        mRowHead = mRowHead->below;
    }

    return result;
}



// Função 6 = transpor uma matriz
Matriz* matrix_transpose(Matriz* m) {
    int numRows = m->column;
    int numCols = m->line;

    Matriz* result = (Matriz*)malloc(sizeof(Matriz));
    result->line = numRows;
    result->column = numCols;
    result->right = result;
    result->below = result;

    Matriz* mRowHead = m->right;

    for (int i = 0; i < numRows; i++) {
        Matriz* newRowHead = (Matriz*)malloc(sizeof(Matriz));
        newRowHead->line = -1;
        newRowHead->column = -1;
        newRowHead->right = newRowHead;
        newRowHead->below = result->below;
        result->below = newRowHead;

        Matriz* lastInRow = newRowHead;

        for (int j = 0; j < numCols; j++) {
            if (mRowHead->below->line == i) {
                Matriz* newElem = (Matriz*)malloc(sizeof(Matriz));
                newElem->line = j;
                newElem->column = i;
                newElem->info = mRowHead->below->info;

                lastInRow->right = newElem;
                newElem->right = newRowHead;
                lastInRow = newElem;

                mRowHead = mRowHead->below;
            }
        }
    }

    return result;
}



// Função 7 = obter um elemento da matriz
float matrix_getelem(Matriz* m, int x, int y) {
    if (x < 0 || x >= m->line || y < 0 || y >= m->column) {
        
        return 0.0;
    }

    Matriz* rowHead = m->right;
    for (int i = 0; i < x; i++) {
        rowHead = rowHead->below;
    }

    Matriz* current = rowHead->right;
    while (current != rowHead) {
        if (current->column == y) {
            return current->info;
        }
        current = current->right;
    }

    return 0.0; // Elemento não encontrado, assume-se zero
}



// Função 8 = alterar um elemento da matriz
void matrix_setelem(Matriz* m, int x, int y, float elem) {
    if (x < 0 || x >= m->line || y < 0 || y >= m->column) {
        
        return;
    }

    Matriz* rowHead = m->right;
    for (int i = 0; i < x; i++) {
        rowHead = rowHead->below;
    }

    Matriz* prev = rowHead;
    Matriz* current = rowHead->right;

    while (current != rowHead && current->column < y) {
        prev = current;
        current = current->right;
    }

    if (current != rowHead && current->column == y) {
        
        current->info = elem;
    } else {
        
        Matriz* newElem = (Matriz*)malloc(sizeof(Matriz));
        newElem->line = x;
        newElem->column = y;
        newElem->info = elem;

        prev->right = newElem;
        newElem->right = current;
    }
}



//inicio da função principal

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
