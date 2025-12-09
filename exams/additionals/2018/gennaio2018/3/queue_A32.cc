using namespace std;
#include "queue.h"
#include <iostream>

void init(queue &q) {
  // Inizializza la coda
  q.tail = q.head = NULL;
}

void deinit(queue &q) {
  // Rimuove tutti gli elementi dalla coda
  while(dequeue(q));
  q.tail = NULL;
}

bool is_empty(const queue &q) {
  // Vero se e solo se la coda e' vuota
  return q.head == NULL;
}

bool enqueue(queue &q, int n) {
  bool ris = false;
  // Allocazione nuovo elemento
  elem* last = new (nothrow) elem;
  if (last != NULL) {
    last->next = NULL;
    last->value = n;
    if (is_empty(q)) {
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
  if (!is_empty(q)) {
    // Toglie il primo elemento dalla coda
    // e sposta il puntatore
    elem* first = q.head;
    q.head = q.head->next;
    delete first;
    ris = true;
  }
  return ris;
}

bool first(const queue &q, int &out) {
  bool ris = false;
  if (is_empty(q)) {
    out = q.head->value;
    ris = true;
  }
  return ris;
}

void print(const queue &q) {
  // Stampa tutti gli elementi
  elem* tmp = q.head;
  while (tmp != NULL) {
    cout << tmp->value << " ";
    tmp = tmp->next;
  }
  cout << endl;
}
