#include <stdio.h>
#include <stdlib.h>

void inverter(int *v, int n) {
    int j = n - 1;
    int i = 0;
    
    while (i < j) {
      int temp = v[i];
      v[i] = v[j];
      v[j] = temp;
      i++;
      j--;
    }
};

void main() {
    int vector[] = {1, 2, 3, 4, 5};
    printf("Vetor original: \n");
    for(int i = 0; i < (sizeof(vector) / sizeof(vector[0])); i++) {
        printf("%d\n", vector[i]);
    };

    inverter(vector, (sizeof(vector) / sizeof(vector[0])));

    printf("Vetor invertido: \n");
    for(int i = 0; i < (sizeof(vector) / sizeof(vector[0])); i++) {
        printf("%d\n", vector[i]);
    };
};