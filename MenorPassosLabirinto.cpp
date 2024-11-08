#include <bits/stdc++.h> 
using namespace std;
    
void principal(int m, int n, int x, int y,vector<vector<int>> &lab, vector<int> &caminhos, vector<vector<int>> &visitados, int passos){
    //Começa com passo 0 (por que deu certo).

    //Array como todas as direções possiveis para se andar em x
    int direcaox[4] = {1, -1, 0, 0};
    //Mesma coisa de y
    int direcaoy[4] = {0, 0, 1, -1};
    //Aqui temos um comb se pegar o indice 0 de cada vai dar (1, 0) que é andar para baixo
   
    
    //Se chegou ao destino, adiciona a quantidade de passos no array caminhos e retorna saindo da função
    if(x == m - 1 && y == n - 1){
        caminhos.push_back(passos);
        return;
    }

    //For para calcular uma nova posição com base no nosso x e y atual, ex: 
    /* x == 1 y == 2 
    xnovo vai receber x + 1 no caso quando i for 0, pois o valor do array dx é 1 no indice 0
    Mesma coisa ynovo*/
    
    for(int i = 0; i < 4; i++){
        int xnovo = x + direcaox[i];
        int ynovo = y + direcaoy[i];

        //Veirfica se a nova posição de x e y é valida de chama a função recursiva aumentando os passos e marcando como visitado e desmarcando para poder andar dnv
        if(xnovo >= 0 && xnovo < m && ynovo >= 0 && ynovo < n && visitados[xnovo][ynovo] == 0 && lab[xnovo][ynovo] == 0){
            //Marca a posição novo x e novo y como visitado
            visitados[xnovo][ynovo] = 1;
            //chama a função recursiva aumentando o passo em 1 e com xnovo e ynovo como novas posições
            principal(m, n, xnovo, ynovo, lab, caminhos, visitados, passos + 1);
            //Desmarca a posição para que possa ser usada denovo
            visitados[xnovo][ynovo] = 0;
        }
    }  
}




int main(){

    int m, n;
    //Ler linhas e colunas
    cin >> m >> n;

    //Criar a matriz labirinto
    vector<vector<int>> lab(m, vector<int>(n, 0));

    //Variavel com a quantidade de obstaculos
    int quantObs;
    cout  << "Digite a quantidade de obstaculos" << endl;
    cin >> quantObs;
    
    for(int i = 0; i < quantObs; i++){
        int posObstaculoM, posObstaculoN;
        cin >> posObstaculoM >> posObstaculoN;
        if (posObstaculoM >= 0 && posObstaculoM < m && posObstaculoN >= 0 && posObstaculoN < n) {
            lab[posObstaculoM][posObstaculoN] = 1;
        }
    }    

    //Array que vai marcar a quantidade de paços de cada caminho / seu tamanho é a quantidade de caminho
    vector<int> caminhos;

    //Matriz que vai guardar os lugares visitados.
    vector<vector<int>> visitados(m, vector<int>(n, 0));

    //Marca na posição [0][0] da matriz de visitados que foi visitado, representado como 1
    //Cada lugar visitado tem 1 como valor
    visitados[0][0] = 1;
    //Chama a função principal, começando na posição zero, passando os vetores que serao atualizados, e começando com 0 passos dados
    principal(m, n, 0, 0, lab, caminhos, visitados, 0);



    //Variavel da quantidade de caminhos
    int quant_Caminhos = caminhos.size();
    //Variavel de menor passo dado
    int menor_quant_passo_dado;

    //Se caminhos estiver vazio "retorna" 0, não tem caminhos possiveis
    if(caminhos.empty()){
        menor_quant_passo_dado = 0;
    }else{
        menor_quant_passo_dado = *min_element(caminhos.begin(), caminhos.end());
    }

    cout << endl << quant_Caminhos << " " << menor_quant_passo_dado;

    return 0;
}