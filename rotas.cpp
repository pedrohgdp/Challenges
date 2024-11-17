#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void dfs(int u, vector<vi> &grafoNormal, vi &visitados, stack<int> &pilha){
    visitados[u] = 1;
    for(int v : grafoNormal[u]){
        if(!visitados[v]){
            dfs(v, grafoNormal, visitados, pilha);
        }
    }
    pilha.push(u);
}



void reverseDfs(int u, vector<vi> &grafoInvertido, vi &visitados, vi &scc){
    visitados[u] = 1;
    scc.push_back(u);
    for(int v : grafoInvertido[u]){
        if(!visitados[v]){
            reverseDfs(v, grafoInvertido, visitados, scc);
        }
    }
}




int main(){

    int nv, m;
    while(cin >> nv >> m, nv != 0 && m != 0){
        vector<vi> grafoNormal(nv);
        vector<vi> grafoInvertido(nv);


        int u, v, r;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> r;
            if(r == 1){
                grafoNormal[u - 1].push_back(v - 1);
                grafoInvertido[v - 1].push_back(u - 1);
            }
            if(r == 2){
                grafoNormal[u - 1].push_back(v - 1);
                grafoInvertido[u - 1].push_back(v - 1);
                grafoNormal[v - 1].push_back(u - 1);
                grafoInvertido[v - 1].push_back(u - 1);
            }
        }

        vi visitados(nv, 0);
        stack<int> pilha;
        for(int i = 0; i < nv; i++){
            if(!visitados[i]){
                dfs(i, grafoNormal, visitados, pilha);
            }
        }

        fill(visitados.begin(), visitados.end(), 0);
        bool amorTotal = false;
        while(!pilha.empty()){
            int u = pilha.top();
            pilha.pop();
            if(!visitados[u]){
                vi scc;
                reverseDfs(u, grafoInvertido, visitados, scc);
                if(scc.size() == nv){
                    amorTotal = true;
                    break;
                }
            }
        }

        cout << (amorTotal ? 1 : 0) << endl;
    }
    return 0;
}