#ifndef QUEUE_H
 #define QUEUE_H


struct node {
  float val;
  node *next;
};

struct queue {
  node *head;
  node *tail;
};


enum retval {FALSE = 0, TRUE = 1};


void   crea	(queue &q);
void   inserisci (queue &q, float val);
retval elimina (queue &q);
retval vuota   (const queue &q);
retval primo   (const queue &q, float &result);
void   stampa   (const queue &q);


#endif // QUEUE_H
