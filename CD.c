#include <stdio.h>
#include <stdlib.h>


struct CD{
    
    char banda[50];
    int estoque, ano, genero, id;
    float preco;
    
};

int num=0;
struct CD cd[100];
void Cadastrar();
void Pesquisar();
void Vender();
void Consultar();

int main(){
    
    int opcao;
    
    do{
    printf("\033[34m");
    printf("------ Som & Arte ------\n");
     printf("\033[0m");
    printf("1 - Cadastrar CD\n");
    printf("2 - Pesquisar\n");
    printf("3 - Consultar\n");
    printf("4 - Vender\n");
    printf("0 - Sair\n");
    printf("Selecione uma opção: ");
    scanf("%d", &opcao);
    getchar();
    system("clear");
    switch(opcao){
        case 1:
           Cadastrar();
           break;
        
        case 2:
           Pesquisar();
           break;
           
        case 3:
           Consultar();
           break;
           
        case 4:
           Vender();
           break;
           
        case 0:
           printf("Volte sempre!!");
           break;
        
        default:
           printf("Opção invalida!!");
           break;
    }
    
    printf("\033[34m");
    printf("Clique enter para continuar...\n");
    printf("\033[0m");
    getchar();
    getchar();
    system("clear");
    
    }while(opcao!=0);
    
    return 0;
}

void Cadastrar(){
    
    printf("\033[34m");
    printf("------ Cadastro ------\n");
    printf("\033[0m");
    printf("Banda: ");
    scanf(" %[^\n]", cd[num].banda);
    printf("Genêro: ");
    scanf(" %d", &cd[num].genero);
    printf("Ano: ");
    scanf("%d", &cd[num].ano);
    printf("Preço: ");
    scanf("%f", &cd[num].preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &cd[num].estoque);
    cd[num].id= num;
    printf("\033[31m");
    printf("ID: %d\n", cd[num].id);
    printf("\033[0m");
    num++;
}

void Pesquisar(){
    

    int genero, encontrar=0;
    
    if(num==1){
        printf("\033[35m");
        printf("------ Pesquisar ------\n");
        printf("\033[0m");
        printf("Genêro: ");
        printf("1 - Pop\n");
        printf("2 - Rock\n");
        printf("3 - Hip hop\n");
        printf("4 - Funk\n");
        printf("5 - Sertanejo\n");
        printf("6 - Mpb\n");
        printf("7 - Rap\n");
        printf("8 - Reggae\n");
        printf("Selecione uma opção: ");
        scanf(" %d", &genero);
        for(int i=0; i<num; i++){
            if(genero==cd[i].genero){
                printf("Banda: %s\n", cd[i].banda);
                printf("Genêro: %d\n", cd[i].genero);
                printf("Ano: %d\n", cd[i].ano);
                printf("Preço: %.2f\n", cd[i].preco);
                printf("ID: %d\n", cd[num].id);
                printf("Quantidade em estoque: %d\n", cd[i].estoque);
                printf("\033[37m");
                printf("\033[45m");
                printf("------------------------------\n");
                printf("\033[0m");
                printf("\033[0m");
                encontrar=1;
            }
            else if(encontrar==0){
                printf("Nenhum cd encontrado!!\n");
            }
        }
    }
    else{
        printf("Nenhum CD cadastrado!!\n");
    }
}

void Consultar(){
    
    int  id, encontrar=0;
    
    
    if(num==1){
    printf("\033[34m");
    printf("------ Consultar ------\n");
    printf("\033[0m");
    printf("Preenha as informações do produto que deseja:\n");
    printf("ID: ");
    scanf("%d", &id);
    getchar();
    system("clear");
    for(int i=0; i<num; i++){
        if(id==cd[i].id){
            printf("\033[34m");
            printf("------ Consultar ------\n");
            printf("\033[0m");
            printf("Banda: %s\n", cd[i].banda);
            printf("Genêro: %d\n", cd[i].genero);
            printf("Ano: %d\n", cd[i].ano);
            printf("Preço: %.2f\n", cd[i].preco);
            printf("ID: %d\n", cd[num].id);
            if(cd[i].estoque>0){
                printf("\033[32m");
                printf("Quantidade em estoque: %d\n", cd[i].estoque);
            }
            else{
                printf("\033[31m");
                printf("Quantidade em estoque: %d\n", cd[i].estoque);
            }
        
            encontrar=1;
        }
        else if(encontrar==0){
            printf("CD não encontrado!!\n");
        }
    }
}
}

void Vender(){
    
    int quantidade, opcao, id, i, encontrar=0;
    
    if(num==1){
    printf("\033[34m");
    printf("------ Venda ------\n");
    printf("\033[0m");
    printf("Preenha as informações do produto que deseja:\n");
    printf("ID: ");
    scanf("%d", &id);
    getchar();
    system("clear");
    
    for(i=0; i<num; i++){
        if(id==cd[i].id){
            
            printf("\033[34m");
            printf("------ Venda ------\n");
            printf("\033[0m");
            
            printf("Banda: %s\n", cd[i].banda);
            printf("Genêro: %d\n", cd[i].genero);
            printf("Ano: %d\n", cd[i].ano);
            printf("Preço: %.2f\n", cd[i].preco);
            printf("Quantidade em estoque: %d\n", cd[i].estoque);
            printf("ID: %d\n", cd[num].id);
            printf("Digite a quantidade que deseja comprar: ");
            scanf("%d", &quantidade);
            getchar();
            system ("clear");
            printf("Quantidade: %d\n", quantidade);
            printf("\033[34m");
            printf("Total: R$%.2f\n", quantidade*cd[i].preco);
            printf("\033[0m");
            printf("\nDeseja confirmar a compra? (1 - Sim / 2 - Não\n");
            scanf("%d", &opcao);
            getchar();
            system ("clear");
            switch(opcao){
                case 1:
                   printf("Compra confirmada!!\n");
                   cd[i].estoque = cd[i].estoque - quantidade;
                   break;
        
                case 2:
                   printf("Compra cancelada!!\n");
                   break;
         
                default:
                   printf("Opção invalida!!\n");
            
            encontrar=1;
        }
        
        }
        else if(encontrar==0){
            printf("Nennhum cd encontrado!!\n");
        }
    }
    
    }

    else{
        printf("Nenhum produto cadastrado!!\n");
    }
}
