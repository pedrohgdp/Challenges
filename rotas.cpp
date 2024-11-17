/*PROBLEM: 


Aphrodite is concerned about humanity's love lives. Her original plan was for everyone
in a group of N people to love one another. However, this ideal scenario hasn't 
materialized. For instance, Zé loves Maria, who loves Sebastião, who loves Carolina.
Your task is to create a program that determines if "total love" exists within a given
group. This means checking if every pair of people in the group loves each other reciprocally.

*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

//NORMAL DFS BUT WE PUT U ON THE STACK AT THE END.
void dfs(int u, vector<vi> &normalGraph, vi &visited, stack<int> &pilha){
    visited[u] = 1;
    for(int v : normalGraph[u]){
        if(!visited[v]){
            dfs(v, normalGraph, visited, pilha);
        }
    }
    pilha.push(u);
}


//NORMAL DFS BUT IN INVERSE GRAPH
void reverseDfs(int u, vector<vi> &invertedGraph, vi &visited, vi &scc){
    visited[u] = 1;
    scc.push_back(u);
    for(int v : invertedGraph[u]){
        if(!visited[v]){
            reverseDfs(v, invertedGraph, visited, scc);
        }
    }
}

int main(){

    //WE CREATE THE NUMBER OF VERTICES AND NUMBER OF RELATIONSHIPS
    int nv, m; 
    //WE READ NV AND M AND DO THAT WHILE NV AND M IS DIFFERENT FROM 0
    while(cin >> nv >> m, nv != 0 && m != 0){
        //WE CREATE THE TWO GRAPHS NORMAL AND INVERTED
        vector<vi> normalGraph(nv);
        vector<vi> invertedGraph(nv);

        //CREATE VERTICES U AND V AND R
        //R == 1 RESULT IN U LOVES V 
        //R == 2 RESULT IN U LOVES V AND V LOVES U
        int u, v, r;
        for(int i = 0; i < m; i++){ 
            //WE READ U V AND R
            cin >> u >> v >> r;
            if(r == 1){
                //AND WE PUT THE LOGIC OF R == 1 OR R == 2
                normalGraph[u - 1].push_back(v - 1);
                invertedGraph[v - 1].push_back(u - 1);
            }
            if(r == 2){
                normalGraph[u - 1].push_back(v - 1);
                invertedGraph[u - 1].push_back(v - 1);
                normalGraph[v - 1].push_back(u - 1);
                invertedGraph[v - 1].push_back(u - 1);
            }
        }

        //WE CREATE A VECTOR OF INTEGERS TO MARK THE VERTICES VISITED
        vi visited(nv, 0);

        //WE CREATE THE STACK
        stack<int> pilha;
        //WE FILL THE STACK USING DFS
        for(int i = 0; i < nv; i++){
            if(!visited[i]){
                dfs(i, normalGraph, visited, pilha);
            }
        }

        //WE MARK ALL VERTICES AS NOT VISITED
        fill(visited.begin(), visited.end(), 0);
        //WE CREATE TOTAL LOVE VARIABLE 
        bool totalLove = false;
        //WE USE DFS ON INVERSE GRAPH TO GET THE SCC OF THE GRAPH
        while(!pilha.empty()){
            int u = pilha.top();
            pilha.pop();
            if(!visited[u]){
                //VECTOR WITH SCCS
                vi scc;
                reverseDfs(u, invertedGraph, visited, scc);
                if(scc.size() == nv){
                    totalLove = true;
                    break;
                }
            }
        }

        //IF TOTALLOVES IS TRUE WE PRINT 1 ELSE WE PRINT 0
        cout << (totalLove ? 1 : 0) << endl;
    }
    return 0;
}