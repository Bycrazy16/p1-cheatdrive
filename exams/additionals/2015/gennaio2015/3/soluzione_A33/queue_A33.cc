using namespace std;

#include "queue.h"
#include <iostream>

static int next(int index, const queue &q) {
	return (index + 1) % q.size;
}

void init(queue &q, int maxdim) {
	q.tail = q.head = 0;
	q.size = maxdim + 1;
	q.elem = new double[q.size];
}

void deinit(queue &q) {
	delete[] q.elem;
}

static bool is_empty(const queue &q) {
	return q.tail == q.head;
}

static bool is_full(const queue &q) {
	return next(q.tail, q) == q.head;
}

bool enqueue(queue &q, double n) {
	bool ris = false;
	if (!is_full(q)) {
		q.elem[q.tail] = n;
		q.tail = next(q.tail, q);
		ris = true;
	}
	return ris;
}

bool dequeue(queue &q) {
	bool ris = false;
	if (!is_empty(q)) {
		q.head = next(q.head, q);
		ris = true;
	}
	return ris;
}

bool first(queue &q, double &out) {
	bool ris = false;
	if (!is_empty(q)) {
		out = q.elem[q.head];
		ris = true;
	}
	return ris;
}
void print(const queue &q) {
	for (int i = q.head; i != q.tail; i = next(i, q)) {
		cout << q.elem[i] << endl;
	}
	cout << endl;
}
