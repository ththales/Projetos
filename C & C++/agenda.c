/*
    Programa: Agenda de contatos
    - Nome, telefone e idade
    I) Imprimir
    II) Incluir
    III) Buscar
    IV) Excluir
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int opc;
 
typedef struct {
    char nome[50], telefone[20];
    int idade;
}Cadastro;
 
void menu();

void limparBuffer() {
    while(getchar()!='\n');
}
 
void adicionarContato() {
    int tam;
    FILE *p;
    Cadastro contatos;
    printf("Nome: ");
    limparBuffer();
    fgets(contatos.nome, 50, stdin);
    tam = strlen(contatos.nome);
    contatos.nome[tam-1] = '\0';
    printf("Telefone: ");
    fgets(contatos.telefone, 20, stdin);
    tam = strlen(contatos.telefone);
    contatos.telefone[tam-1] = '\0';
    printf("Idade: ");
    scanf("%d", &contatos.idade);
    p = fopen("agenda.txt", "a");
    if(p==NULL) {
        printf("Falha ao abrir o arquivo.\n");
        exit(1);
    }
    fprintf(p, "%s %s %d\n", contatos.nome, contatos.telefone, contatos.idade);
    fclose(p);
    menu();
    //printf("%s %s %d\n", contatos.nome, contatos.telefone, contatos.idade); 
}
 
void buscarContato() {
    
}
 
void excluirContato() {

}
 
void menu() {
    printf("----- Agenda -----\n\n");
    printf("1 - Adicionar Contato\n");
    printf("2 - Buscar Contato\n");
    printf("3 - Excluir Contato\n");
    printf("4 - Sair\n\n");
    printf("Selecione uma opção: ");
    scanf("%d", &opc);
    while(opc<1 || opc>4) {
        printf("Opção inválida, tente novamente: ");
        scanf("%d", &opc);
    }
    if(opc==1)
        adicionarContato();
    else if(opc==2)
        buscarContato();
    else if(opc==3)
        excluirContato();
}
 
int main() {
    menu();
    printf("Saindo da Agenda\n");
    return 0;
}