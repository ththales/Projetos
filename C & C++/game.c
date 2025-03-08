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
        num = (rand()%3)+1;
        if(num==0) {
            strcpy(player[i].class, "Knight");
            player[i].hp = 90;
            player[i].atk = 30;
            player[i].def = 50;
        }
        else if(num==1) {
            strcpy(player[i].class, "Sorcerer");
            player[i].hp = 45;
            player[i].atk = 80;
            player[i].def = 20;
        }
        else {
            strcpy(player[i].class, "Bandit");
            player[i].hp = 55;
            player[i].atk = 60;
            player[i].def = 40;
        }
    }
}

void playerAttack() {
    printf("Attack test");
}

void viewCardInfo() {
    system("cls");
    printf("----- View Card Info -----\n\n");
    for(int i=0; i<5; i++) {
        printf("Card %d\n", i+1);
        printf("Class: %s\n", )
    }
}

void gameStart() {
    int battleQuantity, turn;
    Card cardsP1[5], cardsP2[5];
    system("cls");
    printf("----- Game start! -----\n");
    printf("Battle quantity: ");
    scanf("%d", &battleQuantity);
    for(int i=0; i<battleQuantity; i++) {
        turn = (rand()%2)+1;
        randomizeCards(cardsP1);
        randomizeCards(cardsP2);
        printf("Attack the enemy\n");
        printf("View my cards\n\n");
        printf("Select a option:");
        scanf("%d", &choose);
        if(choose==1) {
            playerAttack();
        }
        else {
            if(turn==1)
                viewCardInfo(cardsP1);
            else
                viewCardInfo(cardsP2);
        }
    }
}

void gameRules() {
    system("cls");
    printf("----- Game rules! -----");
}

void gameCards() {
    system("cls");
    printf("----- Game cards -----");
}

void mainMenu() {
    printf("Select a option: ");
    scanf("%d", &choose);
    if(choose==1)
        gameStart();
    else if(choose==2)
        gameRules();
    else if(choose==3);
        gameCards();
}



int main() {
    srand(time(NULL));
    mainMenu();
    return 0;
}