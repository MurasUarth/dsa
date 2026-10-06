#include <stdio.h>
#include <stdlib.h>

void troca_vizinhos(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int vector[6] = {10, 20, 30, 40, 50, 60};

  printf("Vetor original: ");

  for(int i = 0; i < (sizeof(vector) / sizeof(vector[0])); i++) {
    printf("%d ", vector[i]);
  }

  printf("\n");

  for(int i = 0; i < (sizeof(vector) / sizeof(vector[0])); i += 2) {
    troca_vizinhos(&vector[i], &vector[i + 1]);
  }

  printf("Vetor com vizinhos trocados: ");

  for(int i = 0; i < (sizeof(vector) / sizeof(vector[0])); i++) {
    printf("%d ", vector[i]);
  }

  printf("\n");

  return 0;
}