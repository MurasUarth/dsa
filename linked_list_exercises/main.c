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

    revertList(head);

    printList(head);

    return 0;
}
