#include <stdio.h>
#include <stdlib.h>

int *intercalar(int *v1, int *v2, int n, int *n3) {
  *n3 = 2 * n;
  int *v = (int *) malloc((*n3) * sizeof(int));

  for(int i = 0; i < n; i++) {
    v[2 * i] = v1[i];
    v[2 * i + 1] = v2[i];
  }

  return v;
}

int main() {
  int n = 3;
  int n3;
  int *v1 = malloc(n * sizeof(int));
  int *v2 = malloc(n * sizeof(int));
  v1[0] = 10; v1[1] = 20; v1[2] = 30;
  v2[0] = 40; v2[1] = 50; v2[2] = 60;

  for(int i = 0; i < n; i++) {
    printf("%d ", v1[i]);
  }
  printf("\n");

  int *v3 = intercalar(v1, v2, n, &n3);

  for(int i = 0; i < n3; i++) {
    printf("%d ", v3[i]);
  }
  printf("\n");

  free(v1);
  free(v2);
  free(v3);

  return 0;
}