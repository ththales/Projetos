/*
    Jogo  de batalha de cartas desenvolvido para AED da disciplina Técnicas de Programação
    Aluno: Thales Alves Araújo
    Professora: Carmen Cecilia Centeno
    Data de início: 29/10/24
    Data de conclusão: 05/11/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

char next[100];
int choose;

typedef struct {
    char class[100];
    int hp, atk, def;
}Card;

void mainMenu();

void randomizeCards(Card *player, int *special) {
    int num;
    for(int i=0; i<5; i++) {
        num = (rand()%10)+1;
        if(num==1) {
            strcpy(player[i].class, "Cavaleiro");
            player[i].hp = 90;
            player[i].atk = 45;
            player[i].def = 50;
        }
        else {
            if(num==2) {
                strcpy(player[i].class, "Bandido");
                player[i].hp = 60;
                player[i].atk = 70;
                player[i].def = 30;
            }
            else {
                if(num==3) {
                    strcpy(player[i].class, "Arqueiro");
                    player[i].hp = 55;
                    player[i].atk = 65;
                    player[i].def = 35;
                }
                else {
                    if(num==4) {
                        strcpy(player[i].class, "Clerigo");
                        player[i].hp = 70;
                        player[i].atk = 35;
                        player[i].def = 60;
                    }
                    else {
                        if(num==5) {
                            strcpy(player[i].class, "Feiticeiro");
                            player[i].hp = 50;
                            player[i].atk = 80;
                            player[i].def = 30;
                        }
                        else {
                            if(num==6) {
                                strcpy(player[i].class, "Necromante");
                                player[i].hp = 55;
                                player[i].atk = 60;
                                player[i].def = 45;
                            }
                            else {
                                if(num==7) {
                                    strcpy(player[i].class, "Cacador de Demonios");
                                    player[i].hp = 45;
                                    player[i].atk = 75;
                                    player[i].def = 20;
                                }
                                else {
                                    strcpy(player[i].class, "Vampiro");
                                    player[i].hp = 80;
                                    player[i].atk = 45;
                                    player[i].def = 55;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<3; i++) {
        special[i] = (rand()%3)+1;
    }
}

void playerAttack(Card *player1, Card *player2, int cardP1, int cardP2, int *aliveP1, int *aliveP2) {
    system("cls");
    int damageP1, damageP2;
    damageP1 = player1[cardP1].atk-player2[cardP2].def;
    damageP2 = player2[cardP2].atk-player1[cardP1].def;
    if(player1[cardP1].def>0)
        player1[cardP1].def -= 15;
    else
        player1[cardP1].def = 0;
    if(player2[cardP2].def>0)
        player2[cardP2].def -= 15;
    else player2[cardP2].def = 0;
    if(damageP1<0)
        damageP1 = 0;
    if(damageP2<0)
        damageP2 = 0;
    player1[cardP1].hp -= damageP2;
    player2[cardP2].hp -= damageP1;
    printf("------------------------------\n");
    printf("Resultados da batalha:\n");
    printf("P1: O %s (P1) atacou %s (P2)\n", player1[cardP1].class, player2[cardP2].class);
    printf("P2: Mas %s (P2) atacou de volta!\n\n", player2[cardP2].class);
    if(player1[cardP1].hp<=0) {
        printf("P1: O %s morreu!\n", player1[cardP1].class);
        player1[cardP1].hp = 0;
        *aliveP1 -= 1;
    }
    else
        printf("P1: O %s sobreviveu com %d de HP!\n", player1[cardP1].class, player1[cardP1].hp);
    if(player2[cardP2].hp<=0) {
        printf("P2: %s morreu!\n", player2[cardP2].class);
        player2[cardP2].hp = 0;
        *aliveP2 -= 1;
    }
    else
        printf("P2: O %s sobreviveu com %d de HP\n", player2[cardP2].class, player2[cardP2].hp);
    printf("------------------------------\n\n");
    printf("Digite qualquer tecla para continuar: ");
    scanf("%s", next);
}

void viewCardInfo(Card *player) {
    printf("----- Suas cartas -----\n\n");
    for(int i=0; i<5; i++) {
        if(player[i].hp>0) {
            printf("Carta %d\n", i+1);
            printf("Classe: %s\n", player[i].class);
            printf("HP: %d\nATK: %d\nDEF: %d\n\n", player[i].hp, player[i].atk, player[i].def);
        }
    }
}

void useSpecial(int *special, Card *player, Card *enemy, int *playerTurn) {
    system("cls");
    printf("----- Habilidades Especiais disponiveis -----\n\n");
    printf("1 - Ressurgir dos mortos: %d\n", special[0]);
    printf("2 - Bencao divina: %d\n", special[1]);
    printf("3 - Maldicao: %d\n\n", special[2]);

    printf("Selecione uma habilidade ou 0 para voltar: ");
    scanf("%d", &choose);
    while((choose<1 || choose>3) || special[choose-1]<=0 ) {
        printf("Habilidade indisponivel! Escolha outra: ");
        scanf("%d", &choose); 
    }
    if(choose==1) {
        system("cls");
        int j = 0;
        printf("----- Ressurgir dos mortos -----\n");
        printf("----- Cartas mortas -----\n\n");
        for(int i=0; i<5; i++) {
            if(player[i].hp==0) {
                printf("Carta %d\n", i+1);
                printf("Classe: %s\n", player[i].class);
                printf("HP: %d\nATK: %d\nDEF: %d\n\n", player[i].hp, player[i].atk, player[i].def);
                j++;
            }
        }
        if(j==0) {
            printf("Voce nao possui cartas para reviver!\n\n");
            printf("Digite qualquer tecla para continuar: ");
            scanf("%s", next);
        }
        else {
            printf("Selecione uma carta para reviver: ");
            scanf("%d", &choose);
            while((choose<1 || choose>5) || player[choose-1].hp>0) {
                printf("Essa carta nao esta morta ou e invalida! Tente novamente: ");
                scanf("%d", &choose);
            }
            if(strcmp(player[choose-1].class, "Cavaleiro")==0) {
                player[choose-1].hp = 90/2;
                player[choose-1].def = 50;
            }
            else if(strcmp(player[choose-1].class, "Bandido")==0) {
                player[choose-1].hp = 60/2;
                player[choose-1].def = 30;
            }
            else if(strcmp(player[choose-1].class, "Arqueiro")==0) {
                player[choose-1].hp = 55/2;
                player[choose-1].def = 35;
            }
            else if(strcmp(player[choose-1].class, "Clerigo")==0) {
                player[choose-1].hp = 70/2;
                player[choose-1].def = 60;
            }
            else if(strcmp(player[choose-1].class, "Feiticeiro")==0) {
                player[choose-1].hp = 50/2;
                player[choose-1].def = 30;
            }
            else if(strcmp(player[choose-1].class, "Necromante")==0) {
                player[choose-1].hp = 55/2;
                player[choose-1].def = 45;
            }
            else if(strcmp(player[choose-1].class, "Cacador de Demonios")==0) {
                player[choose-1].hp = 45/2;
                player[choose-1].def = 20;
            }
            else {
                player[choose-1].hp = 80/2;
                player[choose-1].def = 55;
            }
            printf("Carta %d revivida!\nVida atual do %s: %d\n\n", choose, player[choose-1].class, player[choose-1].hp);
            special[0]--;
            printf("Digite qualquer tecla para continuar: ");
            scanf("%s", next);
            if(*playerTurn==1)
                *playerTurn = 2;
            else
                *playerTurn = 1;
        }
    }
    else if(choose==2) {
        system("cls");
        printf("----- Bencao Divina -----\n");
        printf("Todas suas cartas receberam +15 de HP!\n\n");
        viewCardInfo(player);
        special[1]--;
        printf("Digite qualquer tecla para continuar: ");
        scanf("%s", next);
        if(*playerTurn==1)
            *playerTurn = 2;
        else
            *playerTurn = 1;
    }
    else if(choose==3){
        system("cls");
        printf("----- Maldicao -----\n");
        printf("Cartas do oponente:\n\n");
        for(int i=0; i<5; i++) {
            if(enemy[i].hp>0) {
                printf("Carta %d\n", i+1);
                printf("Classe: %s\n", enemy[i].class);
                printf("HP: %d\nATK: %d\nDEF: %d\n\n", enemy[i].hp, enemy[i].atk, enemy[i].def);
            }
        }
        printf("Selecione uma carta do oponente para amaldicoar: ");
        scanf("%d", &choose);
        while((choose<1 || choose>5) || enemy[choose-1].hp<=0){
            printf("Nao e possivel amaldicoar uma carta morta ou inexistente, tente novamente: ");
            scanf("%d", &choose);
        }
        enemy[choose-1].hp /= 2;
        enemy[choose-1].def = 0;
        printf("%s foi amaldicoado! Seu HP foi reduzido pela metade e sua DEF quebrada!\n\n", enemy[choose-1].class);
        special[2]--;
        printf("Digite qualquer tecla para continuar: ");
        scanf("%s", next);
        if(*playerTurn==1)
            *playerTurn = 2;
        else
            *playerTurn = 1;
    }
    system("cls");
}

void gameStart(){
    int matchesNumber, turn;
    int selectedCardP1 = 0, selectedCardP2 = 0;
    int cardsAliveP1, cardsAliveP2;
    int specialP1[3], specialP2[3];
    int firstTurnDoneP1, firstTurnDoneP2;
    int battleCounter;
    Card cardsP1[5], cardsP2[5];
    system("cls");
    printf("----- Iniciar partida -----\n");
    printf("Insira o numero de partidas: ");
    scanf("%d", &matchesNumber);
    while(matchesNumber<=0) {
        printf("Numero de partidas invalido! Tente novamente: ");
        scanf("%d", &matchesNumber);
    }
    for(int i=1; i<=matchesNumber; i++) {
        system("cls");
        turn = (rand()%2)+1;
        cardsAliveP1 = cardsAliveP2 = 5;
        firstTurnDoneP1 = firstTurnDoneP2 = 0;
        battleCounter = 1;
        randomizeCards(cardsP1, specialP1);
        randomizeCards(cardsP2, specialP2);
        while((cardsAliveP1>0) && (cardsAliveP2>0)) {
            do {
                system("cls");
                if(turn==1)
                    viewCardInfo(cardsP1);
                else
                    viewCardInfo(cardsP2);
                printf("----- Batalha %d -----\n", battleCounter);
                printf("----- Turno do jogador %d! -----\n", turn);
                printf("1 - Atacar oponente\n");
                printf("2 - Ver suas habilidades\n\n");
                printf("Selecione uma opcao: ");
                scanf("%d", &choose);
                while(choose<1 || choose>2) {
                    printf("Opcao invalida! Tente novamente: ");
                    scanf("%d", &choose);
                }
                if(choose==2) {
                    if(turn==1)
                        useSpecial(specialP1, cardsP1, cardsP2, &turn);
                    else
                        useSpecial(specialP2, cardsP2, cardsP1, &turn);
                }
                else
                    choose = -1;
            }while(choose!=-1);
            printf("Numero da carta: ");
            scanf("%d", &choose);
            if(turn==1) {
                while((choose<0 || choose>5) || (cardsP1[choose-1].hp<=0)) {
                    printf("Essa carta esta morta ou invalida! Digite o numero de outra carta: ");
                    scanf("%d", &choose);
                }
            }
            else {
                while((choose<0 || choose>5) || (cardsP2[choose-1].hp<=0)) {
                    printf("Essa carta esta morta ou invalida! Digite o numero de outra carta: ");
                    scanf("%d", &choose);
                }
            }
            system("cls");
            if(turn==1) {
                selectedCardP1 = choose-1;
                firstTurnDoneP1 = 1;
                turn = 2;
            }
            else {
                selectedCardP2 = choose-1;
                firstTurnDoneP2 = 1;
                turn = 1;
            }
            if(firstTurnDoneP1!=0 && firstTurnDoneP2!=0) {
                playerAttack(cardsP1, cardsP2, selectedCardP1, selectedCardP2, &cardsAliveP1, &cardsAliveP2);
                printf("\nBatalha %d finalizada!\n", battleCounter);
                firstTurnDoneP1 = firstTurnDoneP2 = 0;
                battleCounter++;
            }
        }
        system("cls");
        printf("----- Partida %d -----\n", matchesNumber);
        if(cardsAliveP1==0)
            printf("Jogador 2 ganhou a partida!\n\n");
        else if(cardsAliveP2==0)
            printf("Jogador 1 ganhou a partida!\n\n");
        else
            printf("Nenhum jogador ganhou a partida, houve empate!\n\n");
    }
    printf("Digite qualquer tecla para voltar ao menu principal: ");
    scanf("%s", next);
    mainMenu();
}

void viewRules() {
    system("cls");
    printf("----- Regras -----\n\n");
    printf("Objetivo principal: matar a maior quantidade de inimigos do oponente, vencendo o jogador com o maior numero de personagens vivos\n\n");
    printf("Turnos: Cada jogador realiza uma determinada acao em seu turno respectivo, como atacar, adicionar efeito ao oponente ou pular sua vez.\n\n");
    printf("O primeiro jogador de cada turno de uma batalha e escolhido aleatoriamente!\n\n");
    printf("A cada batalha finalizada, cada carta escolhida perde 15 de DEF\n\n");

    printf("Digite qualquer tecla para voltar ao menu principal: ");
    scanf("%s", next);
    mainMenu();
}

void viewCards() {
    system("cls");
    printf("----- Cartas -----\n\n");
    printf("Cavaleiro:\n");
    printf("Descricao: Cavaleiro e um personagem de combate corpo a corpo focado em alta defesa e vida, com ataque moderado\n");
    printf("HP: 90\nATK: 45\nDEF: 50\n\n");

    printf("Bandido:\n");
    printf("Descricao: Agil e sorrateiro, o ladrao possui alto ataque, mas baixa vida e defesa, dependendo de ataques rapidos para evitar ser atingido\n");
    printf("HP: 60\nATK: 70\nDEF: 30\n\n");

    printf("Arqueiro:\n");
    printf("Descricao: Especialista em ataques a distancia, o arqueiro mantem distancia para evitar confrontos diretos. Com ataques ageis e precisos, tem HP e defesa moderados.\n");
    printf("HP: 55\nATK: 65\nDEF: 35\n\n");

    printf("Clerigo:\n");
    printf("Descricao: Classe de suporte com habilidades defensivas moderadas e HP razoavel. Seu ataque e baixo, mas sua resistencia o ajuda a proteger aliados.\n");
    printf("Atributos: 70 Hp, 40 Atk, 60 Def\n\n");
    printf("HP: 70\nATK: 40\nDEF: 60\n\n");

    printf("Feiticeiro:\n");
    printf("Descricao: Com grande poder ofensivo, o feiticeiro compensa seu baixo HP e DEF com ataques de longo alcance poderosos.\n");
    printf("Atributos: 50 Hp, Atk 80, Def 30\n\n");
    printf("HP: 50\nATK: 80\nDEF: 30\n\n");

    printf("Necromante:\n");
    printf("Descricao: Um manipulador das trevas, o necromante equilibra ataque e defesa moderados, com baixa vida, sendo eficaz em conjuracoes e ataques estrategicos.\n");
    printf("HP: 55\nATK: 60\nDEF: 45\n\n");

    printf("Cacador de demonios:\n");
    printf("Descricao: Especialista em enfrentar forcas das trevas, com alto ataque e habilidades especificas contra criaturas ocultas. Possui resistencia media, mas seu dano e letal.\n");
    printf("HP: 45\nATK: 75\nDEF: 20\n\n");

    printf("Vampiro:\n");
    printf("Descricao: Um inimigo sedento por sangue e destruicao, possui ataque baixo mas HP relativamente alto.\n");
    printf("HP: 80\nATK: 45\nDEF: 55\n\n");

    printf("Digite qualquer tecla para voltar ao menu principal: ");
    scanf("%s", next);
    mainMenu();
}

void viewSpecial() {
    system("cls");
    printf("----- Habilidades Especiais -----\n\n");

    printf("Ressurgir dos mortos:\n");
    printf("Permite reviver uma carta do jogador que ja morreu, entretanto com metade de HP\n\n");
    
    printf("Bencao divina:\n");
    printf("Aumenta em +15 pontos de HP de todas as cartas do jogador\n\n");

    printf("Maldicao:\n");
    printf("Permite o jogador escolher uma carta do oponente e quebrar sua defesa\n\n");

    printf("Obs: E possivel ter no maximo 3 usos de cada habilidade abaixo, sendo o numero randomizado a cada partida para os jogadores\n\n");
    
    printf("Digite qualquer tecla para voltar ao menu principal: ");

    scanf("%s", next);
    mainMenu();
}

void mainMenu() {
    system("cls");
    printf("----- DSCardGame -----\n");
    printf("1 - Jogar\n");
    printf("2 - Ver Regras\n");
    printf("3 - Ver Cartas\n");
    printf("4 - Ver Habilidades Especiais\n");
    printf("5 - Sair\n");
    scanf("%d", &choose);
    while(choose<1 || choose>5) {
        printf("Opcao invalida! Tente novamente: ");
        scanf("%d", &choose);
    }
    if(choose==1)
        gameStart();
    else if(choose==2)
        viewRules();
    else if(choose==3)
        viewCards();
    else if(choose==4)
        viewSpecial();
}

int main() {
    srand(time(NULL));
    system("cls");
    mainMenu();
    system("cls");
    printf("Saindo do jogo...\n");
    return 0;
}