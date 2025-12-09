#ifndef LISTA_H
#define LISTA_H

struct Node {
    int value;
    Node* next;
};

void append(Node*& head, int value);

void printList(Node* head);

void deleteList(Node*& head);

#endif
