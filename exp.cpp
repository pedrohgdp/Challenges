#include <bits/stdc++.h>
using namespace std;

struct expoentes{
    long long a;
    long long b;
    long long c;
};


int main(){

    //Modulo 
    const int mod = 1000000000 + 7;

    int quantTeste = 0;
    cin >> quantTeste;

    vector<expoentes> numeros(quantTeste);
    //Vetor para guardar os resultados de b**c
    vector<long long> resultados(quantTeste);


    //For que vou ler e ja vou calcular b**c
    for(int i = 0; i < quantTeste; i++){
        //Vou ler os valores a b e c.
        cin >> numeros[i].a >> numeros[i].b >> numeros[i].c;
        //Resultado recebe 1 por que o primeiro caso é b * b
        resultados[i] = 1;
        //Pegamos o modulo de b para ja deixar o valor pequeno
        numeros[i].b %= (mod - 1);
        //While para calcula o resultado
        //While roda enquanto o c for > 0;
        while(numeros[i].c > 0){
            //Se o numero for impar eu pego o valor em resultado[i] * base e pego o modulo.
            if(numeros[i].c % 2 == 1){
                resultados[i] = (numeros[i].b * resultados[i]) % (mod - 1);
            }
            //depois disso divido por 2 arredondando por baixo
            numeros[i].c /= 2;
            //O Valor no expoente b recebe ele * ele mesmo e o modulo.
            numeros[i].b = (numeros[i].b * numeros[i].b) % (mod - 1);

            /*
            Resumindo 2 ^ 3
            3 é impar então resultado na casa 0 recebe 2 * 1 == 2
            depois divide 3 / 2 dando 1
            a base 2 recebe 2 * 2 == 4
            1 > 0 e é impar
            resultado recebe 4 * 2 == 8
            divide por 2 dando 0
            base recebe 4 * 4 = 8 
            mas o while ja sai com resultado no i com 8*
            no caso no final sempre vai ser impar então atualizando a base quando par e atualizando o 
            valor na casa do resultados quando é impar no final vamos ter o valor certo*
            */

       }
    }


    //Mesma coisa só que com a
    for(int i = 0; i < quantTeste; i++){
        long long resultadoFinal = 1;
        numeros[i].a %= mod;
        while(resultados[i] > 0){
            if(resultados[i] % 2 == 1){
                resultadoFinal = (numeros[i].a * resultadoFinal) % (mod);
            }
            resultados[i] /= 2;
            numeros[i].a = (numeros[i].a * numeros[i].a) % (mod);
        }
        cout << resultadoFinal << endl;
    }

    return 0;
}
