//Leia um numero inteiro de 4 d ´ ´ıgitos (de 1000 a 9999) e imprima 1 d´ıgito por linha.


#include <stdio.h>

int main(){

    int number;

    printf("Digite um numero inteiro de 4 digitos: ");
    scanf("%d", &number);

    printf("%d\n", number/1000);
    printf("%d\n", (number%1000)/100);
    printf("%d\n", (number%100)/10);
    printf("%d\n", number%10);

    return 0;
}