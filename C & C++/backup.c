#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

/*
    Códigos dos itens do jogo
    Armas
    Comuns (1 a 5)
    1 - Espada Longa (200)
    2 - Adaga afiada (250)
    3 - Cajado Simples (350)
    4 - Machado leve (300)
    5 - Lança fraca (150)
    Raro (6 a 15)
    6 - Lâminas gêmeas das sombras

    Anéis
    Comuns
    7 - Anel da Vitalidade (Aumenta o HP em 100)
    8 - Anel do Ataque (Aumenta o ATK em 100)
    9 - Anel da Proteção (Aumenta a DEF em 100)


*/

typedef struct {
    char nome[1024], classe[100];
    int level, hp, atk, def, armaAtual, itemExtra, moedas, andar;
}Personagem;

FILE *p;
Personagem player;
int opc;

void menuPrincipal();

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void efeitoDigitacao(const char *texto, int delay) {
    while (*texto) {
        putchar(*texto);
        fflush(stdout);
        Sleep(delay); // Atraso em milissegundos
        texto++;
    }
}

void iniciarJogo() {
    int numInimigos;
    system("cls");
    if(player.andar==1) {
        efeitoDigitacao("Depois de ser atacado por um grupo de inimigos,", 50);
        Sleep(500);
        efeitoDigitacao(" voce havia se perdido de seu caminho em uma floresta sombria...\n", 50);
        Sleep(500);
        efeitoDigitacao("A noite caia e a floresta te engolia, ", 50);
        Sleep(500);
        efeitoDigitacao("em uma torturante solidao...\n", 50);
        Sleep(500);
        efeitoDigitacao("O unico barulho que voce ouvia era de seus proprios passos na tempestade que estava chegando...\n", 50);
        Sleep(500);
        efeitoDigitacao("Ao caminhar por um certo tempo, ", 50);
        Sleep(500);
        efeitoDigitacao("voce se depara com uma escada misteriosa que escondia uma especie de masmorra...\n", 50);
        Sleep(500);
        efeitoDigitacao("Sem opcao, ", 50);
        Sleep(500);
        efeitoDigitacao("voce adentra e percebe que acabou preso...\n", 50);
        Sleep(500);
        efeitoDigitacao("Assim, ", 50);
        Sleep(500);
        efeitoDigitacao("deu-se inicio a sua jornada no ", 50);
        system("cls");
        Sleep(500);
        efeitoDigitacao("I N F E R N O", 250);
        Sleep(500);
        efeitoDigitacao("...", 1000);
        Sleep(1000);
        system("cls");
        efeitoDigitacao("\n\n\n", 1);
        efeitoDigitacao("DUNGEON ", 50);
        Sleep(500);
        efeitoDigitacao("OF ", 50);
        Sleep(500);
        efeitoDigitacao("DEATH\n", 50);
        Sleep(500);
        efeitoDigitacao("\nAperte qualquer tecla para iniciar...", 25);
        getch();
    }
    system("cls");
    printf("---------- Dungeon of Death ----------\n");
    printf("---------- Andar %d ----------\n", player.andar);
}

