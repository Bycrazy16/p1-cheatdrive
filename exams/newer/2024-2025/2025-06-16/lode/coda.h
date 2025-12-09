#ifndef CODA_H
#define CODA_H

struct QueueNode {
    int value;
    QueueNode* next;
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;
};

Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
bool isEmpty(Queue* q);
void deleteQueue(Queue* q);

#endif
