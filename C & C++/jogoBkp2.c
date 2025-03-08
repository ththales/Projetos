/*
    Jogo  de batalha de cartas desenvolvido para AED da disciplina Técnicas de Programação
    Aluno: Thales Alves Araújo
    Professora: Carmen Cecilia Centeno
    Data de início: 29/10/24
    Data de conclusão:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int choose;

typedef struct {
    char class[100];
    int hp, atk, def;
}Card;

void randomizeCards(Card *player) {
    int num;
    for(int i=0; i<5; i++) {
        num = (rand()%10)+1;
        if(num==1) {
            strcpy(player[i].class, "Cavaleiro");
            player[i].hp = 80;
            player[i].atk = 45;
            player[i].def = 70;
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
                                    strcpy(player[i].class, "Cacador de demonios");
                                    player[i].hp = 45;
                                    player[i].atk = 75;
                                    player[i].def = 20;
                                }
                                else {
                                    strcpy(player[i].class, "Druida");
                                    player[i].hp = 65;
                                    player[i].atk = 40;
                                    player[i].def = 55;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int mainMenu() {

    system("cls");
    printf("----- DSCardGame -----\n");
    printf("1 - Jogar\n");
    printf("2 - Ver regras\n");
    printf("3 - Ver cartas\n");
    printf("4 - Sair\n");
    scanf("%d", &choose);
    if(choose==1)
        gameStart();
    else if(choose==2)
        viewRules();
    else if(choose==3)
        viewCards();
    else 
        return 0;
}

void gameStart()
{
    int matchesNumber, turn;
    int selectedCardP1 = 0, selectedCardP2 = 0;
    int cardsAliveP1, cardsAliveP2;
    int firstTurnDoneP1, firstTurnDoneP2;
    int battleCounter;
    Card cardsP1[5], cardsP2[5];
    system("cls");
    printf("----- Iniciar partida -----\n");
    printf("Insira o numero de batalhas: ");
    scanf("%d", &matchesNumber);
    for(int i=1; i<=matchesNumber; i++) {
        system("cls");
        turn = (rand()%2)+1;
        cardsAliveP1 = cardsAliveP2 = 5;
        firstTurnDoneP1 = firstTurnDoneP2 = 0;
        battleCounter = 1;
        randomizeCards(cardsP1);
        randomizeCards(cardsP2);
        while((cardsAliveP1>0) && (cardsAliveP2>0)) {
            printf("----- Batalha %d -----\n", battleCounter);
            do {
                printf("----- Turno do jogador %d! -----\n", turn);
                printf("1 - Atacar oponente\n");
                printf("2 - Ver suas cartas\n\n");
                printf("Selecione uma opcao: ");
                scanf("%d", &choose);
                if(choose==2) {
                    if(turn==1)
                        viewCardInfo(cardsP1);
                    else
                        viewCardInfo(cardsP2);
                }
                else
                    choose = -1;
            }while(choose!=-1);
            printf("Numero da carta: ");
            scanf("%d", &choose);
            while(cardsP1[choose-1].hp<=0) {
                printf("Essa carta esta morta! Digite o numero de outra carta: ");
                scanf("%d", &choose);
            }
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
                playerAttack(cardsP1, cardsP2, selectedCardP1, selectedCardP2, &cardsAliveP1, &cardsAliveP2, &turn);
                printf("\n\nBatalha %d finalizada!\n", battleCounter);
                firstTurnDoneP1 = firstTurnDoneP2 = 0;
                battleCounter++;
            }
        }
    }
}

void playerAttack(Card *player1, Card *player2, int cardP1, int cardP2, int *aliveP1, int *aliveP2, int *playerTurn) {
    system("cls");
    int damageP1, damageP2;
    damageP1 = player1[cardP1].atk-player2[cardP2].def;
    damageP2 = player2[cardP2].atk-player1[cardP1].def;
    if(damageP1<0)
        damageP1 = 0;
    if(damageP2<0)
        damageP2 = 0;
    player1[cardP1].hp -= damageP2;
    player2[cardP2].hp -= damageP1;
    printf("Resultados da batalha:\n");
    printf("%s atacou %s\n", player1[cardP1].class, player2[cardP2].class);
    printf("Mas %s atacou de volta!\n\n", player2[cardP2].class);
    if(player1[cardP1].hp<=0) {
        printf("%s morreu!\n", player1[cardP1].class);
        player1[cardP1].hp = 0;
        cardP1++;
        *aliveP1 -= 1;
    }
    else
        printf("%s sobreviveu com %d de HP!\n", player1[cardP1].class, player1[cardP1].hp);
    if(player2[cardP2].hp<=0) {
        printf("%s morreu!\n", player2[cardP2].class);
        player2[cardP2].hp = 0;
        cardP2++;
        *aliveP2 -= 1;
    }
    else
        printf("%s sobreviveu com %d de HP\n", player2[cardP2].class, player2[cardP2].hp);
    if(*playerTurn==1)
        *playerTurn = 2;
    else
        *playerTurn = 1;
}

void viewCardInfo(Card *player) {
    system("cls");
    printf("----- Suas cartas -----\n\n");
    for(int i=0; i<5; i++) {
        printf("Carta %d\n", i+1);
        printf("Classe: %s\n", player[i].class);
        printf("HP: %d\nATK: %d\nDEF: %d\n\n", player[i].hp, player[i].atk, player[i].def);
    }
    printf("Digite qualquer numero para voltar: ");
    scanf("%d", &choose);
}

void viewRules() {
    system("cls");
    printf("----- Regras -----\n\n");
    printf("Objetivo principal: matar a maior quantidade de inimigos do oponente, vencendo o jogador com o maior numero de personagens vivos\n");
    printf("Turnos: Cada jogador realiza uma determinada acao em seu turno respectivo, como atacar, adicionar efeito ao oponente ou pular sua vez.\n");
    printf("O jogador do primeiro turno de uma batalha é escolhido aleatoriamente\n");
    printf("- Obs: pular a vez mata uma das cartas do seu deck, portanto use somente se tiver certeza do que esta fazendo\n");
    printf("Cartas: Cada carta possui uma habilidade especial, que podera afetar diretamente o oponente\n\n");
    printf("Digite qualquer tecla para voltar ao menu principal: ");
    scanf("%d", &choose);
    //Limpando a tela do console
    mainMenu();
}

void viewCards() {
    system("cls");
    printf("----- Cartas -----\n\n");
    printf("Cavaleiro:\n");
    printf("Descricao: Cavaleiro e um personagem de combate corpo a corpo focado em alta defesa e vida, com ataque moderado\n");
    printf("HP: 80\nATK: 45\nDEF: 70\n\n");

    printf("Bandido:\n");
    printf("Descricao: Agil e sorrateiro, o ladrao possui alto ataque, mas baixa vida e defesa, dependendo de ataques rapidos para evitar ser atingido\n");
    printf("HP: 60\nATK: 70\nDEF: 30\n\n");

    printf("Arqueiro:\n");
    printf("Descricao: Especialista em ataques a distância, o arqueiro mantém distancia para evitar confrontos diretos. Com ataques ageis e precisos, tem HP e defesa moderados.\n");
    printf("HP: 55\nATK: 65\nDEF: 35\n\n");

    printf("Clerigo:\n");
    printf("Descricao: Classe de suporte com habilidades defensivas moderadas e HP razoável. Seu ataque e baixo, mas sua resistencia o ajuda a proteger aliados.\n");
    printf("Atributos: 70 Hp, 40 Atk, 60 Def\n\n");
    printf("HP: 70\nATK: 40\nDEF: 60\n\n");

    printf("Feiticeiro:\n");
    printf("Descricao: Com grande poder ofensivo, o feiticeiro compensa seu baixo HP e DEF com ataques de longo alcance poderosos.\n");
    printf("Atributos: 50 Hp, Atk 80, Def 30\n\n");
    printf("HP: 50\nATK: 80\nDEF: 30\n\n");

    printf("Necromante:\n");
    printf("Descricao: Um manipulador das trevas, o necromante equilibra ataque e defesa moderados, com baixa vida, sendo eficaz em conjurações e ataques estratégicos.\n");
    printf("HP: 55\nATK: 60\nDEF: 45\n\n");

    printf("Cacador de demonios:\n");
    printf("Descricao: Especialista em enfrentar forças das trevas, com alto ataque e habilidades específicas contra criaturas ocultas. Possui resistência média, mas seu dano e letal");
    printf("HP: 55\nATK: 60\nDEF: 45\n\n");

    printf("Druida:\n");
    printf("Descricao: Classe magica de suporte, o druida pode curar aliados e invocar forças da natureza, equilibrando defesa e HP para resistir mais em combate.");
    printf("HP: 65\nATK: 45\nDEF: 55\n\n");

    printf("Digite qualquer tecla para voltar ao menu principal: ");
    scanf("%d", &choose);
    mainMenu();
}


int main() {
    srand(time(NULL));
    mainMenu();
    return 0;
}