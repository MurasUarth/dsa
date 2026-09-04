#include <stdio.h>
#include <stdlib.h>

int *inserir(int *v, int *n, int valor) {
  v = (int *) realloc(v, (*n + 1) * sizeof(int));
  if(v == NULL) {
    return NULL;
  }

  v[*n] = valor;

  (*n)++;

  return v;
}

int main() {
  int n = 3;
  int *v = (int *) malloc(n * sizeof(int));
  v[0] = 10; v[1] = 20; v[2] = 30;

  for(int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  v = inserir(v, &n, 40);

  for(int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  free(v);

  return 0;
}