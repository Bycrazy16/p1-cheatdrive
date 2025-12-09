#include <iostream>
#include "tree.h"

using namespace std;

void stampa(const tree &);

int main() 
{
  char option,val;
  tree t, tmp;
  retval res;
  init(t);
  do {
    cout << "\nOperazioni possibili:\n"
         << "Inserimento (i)\n" 
         << "Ricerca (r)\n" 
         << "Stampa ordinata (s)\n" 
         << "Fine (f)\n";
    cin >> option;
    switch (option) {
    case 'i':
      cout << "Val? : ";
      cin >> val;
      res = insert(t,val);
      if (res == FAIL)
        cout << "spazio insufficiente!\n";
      break;
    case 'r':
      cout << "Val? : ";
      cin >> val;
      tmp=cerca(t,val);
      if (!nullp(tmp))
        cout << "Valore trovato!: " << val << endl;
      else
        cout << "Valore non trovato!\n";
      break;
    case 's':
      cout << "Stampa ordinata:\n";
      stampa(t);
      break;
    case 'f':
      break;
    default:
      cout << "Opzione errata\n";
    }
  } while (option != 'f');
}

// Si scrivano qui sotto le definizioni della funzione *NON RICORSIVA*:
// void stampa(const tree &)
// e di tutte le funzioni e strutture dati ausiliarie richieste.

// Definizione di uno stack ausiliario di tree

struct stacknode{
  tree val;
  stacknode *next;
};

typedef stacknode * stack ;


bool emptyp (const stack & s) {
  return (s == NULL);
}

void init(stack & s) {
  s = NULL;
}

retval top (tree &n,const stack & s) {
  retval res;
  if (emptyp(s))
    res=FAIL;
  else {
    n=s -> val;
    res=OK;
  }
  return res;
}

retval push (tree n,stack & s) {
  retval res;
  stacknode * np = new (nothrow) stacknode;
  if (np==NULL)
    res = FAIL;
  else {
    np -> val = n;
    np -> next = s;
    s = np;
    res = OK;
  }
  return res;
}

retval pop (stack & s) {
  retval res;
  if (emptyp(s))
    res=FAIL;
  else {
    stacknode *first = s;
    s = s -> next;
    delete first; 	
    res=OK;             
  }		
  return res;
}


// DEFINIZIONE DELLA ROUTINE ITERATIVA DI STAMPA

void stampa(const tree & t) {
  tree tmp = t;
  stack s;
  init(s);
  while (!emptyp(s) || tmp!=NULL) {
    if (tmp!=NULL) {
      push(tmp,s);
      tmp = tmp->left;
    }
    else {
      top(tmp,s);
      pop(s);
      cout << tmp->item << endl;
      tmp=tmp->right;
    }
  }
}
