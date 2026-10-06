## Exercício 3. Considere int v[5]; e int *p;. 

int v[5];
int *p;

## Classifique cada atribuição como legal ou ilegal e, quando for legal, explique o que ela representa.

a) p = v;
b) p = &v;
c) p = &v[0];
d) v = p;
e) p = v + 2;

## Respotas:

a) legal: p aponta para o endereço de memória de v[0];
b) ilegal: o compilador tenta atribuir os endereços de todas as posições do vetor;
c) legal: idem a; a e c são equivalentes.
d) ilgeal: essa atribuição não respeita as regras de atribuição em vetores;
e) legal: p aponta para o endereço de memória de v[2];