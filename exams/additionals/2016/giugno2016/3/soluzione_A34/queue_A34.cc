using namespace std;
#include <iostream>
#include <cstdlib>

#include "queue.h"


void crea (queue &q)
{
    q.head = q.tail = NULL;
}

retval vuota (const queue &q) 
{
    return (q.head == NULL ? TRUE : FALSE);
}

void inserisci (queue &q, float val)
{
    node *n = new node;
    
    n->val = val;
    n->next = NULL;
    if (vuota(q)) 
      q.head = q.tail = n;
    else 
    {
      q.tail->next = n;
      q.tail = n;
    }
}

retval elimina (queue &q)
{ 
    node *first;
    if (vuota(q)) 
      return FALSE;
    
    first = q.head;
    q.head = q.head->next;
    delete first; 
    
    if (vuota(q)) 
      q.tail = NULL;
    
    return TRUE;
}

retval primo (const queue &q, float &result)
{ 
    if (vuota(q)) 
      return FALSE;
    
    result = q.head->val;
    return TRUE;
}


void stampa (const queue &q) 
{
    node *n = q.head;
    while (n != NULL) 
    {
      cout << n->val << " ";
      n = n->next;
    }
    cout << endl;
}
