#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CD
{
    char genero[20], banda[20];
    int ano, qtd, id;
    float vl;
};

struct CD cds[20];

int numcd = 0;  // Mantive numcd como antes

void cadastrar();
void vender();
void filtrar();
void consultar();

int main(){
    int opcao;  // Renomeei opc para opcao
    do{
        system("cls");
        printf("------ Som & Arte ------\n");
        printf("[ 1 ] - Cadastrar CD\n");
        printf("[ 2 ] - Vender CD\n");
        printf("[ 3 ] - Filtrar por banda\n");
        printf("[ 4 ] - Consultar estoque\n");
        printf("[ 0 ] - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);  // Usando a variável 'opcao' agora
        system("cls");

        switch (opcao)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            vender();
            break;
        case 3:
            filtrar();
            break;
        case 4:
            consultar();
            break;
        case 0:
            printf("Fechando sistema...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
        printf("\nPressione ENTER para continuar\n");
        getchar();
        getchar();
    }while (opcao != 0);  // Verificando 'opcao' no loop
    return 0;
}

void cadastrar(){
    printf("Digite o genero do CD:\n");
    scanf("%s", cds[numcd].genero);
    printf("Digite a banda do CD:\n");
    scanf("%s", cds[numcd].banda);
    printf("Digite o ano do CD:\n");
    scanf("%d", &cds[numcd].ano);
    printf("Digite a quantidade de copias que serao cadastradas:\n");
    scanf("%d", &cds[numcd].qtd);
    printf("Digite o valor de cada copia:\n");
    scanf("%f", &cds[numcd].vl);
    printf("CD cadastrado no ID: %d!\n", numcd);
    cds[numcd].id = numcd;
    numcd++;
}

void vender(){
    int id, qtd;
    printf("Digite o ID do CD que deseja vender:\n");
    scanf("%d", &id);
    for(int i = 0; i < numcd; i++){
        if(id == cds[i].id){
            printf("Digite a quantidade que deseja vender:\n");
            scanf("%d", &qtd);
            if(qtd <= cds[i].qtd){
                cds[i].qtd -= qtd;
                printf("CD(s) vendidos!\n");
                printf("Banda do CD: %s\n", cds[i].banda);
                printf("Genero do CD: %s\n", cds[i].genero);
                printf("Ano do CD: %d\n", cds[i].ano);
                printf("Quantidade vendida: %d\n", qtd);
                printf("Valor da unidade: %.2f\n", cds[i].vl);
                printf("Valor total da venda: %.2f\n", cds[i].vl * qtd);
                printf("Copias restantes em estoque: %d\n", cds[i].qtd);
            }else{
                printf("Nao e possivel vender essa quantidade de copias!\n");
                printf("Copias restantes: %d\n", cds[i].qtd);
            }
            return;
        }
    }
    printf("CD nao encontrado!\n");
}

void filtrar(){
    char banda[20];
    int count = 0;
    printf("Digite a banda que deseja usar para filtrar:\n");
    scanf("%s", banda);
    for(int i = 0; i < numcd; i++){
        if(strcmp(banda, cds[i].banda) == 0){
            printf("\nCD encontrado!\n");
            printf("Genero do CD: %s\n", cds[i].genero);
            printf("Ano do CD: %d\n", cds[i].ano);
            printf("Valor da unidade: %.2f\n", cds[i].vl);
            printf("Copias restantes em estoque: %d\n", cds[i].qtd);
            count = 1;
        }
    }
    if(count == 0){
        printf("Nenhum CD dessa banda encontrado!\n");
    }
}

void consultar(){
    int id;
    printf("Digite o ID do CD que deseja consultar:\n");
    scanf("%d", &id);
    for(int i = 0; i < numcd; i++){
        if(id == cds[i].id){
            printf("CD encontrado no estoque!\n");
            printf("Copias restantes em estoque: %d\n", cds[i].qtd);
            return;
        }
    }
    printf("CD nao encontrado!\n");
}
