#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Head *createList(void) {
    Head *head = malloc(sizeof(Head));

    if (head == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    head->pFirst = NULL;

    return head;
}

int isEmpty(Head *head) {
    return head->pFirst == NULL;
}

Node *createNode(Info info) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    newNode->info = info;
    newNode->pNext = NULL;

    return newNode;
}

void insertFirst(Head *head, Info info) {
    Node *newNode = createNode(info);

    newNode->pNext = head->pFirst;
    head->pFirst = newNode;
}

void insertLast(Head *head, Info info) {
    Node *newNode = createNode(info);

    if (isEmpty(head)) {
        head->pFirst = newNode;
        return;
    }

    Node *currentNode = head->pFirst;

    while (currentNode->pNext != NULL) {
        currentNode = currentNode->pNext;
    }

    currentNode->pNext = newNode;
}

int removeFirst(Head *head) {
    if (isEmpty(head)) {
        return 0;
    }

    Node *removedNode = head->pFirst;

    head->pFirst = removedNode->pNext;

    free(removedNode);

    return 1;
}

int removeLast(Head *head) {
    if (isEmpty(head)) {
        return 0;
    }

    if (head->pFirst->pNext == NULL) {
        free(head->pFirst);
        head->pFirst = NULL;

        return 1;
    }

    Node *currentNode = head->pFirst;

    while (currentNode->pNext->pNext != NULL) {
        currentNode = currentNode->pNext;
    }

    Node *removedNode = currentNode->pNext;

    currentNode->pNext = NULL;

    free(removedNode);

    return 1;
}

int search(Head *head, int value, Info *result) {
    Node *currentNode = head->pFirst;

    while (currentNode != NULL) {
        if (currentNode->info.value == value) {
            *result = currentNode->info;
            return 1;
        }

        currentNode = currentNode->pNext;
    }

    return 0;
}

void printList(Head *head) {
    Node *currentNode = head->pFirst;

    while (currentNode != NULL) {
        printf("[%d] -> ", currentNode->info.value);
        currentNode = currentNode->pNext;
    }

    printf("NULL\n");
}

void freeList(Head *head) {
    Node *currentNode = head->pFirst;

    while (currentNode != NULL) {
        Node *removedNode = currentNode;

        currentNode = currentNode->pNext;

        free(removedNode);
    }

    head->pFirst = NULL;

    free(head);
}

int countList(Head *head) {
    Node *currentNode = head->pFirst;
    int count = 0;

    if(currentNode == NULL) {
        return count;
    }

    while(currentNode != NULL) {
        count++;
        currentNode = currentNode->pNext;
    }

    return count;
}

int countHigherValues(Head *head, int value) {
    if(head->pFirst == NULL) {
        printf("A lista está vazia\n");
        return 0;
    }
    
    int count = 0;
    Node *currentNode = head->pFirst;

    while(currentNode != NULL) {
        if(currentNode->info.value > value) {
            count++;
        }

        currentNode = currentNode->pNext;
    }

    return count;
}

void removeValue(Head *head, int value) {
    if(head->pFirst == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node *currentNode = head->pFirst;

    while(head->pFirst->info.value == value) {
        head->pFirst = currentNode->pNext;
        free(currentNode);
        currentNode = head->pFirst;
    }

    printf("Primeiro laço ");

    printList(head);

    while(currentNode != NULL && currentNode->pNext != NULL) {
        while(currentNode->pNext != NULL && currentNode->pNext->info.value == value) {
            printf("entrou no if\n");
            Node *removedNode = currentNode->pNext;
            currentNode->pNext = currentNode->pNext->pNext;
            free(removedNode);
        }
        printf("Segundo laço ");
        printList(head);

        currentNode = currentNode->pNext;
    }
}
