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
         << "Stampa indentata (e)\n"
         << "Stampa in ampiezza (b)\n"
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
      print_ordered(t);
      break;
    case 'e':
      cout << "Stampa indentata:\n";
      print_indented(t);
      break;
    case 'b':
      cout << "Stampa in ampiezza - breadth-first:\n";
      stampa(t);
      break;
     case 'f':
      break;
    default:
      cout << "Optione errata\n";
    }
  } while (option != 'f');
}


// ////////////////////////////////////////////////////
// Si scrivano qui sotto le definizioni della funzione *NON RICORSIVA*:
// void stampa(const tree &)
// e di tutte le funzioni e strutture dati ausiliarie richieste.
// ////////////////////////////////////////////////////

// ////////////////////////////////////////////////////
// Definizione di una coda ausiliaria di tree
// ////////////////////////////////////////////////////


struct queuenode{
  tree val;
  queuenode *next;
};

struct queue {
  queuenode* head;
  queuenode* tail;
};


void queueinit(queue &q) {
  // Inizializza la coda
  q.tail = q.head = NULL;
}

bool queueemptyp(const queue &q) {
  // Vero se e solo se la coda e' vuota
  return q.head == NULL;
}

bool enqueue(queue &q, tree n) {
  bool ris = false;
  // Allocazione nuovo elemento
  queuenode* last = new (nothrow) queuenode;
  if (last != NULL) {
    last->next = NULL;
    last->val = n;
    if (queueemptyp(q)) {
      // Primo e ultimo elemento
      q.head = q.tail = last;
    } else {
      // Caso generale
      q.tail->next = last;
      q.tail = last;
    }
    ris = true;
  }
  return ris;
}

bool dequeue(queue &q) { 
  bool ris = false;
  if (!queueemptyp(q)) {
    // Toglie il primo elemento dalla coda
    // e sposta il puntatore
    queuenode* first = q.head;
    q.head = q.head->next;
    delete first;
    ris = true;
  }
  return ris;
}

bool first(const queue &q, tree & out) {
  bool ris = false;
  if (!queueemptyp(q)) {
    out = q.head->val;
    ris = true;
  }
  return ris;
}

// ////////////////////////////////////////////////////
// DEFINIZIONE DELLA ROUTINE ITERATIVA DI STAMPA
// ////////////////////////////////////////////////////

void stampa(const tree & t) {
  if (t!=NULL) {
    tree tmp = t;
    queue q;
    queueinit(q);
    enqueue(q,tmp);    
    while (!queueemptyp(q)) {
        first(q,tmp);
        dequeue(q);
        cout << tmp->item << " ";
        if (!emptyp(tmp->left))
  	  enqueue(q,tmp->left);
        if (!emptyp(tmp->right))
  	  enqueue(q,tmp->right);
    }
    cout << endl;
  }
}

