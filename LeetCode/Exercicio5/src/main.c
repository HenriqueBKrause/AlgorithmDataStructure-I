// 2357. Make Array Zero by Subtracting Equal Amounts

/*Você recebe uma matriz inteira não negativa . Em uma operação, você deve:nums

Escolha um inteiro positivo tal que seja menor ou igual ao menor elemento diferente de zero no .xxnums
Subtrair de cada elemento positivo em .xnums
Retorne o número mínimo de operações para tornar cada elemento igual a .nums0

*/

#include <stdiio.h>
#include <stdlib.h>

int minimumOperations(int* nums, int numsSize){

    int ops=0;
    int t;

    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[j]<nums[i])
            {
                t=nums[j];
                nums[j]=nums[i];
                nums[i]=t;
            }
        }
    }

    int count=0;

    for(int i=0;i<numsSize;i++)
    {
        if(ops<nums[i])
        {
            ops+=nums[i]-ops;
            count++;
        }
    }

    return count;

}