#include <iostream>
#include <climits>

#include "lista.h"   
#include "coda.h"  

using namespace std;

// Funzione da completare
int secondoMinimo(Node* head) {
    
}

// MAIN di esempio
int main() {

    Node* head = nullptr;

    // Lista: 10 → 15 → 5 → 20
    append(head, 10);
    append(head, 15);
    append(head, 5);
    append(head, 20);

    cout << "La lista e': ";
    printList(head);

    int risultato = secondoMinimo(head);
    cout << "Il secondo minimo e' " << risultato << endl;

    deleteList(head);
    return 0;
}
