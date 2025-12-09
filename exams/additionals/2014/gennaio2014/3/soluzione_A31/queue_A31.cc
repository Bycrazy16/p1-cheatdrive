#include "queue.h"
#include <iostream>

using namespace std;

static int next(int index, const queue &q) {
    return (index + 1) % q.dim;
}

void init(queue &q, int maxdim) {
    q.tail = q.head = 0;
    q.dim = maxdim + 1;
    q.elem = new float[q.dim];
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

bool enqueue(queue &q, float n) {
    if (is_full(q)) {
        return false;
    }
    q.elem[q.tail] = n;
    q.tail = next(q.tail, q);
    return true;
}

bool dequeue(queue &q) {
    if (is_empty(q)) {
        return false;
    }
    q.head = next(q.head, q);
    return true;
}

bool first(queue &q, float &out) {
	if (is_empty(q)) {
		return false;
	}
	out = q.elem[q.head];
	return true;
}

void print(const queue &q) {
	for (int i = q.head; i != q.tail; i = next(i, q)) {
		cout << q.elem[i] << endl;
	}
	cout << endl;
}
