#include <stdio.h>
#include <string.h>

typedef struct
{
    char dadosNomes[100], dadosEmails[100], dadosSenhas[100];
}Usuario;

void removeNewline(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}


void cadastroUsuario(Usuario *usuarios, int *cont_usuarios)
{
    printf("Cadastro\n");
    printf("--------------------------\n");
    printf("Digite seu nome completo:\n");
    fgets(usuarios[*cont_usuarios].dadosNomes, 100, stdin);
    fflush(stdin);
    printf("Digite seu e-mail:\n");
    fgets(usuarios[*cont_usuarios].dadosEmails, 100, stdin);
    fflush(stdin);
    printf("Digite sua senha:\n");
    fgets(usuarios[*cont_usuarios].dadosSenhas, 100, stdin);
    printf("Cadastro realizado!\n");
    printf("--------------------------\n");
    *cont_usuarios += 1;
}

void loginUsuario(Usuario *usuarios, int cont_usuarios)
{
    char email[100], senha[100];
    int i=0;
    printf("Login\n");
    printf("--------------------------\n");
    do
    {
        i=0;
        printf("Digite seu e-mail:\n");
        fgets(email, 100, stdin);
        removeNewline(email);
        while(i<cont_usuarios && strcmp(email, usuarios[i].dadosEmails)!=0)
        {
            i++;
        }
        if(i==cont_usuarios)
        {
            printf("E-mail invalido...\nTente novamente:\n");
        }
    }while(i==cont_usuarios);
    do
    {
        printf("Digite sua senha:\n");
        fgets(senha, 100, stdin);
        removeNewline(senha);
        if(strcmp(senha, usuarios[i].dadosSenhas)!=0)
        {
            printf("Senha invalida...\nTente novamente:\n");
        }
    }while(strcmp(senha, usuarios[i].dadosSenhas)!=0);
    printf("Login realizado!");
}

int main()
{
    int opc, cont_usuarios = 0;
    Usuario usuarios[100];
    printf("Escolha uma opcao:\n1 - Cadastrar usuario\n2 - Fazer Login\n");
    printf("--------------------------\n");
    scanf("%d", &opc);
    fflush(stdin);
    while(opc!=1 && opc!=2)
    {
        printf("Opcao invalida!\nTente novamente...\n");
        printf("Escolha uma opcao:\n1 - Cadastrar usuário\n2 - Fazer Login\n");
        scanf("%d", &opc);
    }
    if(opc==1)
    {
        cadastroUsuario(usuarios, &cont_usuarios);
    }
    loginUsuario(usuarios, cont_usuarios);
    printf("Deseja complementar seu perfil?\n1 - Sim\n2 - Nao");
    scanf("%d", &opc);
    fflush(stdin);
    while(opc!=1 && opc!=2)
    {
        printf("Opcao invalida!\nTente novamente...\n");
        printf("Escolha uma opcao:\n1 - Sim usuário\n2 - Nao\n");
        scanf("%d", &opc);
    }
    return 0;
}