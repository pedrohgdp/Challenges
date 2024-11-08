#include <bits/stdc++.h>
using namespace std;


int main(){

    int quantTernos;

    //Ler quantidade de ternos
    cin >> quantTernos;

    vector<int> custo_Terno(quantTernos, 0);
    //Ler o custo de cada terno
    for(int i = 0; i < quantTernos; i++){
        cin >> custo_Terno[i];
    }

    vector<int> custosTrocas(quantTernos, INT_MAX);
    //0 na posição 0 por que nao tem custo de troca
    custosTrocas[0] = 0;

    //Vector vai guardar o valor da troca até derminado lugar, começa tudo em 0
    //for começa em 1 por que sim
    for(int i = 0; i < quantTernos; i++){
        //valor de troca de i para i + 1 isso vai ser guardado no lugar de i + 1
        //Nesse caso é o valor que esta no custo de trocas na posição ( na primeira iteração 0), mais a diferença do custo de terno de uma posição e outra
        if(i + 1 < custosTrocas.size()){
            custosTrocas[i + 1] = min(custosTrocas[i + 1], custosTrocas[i] + abs(custo_Terno[i] - custo_Terno[i + 1]));
        }
        //verifica se nao esta fora da posição o i + 2 e faz a mesma coisa
        if(i + 2 < custo_Terno.size()){
            custosTrocas[i + 2] = min(custosTrocas[i + 2], custosTrocas[i] + abs(custo_Terno[i] - custo_Terno[i + 2]));
        }
    }
    //A soma serve para somar a quantidade de custo do primeiro até o i que estamos 
    //No caso o custo do primeiro até o i que estamos + o custo para ir até o proximo
    //Assim quando chegar no ultimo fazendo isso vmaos ter o valor da menor quantidade de paços

    cout << endl;

    //Imprime o ultimo elemento do array
    cout << custosTrocas[quantTernos - 1] << endl;

    //teste mudança 1
    
    return 0;
}
