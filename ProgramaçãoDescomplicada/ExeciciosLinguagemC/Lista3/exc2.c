// Se os numeros de 1 a 5 s ´ ao escritos em palavras: um, dois, tr ˜ es, quatro, cinco, ent ˆ ao h ˜ a´
// 2 + 4 + 4 + 6 + 5 = 22 letras usadas no total. Fac¸a um programa que conte quantas letras
// seriam utilizadas se todos os numeros de 1 a 1000 (mil) fossem escritos em palavras. ´
// OBS: Nao conte espac¸os ou hifens.


#include <stdio.h>

int contar_letras(int numero) {
    int letras = 0;

    if (numero == 0) {
        return 0;
    }

    if (numero <= 20) {
        char *numeros_ate_20[] = {
            "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez",
            "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"
        };

        letras += strlen(numeros_ate_20[numero - 1]);
    } else if (numero < 100) {
        int dezena = numero / 10;
        int unidade = numero % 10;

        char *dezenas[] = {
            "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"
        };

        letras += strlen(dezenas[dezena - 2]);

        if (unidade > 0) {
            letras += contar_letras(unidade);
        }
    } else if (numero < 1000) {
        int centena = numero / 100;
        int resto = numero % 100;

        letras += contar_letras(centena) + strlen("cento");

        if (resto > 0) {
            letras += contar_letras(resto) + strlen("e");
        }
    } else {
        letras += strlen("mil");
    }

    return letras;
}

int contar_letras_ate_mil() {
    int total_letras = 0;

    for (int i = 1; i <= 1000; i++) {
        total_letras += contar_letras(i);
    }

    return total_letras;
}

int main() {
    int total_letras = contar_letras_ate_mil();

    printf("O número total de letras utilizadas ao escrever os números de 1 a 1000 por extenso é: %d\n", total_letras);

    return 0;
}