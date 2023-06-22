/*Fac¸a um algoritmo que calcule o IMC de uma pessoa e mostre sua classificac¸ao de ˜
acordo com a tabela abaixo:*/



#include <stdio.h>



int main(){

    float peso, altura, imc;

    printf("Digite o peso: ");
    scanf("%f", &peso);

    printf("Digite a altura: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    if(imc < 18.5){
        printf("Abaixo do peso");
    }else if(imc >= 18.5 && imc < 24,9){
        printf("Peso normal");
    }else if(imc >= 25 && imc < 29,9){
        printf("Sobrepeso");
    }else if(imc >= 30 && imc < 34,9){
        printf("Obeso leve");
    }else if(imc >= 35 && imc < 40){
        printf("Obeso moderado");
    }else{
        printf("Obeso morbido");
    }

    return 0;
}