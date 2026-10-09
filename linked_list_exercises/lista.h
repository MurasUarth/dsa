#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int value;
} Info;

typedef struct Node {
    Info info;
    struct Node *pNext;
} Node;

typedef struct {
    Node *pFirst;
} Head;

Head *createList(void);

int isEmpty(Head *head);

void insertFirst(Head *head, Info info);

void insertLast(Head *head, Info info);

int removeFirst(Head *head);

int removeLast(Head *head);

int search(Head *head, int value, Info *result);

void printList(Head *head);

void freeList(Head *head);

int countList(Head *head);

int countHigherValues(Head *head, int value);

void removeValue(Head *head, int value);

void revertList(Head *head);

#endif
