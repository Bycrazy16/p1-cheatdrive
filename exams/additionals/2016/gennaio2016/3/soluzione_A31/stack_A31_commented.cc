using namespace std;
#include "stack.h"
#include <iostream>

static bool is_empty(const stack &s)
{
    return s.index == 0;				// ritorna vero vero se la pila è vuota, false altrimenti
}

static bool is_full(const stack &s)
{
    return s.index == s.dim;			// l'index è uguale alla dimensione della pila
}

void init(stack &s, int maxdim)
{
    s.index = 0;						// l'indice si trova a 0
    s.dim = maxdim;						// la dimensione si trova a max dim
    s.elem = new double[maxdim];		// alloca dinamicamente un array di double
}

void deinit(stack &s)
{
    delete[] s.elem;					// dealloca gli elementi dell'array elem
}

bool top(const stack &s, double &out)
{
    if (is_empty(s)) {
        return false;
    } else {
        out = s.elem[s.index-1];
        return true;
    }
}

bool push(stack &s, double n)
{
    if (is_full(s)) {				// return s.index == s.maxdim
        return false;				// permette di scrivere il messaggio di pila piena
    } else {
        s.elem[s.index++] = n;		// aggiunge l'elemento in posizione n e aggionra l'indice
        return true;				// l'operazione va a buon fine
    }
}
    
bool pop(stack &s) 
{
    if (is_empty(s)) {				// se la pila è piena non ha nessun elemento da togliere
        return false;				// quindi ritorna falso
    } else {
        s.index--;					// decrementa l'indice dimenticandosi del contenuto
        return true;				// ritorna vero
    }
}
    
void print(const stack &s) 
{
    for (int i = 0; i < s.index; i++) {
        cout << s.elem[i] << " ";
    }
    cout << endl;
}
