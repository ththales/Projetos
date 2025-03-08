#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
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
    char nome[100];
    int dano;
    char raridade[100];
} Arma;

Arma armas[] = {
    {"Espada Longa", 200, "(Comum)"}, //0
    {"Adaga Afiada", 250, "(Comum)"}, //1
    {"Cajado Simples", 350, "(Comum)"}, //2
    {"Machado leve", 300, "(Comum)"}, //3...
    {"Lanca Fraca", 150, "(Comum)"},
};

typedef struct {
    char nome[50];
    int totalMelhoria;
}ItemExtra;

ItemExtra itens[] = {
    {"Anel da Vitalidade", 100}, //0
    {"Anel do Ataque", 100}, //1
    {"Anel da Protecao", 100}, //2
    {"Nenhum", 0}, //3...
};

typedef struct {
    char nome[1024], classe[100];
    int level, hp, def, armaAtual, itemExtra, moedas, andar;
}Personagem;

typedef struct {
    char nome[100];
    int level, hp, atk, def, droparArma;
}Inimigo;

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
        Sleep(delay);
        texto++;
    }
}

void informacoesJogador() {
    printf("\n---------- %s ----------\n", player.nome);
    printf("Classe: %s\n", player.classe);
    printf("Level: %d\n", player.level);
    printf("HP: %d\n", player.hp);
    printf("ATK: %d\n", armas[player.armaAtual].dano);
    printf("DEF: %d\n", player.def);
    printf("Arma atual: %s %s\n", armas[player.armaAtual].nome, armas[player.armaAtual].raridade);
    printf("Item extra: %s\n", itens[player.itemExtra].nome);
    printf("Moedas: %d\n\n", player.moedas);
}

void equiparItem() {

}

