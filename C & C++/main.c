#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome_completo[100], apelido[100], senha[17], senha_2[17];
    int dia, mes, ano, cpf[11];
}Cliente;

Cliente cadastro, login;
int opc;

int verificarCPF(int *cpf_cpy)
{
    int dig_b1 = 0, dig_b2 = 0, val_b1 = 1, val_b2 = 9;
    for(int i=0; i<9; i++)
    {
        dig_b1 += cpf_cpy[i]*val_b1;
        val_b1++;
    }
    for(int i=0; i<10; i++)
    {
        dig_b2 += cpf_cpy[i]*val_b2;
        val_b2--;
    }
    dig_b1 %= 11;
    if(dig_b1==10)
    {
        dig_b1 = 0;
    }
    dig_b2 %= 11;
    if(dig_b2==10)
    {
        dig_b2 = 0;
    }
    if(dig_b1==cpf_cpy[9] && dig_b2==cpf_cpy[10])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void CadastrarUsuario()
{
    //Declarando variáveis
    int acc;
    opc = 0;

    while(opc!=1)
    {
        //Iniciando o cadastro
        printf("------------------------\n\tCADASTRO\n------------------------\n\n");

        //Nome completo
        printf("Nome completo: ");
        fflush(stdin);
        fgets(cadastro.nome_completo, 100, stdin);

        //Apelido (Nickname)
        printf("Apelido: ");
        fflush(stdin);
        fgets(cadastro.apelido, 100, stdin);
        while(strlen(cadastro.apelido)<5)
        {
            printf("Apelido curto demais, tente novamente: ");
            fflush(stdin);
            fgets(cadastro.apelido, 100, stdin);
        }
        while(strlen(cadastro.apelido)>15)
        {
            printf("Apelido extenso demais, tente novamente: ");
            fflush(stdin);
            fgets(cadastro.apelido, 100, stdin);
        }

        //Senha
        printf("Crie uma senha\nREQUISITOS:\n\nMIN: 8 CARACTERES\nMAX: 16 CARACTERES\nUMA LETRA MAIUSCULA NO MINIMO\nUM OU MAIS CARACTERES ESPECIAIS\n");
        printf("Criar senha: ");
        fflush(stdin);
        fgets(cadastro.senha, 17, stdin);
        while(strlen(cadastro.senha)<9)
        {
            printf("Senha curta demais, tente novamente: ");
            fflush(stdin);
            fgets(cadastro.senha, 17, stdin);
        }
        while(strlen(cadastro.senha)>16)
        {
            printf("Senha muito longa, tente novamente: ");
            fflush(stdin);
            fgets(cadastro.senha, 17, stdin);
        }
        printf("Confirmar senha: ");
        fflush(stdin);
        fgets(cadastro.senha_2, 17, stdin);
        while(strcmp(cadastro.senha, cadastro.senha_2)!=0)
        {
            printf("As senhas nao coincidem, tente novamente: ");
            fflush(stdin);
            fgets(cadastro.senha_2, 17, stdin);
        }

        //#ifdef DATA DE NASCIMENTO
        printf("Dia de nascimento: ");
        scanf("%d", &cadastro.dia);
        while(cadastro.dia<1 || cadastro.dia>31)
        {
            printf("Dia de nascimento invalido, tente novamente: ");
            scanf("%d", &cadastro.dia);
        }
        printf("Mes de nascimento: ");
        scanf("%d", &cadastro.mes);
        while(cadastro.mes<1 || cadastro.mes>12)
        {
            printf("Mes de nascimento invalido, tente novamente: ");
            scanf("%d", &cadastro.mes);
        }
        printf("Ano de nascimento: ");
        scanf("%d", &cadastro.ano);
        while(cadastro.ano<1900 || cadastro.ano>2024)
        {
            printf("Ano de nascimento invalido, tente novamente: ");
            scanf("%d", &cadastro.ano);
        }
        //#endif

        //#ifdef CPF
        printf("CPF: ");
        for(int i=0; i<11; i++)
        {
            scanf("%1d", &cadastro.cpf[i]);
        }
        acc = verificarCPF(cadastro.cpf);
        while(acc!=1)
        {
            printf("CPF invalido, tente novamente: ");
            for(int i=0; i<11; i++)
            {
                scanf("%1d", &cadastro.cpf[i]);
            }
            acc = verificarCPF(cadastro.cpf);
        }
        //#endif

        //#ifdef Verificando dados
        int j = 0;
        printf("---------------------------------\n\tVERIFICANDO DADOS\n---------------------------------\n\n");
        printf("Nome completo: %s\n", cadastro.nome_completo);
        printf("Data de nascimento: %d/%d/%d\n", cadastro.dia, cadastro.mes, cadastro.ano);
        printf("CPF: ");
        for(int i=0; i<14; i++)
        {
            if(i==3 || i==7)
            {
                printf(".");
            }
            else
            {
                if(i==11)
                {
                    printf("-");
                }
                else
                {
                    printf("%d", cadastro.cpf[j]);
                    j++;
                }
            }
        }
        printf("\n\nSeus dados estao corretos? (1-Sim, 2-Nao): ");
        scanf("%d", &opc);
        //#endif
    }
}

void LogarUsuario()
{
    //Iniciando o Login
    printf("------------------------\n\tLOGIN\n------------------------\n\n");

    //Usuario
    printf("Usuario: ");
    fflush(stdin);
    fgets(login.apelido, 100, stdin);
    if(strcmp(login.apelido, cadastro.apelido)!=0)
    {
        printf("Usuario inexistente, criar conta? (1-Sim, 2-Nao): ");
        fflush(stdin);
        scanf("%d", &opc);
        if(opc==1)
        {
            CadastrarUsuario();
            printf("Deseja realizar Login? (1-Sim, 2-Nao): ");
            scanf("%d", &opc);
            if(opc==1)
            {
                LogarUsuario();
            }
        }
    }
    else
    {
        //Senha
        printf("Senha: ");
        fflush(stdin);
        fgets(login.senha_2, 17, stdin);
        while(strcmp(login.senha_2, cadastro.senha)!=0)
        {
            printf("Senha incorreta, tente novamente: ");
            fflush(stdin);
            fgets(login.senha_2, 17, stdin);
        }
        printf("Login realizado com sucesso!!!\n");
    }
}

int main()
{
    printf("Selecione uma opcao:\n1-Criar conta\n2-Fazer Login\n");
    scanf("%d", &opc);

    //Cadastro
    if(opc==1)
    {
        CadastrarUsuario();
        printf("Deseja realizar Login? (1-Sim, 2-Nao): ");
        scanf("%d", &opc);
        if(opc==1)
        {
            LogarUsuario();
        }
    }
    else
    {
        LogarUsuario();
    }
    return 0;
}