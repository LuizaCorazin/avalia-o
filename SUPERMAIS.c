#include <stdio.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto produto;
int produtoCadastrado = 0;

void cadastrarProduto() {
    printf("\033[33m");
    printf("\n---  ❤️  Cadastro do Produto ❤️️  ---\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", produto.nome);

    printf("Quantidade em estoque: ");
    scanf("%d", &produto.quantidade);

    printf("Preço por unidade (R$): ");
    scanf("%f", &produto.preco);

    produtoCadastrado = 1;
    printf("Produto cadastrado com sucesso!\n");
}

void visualizarEstoque() {
    if (produtoCadastrado) {
        printf("\n--- Informações do Produto ---\n");
        printf("Nome: %s\n", produto.nome);
        printf("Quantidade em estoque: %d\n", produto.quantidade);
        printf("Preço por unidade: R$%.2f\n", produto.preco);
    } else {
        printf("\nNenhum produto cadastrado.\n");
    }
}

void realizarCompra() {
    if (!produtoCadastrado) {
        printf("\nNenhum produto cadastrado para realizar uma compra.\n");
        return;
    }

    int quantidadeCompra;
    printf("\n--- Realizar Compra ---\n");
    printf("Quantidade a comprar: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra <= 0) {
        printf("Quantidade inválida.\n");
        return;
    }

    if (quantidadeCompra > produto.quantidade) {
        printf("Quantidade solicitada excede o estoque atual: %d\n", produto.quantidade);
    } else {
        produto.quantidade -= quantidadeCompra;
        printf("Compra realizada com sucesso!\n");
        printf("Quantidade restante em estoque: %d\n", produto.quantidade);
    }
}

int main() {
    int opcao;

    do {
       
        printf("\033[0m");
        printf("\n--- 🍉🍍🍎 SuperMais!!🍉🍍🍎 ---\n");
        printf("\033[32m");
        printf("1. Cadastrar produto\n");
        printf("2. Estoque\n");
        printf("3. Realizar compra\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarEstoque();
                break;
            case 3:
                realizarCompra();
                break;
            case 0:
                printf("\nEncerrando o sistema. Obrigado!\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
