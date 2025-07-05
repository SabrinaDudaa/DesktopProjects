#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"

void Bolha(int n, int *l) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (l[j] > l[j + 1]) {
                int temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
        }
    }

    // Exibe os números ordenados
  /*  for (int i = 0; i < n; i++) {
        printf("%d ", l[i]);
    }
    printf("\n");*/
}

void Bolhacomp(int n, int *V){
        int mudou = 1; // Verdadeiro
        int indice = n; // Último índice

        while (mudou) {
            mudou = 0; //assumimos que não houve trocas
            int j = 1;

            while (j < n) {
                if (V[j - 1] > V[j]) {
                    // Troca os elementos adjacentes
                    int auxiliar = V[j - 1];
                    V[j - 1] = V[j];
                    V[j] = auxiliar;

                    mudou = 1; // Houve troca, então ainda não está ordenado
                }
                j++;
            }
            n = indice; // Ajusta o limite para evitar iterar elementos já ordenados
        }

      /*  printf("Vetor ordenado (Bolha com Parada):\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", V[i]);
        }
        printf("\n");*/
}

void insercaoDireta(int n, int *V) {
    for (int i = 1; i < n; i++) {
        int auxiliar = V[i];
        int j = i - 1;

        // Move os elementos maiores que o auxiliar para frente
        while (j >= 0 && auxiliar < V[j]) {
            V[j + 1] = V[j];
            j--;
        }

        // Insere o elemento na posição correta
        if (j != i - 1) {
            V[j + 1] = auxiliar;
        }
    }

  /*  printf("Vetor ordenado (Inserção Direta):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}
void insercaoBinaria(int n, int *V) {
    for (int i = 1; i < n; i++) {
        int auxiliar = V[i];
        int esq = 0, dir = i;

        // Busca binária para encontrar a posição de inserção
        while (esq < dir) {
            int meio = (esq + dir) / 2;
            if (V[meio] <= auxiliar) {
                esq = meio + 1;
            } else {
                dir = meio;
            }
        }

        // Desloca os elementos para abrir espaço
        for (int j = i; j > dir; j--) {
            V[j] = V[j - 1];
        }

        // Insere o elemento na posição correta
        V[dir] = auxiliar;
    }
    /*printf("Vetor ordenado (Inserção Binária):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}
void Shellsort(int n, int *V) {
    int h = 1;


    while (h < n) {
        h = 3 * h + 1;
    }


    while (h > 1) {
        h = h / 3;

        for (int i = h; i < n; i++) {
            int auxiliar = V[i];
            int j = i - h;


            while (j >= 0 && auxiliar < V[j]) {
                V[j + h] = V[j];
                j -= h;
            }
            V[j + h] = auxiliar;
        }
    }

   /* printf("Vetor ordenado (Shellsort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}
void selecaoDireta(int n, int *V) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;

        // Encontra o menor elemento no subvetor não ordenado
        for (int j = i + 1; j < n; j++) {
            if (V[j] < V[menor]) {
                menor = j;
            }
        }

        // Troca os elementos se necessário
        if (i != menor) {
            int auxiliar = V[i];
            V[i] = V[menor];
            V[menor] = auxiliar;
        }
    }

   /* printf("Vetor ordenado (Seleção Direta):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}

void heap(int *V, int n, int i) {
    int maior = i;        // Inicializa o maior como raiz
    int esq = 2 * i + 1;  // Filho esquerdo
    int dir = 2 * i + 2;  // Filho direito

    // Se o filho esquerdo for maior que a raiz
    if (esq < n && V[esq] > V[maior]) {
        maior = esq;
    }

    // Se o filho direito for maior que o maior atual
    if (dir < n && V[dir] > V[maior]) {
        maior = dir;
    }

    // Se o maior não for a raiz
    if (maior != i) {
        int temp = V[i];
        V[i] = V[maior];
        V[maior] = temp;

        // Recursivamente heapifica a subárvore afetada
        heap(V, n, maior);
    }
}

void Heapsort(int n, int *V) {
    // Constrói
    for (int i = n / 2 - 1; i >= 0; i--) {
        heap(V, n, i);
    }

    // Extrai
    for (int i = n - 1; i >= 0; i--) {
        int temp = V[0];
        V[0] = V[i];
        V[i] = temp;

        // Chama na raiz
        heap(V, i, 0);
    }

   /* printf("Vetor ordenado (Heapsort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}
int particiona(int *V, int inicio, int fim, int pivo) {
    int pivo_valor = V[pivo];
    int i = inicio - 1;

    // Move o pivô para o final
    int temp = V[pivo];
    V[pivo] = V[fim];
    V[fim] = temp;

    for (int j = inicio; j < fim; j++) {
        if (V[j] <= pivo_valor) {
            i++;
            temp = V[i];
            V[i] = V[j];
            V[j] = temp;
        }
    }

    // Move o pivô pro lugar certo
    temp = V[i + 1];
    V[i + 1] = V[fim];
    V[fim] = temp;

    return i + 1;
}

void Quicksort(int *V, int inicio, int fim, int tipo) {
    if (inicio < fim) {
        int pivo;

        // Escolhe
        if (tipo == 1) { // Primeiro
            pivo = inicio;
        } else if (tipo == 2) { // meio
            pivo = (inicio + fim) / 2;
        } else if (tipo == 3) { // Mediana
            int a = V[inicio], b = V[(inicio + fim) / 2], c = V[fim];
            if ((a <= b && b <= c) || (c <= b && b <= a)) {
                pivo = (inicio + fim) / 2;
            } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
                pivo = inicio;
            } else {
                pivo = fim;
            }
        }

        int q = particiona(V, inicio, fim, pivo);

        // Ordena
        Quicksort(V, inicio, q - 1, tipo);
        Quicksort(V, q + 1, fim, tipo);
    }
   /* printf("Vetor ordenado (Quicksort):\n");
    for (int i = 0; i < fim; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}

void merge(int *V, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esq = (int *)malloc(n1 * sizeof(int));
    int *dir = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        esq[i] = V[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        dir[j] = V[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            V[k++] = esq[i++];
        } else {
            V[k++] = dir[j++];
        }
    }

    while (i < n1) {
        V[k++] = esq[i++];
    }
    while (j < n2) {
        V[k++] = dir[j++];
    }

    free(esq);
    free(dir);
}

void Mergesort(int *V, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        Mergesort(V, inicio, meio);
        Mergesort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
    /*printf("Vetor ordenado (Mergesort):\n");
    for (int i = 0; i < fim; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}

void countingSort(int *V, int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(V[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(V[i] / exp) % 10] - 1] = V[i];
        count[(V[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        V[i] = output[i];
    }

    free(output);
}

void Radixsort(int n, int *V) {
    int max = V[0];
    for (int i = 1; i < n; i++) {
        if (V[i] > max) {
            max = V[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(V, n, exp);
    }

  /*  printf("Vetor ordenado (Radixsort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}

void Bucketsort(int n, int *V) {
    int max = V[0], min = V[0];
    for (int i = 1; i < n; i++) {
        if (V[i] > max) max = V[i];
        if (V[i] < min) min = V[i];
    }

    int range = max - min + 1;
    int *bucket = (int *)calloc(range, sizeof(int));

    for (int i = 0; i < n; i++) {
        bucket[V[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i] > 0) {
            V[index++] = i + min;
            bucket[i]--;
        }
    }

    free(bucket);

   /* printf("Vetor ordenado (Bucketsort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");*/
}

