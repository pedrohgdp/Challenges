#include <bits/stdc++.h> 
using namespace std;


//Esse booleano vai retornar se o numero é primo ou não
bool isPrime(int n){

    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;

    if(n % 2 == 0 || n % 3 == 0) return false; //Se o numero dividido pelos 2 primeiros primos
    //Der resto 0, então ele nao é primo!

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
        // n  % i = 6k + a5 e n % ( i + 2 ) = 6k + 1
        //Ele não são todos primos, mas todos primos podem ser escritos 
    }
    
    return true;

}

//Função para calcular a quantidade de operações para ir de N não primo Para n + x primo onde x é a quantidade de operações

int nextPrimeSteps(int n){
    //Se for 1 retorna 1 pq é só uma operação de 1 para o proximo primo
    if(n == 1) return 1;
    //Se for 0 retorna 2 pq é a quantidade de operações até o proximo primo
    if(n < 1) return 2;
    //Operaçoes começa com 0
    int operations = 0;
    //Enquanto n não for primo a gente aumenta 1 em n e aumenta 1 em operações
    while(!isPrime(n)){
        n++;
        operations++;
    }

    return operations;
}



//Função para ver a quantidade de operaçoes para transformar uma linha inteira em um linha com todos elementos primos
int smallerOperationLine(vector<vector<int>> &matriz, int line, int column){
    //Minimo de opperações começa com um numero grande por conta de ser substituida.
    int minOperations = INT_MAX;
    for(int l = 0; l < line; l++){
        //Quantidade de operaçoes atuais
        int operationsLine = 0;
        int lineStop = l;

        for(int c = 0; c < column; c++){
            operationsLine += nextPrimeSteps(matriz[lineStop][c]);
        }
        
        minOperations = min(minOperations, operationsLine);
    }
    return minOperations;
}

int smallerOperationColumn(vector<vector<int>> &matriz, int line, int column){
    int minOperations = INT_MAX;
    for(int c = 0; c < column; c++){

        int operationsColumn = 0;
        int columnStop = c;

        for(int l = 0; l < line; l++){
            operationsColumn += nextPrimeSteps(matriz[l][columnStop]);
        }

        minOperations = min(minOperations, operationsColumn);
    }

    return minOperations;
}



int main(){
    
    //Ler linha e Coluna 
    int line, column;
    cin >> line >> column;

    //Matriz com os numeros digitados
    vector<vector<int>> matriz(line, vector<int>(column));

    //For para preencher a matriz
    for(int i = 0; i < line; i++){
        for(int j = 0; j < column; j++){
            cin >> matriz[i][j];
        }
    }

    int smallLine = smallerOperationLine(matriz, line, column);
    int smallColumn = smallerOperationColumn(matriz, line, column);

    cout << min(smallLine, smallColumn) << endl;
    

    return 0;
}
