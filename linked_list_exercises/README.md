# Lista Encadeada (TAD)

Implementação didática de uma Lista Encadeada simples, usada como Tipo Abstrato de Dados (TAD) na disciplina.

## Arquivos

- `lista.h` — interface da TAD: as structs e os protótipos das funções que podem ser usadas.
- `lista.c` — implementação das funções declaradas em `lista.h`.
- `main.c` — programa de exemplo, mostrando como usar a lista.
- `Makefile` — automatiza a compilação do projeto.

## Sobre as structs estarem na interface

Em `lista.h` você vai ver as definições completas das structs `Info`, `Node` e `Head`, e não apenas os nomes dos tipos:

```c
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
```

Isso significa que o `main.c` (ou qualquer outro arquivo que inclua `lista.h`) **enxerga os campos internos** dessas structs, como `head->pFirst` ou `info.value`. Em uma TAD "de verdade", normalmente escondemos esses detalhes do usuário, para que ele só possa manipular a lista através das funções da interface (`insertFirst`, `search`, `freeList`, etc.), sem depender de como ela foi implementada por dentro.

Vocês já usaram structs dentro da implementação de outras TADs. Aqui, **optamos por deixar as structs completas no `.h` de propósito, só para simplificar esta TAD**. Isso não significa que vocês devam acessar os campos diretamente no `main.c` — continuem usando as funções da interface (`insertFirst`, `search`, `freeList`, etc.) para manipular a lista, mesmo que o compilador permita o acesso direto.

Nas próximas TADs (pilha e fila) vamos voltar a esconder esses dados: a struct completa fica só dentro do `.c`, e o `.h` expõe apenas um tipo escondido/encapsulado. Aí sim, o `main.c` não vai mais conseguir acessar os campos internos, nem por engano — só vai ser possível manipular a estrutura através das funções da interface.

## Compilando e executando

O projeto tem um `Makefile` pronto. No terminal, dentro da pasta do projeto:

```sh
make
```

Isso compila `main.c` e `lista.c` e gera o executável `programa`. Para rodar:

```sh
./programa
```

Para apagar os arquivos gerados pela compilação (`.o` e o executável `programa`):

```sh
make clean
```

Se você alterar algum `.c` ou `.h` e rodar `make` novamente, apenas os arquivos que mudaram (e o que depende deles) serão recompilados.
