#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
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

    Tomos
    Tomo da Vida (+25% HP atual)
    Tomo da Fúria (+50% ATK atual)
    Tomo da Seguranca (+75% DEF atual)

*/

typedef struct {
    char nome[100];
    int dano, valor;
    char raridade[100];
} Arma;

Arma armas[] = {
    {"Espada Longa", 200, 150, "(Comum)"}, //0
    {"Adaga Afiada", 250, 200,"(Comum)"}, //1
    {"Cajado Misterioso", 350, 400,"(Comum)"}, //2
    {"Machado Pesado", 300, 350,"(Comum)"}, //3
    {"Lanca Longa", 150, 100,"(Comum)"}, //4
    {"Livro Conjurador de Feiticos", 225, 210,"(Comum)"}, //5
    {"Talisma abencoado", 390, 340,"(Comum)"}, //6
    {"Laminas Duplas das Sombras", 400, 550,"(Rara)"}, //7
    {"Luvas do Golpeador", 560, 500,"(Rara)"}, //8
    {"Alabarda do Soldado Corrompido", 600, 530,"(Rara)"}, //9
    {"Katana do Samurai Esquecido", 760, 690,"(Rara)"}, //10
    {"Rapieira do Orgulhoso", 800, 950,"(Epica)"}, //11
    {"Foice da Morte", 1666, 1500,"(Satanica)"}, //11
    {"Nenhuma", 10, 0,"(Sem classificacao)"}, //12
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
    char raridade[100];
    int arma, danoArma, valor, item;
}Loja;

typedef struct {
    char nome[1024], classe[100];
    int level, xp, hp, maxHp, def, maxDef, armaAtual, itemExtra, moedas, andar, tipoAndar;
}Personagem;

typedef struct {
    char nome[100];
    int level, hp, atk, def, droparArma;
}Inimigo;

FILE *p;
Personagem player;

int opc;

void menuPrincipal();

void salvarJogo();

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
    printf("XP: %d (%d XP para o Level %d)\n", player.xp, (100*(player.level*player.level))-player.xp, player.level+1);
    printf("HP: %d\n", player.hp);
    printf("ATK: %d\n", armas[player.armaAtual].dano);
    printf("DEF: %d\n", player.def);
    printf("Arma atual: %s %s\n", armas[player.armaAtual].nome, armas[player.armaAtual].raridade);
    printf("Item extra: %s\n", itens[player.itemExtra].nome);
    printf("Moedas: %d\n\n", player.moedas);
}

void descansarFogueira() {
    player.tipoAndar = 3;
    salvarJogo();
    player.hp = player.maxHp;
    player.def = player.maxDef;
    system("cls");
    do {
        system("cls");
        printf("---------- Dungeon of Death ----------\n");
        printf("---------- Fogueira %d ----------\n\n", player.andar);
        printf("Voce encontra uma fogueira para descansar, neste momento voce recupera suas forcas para enfrentar um desafio ainda maior...\n\n");
        printf("1 - Seguir em frente\n2 - Melhorar arma\n");
        informacoesJogador();
        printf("Selecione uma opcao: ");
        scanf("%d", &opc);
        while(opc<1 || opc>2) {
            printf("Opcao invalida, tente novamente: ");
            scanf("%d", &opc);
        }
        if(opc==2) {
            int melhoria, custo;
            melhoria = (int)(armas[player.armaAtual].dano+(armas[player.armaAtual].dano*pow(1.25, player.level)));
            custo = (player.level+(rand()%251));
            system("cls");
            printf("---------- Ferreiro ----------\n");
            printf("Voce encontra um ferreiro que aprimora seus equipamentos \"Ola criatura... O que posso fazer por voce?\"\n");
            informacoesJogador();
            printf("1 - Melhorar %s\nNovo dano: %d\nCusto: %d moedas\n\n", armas[player.armaAtual].nome, melhoria, custo);
            printf("Selecione sua arma para melhora-la: ");
            scanf("%d", &opc);
            while(opc!=1) {
                printf("Arma invalida, tente novamente: ");
                scanf("%d", &opc);
            }
            opc = 2;
        }
    } while(opc!=1);
}

