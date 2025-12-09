#ifndef STRUCT_QUEUE_H
#define STRUCT_QUEUE_H

struct elem {
  long value;
  elem* next;
};

struct queue {
  elem* head;
  elem* tail;
};

void init(queue &q);
void deinit(queue &q);
bool enqueue(queue &q, long n);
bool dequeue(queue &q);
bool first(const queue &q, long &out);
void print(const queue &q);

#endif
