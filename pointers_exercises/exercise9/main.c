#include <stdio.h>
#include <stdlib.h>

int *copia_vetor(int *v, int n) {
    int *copia = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        copia[i] = v[i];
    }

    return copia;
}

int main() {
    int vector[6] = {10, 20, 30, 40, 50, 60};

    printf("Vetor original: ");
    for(int i = 0; i < (sizeof(vector) / sizeof(vector[0])); i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    int *copia = copia_vetor(vector, (sizeof(vector) / sizeof(vector[0])));

    printf("Vetor copiado: ");
    for(int i = 0; i < (sizeof(vector) / sizeof(vector[0])); i++) { 
      // tentei usar sizeof(copia) / sizeof(copia[0]) mas não funcionou, sizeof de um (int *) é sempre 8 bytes, e sizeof(vector[0]) é 4 bytes, então o resultado seria 2, e não 6
        printf("%d ", copia[i]);
    }
    printf("\n");

    free(copia);

    return 0;
}