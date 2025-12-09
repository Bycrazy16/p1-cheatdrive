#ifndef STRUCT_CODA_H
#define STRUCT_CODA_H

struct queue {
	int head, tail;
	int size;
	int *elem;
};

void init(queue &q, int maxdim);
void deinit(queue &q);
bool accoda(queue &q, int n);
bool testa(queue &q, int &out);
bool estrai_testa(queue &q);
void stampa(const queue &q);

#endif
