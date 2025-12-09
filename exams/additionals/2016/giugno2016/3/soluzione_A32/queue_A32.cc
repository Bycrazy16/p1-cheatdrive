using namespace std;
#include <iostream>
#include <cstdlib>

#include "queue.h"


void init (queue &q)
{
    q.head = q.tail = NULL;
}

retval empty (const queue &q) 
{
    return (q.head == NULL ? TRUE : FALSE);
}

void enqueue (queue &q, char val)
{
    node *n = new node;
    
    n->val = val;
    n->next = NULL;
    if (empty(q)) 
      q.head = q.tail = n;
    else 
    {
      q.tail->next = n;
      q.tail = n;
    }
}

retval dequeue (queue &q)
{ 
    node *first;
    if (empty(q)) 
      return FALSE;
    
    first = q.head;
    q.head = q.head->next;
    delete first; 
    
    if (empty(q)) 
      q.tail = NULL;
    
    return TRUE;
}

retval first (const queue &q, char &result)
{ 
    if (empty(q)) 
      return FALSE;
    
    result = q.head->val;
    return TRUE;
}


void print (const queue &q) 
{
    node *n = q.head;
    while (n != NULL) 
    {
      cout << n->val << " ";
      n = n->next;
    }
    cout << endl;
}
