#include <stdio.h>

struct pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct pessoa p;
    
    printf("digite seu nome: ");
    scanf("%s", p.nome);
    
    printf("Digite sua idade: ");
    scanf("%d", &p.idade);
    
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    
    return 0;
}

