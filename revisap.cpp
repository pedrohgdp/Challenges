   
   
    //Vamos usar um trie para podermos resolver isso
    /* Uma trie é uma arvore em que cada nó e um char
    Cada nó vai ter um marcador de nó filho
    Marcador se é a ultima letra da palavra
    E um contado para ver quantas palavas tem ela*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    //TrieNode* é um ponteiro para o objeto TrieNode
    map<char, TrieNode*> children;
    bool is_end_of_word = false;
    int count = 0;
};


struct trie {
    //Criamos um ponteiro root que aponta para trienode
    TrieNode* root;
    //Agora criamos um objeto TrieNode e o ponteiro root aponta para ele
    trie(){
        //Incia a raiz
        root = new TrieNode(); 
    }

    //Vamos fazer a função dentro do struct por que sim e por que fica mais facil de manipular
    //Adicionar palavra
    void insert(const string& word){
        //Ponteiro node como a raiz
        TrieNode* node = root; 
        //Para cada letra na palavra
        for(char c : word){
            //Verifica se o nó ja tem filho na trie
            if(node->children.find(c) == node->children.end()){
                //Se n tiver ( ele for o ultimo ) cria ele como um nó com a chave sendo c
                node->children[c] = new TrieNode();
            }
            //Move o ponteiro para esse novo c que é o ultimo
            node = node->children[c];
            node->count++; //Incrementa quantas palavras tem essa letra 
        }
        //Marca como final da palavra
        node->is_end_of_word = true;
    }

    //Remover um Item
    void remove(const string& word){
        //Marca o ponteiro node no root
        TrieNode* node = root;
        //Cria uma pilha para rastrear o caminho
        //Cada elemento é um par contendo o ponteiro do pai e o caractere que leva até ele
        //E util para removermos nós
        stack<pair<TrieNode*, char>> path;
        for(int c : word){
            //Verifica se a palavra esta na trie se c for igual o final
            if(node->children.find(c) == node->children.end()){
                return; //Retorna se nao estiver
            }
            //Adicionamos o nó pai e o caractere c na pilha
            path.push({node, c});
            node = node->children[c]; //Apontamos para o proximo no
            node->count--; //Count-- por que tiramos a letra da arvore trie
        }
        //Se node for o ultimo desmarcamos ele como o ultimo 
        if(node->is_end_of_word){
            node->is_end_of_word = false;
        }
        //Agora vamos remover os nodes desnecessários
        while(!path.empty()){
            //O ponteiro parent aponta para o nó pai do nó do top da pilha
            TrieNode* parent = path.top().first;
            //O char c recebe o valor caractere do ultimo char da pilha
            char c = path.top().second;
            //Tiramos o item de cima da pilha
            path.pop();


            //Se o filho do nó que estamos não tem mais contado (não existe mais palavra que existe)
            //Removemos ele da trie
            if(parent->children[c]->count == 0){
                delete parent->children[c];
                parent->children.erase(c);
            }
        }
    }


    //Contar numero de palavras que começam com prefixo
    // Conta o número de palavras que começam com o prefixo
    int count_prefix(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            //Se nao encontrar o prefixo 
            if (node->children.find(c) == node->children.end()) {
                return 0; 
            }
            //Senao o node recebe o item que estamos
            node = node->children[c];
        }
        //retorna a variavel count no node.
        return node->count;
    }
};


int main(){
    trie trie;

    int operations;
    cin >> operations;

    for(int i = 0; i < operations; i++){
        int operationTipe;
        string s;
        cin >> operationTipe >> s;

        if(operationTipe == 1){
            trie.insert(s);
        }else if(operationTipe == 2){
            trie.remove(s);
        }else if(operationTipe == 3){
            cout << trie.count_prefix(s) << endl;
        }
    }

    return 0;
}