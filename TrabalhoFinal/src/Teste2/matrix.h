#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
Matriz* matrix_create(unsigned int m) {
    Matriz* result = (Matriz*)malloc(sizeof(Matriz));
    result->line = m;
    result->column = m;
    result->right = result;
    result->below = result;

    srand(time(NULL)); // Seed the random number generator

    Matriz* currentRowHead = result;

    for (int i = 0; i < m; i++) {
        Matriz* newRowHead = (Matriz*)malloc(sizeof(Matriz));
        newRowHead->line = -1;
        newRowHead->column = -1;
        newRowHead->right = newRowHead;
        newRowHead->below = currentRowHead->below;
        currentRowHead->below = newRowHead;

        Matriz* lastInRow = newRowHead;

        for (int j = 0; j < m; j++) {
            float randomValue = (float)rand() / RAND_MAX; // Generate random value between 0 and 1
            if (randomValue > 0.7) { // 70% chance of generating a non-zero value
                Matriz* newElem = (Matriz*)malloc(sizeof(Matriz));
                newElem->line = i;
                newElem->column = j;
                newElem->info = randomValue;

                lastInRow->right = newElem;
                newElem->right = newRowHead;
                lastInRow = newElem;
            }
        }

        currentRowHead = newRowHead;
    }

    return result;
}