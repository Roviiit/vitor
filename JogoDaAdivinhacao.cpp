#include<iostream>
#include<cstdlib> //Biblioteca para função abs (Calcular pontos com mais precisao)
#include<ctime> //Biblioteca para função time (Gerador de numero aleatório)
using namespace std; 

int main(){

//Gerador de numero aleatório.
srand(time(NULL));
const int NUMERO_SECRETO = rand() % 100;

//Inicio
cout << "************************************" << endl;
cout << "*Bem vindo ao jogo da adivinhacao!!*" << endl;
cout << "************************************" << endl;
cout << endl;
cout << "O numero secreto esta entre 0 e 99. BOA SORTE!!!" << endl;
cout << endl;

//Variáveis e funcoes para selecionar a dificuldade.
bool selecionar_dificuldade = true;
int numero_tentativas;

while(selecionar_dificuldade){

string dificuldade;
cout << "Escolha o nivel de dificuldade:" << endl;
cout << "| Facil (F) | Medio (M) | Dificil (D) |" << endl;
cout << "Nivel de dificuldade: ";
cin >> dificuldade;
cout << endl;

if(dificuldade == "F" || dificuldade == "f"){
    numero_tentativas = 15;
    cout << "Voce escolheu o nivel facil com 15 tentativas." << endl;
    cout << endl;
    selecionar_dificuldade = false;
}else if(dificuldade == "M" || dificuldade == "m"){
    numero_tentativas = 10;
    cout << "Voce escolheu o nivel medio com 10 tentativas" << endl;
     cout << endl;
    selecionar_dificuldade = false;
}else if(dificuldade == "D" || dificuldade == "d"){
    numero_tentativas = 5;
    cout << "Voce escolheu o nivel dificil com 5 tentativas" << endl;
    cout << endl;
    selecionar_dificuldade = false;
}else {
    cout << "Esta dificuldade nao existe!" << endl;
    cout << endl;
    cout << "Escolha novamente:" << endl;
    cout << endl;
}
}

//Sistema de pontuação e limitação de tentativas
int chance;
int tentativa = 0;
double pontos = 1000.0;
    cout.precision(2);
    cout << fixed;

for(tentativa = 1; tentativa <= numero_tentativas; tentativa++){

cout << "Tentativa " << tentativa << endl;
cout << "Digite um numero: ";
cin >> chance;
cout << endl;

bool nao_acertou = tentativa >= numero_tentativas;
bool acertou = chance == NUMERO_SECRETO;
bool maior = chance > NUMERO_SECRETO;
bool menor = chance < NUMERO_SECRETO;
double pontos_perdidos = abs(chance - NUMERO_SECRETO)/2.0;

if(nao_acertou){
    cout << "O numero secreto era " << NUMERO_SECRETO << endl;
    cout << endl;
    cout << "Voce perdeu!";
    cout << endl;
    break;
}else if(acertou){
    cout << "Parabens! Voce acertou o numero secreto!" << endl;
    cout << endl;
    cout << "Voce acertou o numero secreto em " << tentativa << " tentativas!" << endl;
    cout << endl;
    cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    cout << endl;
    break;
}else if(maior){
    cout << "Sua tentativa foi maior que o numero secreto. Tente novamente." <<endl;
    cout << endl;
}else if(menor){
    cout << "Sua tentativa foi menor que o numero secreto. Tente novamente." << endl;    
    cout << endl;
}
pontos = pontos - pontos_perdidos;
}
return 0;
}