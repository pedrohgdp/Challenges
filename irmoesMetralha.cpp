#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void dfs(int u, vector<pair<long long, vi>> &grafoNormal, vector<int> &visitados, stack<int> &pilha){
    visitados[u] = 1;
    for(int v : grafoNormal[u].second){
        if(!visitados[v]){
            dfs(v, grafoNormal, visitados, pilha);
        }
    }
    pilha.push(u);
}


void reverseDfs(int u, vector<pair<long long, vi>> &grafoInvertido, vector<int> &visitados, vi &scc, long long fortunaSoma){
    visitados[u] = 1;
    scc.push_back(u);
    fortunaSoma += grafoInvertido[u].first;
    for(int v : grafoInvertido[u].second){
        if(!visitados[v]){
            reverseDfs(v, grafoInvertido, visitados, scc, fortunaSoma);
        }
    }
}

int main(){

    int nv, arr;
    cin >> nv >> arr;

    vector<pair<long long, vi>> grafoNormal(nv), grafoInvertido(nv);

    //Leituras das fortunas
    for(int i = 0; i < nv; i++){
        cin >> grafoNormal[i].first;
    }

    int u, v;

    while(arr--){
        cin >> u >> v;
        grafoNormal[u - 1].second.push_back(v - 1);
        grafoInvertido[v - 1].second.push_back(u - 1);
    }



    vector<int> visitados(nv, 0);
    stack<int> pilha;
    for(int i = 0; i < nv; i++){
        if(!visitados[i]){ 
            dfs(i, grafoNormal, visitados, pilha);
        }
    }


    fill(visitados.begin(), visitados.end(), 0);

    //Variavel de fortuna maxima ( total ) ( começa com 0 que vai ser substituida )
    long long maxFortuna = 0;

    while(!pilha.empty()){
        int u = pilha.top();
        pilha.pop();
        if(!visitados[u]){
            vi scc;
            //Variavel para verificar a soma de cada scc
            long long fortunaSoma = 0;
            reverseDfs(u, grafoInvertido, visitados, scc, fortunaSoma);
            //Selecina o maximo entre o que ja esta no maximo fortuna conseguida e a soma do scc atual
            maxFortuna = max(maxFortuna, fortunaSoma);
        }
    }

    cout << maxFortuna << endl;

    //Verificar as somas d

    return 0;
}