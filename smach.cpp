#include <bits/stdc++.h>
using namespace std;

int main(){

    string s, p;
    getline(cin, s); //getline le a linha inteira incluindo espaços
    getline(cin, p);


    //Tamanhos da string e do padrão
    int n = s.length();
    int m = p.length();

    //Contagem de aparições
    int aparicao = 0;
    //Indices
    vector<int> indices;
    //n - m por que caso for maior que isso o padrão p não cabe dentro da string
    //Logo é impossivel ter o padrão a partir da posição de n - m
    for(int i = 0; i <= n - m; i++){
        //substr(i, m) a gente pega a substring que começa em i e vai até m ( que é o tamanho do nosso p )
        if(s.substr(i, m) == p){
            aparicao++;
            indices.push_back(i);
        }
    }

    if(aparicao >= 100){
        cout << aparicao << endl;
    }else{
        cout << aparicao << endl;
        for(int i : indices){
            cout << i << endl;
        }
    }

     return 0;
}

