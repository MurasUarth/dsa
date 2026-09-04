Escreva um programa em C para implementar um sistema simples de controle de
estoque. Para cada produto, devem ser armazenados nome, valor e quantidade em
estoque. Os produtos devem ser representados utilizando uma struct e armazenados
em um vetor alocado dinamicamente.
Menu
Crie uma função menu, que recebe a opção por referência e apresenta:
###### CONTROLE DE ESTOQUE ######
1 - Adicionar produto
2 - Listar produtos
0 - Sair
Opcao:
Ao selecionar Sair, libere a memória do vetor utilizando free.
Cadastro dos produtos
Inicialmente, não deve haver nenhum produto cadastrado e o vetor deve estar vazio. Ao
cadastrar o primeiro produto, aloque espaço para um produto utilizando malloc. Para
cada novo produto cadastrado, aumente o espaço disponível no vetor em uma posição
utilizando realloc. Crie uma função chamada cadastrarProduto que receba um
produto por referência e realize a leitura de seus dados.
Relatório do estoque
A opção Listar produtos deve apresentar um relatório contendo todos os produtos
cadastrados, informando nome, valor, quantidade em estoque e valor total em estoque.
O valor total deve ser calculado multiplicando o valor do produto pela quantidade
disponível. Crie uma função chamada exibirRelatorio que receba um produto por
referência e exiba seus dados.
Utilize as seguintes assinaturas para as funções
● void menu(int *opcao);
● void cadastrarProduto(Produto *produto);
● void exibirRelatorio(Produto *produto);
Exemplo de execução
###### CONTROLE DE ESTOQUE ######
1 - Adicionar produto
2 - Listar produtos
0 - Sair
Opcao: 1
###### Cadastro de Produto ######
Nome: Teclado
Valor: 120.00
Quantidade: 15
###### CONTROLE DE ESTOQUE ######
1 - Adicionar produto
2 - Listar produtos
0 - Sair
Opcao: 1
###### Cadastro de Produto ######
Nome: Mouse
Valor: 80.00
Quantidade: 25
###### CONTROLE DE ESTOQUE ######
1 - Adicionar produto
2 - Listar produtos
0 - Sair
Opcao: 2
===== RELATORIO DO ESTOQUE =====
Nome: Teclado; Valor: R$ 120.00; Quantidade: 15; Valor Total: R$ 1800.00
Nome: Mouse; Valor: R$ 80.00; Quantidade: 25; Valor Total: R$ 2000.00