void combateInimigos() {
    int numInimigos, inimigoLevelAcima, turno = 1, dano, vivos, texto, timer;
    numInimigos = (rand()%5)+1;
    vivos = numInimigos;
    texto = rand()%10;
    Inimigo inimigos[numInimigos];
    printf("\nCOMBATE!\n");
    for(int i=0; i<numInimigos; i++) {
        inimigoLevelAcima = rand()%3;
        if(inimigoLevelAcima==0 && player.andar>1) {
            inimigos[i].level = player.andar-1;
        }
        else {
            if(inimigoLevelAcima==1) {
                inimigos[i].level = player.andar;
            }
            else {
                inimigos[i].level = player.andar+1;
            }
        }
        inimigos[i].hp = 100 + player.andar*5 + rand()%(player.andar*10);
        inimigos[i].atk = 75 + player.andar*3 + rand()%(player.andar*7);
        inimigos[i].def = 50 + player.andar*2 + rand()%(player.andar*5);
    }
    while(player.hp>0 && vivos>0) {
        system("cls");
        printf("---------- Dungeon of Death ----------\n");
        printf("---------- Andar %d ----------\n\n", player.andar);
        switch(texto) {
            case 0:
                printf("Voce se encontra em uma sala escura feita de ossos cercada de esqueletos sedentos por sangue... Derrote-os!\n");
                break;

            case 1:
                printf("A sala e pequena e claustrofobica, com teto baixo e as paredes feitas de madeira podre. O chao range sob seus pes enquanto voce percebe um odor forte de mofo e a sensacao de que algo esta prestes a surgir das sombras... Lute!\n");
                break;

            case 2:
                printf("Ao adentrar uma sala, voce e imediatamente cercado por uma nevoa espessa. As paredes parecem se mover, ondulando a medida que voce tenta se orientar. Vozes sussurram em seu ouvido, mas você nao consegue identificar de onde vem... Batalhe!\n");
                break;

            case 3:
                printf("Voce entra em uma sala abafada, onde a luz parece ser engolida pela escuridao. No canto, formas vagas se movem, e os olhos brilhantes de criaturas sombrias se fixam em voce. Seus passos sao acompanhados por sussurros distantes, como se inimigos invisiveis estivessem esperando o momento certo para atacar... Enfrente-os!\n");
                break;

            case 4:
                printf("O som do vento uivante ecoa pelas paredes de pedra, enquanto vozes fantasmagoricas chamam seu nome. Criaturas de sombras se revelam, mas ao olhar para elas, desaparecem rapidamente... Lute!\n");
                break;

            case 5:
                printf("O ambiente e tomado por uma escuridao densa, mas algo estranho reluz no centro da sala. Formas sombrias se movem lentamente, como se esperassem sua chegada para atacar... Batalhe!\n");
                break;

            case 6: 
                printf("Voce se encontra em uma sala ampla, com o chao coberto por uma camada espessa de poeira. Os olhos de criaturas sombrias aparecem brevemente na escuridao, e seus suspiros podem ser ouvidos ao longe... Enfrente-os!\n");
                break;

            case 7:
                printf("Ao atravessar a porta, voce sente um frio cortante e ouve passos pesados se aproximando. A luz de sua tocha mal ilumina o caminho, deixando a sensacao de estar sendo seguido... Lute!\n");
                break;

            case 8:
                printf("As paredes da sala sao feitas de pedras antigas e desgastadas, cobertas de simbolos que brilham fracamente. Sussurros indecifravels preenchem o espaco, tornando a atmosfera ainda mais aterrorizante... Batalhe!\n");
                break;

            default:
                printf("Uma nevoa densa cobre o chao, e vultos escuros passam rapidamente ao seu redor, sempre fora de seu campo de visao, criando um clima de suspense... Enfrente-os!\n");
                break;
        }
        printf("\n");
        for(int i=0; i<numInimigos; i++) {
            if(inimigos[i].hp>0) {
                printf("Inimigo %d:\n", i+1);
                printf("  Level: %d\n", inimigos[i].level);
                printf("  HP: %d\n", inimigos[i].hp);
                printf("  ATK: %d\n", inimigos[i].atk);
                printf("  DEF: %d\n\n", inimigos[i].def);
            }
        }
        informacoesJogador();
        if(turno==1) {
            printf("Selecione um inimigo para atacar: ");
            scanf("%d", &opc);
            while (opc<1 || opc>numInimigos || inimigos[opc-1].hp<=0) {
                printf("Selecione um inimigo valido! Tente novamente: ");
                scanf("%d", &opc);
            }
            dano = armas[player.armaAtual].dano-inimigos[opc-1].def;
            if(dano<0) {
                dano = 0;
            }
            inimigos[opc-1].hp -= dano;
            if(inimigos[opc-1].hp<=0) {
                inimigos[opc-1].hp = 0;
                vivos--;
            }
            printf("Voce atacou o inimigo %d, deixando-o com %d de HP!\n", opc, inimigos[opc-1].hp);
            turno = 0;
            Sleep(1000);
        }
        else {
            for(int i=0; i<numInimigos; i++) {
                if(inimigos[i].hp>0) {
                    dano = inimigos[i].atk;
                    if(dano<0) {
                        dano = 0;
                    }
                    if(player.def>=dano) {
                        player.def -= dano;
                    }
                    else {
                        dano -= player.def;
                        player.def = 0;
                        player.hp -= dano;
                    }
                    printf("Inimigo %d te atacou! Voce perdeu %d de HP!\n", i+1, dano);
                    timer = rand()%501;
                    timer += rand()%501;
                    Sleep(timer);
                }
            }
            turno = 1;
            Sleep(2500);
        }
    }
    if(player.hp<0) {
        player.hp = 0;
    }
    system("cls");
    printf("---------- FIM DE COMBATE! ----------\n");
    informacoesJogador();
    if(player.hp>0) {
        printf("Voce sobreviveu com %d de HP!\n", player.hp);
    }
    else {
        printf("Voce morreu! Fim de jogo...\n");
    }
}

void bauItens() {
    printf("Bau!\n");
}

void vendedorItens() {
    printf("Vendedor!\n");
}

