#include <iostream>
#include "coda.h"

using namespace std;

Queue* createQueue() {
    Queue* q = new Queue{nullptr, nullptr};
    return q;
}

void enqueue(Queue* q, int value) {
    QueueNode* node = new QueueNode{value, nullptr};
    if (!q->rear) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}

int dequeue(Queue* q) {
    if (!q->front) {
        cerr << "Errore: dequeue da coda vuota" << endl;
        return -1;
    }

    QueueNode* node = q->front;
    int val = node->value;
    q->front = q->front->next;
    if (!q->front) {
        q->rear = nullptr;
    }
    delete node;
    return val;
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

void deleteQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    delete q;
}
