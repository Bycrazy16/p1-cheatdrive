#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H

struct stack {
    int index;
    int dim;
    char *elem;
};

void init(stack &s, int maxdim);
void deinit(stack &s);
bool push(stack &s, char n);
bool top(const stack &s, char &out);
bool pop(stack &s);
void print(const stack &s);

#endif
