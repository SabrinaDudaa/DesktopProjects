#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "organizadores.h"

void gerarNumeros(int n, int opcao) {
    int *numeros = (int *)malloc(n * sizeof(int));
    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Preenchendo o array
    for (int i = 0; i < n; i++) {
        numeros[i] = i + 1;
    }

    if (opcao == 1) {
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            int j = rand() % n;
            int temp = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = temp;
        }
    } else if (opcao == 3) {
        for (int i = 0; i < n / 2; i++) {
            int temp = numeros[i];
            numeros[i] = numeros[n - i - 1];
            numeros[n - i - 1] = temp;
        }
    }

    int escolha;
    printf("Deseja ver os numeros gerados antes de organizar: \n1 - SIM\n2 - NAO\n ");
    scanf("%d", &escolha);
    if (escolha == 1) {
        for (int i = 0; i < n; i++) {
            printf("%d ", numeros[i]);
        }
        printf("\n");
    }

    escolheMetodo(n, &numeros); // Passa o endereço do ponteiro
    FILE *f = fopen("saida.txt", "w");
    if(f == NULL){
        printf("erro ao abrir arquivo");
        exit(1);
    }
    else{
        for(int i = 0; i < n; i++) {
            fprintf(f,"%d\n",numeros[i]);
        }
    }
    fclose(f);
    free(numeros); // Libera memória ao final
}



