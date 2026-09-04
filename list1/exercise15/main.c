#include <stdio.h>
#include <stdlib.h>

int soma_diagonal(int **matriz, int n) {
  int soma = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) {
        soma += matriz[i][j];
      }
    }
  }
  return soma;
}

int main() {
  int n;
  int **matriz;

  printf("Digite o tamanho da matriz quadrada: ");
  scanf("%d", &n);

  matriz = (int **) malloc(n * sizeof(int *));
  for(int i = 0; i < n; i++) {
    matriz[i] = (int *) malloc(n * sizeof(int));
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("Digite o elemento [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  int soma = soma_diagonal(matriz, n);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  printf("A soma da diagonal principal é: %d\n", soma);

  for(int i = 0; i < n; i++) {
    free(matriz[i]);
  }
  free(matriz);



  return 0;
}