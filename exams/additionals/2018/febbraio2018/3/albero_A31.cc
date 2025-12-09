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
  boolean res = FALSO;
  if (vuoto(a) == VERO) {
    a = new (nothrow) Nodo;
    if (a != NULL) {
      a->val = val;
      a->sx = a->dx = NULL;
      res = VERO;
    }
  } else if (val <= a->val) {
    // Caso ricorsivo: scendo a sinistra
    res = inserisci(a->sx, val);
  } else {
    // Caso ricorsivo: scendo a destra
    res = inserisci(a->dx, val);
  }
  return res;
}

boolean cerca(const Albero &a, int val) { 
  boolean res = FALSO;
  if (vuoto(a) == FALSO) {
    if (val == a->val) {
      // Trovato
      res = VERO;
    } else if (val < a->val) {
      // Scendo a sinistra
      res = cerca(a->sx, val);
    } else {
      // Scendo a destra
      res = cerca(a->dx, val);
    }
  }
  return res;
}

void stampa(const Albero &a) {
  if (vuoto(a) == FALSO) {
    // Prima stampo gli elementi MINORI di a->val (cioe` quelli a sx)
    stampa(a->sx);
    // Poi stampo a->val
    cout << a-> val << ' ';
    // Poi stampo gli elementi MAGGIORI (cioe` quelli a dx)
    stampa(a->dx);
  }
}
