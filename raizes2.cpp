#include <bits/stdc++.h>
using namespace std;

void calcular(int p, vector<long long> &raizes){
    for(int s = 1; s < p; s++){
        int numeroRaiz = (s * s) % p;
        if(raizes[numeroRaiz] == -1){
            raizes[numeroRaiz] = s;
        }
    }
}


int main(){

    //s×s≡x (mod p)

    //Variavel do numero 
    long long p;
    cin >> p;
    
    vector<long long> raizes(p, -1);
    raizes[0] = 0;
    calcular(p, raizes);

    for(int i = 0; i < p; i++){
        cout << raizes[i] << " ";
    }

    cout << endl;

    return 0;
}