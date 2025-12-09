#include <iostream>
using namespace std;

struct NodoHuffman {
    char carattere;
    NodoHuffman* sinistro;
    NodoHuffman* destro;
};

// Funzione ricorsiva per trovare il codice di un carattere target
bool TrovaCodice(NodoHuffman* nodo, char target, char* buffer, int profondita) {
    if (!nodo) return false;

    // Se siamo su una foglia e il carattere corrisponde
    if (!nodo->sinistro && !nodo->destro && nodo->carattere == target) {
        buffer[profondita] = '\0'; // fine stringa
        return true;
    }

    // Esplora ramo sinistro (bit 0)
    buffer[profondita] = '0';
    if (TrovaCodice(nodo->sinistro, target, buffer, profondita + 1)) {
        return true;
    }

    // Esplora ramo destro (bit 1)
    buffer[profondita] = '1';
    if (TrovaCodice(nodo->destro, target, buffer, profondita + 1)) {
        return true;
    }

    // Carattere non trovato in questo ramo
    return false;
}

void CodificaParolaI(NodoHuffman* radice, const char* parola, char* codiceRisultato) {
    int indice = 0;

    for (int i = 0; parola[i] != '\0'; ++i) {
        char codiceTemp[100]; // buffer temporaneo per codice del singolo carattere

        if (!TrovaCodice(radice, parola[i], codiceTemp, 0)) {
            cerr << "Errore: carattere '" << parola[i] << "' non trovato nell'albero di Huffman." << endl;
            codiceRisultato[0] = '\0';
            return;
        }

        // Copia il codice del carattere in codiceRisultato
        for (int j = 0; codiceTemp[j] != '\0'; ++j) {
            codiceRisultato[indice++] = codiceTemp[j];
        }
    }

    codiceRisultato[indice] = '\0'; // termina la stringa finale
}

void CodificaParola(NodoHuffman* radice, const char* parola, char* codiceRisultato, int i=0, int l=0) {
    if (parola[i] == '\0') {
        // codiceRisultato[l-1] = '\0'; // termina la stringa
        return;
    }
    char codiceTemp[100]; // buffer temporaneo per il codice del singolo carattere
    if (!TrovaCodice(radice, parola[i], codiceTemp, 0)) {
        cerr << "Errore: carattere '" << parola[i] << "' non trovato nell'albero di Huffman." << endl;
        codiceRisultato[0] = '\0';
        return;
    }
    // Aggiungi il codice del carattere corrente al risultato, non necessariamente in modo ricorsivo
    for (int j = 0; codiceTemp[j] != '\0' && l < 99; ++j) {
        codiceRisultato[l++] = codiceTemp[j];
    }
    codiceRisultato[l] = '\0'; // termina la stringa
    // Chiamata ricorsiva per il prossimo carattere
    CodificaParola(radice, parola, codiceRisultato, i + 1, l);
    return;
}

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
