#include <bits/stdc++.h> 
using namespace std;


int main(){
    //Criar as variaveis
    int n, x;

    cin >> n >> x;


    //Vetor com os preços dos livros
    vector<int> book_Price(n);

    //For para preencher ele
    for(int i = 0; i < n; i++){
        cin >> book_Price[i];
    }

    //Vetor para paginas por livro
    vector<int> pag_Per_Books(n);

    //For para completar paginas por livro
    for(int i = 0; i < n; i++){
        cin >> pag_Per_Books[i];
    }

    //Esse vetor vai armazenar em cada posição dele a quantidade de paginas que podemo comprar com dinheir
    //que temos
    //Começamos com o valor 0 indo até a quantidade de dinheiro que temos 
    vector<int> max_Pag(x + 1, 0);

    for(int i = 0; i <= n; i++){
        int price = book_Price[i]; // Preço do livro atual
        int pag = pag_Per_Books[i]; // Pagina do livro atual

        //Vamos usar a expressão max_pag[j - price] + pag
        //No caso j representa quanto temos para gastar e price o preço do livro
        //Essa subtração vai nos dar uma posição no array que vai dizer quantas paginas podemos comprar
        //No inicio é zero, mas conforme for rodando o for esse array vai preenchendo com os maiores valores
        //No final a ultima posição vai guardar o maior valor de paginas que podemos comprar com dinheiro

        /* Ex temos 10 de dinheiro o livro vale 4, na posição 6 tem paginas ainda
        Então sera 0 + 4 (quant pagina do livro )
        Na proxima vez que cairmos naquela posição, sabemos que temos 4 paginas possiveis para comprar +
        o numero de paginas do livro atual
        
        Isso acontece pois se o primeiro livro for muito caro e tiver poucas paginas, conseguimos
        comprar, mas pode ser que tenha um mais barato com mais paginas que de para comprar com ele*/

        for(int j = x; j >= price; j--){
            max_Pag[j] = max(max_Pag[j], max_Pag[j - price] + pag);
        }
    }


    cout << max_Pag[x - 1];

    return 0;
}