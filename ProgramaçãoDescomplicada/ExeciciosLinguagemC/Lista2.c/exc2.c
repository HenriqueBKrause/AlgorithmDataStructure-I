/*O custo ao consumidor de um carro novo e a soma do custo de f ´ abrica, da comiss ´ ao˜
do distribuidor, e dos impostos. A comissao e os impostos s ˜ ao calculados sobre o custo ˜
de fabrica, de acordo com a tabela abaixo. Leia o custo de f ´ abrica e escreva o custo ao ´
consumidor.

CUSTO DE FABRICA              | % DO DISTRIBUIDOR | % DOS IMPOSTOS
ate R$12.000,00               |       5           |   isento
entre R$12.000,00 e 25.000,00 |      10           |    15
acima de R$25.000,00          |      15           |    20
*/


#include <stdio.h>

int main(){

    float custoFabrica, custoConsumidor, comissao, imposto;

    printf("Digite o custo de fabrica: ");
    scanf("%f", &custoFabrica);

    if(custoFabrica <= 12000){
        comissao = custoFabrica * 0.05;
        imposto = 0;
    }else if(custoFabrica > 12000 && custoFabrica <= 25000){
        comissao = custoFabrica * 0.10;
        imposto = custoFabrica * 0.15;
    }else{
        comissao = custoFabrica * 0.15;
        imposto = custoFabrica * 0.20;
    }

    custoConsumidor = custoFabrica + comissao + imposto;

    printf("O custo ao consumidor e: %.2f", custoConsumidor);

    return 0;
}