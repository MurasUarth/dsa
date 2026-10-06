#include <stdio.h>
#include <stdlib.h>

int *amostra_e_ajusta(int *vetor, int capacidade_inicial, int *tamanho_final) {
    int valor;
    for(int i = 0; i < capacidade_inicial * 1.2; i++) {
        if(i >= capacidade_inicial) {
          printf("Aumentando capacidade do vetor para %d\n", i);
           vetor = (int *) realloc(vetor, ((i + 1) * sizeof(int)));
        }
        printf("Digite o valor %d:\n", i + 1);
        scanf("\n%d", &valor);

        if(valor == 0) {
            if(i >= capacidade_inicial * 0.8) {
                printf("Encerrando programa. \n");
                return vetor;
            } else {
                printf("Preenha pelo menos 80 por cento do vetor antes de encerrar \n");
                i--;
            }
        } else {
                vetor[i] = valor;
                *tamanho_final = *tamanho_final + 1;
        }
    }

    return vetor;
}

void gera_relatorio(int *vetor, int tamanho) {
    int soma = 0;
    int leituras_criticas = 0;
    printf("Vetor Final: [  ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d  ", vetor[i]);
        if(vetor[i] > 20) {
            leituras_criticas++;
        }
        soma += vetor[i];
    }
    printf("]\n");

    int media = soma / tamanho;
    printf("Média de valores de tempo: %d\n", media);
    printf("Leituras críticas: %d\n", leituras_criticas);
}

int main() {
    int s = 10;
    int tamanho_final = 0;
    int *v = ((int *) malloc(s * sizeof(int)));

    v = amostra_e_ajusta(v, s, &tamanho_final);

    gera_relatorio(v, tamanho_final);

    free(v);

    return 0;
}