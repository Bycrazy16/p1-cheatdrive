#include <iostream>
#include <climits>

#include "lista.h"   
#include "coda.h"  

using namespace std;

// Funzione da completare
int secondoMinimo(Node* head) {
    if (!head || !head->next) {
        cerr << "Errore: la lista deve contenere almeno due elementi distinti." << endl;
        return -1;
    }

    Queue* q = createQueue();

    // Inserisce tutti i valori della lista nella coda
    Node* curr = head;
    while (curr) {
        enqueue(q, curr->value);
        curr = curr->next;
    }

    // Estrai i valori dalla coda e trova minimo e secondo minimo
    int min1 = INT_MAX, min2 = INT_MAX;

    while (!isEmpty(q)) {
        int val = dequeue(q);
        if (val < min1) {
            min2 = min1;
            min1 = val;
        } else if (val < min2 && val != min1) {
            min2 = val;
        }
    }

    deleteQueue(q);

    return min2;
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
