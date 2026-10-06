## Exercício 2
int i = 3, j = 5;
int *p, *q;
p = &i;
q = &j;

## Indique o que acontece com i, j, p e q após cada trecho (considere sempre o estado inicial p = &i; q = &j;):
a) *p = *q;
b) p = q;
c) *p = *p + *q;
d) q = &i; *q = 100;

## Repostas:
a) i recebe o valor de j (5);
b) p agora aponta para o endereço de memória de j, assim como q;
c) i recebe o valor de 2j (porque anteriormente, p passou a apontar para j) ou seja 2.5, i recebe 10;
d) q passa a apontar para o endereço de memória do i; i recebe 100.