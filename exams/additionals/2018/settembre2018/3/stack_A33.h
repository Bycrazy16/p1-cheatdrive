#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H

struct stack {
    int index;
    int dim;
    int *elem;
};

void init(stack &s, int maxdim);
void deinit(stack &s);
bool push(stack &s, int n);
bool top(const stack &s, int &out);
bool pop(stack &s);
void print(const stack &s);

#endif
