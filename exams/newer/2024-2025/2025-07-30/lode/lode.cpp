#include <iostream>
using namespace std;

struct NodoHuffman {
    char carattere;
    NodoHuffman* sinistro;
    NodoHuffman* destro;
};

// Inserire qui sotto la definizione della funzione CodificaParola


// Inserire qui sopra la definizione della funzione CodificaParola

int main() {
    // Costruzione manuale dell'albero di esempio:
    //     (*)
    //    /   \
    //  'a'   (*)
    //       /   \
    //     'b'   'c'
    //
    // Codici:
    // 'a' → "0"
    // 'b' → "10"
    // 'c' → "11"

    NodoHuffman nodoA = {'a', nullptr, nullptr};
    NodoHuffman nodoB = {'b', nullptr, nullptr};
    NodoHuffman nodoC = {'c', nullptr, nullptr};

    NodoHuffman nodoInterno = {'*', &nodoB, &nodoC};  
    NodoHuffman radice = {'*', &nodoA, &nodoInterno}; 

    const char* parola = "abc";
    char codice[100];

    CodificaParola(&radice, parola, codice);

    cout << "Parola originale: " << parola << endl;
    cout << "Codifica Huffman: " << codice << endl;

    return 0;
}