void criarPersonagem() {
    player.itemExtra = 0;
    player.level = player.andar = 1;

    system("cls");
    printf("---------- Criar personagem ----------\n\n");
    printf("Digite o nome do personagem: ");
    limparBuffer();
    fgets(player.nome, 1024, stdin);
    int tam = strlen(player.nome);
    player.nome[tam-1] = '\0';

    system("cls");
    printf("---------- Criar personagem ----------\n\n");
    printf("Classes\n");
    printf("1 - Cavaleiro\nHP: 1200\nATK: 200\nDEF: 300\nArma inicial: Espada Longa (Comum)\nMoedas: 400\n\n");
    printf("2 - Bandido\nHP: 850\nATK: 250\nDEF: 150\nArma inicial: Adaga afiada (Comum)\nMoedas: 600\n\n");
    printf("3 = Feiticeiro\nHP: 700\nATK: 350\nDEF: 100\nArma inicial: Cajado Simples (Comum)\nMoedas: 350\n\n");
    printf("Selecione uma classe: ");
    scanf("%d", &opc);
    while(opc<1 || opc >3) {
        printf("Classe invalida, tente novamente: ");
        scanf("%d", &opc);
    }
    if(opc==1) {
        strcpy(player.classe, "Cavaleiro");
        player.hp = 1200;
        player.atk = 200;
        player.def = 300;
        player.armaAtual = 1;
        player.moedas = 400;
    }
    else {
        if(opc==2) {
            strcpy(player.classe, "Bandido");
            player.hp = 850;
            player.atk = 250;
            player.def = 150;
            player.armaAtual = 2;
            player.moedas = 600;
        }
        else {
            strcpy(player.classe, "Feiticeiro");
            player.hp = 700;
            player.atk = 350;
            player.def = 100;
            player.armaAtual = 3;
            player.moedas = 350;
        }
    }

    system("cls");
    printf("---------- Criar personagem ----------\n\n");
    printf("Item extra\n");
    printf("1 - Anel da Vitalidade (comum)\nAumenta o HP em 100\n\n");
    printf("2 - Anel do Ataque (comum)\nAumenta o ATK em 100\n\n");
    printf("3 - Anel da Protecao (comum)\nAumenta a DEF em 100\n\n");
    printf("4 - Nenhum\n\n");
    printf("Selecione um item extra: ");
    scanf("%d", &opc);
    while(opc<1 || opc>4) {
        printf("Item extra invalido, tente novamente: ");
        scanf("%d", &opc);
    }
    if(opc==1) {
        player.itemExtra = 7;
        player.hp += 100;
    }
    else {
        if(opc==2) {
            player.itemExtra = 8;
            player.atk += 100;
        }
        else {
            if(opc==3) {
                player.itemExtra = 9;
                player.def += 100;
            }
        }
    }
    
    system("cls");
    printf("---------- Confirmar criacao ----------\n\n");
    printf("Nome: %s\n\n", player.nome);
    printf("Classe: %s\n\n", player.classe);
    printf("Moedas: %d\n\n", player.moedas);
    printf("Item extra: ");
    if(player.itemExtra==7) {
        printf("Anel da Vitalidade\n");
    }
    else {
        if(player.itemExtra==8) {
            printf("Anel do Ataque\n");
        }
        else {
            if(player.itemExtra==9) {
                printf("Anel da Protecao\n");
            }
            else {
                printf("Nenhum\n");
            }
        }
    }
    printf("\nDeseja iniciar o jogo com o personagem atual?\n1 - Sim\n2 - Nao\n\n");
    printf("Selecione uma opcao: ");
    limparBuffer();
    scanf("%d", &opc);
    while(opc<1 || opc>2) {
        printf("Opcao invalida, tente novamente: ");
        limparBuffer();
        scanf("%d", &opc);
    }
    if(opc==1) {
        p = fopen("save.dat", "w");
        if(p==NULL) {
            printf("Falha ao abrir o save.\n");
            exit(1);
        }
        fprintf(p, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", player.nome, player.classe, player.level, player.hp, player.atk, player.def, player.armaAtual, player.itemExtra, player.andar, player.moedas);
        fclose(p);
        iniciarJogo();
    }
    else {
        criarPersonagem();
    }
}

void carregarJogo() {
    system("cls");
    p = fopen("save.dat", "r");
    char linha[1024];
    if(p==NULL) {
        system("cls");
        printf("---------- ERRO! ----------\n\n");
        printf("Falha ao abrir o save (inexistente ou movido).\n\n");
        printf("Aperte qualquer tecla para voltar ao menu principal...");
        limparBuffer();
        getch();
        fclose(p);
        menuPrincipal();
    }
    fgets(linha, 1024, p); //Nome
    strcpy(player.nome, linha);
    fgets(linha, 1024, p); //Classe
    strcpy(player.classe, linha);
    fgets(linha, 1024, p); //Level
    player.level = atoi(linha);
    fgets(linha, 1024, p); //HP
    player.hp = atoi(linha);
    fgets(linha, 1024, p); //ATK
    player.atk = atoi(linha);
    fgets(linha, 1024, p); //DEF
    player.def = atoi(linha);
    fgets(linha, 1024, p); //Arma atual código
    player.armaAtual = atoi(linha);
    fgets(linha, 1024, p); //Item extra codigo
    player.itemExtra = atoi(linha);
    fgets(linha, 1024, p); //Andar atual
    player.andar = atoi(linha);
    fgets(linha, 1024, p); //Moedas
    player.moedas = atoi(linha);
    fclose(p);
    iniciarJogo();
}

void menuPrincipal() {
    system("cls");
    printf("---------- Dungeon of Death ----------\n");
    printf("1 - Novo Jogo\n");
    printf("2 - Carregar Jogo\n");
    printf("3 - Sair\n\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opc);
    while(opc<1 || opc>3) {
        printf("Opcao invalida, tente novamente: ");
        limparBuffer();
        scanf("%d", &opc);
    }
    if(opc==1) {
        criarPersonagem();
    }
    else {
        if(opc==2) {
            carregarJogo();
        }
    }
}

int main() {
    system("color C");
    menuPrincipal();
    return 0;
}