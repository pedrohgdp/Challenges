#include <bits/stdc++.h>
using namespace std;


int main(){

    //s×s≡x (mod p)

    //Variavel do numero 
    long long p;
    cin >> p;

    vector<long long> raizes(p, -1);

    raizes[0] = 0;

    for(int x = 1; x < p; x++){
        for(int s = 0; s < p; s++){
            if((s * s) % p == x){
                if(raizes[x] == -1 || s < raizes[x]){
                    raizes[x] = s;
                    break;
                }
            }
        }
    }


    for(int i = 0; i < p; i++){
        cout << raizes[i] << " ";
    }

    cout << endl;

    return 0;
}