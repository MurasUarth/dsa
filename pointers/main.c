#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    float price;
    int amount;
} Product;

void menu(int *option) {
    printf("\n ------- Controle de estoque \n");
    printf("1 - Adicionar produto\n");
    printf("2 - Listar produtos\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", option);

};

void addProduct(Product *product) {
    printf("Nome do produto: ");
    scanf(" %s", product->name);
    printf("Valor do produto: ");
    scanf("%f", &product->price);
    printf("Quantidade em estoque: ");
    scanf("%d", &product->amount);
};

void printReport(Product *product) {
    float sum  = product->price * product->amount;
    printf("Nome: %s | Preço: R$ %f | Quantidade: %d | Total: R$ %f \n", product->name, product->price, product->amount, sum);
}

void main() {
    Product *stock = NULL;
    int amount = 0;
    int option;

    do {
        menu(&option);

        switch (option)
        {
        case 1:
            if (stock == NULL) {
                stock = (Product *) malloc(sizeof(Product));
            } else {
                stock = (Product *) realloc(stock, (amount + 1) * sizeof(Product));
            }
            
            addProduct(&stock[amount]);
            amount++;
            
            break;
        case 2:
            for(int i = 0; i < amount; i++) {
                printReport(&stock[i]);
            };
            break;
        default:
            break;
        }
    } while (option != 0);

    free(stock);

    return;
}
