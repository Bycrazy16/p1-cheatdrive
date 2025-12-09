using namespace std;
#include "queue.h"
#include <iostream>

static int next(int index, const queue &q) 
{
    return (index + 1) % q.dim;
}

void init(queue &q, int maxdim) 
{
    q.tail = q.head = 0;
    q.dim = maxdim+1;
    q.elem = new char[q.dim];
}

void deinit(queue &q)
{
    delete[] q.elem;
}

static bool vuota(const queue &q) 
{
    return q.tail == q.head;
}

static bool piena(const queue &q)
{
    return next(q.tail, q) == q.head;
}

bool accoda(queue &q, char n) 
{ 
    if (piena(q)) {
        return false;
    }
    q.elem[q.tail] = n;
    q.tail = next(q.tail, q);
    return true;
}

bool estrai_testa(queue &q) 
{ 
    if (vuota(q)) {
        return false;
    }
    q.head = next(q.head, q);
    return true;
}

bool testa(queue &q, char &out)
{
    if (vuota(q)) {
        return false;
    }
    out = q.elem[q.head];
    return true;
}

void stampa(const queue &q) 
{
    for (int i = q.head; i != q.tail; i = next(i, q)) {
        cout << q.elem[i] << endl;
    }
    cout << endl;
}
