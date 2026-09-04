#include <stdio.h>

void min_max(int *v, int n, int *min, int *max) {
  *min = v[0];
  *max = v[0];

  for(int i = 1; i < n; i++) {
    if(v[i] < *min) {
      *min = v[i];
    }

    if(v[i] > *max) {
      *max = v[i];
    }
  }
}

int main() {
  int vector[6] = {10, 20, 30, 40, 50, 60};
  int menor, maior;

  printf("Vetor original: ");
  for(int i = 0; i < (sizeof(vector) / sizeof(vector[0])); i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");

  min_max(vector, (sizeof(vector) / sizeof(vector[0])), &menor, &maior);

  printf("Menor elemento: %d\n", menor);
  printf("Maior elemento: %d\n", maior);

  return 0;
}