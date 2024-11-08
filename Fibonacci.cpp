#include <bits/stdc++.h> 
using namespace std;


//Função recursiva para calcular a sequencia com basen o n dado
int fibonacci (int n){
    if(n <= 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){

    //Variaveis
    int n = 35; //n numero dado
    int sequencia_fibonacci[n]; //Array que ira receber a sequencia, tamanho do n dado

    //For para completar o array com o que a função fibonacci retornar
    for (int i = 0; i < n; i++){
        sequencia_fibonacci[i] = fibonacci(i);
    }

    //For para printar a sequencia
    for (int i = 0; i < n; i++) {
        cout << sequencia_fibonacci[i] << " ";
    }

    cout << endl;

    bool esta_na_sequencia; //Variavel que sera true se o numero estiver, ou false se não estiver
    //For para verificar se o numero está na sequencia ou não
    for (int i = 0; i < n; i++) {
        if(sequencia_fibonacci[i] == n){
            esta_na_sequencia = true;
            break;
        }else{
            esta_na_sequencia = 0;
        }
    }

    //If/else para imprimir que o numero está ou não está na sequencia.
    if(esta_na_sequencia == true){
        cout << "O numero digitado " << n << " aesta na sequencia!" << endl;
    }else{
        cout << "O numero digitado " << n << " nao esta na sequencia" << endl;
    }

    return 0;
}