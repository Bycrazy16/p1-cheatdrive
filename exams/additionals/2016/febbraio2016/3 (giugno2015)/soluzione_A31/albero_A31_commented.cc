#include <iostream>
#include "albero.h"

using namespace std;

void inizializza(Albero &a) {
	a = NULL;							// inizializza l'albero a NULL
}

boolean vuoto(const Albero &a) {
	return (a == NULL) ? VERO : FALSO;	// ritorna falso se l'albero presenta almeno un elemento
}

boolean inserisci(Albero &a, int val) {
	// Caso base, l'albero risulta vuoto quindi devo allocare un nodo
	if (vuoto(a) == VERO) {				// se l'albero risulta vuoto
		a = new (nothrow) Nodo;			// alloca dinamicamente un nodo, controllando l'eccezione in caso di fallimento
		if (a == NULL) {				// se l'operazione di allocazione dinamica non va a buon fine
			return FALSO;				// ritorna falso: l'inserimento NON è andato a buon fine
		}
		a->val = val;					// scrive nel campo val il valore passato
		a->sx = a->dx = NULL;			// inizializza i rami dx e sx del ramo allocato a NULL
		return VERO;					// ritorna vero: l'inserimento è andato a buon fine
	}
	// Caso ricorsivo, l'albero presenta elementi al suo interno
	// Controllo se scendere a sinistra o a destra
	if (val <= a->val) {				// se il valore e' maggiore o uguale
		// Scendo a sinistra			// inserisci nel ramo sinistro il valore passato come parametro
		return inserisci(a->sx, val);	
	} else if (val > a->val) {			// se il valore e' minore
		// Scendo a destra
		return inserisci(a->dx, val);	// inserisci nel ramo destro il valore passato come parametro
	}
}

boolean cerca(const Albero &a, int val) {
	if (vuoto(a) == VERO) {				// se il ramo risulta vuoto allora
		return FALSO;					// ritorna falso: non ci sono elementi da cercare
	} else if (val == a->val) {			// se il valore cercato si trova ESATTAMENTE nel nodo in cui sei allora
		// Trovato
		return VERO;					// ritorna vero: hai trovato il valore cercato
	} else if (val < a->val) {			// se il <valore cercato> è MINORE del <valore che si trova nel nodo ATTUALE> allora
		// Scendo a sinistra
		return cerca(a->sx, val);		// si cerca ricorsivamente nel ramo sinistro
	} else {
		// Scendo a destra
		return cerca(a->dx, val);		// altrimenti, (se il <valore cercato> è MAGGIORE del <valore che si trova nel nodo ATTUALE>), cerca ricorsivamente nel ramo destro
	}
}

void stampa(const Albero &a) {
	if (vuoto(a) == FALSO) {			// se l'albero non risulta vuoto
		// Prima stampo gli elementi MINORI di a->val (cioe` quelli a sx)
		stampa(a->sx);
		// Poi stampo a->val
		cout << a->val << ' ';
		// Poi stampo gli elementi MAGGIORI (cioe` quelli a dx)
		stampa(a->dx);
	}
}
