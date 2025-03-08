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

//Declarando variáveis globais para escolhas no jogo
char next[100];
int choose;

//Declarando um registro/estrutura para as cartas dos jogadores
typedef struct {
    char class[100];
    int hp, atk, def;
}Card;

void mainMenu();

//Inicializando a função que irá randomizar as cartas e especiais do jogador
void randomizeCards(Card *player, int *special) {
    //Declarando variáveis para randomizar números
    int num;

    //For para randomizar as cinco cartas do jogador atual
    for(int i=0; i<5; i++) {
        num = (rand()%10)+1; //Escolhe um número aleatório de 1 a 10
        if(num==1) {
            //Carta do Cavaleiro
            strcpy(player[i].class, "Cavaleiro");
            player[i].hp = 90;
            player[i].atk = 45;
            player[i].def = 50;
        }
        else {
            if(num==2) {
                //Carta do Bandido
                strcpy(player[i].class, "Bandido");
                player[i].hp = 60;
                player[i].atk = 70;
                player[i].def = 30;
            }
            else {
                if(num==3) {
                    //Carta do Arqueiro
                    strcpy(player[i].class, "Arqueiro");
                    player[i].hp = 55;
                    player[i].atk = 65;
                    player[i].def = 35;
                }
                else {
                    if(num==4) {
                        //Carta do Clérigo
                        strcpy(player[i].class, "Clerigo");
                        player[i].hp = 70;
                        player[i].atk = 35;
                        player[i].def = 60;
                    }
                    else {
                        if(num==5) {
                            //Carta do Feiticeiro
                            strcpy(player[i].class, "Feiticeiro");
                            player[i].hp = 50;
                            player[i].atk = 80;
                            player[i].def = 30;
                        }
                        else {
                            if(num==6) {
                                //Carta do Necromante
                                strcpy(player[i].class, "Necromante");
                                player[i].hp = 55;
                                player[i].atk = 60;
                                player[i].def = 45;
                            }
                            else {
                                if(num==7) {
                                    //Carta do Caçador de Demônios
                                    strcpy(player[i].class, "Cacador de Demonios");
                                    player[i].hp = 45;
                                    player[i].atk = 75;
                                    player[i].def = 20;
                                }
                                else {
                                    //Carta do Vampiro
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

    //Repetição para randomizar a quantidade de cada um dos três especiais disponíveis (0 a 3 possíveis)
    for(int i=0; i<3; i++) {
        special[i] = (rand()%4);
    }
}

//Inicializando a função que controlará o ataque durante um turno
void playerAttack(Card *player1, Card *player2, int cardP1, int cardP2, int *aliveP1, int *aliveP2) {
    system("clear"); //Limpando a tela/console do terminal

    //Declarando variáveis de dano
    int damageP1, damageP2;

    //Calculando o dano causado pelos jogadores
    damageP1 = player1[cardP1].atk-player2[cardP2].def;
    damageP2 = player2[cardP2].atk-player1[cardP1].def;

    //Verificando se o dano dos jogadores é menor do que zero
    if(damageP1<0)
        damageP1 = 0; //Zerando o dano do P1
    if(damageP2<0)
        damageP2 = 0; //Zerando o dano do P2

    //Verificando se a defesa da carta atual dos jogadores é maior do que 0
    if(player1[cardP1].def>0)
        player1[cardP1].def -= 15; //Reduzindo a defesa da carta atual em 15
    else
        player1[cardP1].def = 0; //Caso contrário a defesa é quebrada
    if(player2[cardP2].def>0)
        player2[cardP2].def -= 15; //Reduzindo a defesa da carta atual em 15
    else 
        player2[cardP2].def = 0; //Caso contrário a defesa é quebrada

    //Causando o dano relativo a cada jogador
    player1[cardP1].hp -= damageP2;
    player2[cardP2].hp -= damageP1;

    //Imprimindo os resultados da batalha atual
    printf("------------------------------\n");
    printf("Resultados da batalha:\n");
    printf("P1: O %s (P1) atacou %s (P2)\n", player1[cardP1].class, player2[cardP2].class);
    printf("P2: Mas %s (P2) atacou de volta!\n\n", player2[cardP2].class);

    //Verificando se a carta atual dos jogadores morreu
    if(player1[cardP1].hp<=0) {
        printf("P1: O %s morreu!\n", player1[cardP1].class);
        player1[cardP1].hp = 0; //Zerando o HP da carta atual
        *aliveP1 -= 1; //Total de vivos do deck -1
    }
    else
        printf("P1: O %s sobreviveu com %d de HP!\n", player1[cardP1].class, player1[cardP1].hp);
    if(player2[cardP2].hp<=0) {
        printf("P2: %s morreu!\n", player2[cardP2].class);
        player2[cardP2].hp = 0; //Zerando o HP da carta atual
        *aliveP2 -= 1; //Total de vivos do deck -1
    }
    else
        printf("P2: O %s sobreviveu com %d de HP\n", player2[cardP2].class, player2[cardP2].hp);

    printf("------------------------------\n\n");
    printf("Digite qualquer tecla para continuar: ");
    scanf("%s", next);
}

//Inicializando a função que irá mostrar as cartas contidas no deck do jogador atual e suas informações (Classe, HP, ATK e DEF)
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

//Inicializando a função que controlará o uso de especiais durante a partida
void useSpecial(int *special, Card *player, Card *enemy, int *playerTurn) {
    system("clear"); //Limpando a tela/console do terminal

    //Imprimindo o menu de opções para serem escolhidas
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

    //Verificando qual habilidade foi escolhida para ser usada
    if(choose==1) {
        //Ressurgir dos Mortos

        system("clear"); //Limpando a tela/console do terminal

        //Declarando a variável do contador de cartas para reviver
        int j = 0;

        printf("----- Ressurgir dos mortos -----\n");
        printf("----- Cartas mortas -----\n\n");

        //Inicializando a repetição para verificar se o jogador possui cartas para reviver
        for(int i=0; i<5; i++) {
            if(player[i].hp<=0) {
                printf("Carta %d\n", i+1);
                printf("Classe: %s\n", player[i].class);
                printf("HP: %d\nATK: %d\nDEF: %d\n\n", player[i].hp, player[i].atk, player[i].def);
                j++; //Aumentando em 1 na quantidade de cartas disponíveis para reviver
            }
        }

        //Verificando se o jogador possui cartas para reviver
        if(j==0) {
            //Não possui, uma vez que o contador permaneceu em 0

            printf("Voce nao possui cartas para reviver!\n\n");
            printf("Digite qualquer tecla para continuar: ");
            scanf("%s", next);
        }
        else {
            //Possui, uma vez que o contador foi incrementado

            //Lendo a carta desejada para reviver
            printf("Selecione uma carta para reviver: ");
            scanf("%d", &choose);
            while((choose<1 || choose>5) || player[choose-1].hp>0) {
                printf("Essa carta nao esta morta ou e invalida! Tente novamente: ");
                scanf("%d", &choose);
            }

            //Verificando qual a classe da carta escolhida para voltar com metade do seu HP real
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

            special[0]--; //Reduzindo em 1 no número do especial Ressurgir dos Mortos
            printf("Digite qualquer tecla para continuar: ");
            scanf("%s", next);

            //Alterando o jogador do turno para a próxima rodada
            if(*playerTurn==1)
                *playerTurn = 2;
            else
                *playerTurn = 1;
        }
    }
    else if(choose==2) {
        //Benção Divina
        
        system("clear"); //Limpando a tela/console do terminal

        printf("----- Bencao Divina -----\n");
        printf("Todas suas cartas receberam +15 de HP!\n\n");

        viewCardInfo(player); //Mostrando as cartas atuais do jogador, juntamente a seus atributos

        special[1]--; //Reduzindo em 1 no número do especial Benção Divina

        printf("Digite qualquer tecla para continuar: ");
        scanf("%s", next);

        //Alterando o jogador do turno para a próxima rodada
        if(*playerTurn==1)
            *playerTurn = 2;
        else
            *playerTurn = 1;
    }
    else if(choose==3){
        //Maldição

        system("clear"); //Limpando a tela/console do terminal

        printf("----- Maldicao -----\n");
        printf("Cartas do oponente:\n\n");

        //Repetição para imprimir as cartas do oponente vivas para o jogador atual escolher uma para amaldiçoar
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

        //Amaldiçoando a carta do oponente escolhida
        enemy[choose-1].hp /= 2; //HP reduzido pela metade
        enemy[choose-1].def = 0; //Defesa quebrada

        printf("%s foi amaldicoado! Seu HP foi reduzido pela metade e sua DEF quebrada!\n\n", enemy[choose-1].class);

        special[2]--; //Reduzindo em 1 no número do especial Maldição

        printf("Digite qualquer tecla para continuar: ");
        scanf("%s", next);

        //Alterando o jogador do turno para a próxima rodada
        if(*playerTurn==1)
            *playerTurn = 2;
        else
            *playerTurn = 1;
    }
    system("clear"); //Limpando a tela/console do terminal
}

//Incializando a função que dará início ao jogo
void gameStart(){
    //Declarando variáveis para o jogo
    int matchesNumber, turn; //Número de partidas e turno atual
    int selectedCardP1 = 0, selectedCardP2 = 0; //Cartas selecionadas de P1 e P2
    int cardsAliveP1, cardsAliveP2; //Quantidade de Cartas Vivas de P1 e P2
    int specialP1[3], specialP2[3]; //Quantidade de Especiais de P1 e P2
    int firstTurnDoneP1, firstTurnDoneP2; //Controle do Primeiro Turno de Cada Partida
    int battleCounter; //Contador de Batalhas
    Card cardsP1[5], cardsP2[5]; //Deck de 5 Cartas de P1 e P2

    system("clear"); //Limpando a tela/console do terminal

    //Lendo o número de partidas a serem jogadas
    printf("----- Iniciar partida -----\n");
    printf("Insira o numero de partidas: ");
    scanf("%d", &matchesNumber);
    while(matchesNumber<=0) {
        printf("Numero de partidas invalido! Tente novamente: ");
        scanf("%d", &matchesNumber);
    }

    //Inicializando a partida atual
    for(int i=1; i<=matchesNumber; i++) {
        system("clear"); //Limpando a tela/console do terminal

        turn = (rand()%2)+1; //Randomizando o jogador que começará jogando

        cardsAliveP1 = cardsAliveP2 = 5; //O Número de Cartas Vivas de P1 e P2 começa em 5 para cada batalha

        firstTurnDoneP1 = firstTurnDoneP2 = 0; //Primeiro Turno de P1 e P2 começam em 0 pois não foi finalizado

        battleCounter = 1; //Contador de Batalhas se inicia em 1, pois se iniciou a primeira batalha

        //Randomizando as cartas de P1 e P2
        randomizeCards(cardsP1, specialP1);
        randomizeCards(cardsP2, specialP2);

        //Repetição para continuar a partida enquanto os dois jogadores possuírem cartas vivas
        while((cardsAliveP1>0) && (cardsAliveP2>0)) {
            do {
                system("clear"); //Limpando a tela/console do terminal
                
                //Imprimindo as cartas do jogador atual
                if(turn==1)
                    viewCardInfo(cardsP1);
                else
                    viewCardInfo(cardsP2);

                //Menu de opções para o turno do jogador atual
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

                //Verificando se o jogador decidiu usar os espciais
                if(choose==2) {
                    if(turn==1)
                        useSpecial(specialP1, cardsP1, cardsP2, &turn);
                    else
                        useSpecial(specialP2, cardsP2, cardsP1, &turn);
                }
                //Caso contrário, o jogador decidiu atacar
                else
                    choose = -1;
            }while(choose!=-1); //Repetição rodará enquanto o jogador não atacou ou não escolheu um especial 

            //Lendo a carta desejada para atacar
            printf("Numero da carta: ");
            scanf("%d", &choose);

            //Verificando qual a carta escolhida pelo jogador atual para atacar e se a mesma é válida (viva ou existente)
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

            system("clear"); //Limpando a tela/console do terminal

            //Determinando qual o jogador do próximo turno e verificando se o primeiro turno foi concluído para prosseguir nas próximas batalhas
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

            //Verificando se ambos jogadores já realizaram seu primeiro turno para dar prosseguimento nas batalhas seguintes
            if(firstTurnDoneP1!=0 && firstTurnDoneP2!=0) {
                playerAttack(cardsP1, cardsP2, selectedCardP1, selectedCardP2, &cardsAliveP1, &cardsAliveP2); //Chamando a função para atacar

                printf("\nBatalha %d finalizada!\n", battleCounter);

                firstTurnDoneP1 = firstTurnDoneP2 = 0; //Controle de turno volta para 0

                battleCounter++; //Número de batalhas incrementado em 1
            }
        }

        system("clear"); //Limpando a tela/console do terminal

        //Imprimindo o resultado da partida atual
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

//Inicializando a função que imprimirá as regras do jogo
void viewRules() {
    system("clear");//Limpando a tela/console do terminal

    printf("----- Regras -----\n\n");
    printf("Objetivo principal: matar a maior quantidade de inimigos do oponente, vencendo o jogador com o maior numero de personagens vivos\n\n");
    printf("Turnos: Cada jogador realiza uma determinada acao em seu turno respectivo, como atacar, adicionar efeito ao oponente ou pular sua vez.\n\n");
    printf("O primeiro jogador de cada turno de uma batalha e escolhido aleatoriamente!\n\n");
    printf("A cada batalha finalizada, cada carta escolhida no turno perde 15 de DEF\n\n");

    printf("Digite qualquer tecla para voltar ao menu principal: ");
    scanf("%s", next);
    mainMenu();
}

//Incializando a função que imprimirá as cartas do jogo
void viewCards() {
    system("clear"); //Limpando a tela/console do terminal

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

//Inicializando a função que imprimirá os especiais do jogo
void viewSpecial() {
    system("clear"); //Limpando a tela/console do terminal

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

//Inicializando a função que desenhará o menu principal/inicial jogo
void mainMenu() {
    system("clear"); //Limpando a tela/console do terminal

    printf("----- DSCardGame -----\n");
    printf("1 - Jogar\n");
    printf("2 - Ver Regras\n");
    printf("3 - Ver Cartas\n");
    printf("4 - Ver Habilidades Especiais\n");
    printf("5 - Sair\n\n");

    printf("Selecione uma opcao: ");
    scanf("%d", &choose);
    while(choose<1 || choose>5) {
        printf("Opcao invalida! Tente novamente: ");
        scanf("%d", &choose);
    }

    //Verificando qual foi a escolha da opção do menu inicial do jogo
    if(choose==1)
        gameStart(); //Inicia o jogo
    else if(choose==2)
        viewRules(); //Abre a aba de regras
    else if(choose==3)
        viewCards(); //Abre a aba de cartas
    else if(choose==4)
        viewSpecial(); //Abre a aba de especiais
}

//Inicializando a função principal do programa
int main() {
    srand(time(NULL)); //Randomizando a seed para a geração de números aleatórios do jogo

    system("clear"); //Limpando a tela/console do terminal

    mainMenu(); //Chamando o menu inicial

    system("clear"); //Limpando a tela/console do terminal

    printf("Saindo do jogo...\n");
    return 0;
}