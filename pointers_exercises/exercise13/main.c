#include <stdio.h>
#include <stdlib.h>

int remover(int **v, int *n, int posicao) {
  if(posicao < 0 || posicao >= *n) {
    printf("Posição inválida.\n");
    return 0;
  }

  for(int i = posicao; i < *n - 1; i++) {
    (*v)[i] = (*v)[i + 1];
  }

  (*n)--;

  if(*n > 0) {
    *v = (int *) realloc(*v, *n * sizeof(int));
  } else {
    printf("Último elemento removido. Liberando memória.\n");
    free(*v);
    *v = NULL;
  }

  *v = (int *) realloc(*v, *n * sizeof(int));

  return 1;
}

int main() {
  int n = 5;
  int *v = (int *) malloc(n * sizeof(int));
  v[0] = 10; v[1] = 20; v[2] = 30; v[3] = 40; v[4] = 50;

  for(int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  remover(&v, &n, 0);
  
  for(int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  free(v);
  return 0;
}