#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"


int main(void) {
  int n, opcao;

  printf("Digite a quantidade de números a ser gerada: ");
  scanf("%d", &n);

  printf("Escolha uma opção:\n");
  printf("1 - Gerar números em ordem aleatória\n");
  printf("2 - Gerar números em ordem crescente\n");
  printf("3 - Gerar números em ordem decrescente\n");
  printf("Opção: ");
  scanf("%d", &opcao);

  gerarNumeros(n, opcao);

  return 0;
}