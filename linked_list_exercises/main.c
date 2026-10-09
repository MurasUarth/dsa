#include <stdio.h>
#include "lista.h"

int main(void) {
    Head *head = createList();

    if (isEmpty(head)) {
        printf("A lista esta vazia.\n");
    }

    Info info;
    Info result;

    info.value = 20;
    insertFirst(head, info);

    info.value = 10;
    insertFirst(head, info);

    info.value = 30;
    insertLast(head, info);

    info.value = 40;
    insertLast(head, info);

    printf("Lista: ");
    printList(head);

    if (removeLast(head)) {
        printf("Ultimo elemento removido.\n");
    }

    printf("Lista: ");
    printList(head);

    if (removeFirst(head)) {
        printf("Primeiro elemento removido.\n");
    }

    printf("Lista: ");
    printList(head);

    if (search(head, 30, &result)) {
        printf("Valor 30 encontrado na lista.\n");
    } else {
        printf("Valor 30 nao encontrado na lista.\n");
    }

    printf("Tamanho da lista: %d\n", countList(head));

    printf("%d elemento(s) maiores que %d.\n", countHigherValues(head, 20), 20);

    info.value = 20;
    insertLast(head, info);

    info.value = 20;
    insertFirst(head, info);

    info.value = 30;
    insertLast(head, info);

    info.value = 30;
    insertLast(head, info);

    info.value = 20;
    insertLast(head, info);

    printf("Lista: ");
    printList(head);

    removeValue(head, 20);

    printf("Lista: ");
    printList(head);

    freeList(head);

    return 0;
}