void andarAtual(int eventoAtual) {
    int texto;
    if(eventoAtual<=14) {
        //Inimigos
        texto = rand()%10;
        switch(texto) {
            case 0:
                printf("Voce se encontra em uma sala escura feita de ossos cercada de esqueletos sedentos por sangue... Derrote-os!\n");
                break;

            case 1:
                printf("A sala e pequena e claustrofobica, com teto baixo e as paredes feitas de madeira podre. O chao range sob seus pes enquanto voce percebe um odor forte de mofo e a sensacao de que algo esta prestes a surgir das sombras... Lute!\n");
                break;

            case 2:
                printf("Ao adentrar uma sala, voce e imediatamente cercado por uma nevoa espessa. As paredes parecem se mover, ondulando a medida que voce tenta se orientar. Vozes sussurram em seu ouvido, mas você nao consegue identificar de onde vem... Batalhe!\n");
                break;

            case 3:
                printf("Voce entra em uma sala abafada, onde a luz parece ser engolida pela escuridao. No canto, formas vagas se movem, e os olhos brilhantes de criaturas sombrias se fixam em voce. Seus passos sao acompanhados por sussurros distantes, como se inimigos invisiveis estivessem esperando o momento certo para atacar... Enfrente-os!\n");
                break;

            case 4:
                printf("O som do vento uivante ecoa pelas paredes de pedra, enquanto vozes fantasmagoricas chamam seu nome. Criaturas de sombras se revelam, mas ao olhar para elas, desaparecem rapidamente... Lute!\n");
                break;

            case 5:
                printf("O ambiente e tomado por uma escuridao densa, mas algo estranho reluz no centro da sala. Formas sombrias se movem lentamente, como se esperassem sua chegada para atacar... Batalhe!\n");
                break;

            case 6: 
                printf("Voce se encontra em uma sala ampla, com o chao coberto por uma camada espessa de poeira. Os olhos de criaturas sombrias aparecem brevemente na escuridao, e seus suspiros podem ser ouvidos ao longe... Enfrente-os!\n");
                break;

            case 7:
                printf("Ao atravessar a porta, voce sente um frio cortante e ouve passos pesados se aproximando. A luz de sua tocha mal ilumina o caminho, deixando a sensacao de estar sendo seguido... Lute!\n");
                break;

            case 8:
                printf("As paredes da sala sao feitas de pedras antigas e desgastadas, cobertas de simbolos que brilham fracamente. Sussurros indecifravels preenchem o espaco, tornando a atmosfera ainda mais aterrorizante... Batalhe!\n");
                break;

            default:
                printf("Uma nevoa densa cobre o chao, e vultos escuros passam rapidamente ao seu redor, sempre fora de seu campo de visao, criando um clima de suspense... Enfrente-os!\n");
                break;
        }
        combateInimigos();
    }
    else {
        if(eventoAtual>14 && eventoAtual<=17) {
            //Baú
            texto = rand()%5;
            switch(texto) {
                case 0:
                    printf("Enquanto explora a masmorra sombria, voce tropeca em uma pequena elevacao no solo. Sob a luz tremula de sua tocha, um bau empoeirado revela-se entre as rochas. Gravuras antigas decoram sua superficie, sugerindo que nao era aberto ha seculos. Ao girar a chave enferrujada, o bau emite um som estridente antes de se abrir lentamente, revelando um brilho dourado que preenche o ambiente.\n");
                    break;
                
                case 1:
                    printf("Caminhando pela dungeon, voce ouve um som estranho entre paredes úmidas. Curioso, ele afasta as teias de aranha ali presentes e encontra um bau coberto por poeira. A fechadura parece intacta, mas emite um leve brilho azul, como se esperasse alguem digno de seu conteudo. Com as maos firmes, voce forca a abertura e e recompensado com uma pilha de itens reluzentes e um mapa misterioso.\n");
                    break;
                
                case 2:
                    printf("Nos corredores silenciosos do lugar misterioso, voce encontra uma sala escondida atras de uma tapecaria rasgada. No centro, iluminado por um feixe de luz que atravessa o teto rachado, repousa um bau ornamentado. As dobradicas enferrujadas resistem ao toque, mas com um ultimo esforco, o bau se abre, revelando uma relíquia brilhante que pulsa com energia magica.\n");
                    break;

                case 3:
                    printf("Apos caminhar um pouco, voce encontra um bau ao lado do altar. Entalhes misticos adornam sua superficie, e um brilho pulsante escapa pelas frestas. Ao abrir o bau, um vento leve percorre o ambiente, como se os espiritos do lugar aprovassem sua coragem. Dentro, uma armadura reluzente repousa, acompanhada de um pergaminho que promete revelar segredos antigos.\n");
                    break;

                default:
                    printf("No fundo da sala havia um buraco, onde apenas ecos e sombras reinam, voce avista algo brilhando a distancia. Aproximando-se com cautela, ele encontra um bau finamente trabalhado, adornado com pedras preciosas. Uma aura fria emana do objeto, como se guardasse um poder imenso. Ao abrir o bau, uma explosao de luz revela um artefato lendario, prometendo poder alem da imaginacao.\n");
                    break;
            }
            bauItens();
        }
        else {
            // Vendedor de itens
            texto = rand()%5;
            switch(texto) {
                case 0:
                    printf("Ao avancar pelos corredores umidos da dungeon, iluminados apenas por sua tocha tremula, voce percebe uma figura encapuzada encostada em uma parede de pedra. O som metalico de moedas ecoa pelo ambiente enquanto o estranho arruma seu estoque. Ele ergue o olhar, revelando um sorriso enigmatico. \"Precisa de algo especial para continuar vivo? Hehehe...\", ele diz, mostrando uma variedade de itens raros.\n");
                    break;
                
                case 1:
                    printf("Enquanto explora um salao amplo da dungeon, repleto de estatuas antigas, voce nota uma pequena tenda montada em um canto escuro. O vendedor, com roupas gastas e um olhar astuto, organiza frascos, pergaminhos e armas em uma bancada improvisada. \"Venha, aventureiro! Aqui voce encontrara o que precisa para sobreviver as proximas provacoes.\"\n");
                    break;
                
                case 2:
                    printf("Apos abrir uma pesada porta de madeira, voce e surpreendido por uma pequena sala iluminada por velas. No centro, um mercador de aparencia excentrica organiza meticulosamente suas mercadorias. \"Ora, ora, o que temos aqui?\", ele diz, com uma voz rouca. \"Veio buscar suprimentos ou algo mais... exotico?\"\n");
                    break;
                
                case 3:
                    printf("Ao virar uma esquina na dungeon, voce avista uma fraca luz piscando no fim do corredor. Seguindo o brilho, voce encontra um homem com um manto surrado, sentado ao lado de uma fogueira improvisada. Ao redor dele, caixas e sacolas estao repletas de itens. \"Bem-vindo, viajante! Sorte a sua me encontrar por aqui.\"\n");
                    break;

                default:
                    printf("Em uma sala cheia de tapecarias empoeiradas, voce se depara com um velho mercador sentado em uma cadeira ornamentada. Ele acaricia uma esfera de cristal, enquanto uma vitrine proxima exibe armas reluzentes e pocoes brilhantes. \"Ah, o destino trouxe voce ate mim! Meu estoque e tao vasto quanto os perigos que enfrentara.\"\n");
                    break;
            }
            vendedorItens();
        }
    }
}

