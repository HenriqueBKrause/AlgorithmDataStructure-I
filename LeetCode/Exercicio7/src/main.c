/*387. Primeiro caractere único em uma cadeia de caracteres
*/

#include <stdio.h>


int firstUniqChar(char * s){

    int i, j, count = 0;
    int len = strlen(s);
    int flag = 0;
    
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++){
            if(s[i] == s[j]){
                count++;
            }
        }
        if(count == 1){
            flag = 1;
            return i;
        }
        count = 0;
    }
    if(flag == 0){
        return -1;
    }
    return 0;



}