//Nome, telefone, localização, produtos adquiridos, data da recompra (e que exiba os clientes de outra cidade que nao goiania)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

char opc;

typedef struct{
    char nome[1024], telefone[100], localizacao[100], produtos[1024], dataUltima[1024], dataProx[50];
}Cliente;

void hud();

void buscarCliente() {
    system("cls");
    //Caractere 6
    FILE *p;
    char inicial, clienteAtual[256];
    int tamClienteAtual;
    printf("----- Buscar Clientes -----\n\n");
    printf("Digite a inicial dos clientes desejados: ");
    scanf(" %c", &inicial);
    if(inicial>='a' && inicial<='z') 
        inicial -= ('a'-'A');
    p = fopen("clientes.txt", "r");
    fgets(clienteAtual, 256, p);
    while(fgets(clienteAtual, 360, p)!=NULL) {
        tamClienteAtual = strlen(clienteAtual);
        clienteAtual[tamClienteAtual-1] = '\0';
        if(clienteAtual[6]==inicial) {
            for(int i=0; i<5; i++) { //Numero de informações do cliente q serao lidas nas linhas
                printf("%s\n", clienteAtual);
                fgets(clienteAtual, 256, p);
                tamClienteAtual = strlen(clienteAtual);
                clienteAtual[tamClienteAtual-1] = '\0';
            }
            printf("\n");
        }
    }
    printf("Pressione qualquer tecla para continuar...");
    getch();
    hud();
}

void cadastrarCliente() {
    Cliente cliente;
    FILE *p;
    system("cls");
    printf("----- Cadastrar Um Cliente -----\n\n");
    printf("Digite o nome do cliente: ");
    fgets(cliente.nome, 1024, stdin);
    int strTam = strlen(cliente.nome);
    cliente.nome[strTam-1] = '\0';
    if(cliente.nome[0]>='a' && cliente.nome[0]<='z')
        cliente.nome[0] -= ('a'-'A');
    printf("Digite o telefone do cliente: ");
    fgets(cliente.telefone, 100, stdin);
    strTam = strlen(cliente.telefone);
    cliente.telefone[strTam-1] = '\0';
    printf("Digite a localizacao do cliente: ");
    fgets(cliente.localizacao, 100, stdin);
    strTam = strlen(cliente.localizacao);
    cliente.localizacao[strTam-1] = '\0';
    printf("Digite os produtos adquiridos por %s: ", cliente.nome);
    fgets(cliente.produtos, 1024, stdin);
    strTam = strlen(cliente.produtos);
    cliente.produtos[strTam-1] = '\0';
    printf("Digite a data ultima compra: ");
    fgets(cliente.dataUltima, 1024, stdin);
    strTam = strlen(cliente.dataUltima);
    cliente.dataUltima[strTam-1] = '\0';
    system("cls");
    p = fopen("Clientes.txt", "a");
    fprintf(p, "Nome: %s\nCelular: %s\nLocalizacao: %s\nProdutos adquiridos: %s\nData da ultima compra: %s\n\n", cliente.nome, cliente.telefone, cliente.localizacao, cliente.produtos, cliente.dataUltima);
    fclose(p);
    system("cls");
    printf("Cadastro realizado!\n");
    printf("Pressione qualquer tecla para continuar...");
    getch();
    hud();
}

void hud() {
    system("cls");
    printf("----- Programa de Cadastro de Clientes Gotas de Aromas -----\n\n");
    printf("1 - Cadastrar um cliente\n");
    printf("2 - Buscar cliente\n");
    printf("3 - Sair\n\n");
    printf("Selecione uma opcao: ");
    scanf(" %c", &opc);
    fflush(stdin);
    while(opc<'1' || opc>'3') {
        printf("Opcao invalida, tente novamente: ");
        scanf(" %c", &opc);
        fflush(stdin);
    }
    if(opc=='1') {
        cadastrarCliente();
    }
    else {
        if(opc=='2') {
            buscarCliente();
        }
    }
}

int main() {
    hud();
    return 0;
}