void escolheMetodo(int n,int **l) {
    clock_t inicio, fim;
    double tempo_g;
    printf("Digite o metodo de organizacao:\n");
    printf("1 - Bolha\n");
    printf("2 - Bolha com Parada\n");
    printf("3 - Insercao direta\n");
    printf("4 - Insercao binaria\n");
    printf("5 - Shellsort\n");
    printf("6 - Selecao direta\n");
    printf("7 - Heapsort\n");
    printf("8 - Quicksort\n");
    printf("9 - Mergesort\n");
    printf("10 - Radixsort\n");
    printf("11 - Bucketsort\n");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:{
            inicio = clock();
            Bolha(n,*l);
            fim = clock();
             tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("Tempo de execucao: %f segundos\n", tempo_g);
            break;
        }
      case 2:{
        inicio = clock();
        Bolhacomp(n,*l);
        fim = clock();
        tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execucao: %f segundos\n", tempo_g);
        break;
      }
      case 3:{
          inicio = clock();
          insercaoDireta(n,*l);
          fim = clock();
          tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
          printf("Tempo de execucao: %f segundos\n", tempo_g);
          break;
      }
      case 4:{
        inicio = clock();
        insercaoBinaria(n,*l);
        fim = clock();
        tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execucao: %f segundos\n", tempo_g);
        break;
    }
      case 5:{
          inicio = clock();
          Shellsort(n, *l);
          fim = clock();
          tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
          printf("Tempo de execucao: %f segundos\n", tempo_g);
          break;
        }
      case 6:{
          inicio = clock();
          selecaoDireta(n, *l);
          fim = clock();
          tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
          printf("Tempo de execucao: %f segundos\n", tempo_g);
          break;
      }
      case 7:{
          inicio = clock();
          Heapsort(n, *l);
          fim = clock();
          tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
          printf("Tempo de execucao: %f segundos\n", tempo_g);
          break;
      }
     case 8 :{
         printf("digite como o pivo deve ser escolhido:\n");
         printf("1 - elemento inicial\n");
         printf("2 - elemento central\n");
         printf("3 - mediana\n");
         int z;
         scanf("%d", &z);
         inicio = clock();
         Quicksort(*l, 0, n, z);
         fim = clock();
         tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
         printf("Tempo de execucao: %f segundos\n", tempo_g);
         break;
     }
      case 9:{
          inicio = clock();
          Mergesort(*l,0, n-1);
          fim = clock();
          tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
          printf("Tempo de execucao: %f segundos\n", tempo_g);
          break;
      }
      case 10:{
          inicio = clock();
          Radixsort(n,*l);
          fim = clock();
          tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
          printf("Tempo de execucao: %f segundos\n", tempo_g);
          break;
      }
      case 11:{
          inicio = clock();
          Bucketsort(n, *l);
          fim = clock();
          tempo_g = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
          printf("Tempo de execucao: %f segundos\n", tempo_g);
          break;
      }
      default:{
          printf("numero invalido!");
          exit(1);
      }
    }




}