void bauItens() {
    int texto;
    texto = rand()%5;
    player.tipoAndar = 2;
    salvarJogo();
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
}

void vendedorItens() {
    int qtdItens;
    qtdItens = rand()%5+1;
    Loja itens[qtdItens];
    player.tipoAndar = 1;
    salvarJogo();
    opc = rand()%5;
    printf("---------- Dungeon of Death ----------\n");
    switch(opc) {
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
    printf("\n---------- Itens disponiveis (%d) ----------\n\n", qtdItens);
    for(int i=0; i<qtdItens; i++) {

        int armaAtual = rand()%13;
        itens[i].danoArma = armas[armaAtual].dano;
        if(player.level<=10){
            strcpy(itens[i].raridade, "(Comum)");
        }
        else {
            if(player.level>10 && player.level<=25) {
                strcpy(itens[i].raridade, "(Rara)");
                itens[i].danoArma *= 1.25;
            }
            else {
                if(player.level>25 && player.level<=40) {
                    strcpy(itens[i].raridade, "(Epica)");
                    itens[i].danoArma *= 1.5;
                }
                else {
                    if(player.level>40 && player.level<=60) {
                        strcpy(itens[i].raridade, "(Oculta)");
                        itens[i].danoArma *= 2;
                    }
                    else {
                        strcpy(itens[i].raridade, "(Profana)");
                        itens[i].danoArma += pow(itens[i].danoArma, 1.25);
                    }
                }
            }
        }
        itens[i].valor = pow(itens[i].danoArma, 1.10);
        printf("%d - %s\nATK: %d\nRaridade: %s\nValor: %d moedas\n\n", i+1, armas[armaAtual].nome, itens[i].danoArma, itens[i].raridade, itens[i].valor);
    }
    informacoesJogador();
    printf("Selecione uma opcao: ");
    scanf("%d", &opc);
    while(opc<1 || opc>3) {
        printf("Opcao invalida, tente novamente: ");
        scanf("%d", &opc);
    }
    while(player.moedas<itens[opc-1].valor ) {
        printf("Saldo insuficiente\n");
    }
    if(player.moedas>=itens[opc-1].valor) {
            if(opc==1) {

                player.armaAtual = itens[opc-1].arma;
                armas[player.armaAtual].dano = itens[opc-1].danoArma;
                strcpy(armas[player.armaAtual].raridade, itens[opc-1].raridade);
            }
            else {
                if(opc==2) {

                }
            }
        }
}

void combateInimigos() {
    int numInimigos, inimigoLevelAcima, turno = 1, dano, defender, vivos, texto, timer, xpGanho = 0, moedasGanhas;
    player.tipoAndar = 0;
    int pocoes[3];
    pocoes[0] = pocoes[1] = pocoes[2] = 1;
    salvarJogo();
    numInimigos = (rand()%player.level)+1;
    if(numInimigos>10) {
        numInimigos = 10;
    }
    vivos = numInimigos;
    texto = rand()%10;
    Inimigo inimigos[numInimigos];
    printf("\nCOMBATE!\n");
    for(int i=0; i<numInimigos; i++) {
        inimigoLevelAcima = rand()%3;
        if(inimigoLevelAcima==0 && player.level>1) {
            inimigos[i].level = player.level-1;
        }
        else {
            if(inimigoLevelAcima==1) {
                inimigos[i].level = player.level;
            }
            else {
                inimigos[i].level = player.level+1;
            }
        }
        inimigos[i].hp = 100 + player.level*2.5 + rand()%(player.level*100);
        inimigos[i].atk = 75 + player.level*2 + rand()%(player.level*20);
        inimigos[i].def = 50 + player.level*1.5 + rand()%(player.level*50);
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
            printf("---------- Escolhas ----------\n");
            printf("1 - Atacar\n");
            printf("2 - Defender\n");
            printf("3 - Usar pocao\n\n");
            printf("Selecione uma opcao:\n");
            scanf("%d", &opc);
            while(opc==2 && player.def<=0) {
                printf("Nao e possivel defender pois sua defesa foi quebrada! Tente novamente: ");
                scanf("%d", &opc);
            }
            /* Opcoes
                Atacar - ataca um ou mais inimigos
                Defender - Reduz o dano recebido no próximo turno.
                Usar Poção - Permite ao jogador recuperar HP consumindo uma poção.
                Fugir - Dá uma chance de escapar do combate.
                Habilidades Especiais - Dependendo da arma ou classe do jogador, ele pode ter habilidades diferentes, como um ataque forte ou envenenamento.
                Trocar de Arma - Permite ao jogador mudar de arma no meio da batalha
            */
            if(opc==1) {
                printf("Selecione um inimigo para atacar [ ]\b\b");
                scanf("%d", &opc);
                while (opc<1 || opc>numInimigos || inimigos[opc-1].hp<=0) {
                    printf("Selecione um inimigo valido! Tente novamente: ");
                    scanf("%d", &opc);
                }
                dano = armas[player.armaAtual].dano-inimigos[opc-1].def;
                if(dano>0) {
                    inimigos[opc-1].hp -= dano;
                    inimigos[opc-1].def = 0;
                }
                else {
                    inimigos[opc-1].def = dano*(-1);
                }
                printf("Voce atacou o inimigo %d ", opc);
                if(inimigos[opc-1].hp<=0) {
                    printf("e o matou!\n");
                    inimigos[opc-1].hp = 0;
                    vivos--;
                    xpGanho = inimigos[opc-1].level*100*(1+0.1*(inimigos[opc-1].level-player.level));
                    player.xp += xpGanho;
                    printf("Voce ganhou %d XP nessa eliminacao!\n", xpGanho);
                    if(player.xp>=(100 * (player.level * player.level))) {
                        player.level++;
                        int hpGanho, defGanho;
                        hpGanho = player.level*100;
                        defGanho = player.level*150;
                        player.hp += hpGanho;
                        player.def += defGanho;
                        printf("Voce subiu para o level %d!\n+%d HP e +%d DEF\n", player.level, hpGanho, defGanho);
                    }
                }
                else {
                    printf("deixando-o com %d de HP!\n\n", inimigos[opc-1].hp);
                }
            }
            else {
                if(opc==2) {
                    defender = 1;
                    printf("Voce ira defender os ataques inimigos no proximo turno!\n\n");
                }
                else {
                    if(opc==3) {
                        printf("Selecione uma pocao\n");
                        printf("1 - Vitalidade (+%d HP)\nDisponivel: %d\n", (int)(player.hp*0.10), pocoes[0]);
                        printf("2 - Abencoar escudo (+%d DEF)\nDisponivel: %d\n", (int)(player.def*0.15), pocoes[1]);
                        printf("3 - Fortalecer-se (+%d ATK)\nDisponivel: %d\n\n",(int)(armas[player.armaAtual].dano*0.7), pocoes[2]);
                        printf("Selecione uma opcao: ");
                        scanf("%d", &opc);
                        while((opc<1 || opc>3) || (pocoes[opc-1]==0)) {
                            printf("Opcao invalida! Tente novamente: ");
                            scanf("%d", &opc);
                        }
                        if(opc==1) {
                            player.hp += (int)(player.hp*0.10);
                            pocoes[0]--;
                        }
                        else {
                            if(opc==2) {
                                player.def += (int)(player.def*0.15);
                                pocoes[1]--;
                            }
                            else {
                                armas[player.armaAtual].dano += (int)(armas[player.armaAtual].dano*0.7);
                                pocoes[2]--;
                            }
                        }
                    }
                }
            }
            turno = 0;
            printf("Pressione qualquer tecla para continuar...");
            getch();
        }
        else {
            for(int i=0; i<numInimigos; i++) {
                if(inimigos[i].hp>0) {
                    if(defender==1) {
                        dano = inimigos[i].atk*0.15;
                    }
                    else {
                        dano = inimigos[i].atk;
                    }
                    printf("Inimigo %d te atacou! ", i+1);
                    if(dano<0) {
                        dano = 0;
                    }
                    if(player.def>=dano) {
                        printf("e voce perdeu %d de DEF!\n", dano);
                        player.def -= dano;
                    }
                    else {
                        printf("e voce perdeu %d de HP!\n", dano);
                        dano -= player.def;
                        player.def = 0;
                        player.hp -= dano;
                    }
                    timer = rand()%501;
                    timer += rand()%501;
                    Sleep(timer);
                }
            }
            printf("\n");
            turno = 1;
            defender = 0;
            printf("Pressione qualquer tecla para continuar...");
            getch();
        }
    }
    if(player.hp<0) {
        player.hp = 0;
    }
    system("cls");
    printf("---------- FIM DE COMBATE! ----------\n\n");
    if(player.hp>0) {
        moedasGanhas = ((rand()%player.level+1)*100)+(rand()%51);
        printf("Voce sobreviveu com %d de HP e ganhou %d de XP!\n", player.hp, xpGanho);
        printf("voce coletou %d moedas nesse andar!\n", moedasGanhas);
        player.moedas += moedasGanhas;
        informacoesJogador();
    }
    else {
        printf("Voce morreu! Fim de jogo...\n");
        informacoesJogador();
        p = fopen("save.dat", "w");
        if(p==NULL) {
            printf("Erro ao abrir arquivo do save.\n");
            exit(1);
        }
        fclose(p);
        remove("save.dat");
        printf("Aperte enter para voltar ao menu principal...");
        fflush(stdin);
        getch();
        menuPrincipal();
    }
}

