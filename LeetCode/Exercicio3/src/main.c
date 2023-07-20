#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum ( int* nums, int numsSize, int target, int* returnSize ) {
    int* result = ( int* ) malloc ( 2 * sizeof ( int ) );
    *returnSize = 2;

   
    int hashMap[100000] = { 0 };

    for ( int i = 0; i < numsSize; i++ ) {
        int complement = target - nums[i];

   
        if (hashMap[complement] != 0) {
            result[0] = hashMap[complement] - 1; 
            result[1] = i; 
            return result;
        }

        hashMap[nums[i]] = i + 1;
    }

    return NULL; 
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("Nenhum par encontrado!\n");
    }

    return 0;
}