void salvarJogo() {
    p = fopen("save.dat", "w");
    if(p==NULL) {
        printf("Falha ao abrir o save.\n");
        exit(1);
    }
    fprintf(p, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d", player.nome, player.classe, player.level, player.hp, player.def, player.armaAtual, player.itemExtra, player.andar, player.moedas);
    fclose(p);
}

void jogar() {
    int eventoAndar;
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
        efeitoDigitacao("\nAperte qualquer tecla para continuar...", 25);
        getch();
    }
    for(int i=player.andar; i<=100; i++) {
        system("cls");
        if(i!=10 && i!=20 && i!=30) {
            eventoAndar = rand()%20;
            andarAtual(eventoAndar);
            printf("Aperte enter para continuar...");
            fflush(stdin);
            getchar();
        }
        player.andar++;
        salvarJogo();
    }
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
        player.def = 300;
        player.armaAtual = 0;
        player.moedas = 400;
    }
    else {
        if(opc==2) {
            strcpy(player.classe, "Bandido");
            player.hp = 850;
            player.def = 150;
            player.armaAtual = 1;
            player.moedas = 600;
        }
        else {
            strcpy(player.classe, "Feiticeiro");
            player.hp = 700;
            player.def = 100;
            player.armaAtual = 2;
            player.moedas = 350;
        }
    }

    system("cls");
    printf("---------- Criar personagem ----------\n\n");
    printf("Item extra\n");
    printf("1 - Anel da Vitalidade\nAumenta o HP em 100\n\n");
    printf("2 - Anel do Ataque\nAumenta o ATK em 100\n\n");
    printf("3 - Anel da Protecao\nAumenta a DEF em 100\n\n");
    printf("4 - Nenhum\n\n");
    printf("Selecione um item extra: ");
    scanf("%d", &opc);
    while(opc<1 || opc>4) {
        printf("Item extra invalido, tente novamente: ");
        scanf("%d", &opc);
    }
    if(opc==1) {
        player.itemExtra = 0;
        player.hp += 100;
    }
    else {
        if(opc==2) {
            player.itemExtra = 1;
            armas[player.armaAtual].dano += 100;
        }
        else {
            if(opc==3) {
                player.itemExtra = 2;
                player.def += 100;
            }
        }
    }
    
    system("cls");
    printf("---------- Confirmar criacao ----------\n\n");
    informacoesJogador();
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
        salvarJogo();
        jogar();
    }
    else {
        criarPersonagem();
    }
}

void carregarJogo() {
    int tam;
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
    tam = strlen(player.nome);
    player.nome[tam-1] = '\0';
    fgets(linha, 1024, p); //Classe
    strcpy(player.classe, linha);
    tam = strlen(player.classe);
    player.classe[tam-1] = '\0';
    fgets(linha, 1024, p); //Level
    player.level = atoi(linha);
    fgets(linha, 1024, p); //HP
    player.hp = atoi(linha);
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
    jogar();
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
    srand(time(NULL));
    system("color C");
    menuPrincipal();
    return 0;
}