#include <bits/stdc++.h> 
using namespace std;


const int mod = 10e9 + 7;

bool is_Valid(int i, int j, int m, const vector<vector<char>> &lab){
    return i >= 0 && i < m  && j >= 0 && j < m  && lab[i][j] == '.';
}

int main(){
    int m;
    cin >> m;
    //Criar a matriz labirinto
    vector<vector<char>> lab(m, vector<char>(m));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> lab[i][j];
        }
    }


    //Vetor de caminhos, cada caminho vai guardar o valor para chegar até ele desde a posição inicial
    vector<vector<int>> caminhos(m, vector<int>(m, 0));


    if(lab[0][0] == '.'){
        caminhos[0][0] = 1;
    }

    //For para fazer calculo de quantas vezes tenho que percorrer para chegar até esse caminho
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(is_Valid(i, j, m, lab)){
                if(i > 0 && is_Valid(i - 1, j, m, lab)){
                    caminhos[i][j] = (caminhos[i][j] + caminhos[i - 1][j]) % mod;
                }
                if(j > 0 && is_Valid(i, j - 1, m, lab)){
                    caminhos[i][j] = (caminhos[i][j] + caminhos[i][j - 1]) % mod;
                }
                if(i > 0 && j > 0 && is_Valid(i - 1, j - 1, m, lab)){
                    caminhos[i][j] = (caminhos[i][j] + caminhos[i - 1][j - 1]) % mod;
                }
            }
            //Se a posição for valida, vamos somar o valor para chegar até a celula de cima mais o valor da celula que estamos ( usando 
            // o modulo para não dar overflow ) e vamos guardar esse valor na posição que estamos
            //No final cada celula vai ter a quantidade total de maneira de chegar nela
            //Ou seja somando o valor da de cima com a de baixo ( que é a que estamos ) e guardando esse valor na de baixo ( que é a que estamos)
            //Vamos ter mais uma quantidade de maneira para chegar na de baixo por que temos que a chegando na de cima vamos para essa se quiser
        }
    }
    
    cout << caminhos[m-1][m-1] << endl;

    return 0;
}