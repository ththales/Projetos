#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct carta {
    char *face;
    char *naipe;
};
typedef struct carta Carta;
void completaBaralho(Carta *wBaralho, char *wFace[], char *wNaipe[]) {
    int i, j, k = 0;
    for(i=0; i<4; i++) {
        for(j=0; j<13; j++) {
            wBaralho[k].face = wFace[j];
            wBaralho[k].naipe = wNaipe[i];
            k++;
        }
    }
}
void embaralhar(Carta *wBaralho) {
    Carta temp;
    for(int i=0; i<52; i++) {
        int j = rand()%52;
        temp.face = wBaralho[i].face;
        wBaralho[i].face = wBaralho[j].face;
        wBaralho[j].face = temp.face;
        temp.naipe = wBaralho[i].naipe;
        wBaralho[i].naipe = wBaralho[j].naipe;
        wBaralho[j].naipe = temp.naipe;
    }
}
 
void distribuirCarta(Carta *wBaralho, char *wFace[], int *soma, char *cartaAtual, int *num) {
    int i;
    strcpy(cartaAtual, wBaralho[*num].face);
    strcat(cartaAtual, " de ");
    strcat(cartaAtual, wBaralho[*num].naipe);
    strcat(cartaAtual, "\n");
    printf("%s", cartaAtual);
    *num += 1;
    for(i=0; i<12 && strcmp(wBaralho[*num].face, wFace[i])!=0; i++);
    if(i<10)
        *soma += i+1;
    else
        *soma += 10;
}

int main() {
    Carta baralho[52];
    char *face[13] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    char *naipe[4] = {"Copas", "Ouros", "Paus", "Espadas"};
    char carta[50];
    int numCarta = 0;
    int sJogador = 0, sBanca = 0, escolha;
    srand(time(NULL));
    completaBaralho(baralho, face, naipe);
    embaralhar(baralho);

    do {
        printf("Carta da Banca: ");
        distribuirCarta(baralho, face, &sBanca, carta, &numCarta);
    }while(sBanca<=21);

    printf("(Jogador) Escolher uma carta? (1 - Sim, 0 - Nao): ");
    scanf("%d", &escolha);
    while(escolha==1) {
        distribuirCarta(baralho, face, &sJogador, carta, &numCarta);
        printf("(Jogador) Escolher outra carta? (1 - Sim, 0 - Nao): ");
        if(sJogador>21) {
            escolha = 0;
            printf("Limite estourado!\nVocê perdeu!");
            return 0;
        }
        else
            scanf("%d", &escolha);
    }

    if((sJogador<=21 && sJogador>sBanca) || sBanca>21)
        printf("Jogador ganhou\n");
    else
        printf("Banca ganhou\n");
    return 0;
}