#include <stdio.h>
#include <stdlib.h>

void min_max(int *v, int n) {
  int min = v[0];
  int max = v[0];

  for(int i = 1; i < n; i++) {
    if(v[i] < min) {
      min = v[i];
    }

    if(v[i] > max) {
      max = v[i];
    }
  }
  printf("Menor valor: %d, Maior valor: %d\n", min, max);
}

void menu(int *option) {
  printf("\n ------- Opções \n");
  printf("1 - Adicionar elemento\n");
  printf("-1 - Sair\n");
  printf("Opcao: ");
  scanf("%d", option);
}

void adicionarElemento(int *vector, int *amount) {
  int el;

  printf("Digite o elemento a ser adicionado: ");
  scanf("%d", &el);

  if(*amount == 0) {
    vector[0] = el;
  } else {
    vector = (int *) realloc(vector, (*amount + 1) * sizeof(int));
    vector[*amount] = el;
  }

  (*amount)++;
}

int main() {
  int *vector = (int *) malloc(sizeof(int));
  int option;
  int amount = 0;

  do {
    menu(&option);

    switch (option)
    {
      default:
        break;
      case 1:
        adicionarElemento(vector, &amount);
    }
  } while (option != -1);

  printf("Vetor final: ");
  for (int i = 0; i < amount; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");

  printf("Quantidade de elementos: %d\n", amount);

  printf("\n");

  min_max(vector, amount);

  free(vector);

  return 0;
}