void salvarJogo() {
    p = fopen("save.dat", "w");
    if(p==NULL) {
        printf("Falha ao abrir o save.\n");
        exit(1);
    }
    fprintf(p, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", player.nome, player.classe, player.level, player.xp, player.hp, player.maxHp, player.def, player.maxDef, player.armaAtual, player.itemExtra, player.andar, player.tipoAndar, player.moedas);
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
            if(i!=9 && i!=19 && i!=29) {
                eventoAndar = rand()%20;
                if(eventoAndar<=14) {
                    combateInimigos();
                }
                else {
                    if(eventoAndar>14 && eventoAndar<=17) {
                        bauItens();
                    }
                    else {
                        vendedorItens();
                    }
                }
            }
            else {
                descansarFogueira();
            }
            printf("Aperte enter para continuar...");
            fflush(stdin);
            getchar();
        }
        player.andar++;
        salvarJogo();
    }
}

void criarPersonagem() {
    player.xp = player.itemExtra = 0;
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
        player.hp = player.maxHp = 1200;
        player.def = player.maxDef = 300;
        player.armaAtual = 0;
        player.moedas = 400;
    }
    else {
        if(opc==2) {
            strcpy(player.classe, "Bandido");
            player.hp = player.maxHp = 850;
            player.def = player.maxDef = 150;
            player.armaAtual = 1;
            player.moedas = 600;
        }
        else {
            strcpy(player.classe, "Feiticeiro");
            player.hp = player.maxHp = 700;
            player.def = player.maxDef = 100;
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
        player.maxHp += 100;
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
                player.maxDef += 100;
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
        printf("Slot de saves vazio (inexistente ou movido).\n\n");
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
    fgets(linha, 1024, p); //XP
    player.xp = atoi(linha);
    fgets(linha, 1024, p); //HP
    player.hp = atoi(linha);
    fgets(linha, 1024, p); //MAX HP
    player.maxHp = atoi(linha);
    fgets(linha, 1024, p); //DEF
    player.def = atoi(linha);
    fgets(linha, 1024, p); //MAX DEF
    player.maxDef = atoi(linha);
    fgets(linha, 1024, p); //Arma atual código
    player.armaAtual = atoi(linha);
    fgets(linha, 1024, p); //Item extra codigo
    player.itemExtra = atoi(linha);
    fgets(linha, 1024, p); //Andar atual
    player.andar = atoi(linha);
    fgets(linha, 1024, p); //Tipo Andar Atual
    player.tipoAndar = atoi(linha);
    fgets(linha, 1024, p); //Moedas
    player.moedas = atoi(linha);
    fclose(p);
    switch (player.tipoAndar){
        case 0:
            combateInimigos();
            break;
        case 1:
            vendedorItens();
            break;
        case 2:
            bauItens();
            break;
        case 3:
            descansarFogueira();
            break;
    }
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
    printf("Saindo do jogo...");
    return 0;
}