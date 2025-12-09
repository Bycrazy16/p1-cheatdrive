#include <iostream>
#include "albero.h"

using namespace std;

void inizializza(Albero &a) {
	a = NULL;
}

boolean vuoto(const Albero &a) {
	return (a == NULL) ? VERO : FALSO;
}

boolean inserisci(Albero &a, int val) {
	// Caso base
	if (vuoto(a) == VERO) {
		a = new (nothrow) Nodo;
		if (a == NULL) {
			return FALSO;
		}
		a->val = val;
		a->sx = a->dx = NULL;
		return VERO;
	}
	// Caso ricorsivo. Controllo se scendere a sinistra o a destra
	if (val < a->val) {
		// Scendo a sinistra
		return inserisci(a->sx, val);
	} else if (val >= a->val) {
		// Scendo a destra
		return inserisci(a->dx, val);
	}
}

boolean cerca(const Albero &a, int val) {
	if (vuoto(a) == VERO) {
		return FALSO;
	} else if (val == a->val) {
		// Trovato
		return VERO;
	} else if (val < a->val) {
		// Scendo a sinistra
		return cerca(a->sx, val);
	} else {
		// Scendo a destra
		return cerca(a->dx, val);
	}
}

void stampa(const Albero &a) {
	if (vuoto(a) == FALSO) {
		// Prima stampo gli elementi MINORI di a->val (cioe` quelli a sx)
		stampa(a->sx);
		// Poi stampo a->val
		cout << a->val << ' ';
		// Poi stampo gli elementi MAGGIORI (cioe` quelli a dx)
		stampa(a->dx);
	}
}
