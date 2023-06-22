//  Façaa um programa que calcule o maior numero palındromo feito a partir do produto de
// dois numeros de 3 dıgitos. Ex: O maior palındromo feito a partir do produto de dois
// numeros de dois dıgitos e 9009 = 91*99.


#include <stdio.h>

int eh_palindromo(int numero) {
    int original = numero;
    int invertido = 0;

    while (numero > 0) {
        invertido = invertido * 10 + (numero % 10);
        numero /= 10;
    }

    return original == invertido;
}

int maior_palindromo() {
    int maior_palindromo = 0;

    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            int produto = i * j;

            if (eh_palindromo(produto) && produto > maior_palindromo) {
                maior_palindromo = produto;
            }
        }
    }

    return maior_palindromo;
}

int main() {
    int resultado = maior_palindromo();

    printf("O maior palíndromo obtido a partir do produto de dois números de três dígitos é: %d\n", resultado);

    return 0;
}
