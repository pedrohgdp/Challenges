#include <bits/stdc++.h> 
using namespace std;


int main(){

    int quantNumbers;
    cin >> quantNumbers;

    vector<int> numbers(quantNumbers);
    //For para ler os valores do array
    for(int i = 0; i < quantNumbers; i++){
        cin >> numbers[i];
    }

    vector<int> numbersOfDiv(quantNumbers, 2);


    for(int i = 0; i < quantNumbers; i++){
        for(int j = 2; j < numbers[i]; j++){
            if(numbers[i] % j == 0){
                numbersOfDiv[i]++;
            }
        }
    }

    cout << endl;
    cout << endl;
    for(int i = 0; i < quantNumbers; i++){
        cout << numbersOfDiv[i] << endl;
    }

    return 0;
}