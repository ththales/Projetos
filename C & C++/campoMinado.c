#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    srand(time(NULL));
    char jogar = 'S';
    int vitorias, derrotas;
    vitorias = derrotas = 0;
    do {

        char campo[5][5], campoCopia[5][5];
        int playerPontos = 0;
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                campo[i][j] = campoCopia[i][j] = 'X';
            }
        }
        for(int i=0; i<10; i++) {
            int lin = rand()%5;
            int col = rand()%5;
            campoCopia[lin][col] = 'B';
        }
        int lin, col;
        do{
            system("cls");
            for(int i=0; i<5; i++) {
                for(int j=0; j<5; j++) {
                    printf("%c ", campo[i][j]);
                }
                printf("\n");
            }
            printf("Linha: ");
            scanf("%d", &lin);
            while(lin<1 || lin>5) {
                printf("Linha invalida! Tente novamente...\n");
                scanf("%d", &lin);
            }
            printf("Coluna: ");
            scanf("%d", &col);
            while(col<1 || col>5) {
                printf("Coluna invalida! Tente novamente...\n");
                scanf("%d", &col);
            }
            while(campo[lin-1][col-1]=='C') {
                printf("Voce ja selecionou esse espaco! Tente novamente...\n");
                printf("Linha: ");
                scanf("%d", &lin);
                printf("Coluna: ");
                scanf("%d", &col);
            }
            if(campoCopia[lin-1][col-1]!='B') {
                playerPontos++;
                campo[lin-1][col-1] = 'C';
            }
        } while(playerPontos<5 && campoCopia[lin-1][col-1]!='B');
        if(playerPontos==5) {
            vitorias++;
            printf("Voce ganhou! :)\n");
        }
        else {
            derrotas++;
            printf("Voce perdeu! :(\n");
        }
        printf("Jogar novamente? (S - Sim, N - Nao): ");
        while (getchar() != '\n');
        scanf("%c", &jogar);
    } while(jogar=='S' || jogar=='s');
    printf("%d vitorias\n%d derrotas\n", vitorias, derrotas);
    return 0;
}