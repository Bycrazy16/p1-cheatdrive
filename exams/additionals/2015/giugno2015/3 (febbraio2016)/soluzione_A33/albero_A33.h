// -*- C++ -*-
#ifndef ALBERO_H 
#define ALBERO_H 

struct Nodo {
    int val;
    Nodo *sx;
    Nodo *dx;
};

typedef Nodo * Albero;

enum boolean { VERO, FALSO };

void inizializza(Albero &t);
boolean vuoto(const Albero &t);
boolean inserisci(Albero &t, int val);
boolean cerca(const Albero &t, int val);
void stampa(const Albero &t);

#endif
