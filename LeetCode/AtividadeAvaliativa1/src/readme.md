# Longest Nice Substring

## Descrição

Este programa em C resolve o problema 1763 - Longest Nice Substring do Leetcode. O objetivo é encontrar a maior substring "nice" em uma string dada. Uma string é considerada "nice" se contiver todas as letras do alfabeto, tanto em maiúsculas quanto em minúsculas.

O programa foi desenvolvido por Henrique Borges Krause como parte de um exercício do Leetcode.

## Informações do Autor

- Nome: Henrique Borges Krause
- Matrícula: 21201500

## Funcionamento

O programa percorre todas as substrings possíveis da string de entrada e verifica se cada substring é "nice". A substring mais longa que atende a esse critério é retornada como resultado.

## Testes

Foram realizados testes utilizando os próprios casos de teste fornecidos pelo Leetcode. Os resultados foram os seguintes:

- **Caso de teste 1:**

  - Entrada: "YazaAay"
  - Saída esperada: "aAa"

  O programa retornou a saída esperada, indicando que o teste passou com sucesso.

- **Caso de teste 2:**

  - Entrada: "abABB"
  - Saída esperada: "abABB"

  O programa retornou a saída esperada, indicando que o teste passou com sucesso.

- **Caso de teste 3:**

  - Entrada: "abA"
  - Saída esperada: ""

  O programa retornou a saída esperada, indicando que o teste passou com sucesso.

Os resultados dos testes mostram que o programa funciona conforme o esperado.

## Limitações

Este programa serve como uma solução básica para o problema e pode não ser otimizado para lidar com entradas muito grandes. Além disso, não foram realizados testes extensivos além dos casos de teste fornecidos pelo Leetcode.

## Referências

- [Problema 1763 - Longest Nice Substring no Leetcode](https://leetcode.com/problems/longest-nice-substring/)
