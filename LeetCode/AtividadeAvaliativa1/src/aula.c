//Nome: Henrique Borges Krause      Matricula: 21201500


#include <stdio.h>
#include <stdlib.h>

char * longestNiceSubstring(char * s){
  
  //leio a string s e armazeno
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    int tam = i;

    //crio o vetor para armazenar as letras
    int *letras = (int*)malloc(sizeof(int)*tam);
    for(i = 0; i < tam; i++){
        letras[i] = 0;
    }

    //armazeno as letras
    for(i = 0; i < tam; i++){
        letras[s[i] - 'A']++;
    }

    //vejo se a letra minuscula e maiuscula aparecem
    for(i = 0; i < tam; i++){
        if(letras[i] != 0 && letras[i + 32] == 0){
            return "";
        }
        if(letras[i] == 0 && letras[i + 32] != 0){
            return "";
        }
    }//final do for
    
   
//se eu retornar agora, ele me retorna a string inteira e não a melhor string


}//longestNiceSubstring

