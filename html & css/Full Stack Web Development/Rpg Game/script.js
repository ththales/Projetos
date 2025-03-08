// Declarando Variáveis
let xp = 0;
let health = 100;
let gold = 50;
let currentWeapon = 0;
let fighting;
let monsterHealth;
let inventory = ["stick"];

//Declarando constante
const button1 = document.querySelector("#button1");
const button2 = document.querySelector("#button2");
const button3 = document.querySelector("#button3");
const text = document.querySelector("#text");
const xpText = document.querySelector("#xpText");
const hpText = document.querySelector("#hpText");
const goldText = document.querySelector("#goldText");
const monsterStats = document.querySelector("#monsterStats");
const monsterNameText = document.querySelector("#monsterName");
const monsterHpText = document.querySelector("#monsterHp");

//Atribuindo uma função para cada respectivo botão
button1.onclick = goStore;
button2.onclick = goCave;
button3.onclick = fightDragon;

function goStore() {
    //Imprimindo "Foi pra loja" no Console do navegador
    //console.log("Foi pra loja.");
    button1.innerText = "Click Me";

}

function goCave() {
    console.log("Foi pra caverna.");
}

function fightDragon() {
    console.log("Lutar contra dragão.");
}
