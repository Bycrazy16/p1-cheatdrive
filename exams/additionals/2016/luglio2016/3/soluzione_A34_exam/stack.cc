using namespace std;
#include <iostream>

#include "stack.h"	/* definizione di node e di stack */

// variabile globale indice che punta alla prima cella libera di memoria
int index;

// testa se la pila e' vuota
retval empty (const stack &s) {
	return (s->next == NULL) ? TRUE : FALSE;
}

// inizializza -> alloca dinamicamente
void init (stack &s) {
	index = 0;
}

// dealloca
void deinit (stack &s) {
	delete[] node;
}

// equivalente a pop, devo testare se la pila e' vuota
retval shrink (stack &s) {
	// se la pila e' vuota -> non posso rimuovere elementi -> ritorna FALSE
	if(empty(s)) {
		return FALSE;
	}
	index--;			// diminuisce l'indice dimenticandosi del valore memorizzato in quella cella
	return TRUE;		// l'operazione e' andata a buon fine -> ritorna TRUE
}

// equivalente a push, se la pila e' vuota devo allocare un nuovo nodo
// non devo controllare se la pila e' piena -> e' allocata dinamicamente
void add (stack &s, double val) {
	if(empty(s)) {
		s->next = new (nothrow) node;
	}
	s->val[index] = val;	// scrive il valore passato come parametro in posizione indice
	index++;				// aumenta l'indice
}

// mostra il primo elemento senza buttarlo via
retval first (const stack &s, double &result) {
	// se la pila e' vuota -> non c'e' niente da mostrare -> esci
	if(empty(s)) {
		return FALSE;
	}
	result = s->val[index-1];
	return TRUE;
}

// stampa la pila
void print (const stack &s) {
	for(int i = 0; i < index; i++) {					// il contatore si ferma quando la pila non ha piu' elementi
		cout << "[" << i << "]: " << s->val << endl;	// stampa i valori in posizione indice
	}
	// non ha un valore di ritorno perche' e' void
}
