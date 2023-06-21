//Fac¸a um programa para ler as dimensoes de um terreno (comprimento ˜ c e largura l),
//bem como o prec¸o do metro de tela p. Imprima o custo para cercar este mesmo terreno
//com tela

#include <stdio.h>


int main(){

    float comprimento, largura, preco, custo;

    printf("Digite o comprimento do terreno: ");
    scanf("%f", &comprimento);

    printf("Digite a largura do terreno: ");
    scanf("%f", &largura);

    printf("Digite o preco do metro de tela: ");
    scanf("%f", &preco);

    custo = (comprimento*2 + largura*2)*preco;

    printf("O custo para cercar o terreno eh: %.2f", custo);

    return 0;
}
