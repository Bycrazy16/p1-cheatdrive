#ifndef QUEUE_H
 #define QUEUE_H


struct node {
  double val;
  node *next;
};

struct queue {
  node *head;
  node *tail;
};


enum retval {FALSE = 0, TRUE = 1};


void   crea	(queue &q);
void   inserisci (queue &q, double val);
retval elimina (queue &q);
retval vuota   (const queue &q);
retval primo   (const queue &q, double &result);
void   stampa   (const queue &q);


#endif // QUEUE_H
