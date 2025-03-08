/// @description Esse código rodará quando o objeto atual for criado (Evento create)
/// 01) Comentárioos
// Isso é um comentário

/*
	Isso também é um comentário
    a
    b
    c
    d
    e
    ...
*/

/// 02) Imprimindo mensagens na tela (string)

show_message("Hello world");

//Exercicio 1: Crie uma história utilizando 5 funções show_message()
//Era uma vez um pudim que foi atravessar a rua e foi atropelado
show_message("Era uma vez...");
show_message("Um pudim foi atravessar a rua,");
show_message("mas mal podia esperar pelo o que estava por vir...");
show_message("Foi atropelado :(");
show_message("Por um avião!");

//Note que no GameMaker, os caracteres especiais ~, ´ etc já estão inclusos, diferente de C e C++, não é necessário se preocupar

/// 03) Tipos de dados
/*
    char = 'a'; (Caracter único)
    string = "Olá, como vai?"; (Sequência de caracteres)
    int = 5, 30, 20, 100 (Números inteiros)
    float = 4.53, 9.423, 9213.2 (Números decimais)
    bool = 1/true or 0/false (Dados booleanos (verdadeiro ou falso))
*/

//Exercicio 2: Fale, utilizando mensagens separadas, seu nome inteiro, a sua idade, qual estado você vive e sua altura
show_message("Thales Alves Araújo");
show_message(19);
show_message("GO");
show_message(1.75);

//Exercicio 3: Crie uma variável e pergunte se o usuário é do sexo masculino ou feminino
menino = true;
show_message(menino);

/// 04) Variáveis
/*
    Def: Espaço alocado para armazenar informações
    Essas informações que podem sofrer alterações.

    obs: Diferente das linguagens C, C++, por exemplo, não é necessário informar o tipo da variável durante a declaração
*/
nome = "Joao";

//Imprimindo o conteúdo da variável nome
show_message(nome);

//Mudando o conteúdo da variável nome
nome = "Pedro";

//Imprimindo o conteúdo da variável nome após sua mudança
show_message(nome);

/* 
    Exercicio 4: Crie 4 variáveis, armazene dentro delas os seguintes valores: nome inteiro, idade, estado e altura, de uma pessoa
    Após isso, imprima na tela esses dados, respectivamente.
*/

//Declarando variáveis
nome = "Paulo";
idade = 73;
estado = "SP";
altura = 1.83;

//Imprimindo o conteúdo de cada variável
show_message(nome);
show_message(idade);
show_message(estado);
show_message(altura);

/// 05) Convenções de nomenclatura
/*
    Snake case: Separa as palavras usando underline (_)
    Ex: obj_player, spr_idle, ...

    Camel case: Separa as palavras com a letra inicial de cada uma sendo maiúscula
    Ex: objPlayer, sprIdle, ...
    
    Obs: O GameMaker é Case sensitive, ou seja, ele diferencia letras maiúsculas de minúsculas

*/

/// 06) Lendo dados do usuário
//Lendo uma string
nome = get_string("Digite seu nome: ", "nome completo");

//Imprimindo o nome do usuário
show_message("Seu nome é: " + nome);

/* 
    Exercicio 5: Crie 4 variáveis, armazene dentro delas os seguintes valores (string) lidos pelo teclado do usuário: nome inteiro, idade, estado
    e altura, de uma pessoa
    Após isso, imprima na tela esses dados, respectivamente, usando apenas 1 show message
*/

//Lendo os dados do usuário
nome = get_string("Digite seu nome: ", "");
idade = get_string("Ditie sua idade: ", "");
estado = get_string("Digite seu estado: ", "");
altura = get_string("Digite sua altura: ", "");

//Armazenando todo o texto em uma única variável
texto = "Seu nome é: " + nome + "\nSua idade é: " + idade + "\nSeu estado é: " + estado + "\nSua altura é: " + altura;

// Obs: Se usa o + para concatenar as stringes, ou seja, na verdade estou juntando os dados lidos com a string que quero armazenar

//Imprimindo o texto completo
show_message("Dados cadastrados\n" + texto);

//Lendo números
idade = get_integer("Digite sua idade", "");

//Imprimindo o numero lido (usando 2 show_message)
show_message("Sua idade é: ");
show_message(idade);

//Exercicio 6: Imprimindo o numero lido (usando 1 show_message)
show_message("Sua idade é: " + string(idade));