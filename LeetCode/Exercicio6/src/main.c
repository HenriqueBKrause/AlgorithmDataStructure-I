// 1337. The K Weakest Rows in a Matrix
/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){

    int* result = (int*)malloc(sizeof(int)*k);
    int* soldiers = (int*)malloc(sizeof(int)*matSize);
    int* index = (int*)malloc(sizeof(int)*matSize);
    int i,j;
    int temp;
    int tempIndex;
    int count = 0;
    int flag = 0;
    int min = 0;
    int minIndex = 0;

    for(i=0;i<matSize;i++){
        soldiers[i] = 0;
        index[i] = i;z
        for(j=0;j<matColSize[i];j++){
            if(mat[i][j] == 1){
                soldiers[i]++;
            }
        }
    }

    for(i=0;i<matSize;i++){
        min = soldiers[i];
        minIndex = i;
        for(j=i;j<matSize;j++){
            if(soldiers[j] < min){
                min = soldiers[j];
                minIndex = j;
            }
        }
        temp = soldiers[i];
        soldiers[i] = soldiers[minIndex];
        soldiers[minIndex] = temp;

        tempIndex = index[i];
        index[i] = index[minIndex];
        index[minIndex] = tempIndex;
    }

    for(i=0;i<k;i++){
        result[i] = index[i];
    }

    *returnSize = k;
    return result;


}