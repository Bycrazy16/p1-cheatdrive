using namespace std;
#include <iostream>
#include <cstdlib>

#include "queue.h"


void init (queue &q)
{
    q.head = q.tail = NULL;						// inizializzo la coda inizializzando testa e coda a null
}

retval empty (const queue &q) 
{
    return (q.head == NULL ? TRUE : FALSE);		// la coda è vuota se la testa è pari a NULL
}

void enqueue (queue &q, long val)
{
    node *n = new node;							// crea un nuovo nodo
    
    n->val = val;								// inserisce il valore passato nel valore della struttura
    n->next = NULL;								// inizializzo next a NULL
    if (empty(q)) 								// se la coda risulta vuota allora
      q.head = q.tail = n;						// rendi testa e cosa uguali al nodo appena creato
    else 										// se la coda NON e' vuota allora
    {
      q.tail->next = n;							// sto scrivendo nel campo next di coda che avrà un prossimo elemento
      q.tail = n;								// comunico al campo coda che si deve spostare all'ultimo elemento inserito (index++)
    }
}

retval dequeue (queue &q)
{ 
    node *first;								// dichiaro un nodo primo
    if (empty(q)) 								// se la coda e' vuota allora
      return FALSE;								// ritorni falso
    
    first = q.head;								// il primo diventa la testa della coda
    q.head = q.head->next;						// la testa diventa il prossimo della 
    delete first;								// cancella il primo della coda
    
    if (empty(q)) 
      q.tail = NULL;
    
    return TRUE;
}

retval first (const queue &q, long &result)		// corrisponde al top di pila
{ 
    if (empty(q)) 
      return FALSE;
    
    result = q.head->val;						// stampa il valore contenuto in head
    return TRUE;
}


void print (const queue &q) 
{
    node *n = q.head;
    while (n != NULL)							// finchè n non punta ad una cella vuota
    {
      cout << n->val << " ";					// stanpo il valore corrente
      n = n->next;								// sovrascrivo il valore corrent con il prossimo
    }
    cout << endl;
}
