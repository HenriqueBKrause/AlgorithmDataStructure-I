// 1464. Maximum Product of Two Elements in an Array
//Dada a matriz de inteiros, você escolherá dois índices diferentes e dessa matriz. Retorne o valor máximo de . numsij(nums[i]-1)*(nums[j]-1)

int maxProduct(int* nums, int numsSize){

 int i, j, max = 0;

    for(i = 0 ; i < numsSize ; i++){
        for(j = 0; j < numsSize ; j++){
            if( (nums[i]-1) * (nums[j]-1) > max  ){
                max = (nums[i]-1) * (nums[j]-1);
            }
        }
    }
}