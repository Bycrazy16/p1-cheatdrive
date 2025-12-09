#ifndef STRUCT_QUEUE_H
#define STRUCT_QUEUE_H

struct queue {
	int head, tail;
	int dim;
	float *elem;
};

void init(queue &q, int maxdim);
void deinit(queue &q);
bool enqueue(queue &q, float n);
bool dequeue(queue &q);
bool first(queue &q, float &out);
void print(const queue &q);

#endif

