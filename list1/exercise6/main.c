#include <stdio.h>
#include <stdlib.h>

int soma(int *v, int n) {
    int sum = 0;
    int *p = v;

    for(int i = 0; i < n; i++) {
        sum += *p;
        p++;
    };

    return sum;
};

void main() {
    int vector[] = {1, 2, 3, 4, 5};
    int sum = soma(vector, (sizeof(vector) / sizeof(vector[0])));
    printf("Soma: %d\n", sum);
};