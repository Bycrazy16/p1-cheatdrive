#include <iostream>
#include "lista.h"

using namespace std;

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->value << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void deleteList(Node*& head) {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}
